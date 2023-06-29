void pressMode03(int funPosition){
  actOnHighButtonStates();
  switch (funPosition){
    case 101:
      assignKeyReport(HID_KEY_ARROW_RIGHT);
      break;
    case 102:
      assignKeyReport(HID_KEY_ARROW_DOWN);
      break;
    case 103:
      assignKeyReport(HID_KEY_ARROW_LEFT);
      break;
    case 104:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 105:
      // Control
      bitWrite(keyReport.modifier, 4, 1);
      break;
    case 106:
      // Shortcut (Shift + F10)
      bitWrite(keyReport.modifier, 5, 1);
      assignKeyReport(HID_KEY_F10);
      break;
    case 107:
      // Alt
      bitWrite(keyReport.modifier, 6, 1);
      break;
    case 108:
      assignKeyReport(HID_KEY_SPACE);
      break;
    case 201:
      // Control + tab
      bitWrite(keyReport.modifier, 4, 1);
      assignKeyReport(HID_KEY_TAB);
      break;
    case 202:
      assignKeyReport(HID_KEY_ARROW_UP);
      break;
    case 203:
      // Control + tab + shift
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      assignKeyReport(HID_KEY_TAB);
      break;
    case 204:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 205:
      // Windows + R = command prompt
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_R);
      break;
    case 206:
      // Windows + D = show desktop
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_D);
      break;
    case 207:
      ble.print("AT+BleHidControlKey=calculator\n");
      break;
    case 208:
      // Windows + R = command prompt
      // type "calc" then [enter]
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_R);
      break;
    case 301:
      // Control + V = paste
      bitWrite(keyReport.modifier, 4, 1);
      assignKeyReport(HID_KEY_V);
      break;
    case 302:
      // Control + C = copy
      bitWrite(keyReport.modifier, 4, 1);
      assignKeyReport(HID_KEY_C);
      break;
    case 303:
      // Control + x = cut
      bitWrite(keyReport.modifier, 4, 1);
      assignKeyReport(HID_KEY_X);
      break;
    case 304:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 305:
      // Control + alt + shift + 0 = AutoHotkey macro
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_0);
      break;
    case 306:
      // Control + alt + shift 9 = AutoHotkey macro
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_9);
      break;
    case 307:
      // Control + tab
      bitWrite(keyReport.modifier, 4, 1);
      assignKeyReport(HID_KEY_TAB);
      break;
    case 308:
      // Control + tab + shift
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      assignKeyReport(HID_KEY_TAB);
      break;
    case 401:
      // Windows + R = command prompt
      // type "calc" then [enter]
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_R);
      break;
    case 402:
      // Windows + R = command prompt
      // type "calc" then [enter]
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_R);
      break;
    case 403:
      // Windows + R = command prompt
      // type "calc" then [enter]
      bitWrite(keyReport.modifier, 7, 1);
      assignKeyReport(HID_KEY_R);
      break;
    case 404:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 405:
      // Control + alt + shift 5 = AutoHotkey macro
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_5);
      break;
    case 406:
      // Control + alt + shift 4 = AutoHotkey macro
      bitWrite(keyReport.modifier, 4, 1);
      bitWrite(keyReport.modifier, 5, 1);
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_4);
      break;
    case 407:
      // Alt + D = select address bar
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_D);
      break;
    case 408:
      // Alt + escape = scroll through windows
      bitWrite(keyReport.modifier, 6, 1);
      assignKeyReport(HID_KEY_ESCAPE);
      break;
    case 501:
      assignKeyReport(HID_KEY_BACKSPACE);
      break;
    case 502:
      assignKeyReport(HID_KEY_F12);
      break;
    case 503:
      assignKeyReport(HID_KEY_F11);
      break;
    case 504:
      assignKeyReport(HID_KEY_F10);
      break;
    case 505:
      assignKeyReport(HID_KEY_F9);
      break;
    case 506:
      assignKeyReport(HID_KEY_F8);
      break;
    case 507:
      assignKeyReport(HID_KEY_F7);
      break;
    case 508:
      assignKeyReport(HID_KEY_F6);
      break;
    case 509:
      assignKeyReport(HID_KEY_F5);
      break;
    case 510:
      assignKeyReport(HID_KEY_F4);
      break;
    case 511:
      assignKeyReport(HID_KEY_F3);
      break;
    case 512:
      assignKeyReport(HID_KEY_F2);
      break;
    case 513:
      assignKeyReport(HID_KEY_F1);
      break;
    default:
      pressMode00(funPosition);
      break;
  }
}

// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 

