void startupLightShow(int activeLED) {
  if (activeLED == 0) {
    pixels.setPixelColor(activeLED, pixels.Color(0, maxBrightness, 0));
  } else {
    pixels.setPixelColor(activeLED, pixels.Color(0, 0, maxBrightness));
  }
  pixels.show();
  if (activeLED == 0) {
    delay(400);
  }
  delay(100);
  if (activeLED == 0) {
    pixels.clear();
    pixels.show();
  }
}

void errorLight(){
  for(int i=1; i<addressableLEDs+1; i++){
    pixels.setPixelColor(i, pixels.Color(maxBrightness, 0, 0));
    pixels.show();
  }
}

void lightCircle(){
  if(millis() % 400 <= 10){
    delay(10);
    for(int i=1;i<7;i++){
      int randomColor = random(0, 767);
      colorWheel(i, randomColor);
    }
    pixels.show();
    Serial.print(F("Standby mode\n"));
  }
}

int colorWheel(int funAddress, int funColor){
  int funRed = 0;
  int funGrn = 0;
  int funBlu = 0;
  int funOffset = 0;
  
  if(funColor <= 255){
    funOffset = funColor - 0;
    funRed = 255 - funOffset;
    funGrn = funOffset;
    funBlu = 0;
  }else if(funColor <= 511){
    funOffset = funColor - 256;
    funRed = 0;
    funGrn = 255 - funOffset;
    funBlu = funOffset;
  }else if(funColor <= 767){
    funOffset = funColor - 512;
    funRed = funOffset;
    funGrn = 0;
    funBlu = 255 - funOffset;
  }else{
    funRed = 10;
    funGrn = 10;
    funBlu = 10;
  }
  pixels.setPixelColor(funAddress, pixels.Color(funRed, funGrn, funBlu));
}
