void printButtonStates(){
  for (int i = keyboardRowCount-1; i >= 0; i--) {
    for (int k = keyboardColumnCount-1; k >= 0; k--) {
      Serial.print(buttonStates[i][k]);
      Serial.print(" ");
    }
    Serial.print("\n");
  }
  Serial.print("\n\n");
}

void actOnHighButtonStates(){
  bool funButtonPressed = LOW;
  for (int i = 0; i < keyboardRowCount; i++) {
    for (int k = 0; k < keyboardColumnCount; k++) {
      if (buttonStates[i][k]) {
        funButtonPressed = HIGH;
      }
    }
  }
  if (funButtonPressed) {
    pixels.setPixelColor(0, pixels.Color(0, 0, maxBrightness));
    pixels.show();
  }else{
    pixels.clear();
    pixels.show();
  }
}

void actOnRisingEdges() {
  for(int m=5;m>=0;m--){
    if(risingEdgeQueue[m] != 0){
      switch (currentMode){
        case 0:
          // Regular typing mode
          pressMode00(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 1:
          // Numpad, Arrows and naviation  mode
          pressMode01(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 2:
          // Defunct
          pressMode02(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 3:
          // Macros 1
          pressMode03(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 4:
          // Fast repeat of regular keys
          pressMode00(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 5:
          // Macros 2
          pressMode00(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 8:
          // Sticky
          pressMode00(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 9:
          // Macros 3
          pressMode00(risingEdgeQueue[m]);
          risingEdgeQueue[m] = 0;
          break;
        case 15:
          // Standby mode
          break;
        default:
          Serial.print(F("Invalid mode when pressing keys\t"));
          Serial.print(currentMode);
          Serial.print("\n");
          errorLight();
          break;
      }
    }
  }
}

void actOnFallingEdges() {
  for(int m=5;m>=0;m--){
    if(fallingEdgeQueue[m] != 0){
      switch (currentMode){
        case 0:
          // Regular typing mode
          releaseMode00(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 1:
          // Numpad, arrows and naviation mode
          releaseMode01(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 2:
          // defunct
          releaseMode02(fallingEdgeQueue[m]);
          break;
        case 3:
          // Macros 1
          releaseMode03(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 4:
          // Fast repeat of regular keys
          releaseMode00(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 5:
          // Macros 2
          releaseMode00(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 8:
          // Sticky
          releaseMode00(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 9:
          // Macros 3
          releaseMode00(fallingEdgeQueue[m]);
          fallingEdgeQueue[m] = 0;
          break;
        case 15:
          // Standby mode
          break;
        default:
          Serial.print(F("Invalid mode when releasing keys\t"));
          Serial.print(currentMode);
          Serial.print("\n");
          errorLight();
          break;
      }
    }
  }
}

void timeCycleStart(){
  fullCycleTimer = millis();
}
void timeCycleStop(){
  fullCycleTimer = millis() - fullCycleTimer;
  Serial.print(F("Full "));
  Serial.print(fullCycleTimer);
  Serial.print("\t");
  if((fullCycleTimer > cycleTimeMax) && fullCycleTimer < 3000){
    cycleTimeMax = fullCycleTimer;
  }
  
  Serial.print(F("Max "));
  Serial.print(cycleTimeMax);
  Serial.print("\n\n");
}

int scanKeys() {
  int funRisenEdge = 0;
  int funFallenEdge = 0;
  risingEdgeCounter = 0;
  fallingEdgeCounter = 0;
  risingEdgeOccured = false;
  fallingEdgeOccured = false;
  for (int i = 0; i < keyboardRowCount; i++) {
    digitalWrite(keyboardRowPins[i], LOW);
    for (int k = 0; k < keyboardColumnCount; k++) {
      buttonStates[i][k] = !pcf.digitalRead(k);
      if (buttonStates[i][k] && !previousButtonStates[i][k]) {
        // If the current and previous state indicate a rising edge...
        risingEdgeOccured = true;
        funRisenEdge = ((100 * i) + k) + 101;
        risingEdgeQueue[risingEdgeCounter] = funRisenEdge;
        risingEdgeCounter++;
        if(risingEdgeCounter >= 6){
          // If there are more than six rising edges, someone is mashing the keyboard
          risingEdgeCounter = 0;
          errorLight();
        }
      }
      if (!buttonStates[i][k] && previousButtonStates[i][k]) {
        // If the current and previous state indicate a falling edge...
        fallingEdgeOccured = true;
        funFallenEdge = ((100 * i) + k) + 101;
        fallingEdgeQueue[fallingEdgeCounter] = funFallenEdge;
        fallingEdgeCounter++;
        if(fallingEdgeCounter >= 6){
          // If there are more than six falling edges, someone has mashed the keyboard
          fallingEdgeCounter = 0;
        }
      }
      previousButtonStates[i][k] = buttonStates[i][k];
    }
    digitalWrite(keyboardRowPins[i], HIGH);
  }
}


int scanMode(){
  float funRunningTotal = 0;
  for(int i=0;i<4;i++){
    if(!digitalRead(modeButtons[i])){
      funRunningTotal += pow(2, i);
    }
  }
  int funRunningInteger = round(funRunningTotal);
  return funRunningInteger;
}
