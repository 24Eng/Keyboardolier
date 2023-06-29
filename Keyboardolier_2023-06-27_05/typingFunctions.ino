
void sendKeystroke(){
  ble.atcommand("AT+BLEKEYBOARDCODE", (uint8_t*) &keyReport, 8);
//  actOnHighButtonStates();
}

void assignKeyReport(int funNewKey){
  for(int i=0;i<6;i++){
    if(keyReport.keycode[i] == 0){
      keyReport.keycode[i] = funNewKey;
      return;
    }
  }
  Serial.print(F("Could not assign key report\n"));
  errorLight();
}

void sendTypedMessage() {
  if (risingEdgeOccured || fallingEdgeOccured) {
    sendKeystroke();
  }
}

void releaseAllKeys(){
  for(int i;i<6;i++){
    keyReport.keycode[i] = HID_KEY_NONE;
  }
  keyReport.modifier = HID_KEY_NONE;
//  sendKeystroke();
}

void releasePosition(int funPosition){
  keyReport.keycode[funPosition] = HID_KEY_NONE;
}

void releaseKey(int funReleasedKey){
  for(int i=0;i<6;i++){
    if(keyReport.keycode[i] == funReleasedKey){
      keyReport.keycode[i] = 0x00;
    }
  }
}

void pressEnterKey(){
  assignKeyReport(HID_KEY_RETURN);
  sendKeystroke();
  releaseKey(HID_KEY_RETURN);
  sendKeystroke();
}

/*
  ble.print("AT+BleKeyboard=");
  ble.println(keys);

  if( ble.waitForOK() ){
    Serial.println( F("OK!") );
  }else{
    Serial.println( F("FAILED!") );
  }
*/