void releaseMode03(int funPosition){
  actOnHighButtonStates();
  switch (funPosition){
    case 101:
      releaseKey(HID_KEY_ARROW_RIGHT);
      break;
    case 102:
      releaseKey(HID_KEY_ARROW_DOWN);
      break;
    case 103:
      releaseKey(HID_KEY_ARROW_LEFT);
      break;
    case 104:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 105:
      bitWrite(keyReport.modifier, 4, 0); // Control release
      break;
    case 106:
      bitWrite(keyReport.modifier, 5, 0); // Shift release
      releaseKey(HID_KEY_F10);
      break;
    case 107:
      bitWrite(keyReport.modifier, 6, 0); // Alt release
      break;
    case 108:
      releaseKey(HID_KEY_SPACE);
      break;
    case 201:
      bitWrite(keyReport.modifier, 4, 0); // Control release
      releaseKey(HID_KEY_TAB);
      break;
    case 202:
      releaseKey(HID_KEY_ARROW_UP);
      break;
    case 203:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_TAB);
      break;
    case 204:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 205:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_R);
      break;
    case 206:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_D);
      break;
    case 207:
      break;
    case 208:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_R);
      sendKeystroke();
      delay(500);
      ble.print(F("AT+BleKeyboard=notepad.exe\n"));
      pressEnterKey();
      break;
    case 301:
      bitWrite(keyReport.modifier, 4, 0); // Control release
      releaseKey(HID_KEY_V);
      break;
    case 302:
      if(keyReport.modifier >= 0x10){
        keyReport.modifier = keyReport.modifier - 0x10;
      }else{
        keyReport.modifier = 0;
      }
      releaseKey(HID_KEY_C);
      break;
    case 303:
      bitWrite(keyReport.modifier, 4, 0); // Control release
      releaseKey(HID_KEY_X);
      break;
    case 304:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 305:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_0);
      break;
    case 306:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_9);
      break;
    case 307:
      bitWrite(keyReport.modifier, 4, 0); // Control release
      releaseKey(HID_KEY_TAB);
      break;
    case 308:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_TAB);
      break;
    case 401:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_R);
      sendKeystroke();
      delay(500);
      ble.print(F("AT+BleKeyboard=https://www.youtube.com/\n"));
      delay(200);
      ble.print(F("AT+BleKeyboard=watch?v=rUxyKA_\n"));
      delay(200);
      ble.print(F("AT+BleKeyboard=-grg\n"));
      pressEnterKey();
      break;
    case 402:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_R);
      sendKeystroke();
      delay(500);
      ble.print(F("AT+BleKeyboard=https://www.youtube.com/\n"));
      delay(200);
      ble.print(F("AT+BleKeyboard=watch?v=MVPTGNGi\n"));
      delay(200);
      ble.print(F("AT+BleKeyboard=I\n"));
      ble.print(F("AT+BleKeyboard=-4\n"));
      pressEnterKey();
      break;
    case 403:
      bitWrite(keyReport.modifier, 7, 0); // GUI release
      releaseKey(HID_KEY_R);
      sendKeystroke();
      delay(500);
      ble.print(F("AT+BleKeyboard=https://www.youtube.com/\n"));
      delay(200);
      ble.print(F("AT+BleKeyboard=watch?v=jfKfPfyJRdk\n"));
      pressEnterKey();
      break;
    case 404:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 405:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_5);
      break;
    case 406:
      keyReport.modifier = 0x00;
      releaseKey(HID_KEY_4);
      break;
    case 407:
      bitWrite(keyReport.modifier, 6, 0); // Alt release
      releaseKey(HID_KEY_D);
      break;
    case 408:
      bitWrite(keyReport.modifier, 6, 0); // Alt release
      releaseKey(HID_KEY_ESCAPE);
      break;
    case 501:
      releaseKey(HID_KEY_BACKSPACE);
      break;
    case 502:
      releaseKey(HID_KEY_F12);
      break;
    case 503:
      releaseKey(HID_KEY_F11);
      break;
    case 504:
      releaseKey(HID_KEY_F10);
      break;
    case 505:
      releaseKey(HID_KEY_F9);
      break;
    case 506:
      releaseKey(HID_KEY_F8);
      break;
    case 507:
      releaseKey(HID_KEY_F7);
      break;
    case 508:
      releaseKey(HID_KEY_F6);
      break;
    case 509:
      releaseKey(HID_KEY_F5);
      break;
    case 510:
      releaseKey(HID_KEY_F4);
      break;
    case 511:
      releaseKey(HID_KEY_F3);
      break;
    case 512:
      releaseKey(HID_KEY_F2);
      break;
    case 513:
      releaseKey(HID_KEY_F1);
      break;
    default:
      releaseMode00(funPosition);
      break;
  }
}
