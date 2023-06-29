void pressMode01(int funPosition){
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
      assignKeyReport(HID_KEY_KEYPAD_ENTER);
      break;
    case 106:
      assignKeyReport(HID_KEY_KEYPAD_DECIMAL);
      break;
    case 107:
      assignKeyReport(HID_KEY_KEYPAD_0);
      break;
    case 108:
      assignKeyReport(HID_KEY_KEYPAD_0);
      break;
    case 201:
      // Control
      bitWrite(keyReport.modifier, 4, 1);
      break;
    case 202:
      assignKeyReport(HID_KEY_ARROW_UP);
      break;
    case 203:
      // Shift
      bitWrite(keyReport.modifier, 5, 1);
      break;
    case 204:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 205:
      assignKeyReport(HID_KEY_KEYPAD_ENTER);
      break;
    case 206:
      assignKeyReport(HID_KEY_KEYPAD_3);
      break;
    case 207:
      assignKeyReport(HID_KEY_KEYPAD_2);
      break;
    case 208:
      assignKeyReport(HID_KEY_KEYPAD_1);
      break;
    case 301:
      assignKeyReport(HID_KEY_PAGE_DOWN);
      break;
    case 302:
      assignKeyReport(HID_KEY_END);
      break;
    case 303:
      assignKeyReport(HID_KEY_DELETE);
      break;
    case 304:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 305:
      assignKeyReport(HID_KEY_KEYPAD_ADD);
      break;
    case 306:
      assignKeyReport(HID_KEY_KEYPAD_6);
      break;
    case 307:
      assignKeyReport(HID_KEY_KEYPAD_5);
      break;
    case 308:
      assignKeyReport(HID_KEY_KEYPAD_4);
      break;
    case 401:
      assignKeyReport(HID_KEY_PAGE_UP);
      break;
    case 402:
      assignKeyReport(HID_KEY_HOME);
      break;
    case 403:
      assignKeyReport(HID_KEY_INSERT);
      break;
    case 404:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 405:
      assignKeyReport(HID_KEY_KEYPAD_ADD);
      break;
    case 406:
      assignKeyReport(HID_KEY_KEYPAD_9);
      break;
    case 407:
      assignKeyReport(HID_KEY_KEYPAD_8);
      break;
    case 408:
      assignKeyReport(HID_KEY_KEYPAD_7);
      break;
    case 501:
      assignKeyReport(HID_KEY_PAUSE);
      break;
    case 502:
      assignKeyReport(HID_KEY_SCROLL_LOCK);
      break;
    case 503:
      assignKeyReport(HID_KEY_PRINT_SCREEN);
      break;
    case 504:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 505:
      assignKeyReport(HID_KEY_KEYPAD_SUBTRACT);
      break;
    case 506:
      assignKeyReport(HID_KEY_KEYPAD_MULTIPLY);
      break;
    case 507:
      assignKeyReport(HID_KEY_KEYPAD_DIVIDE);
      break;
    case 508:
      assignKeyReport(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    default:
      pressMode00(funPosition);
      break;
  }
}

// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 

void releaseMode01(int funPosition){
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
      releaseKey(HID_KEY_KEYPAD_ENTER);
      break;
    case 106:
      releaseKey(HID_KEY_KEYPAD_DECIMAL);
      break;
    case 107:
      releaseKey(HID_KEY_KEYPAD_0);
      break;
    case 108:
      releaseKey(HID_KEY_KEYPAD_0);
      break;
    case 201:
      // Control
      bitWrite(keyReport.modifier, 4, 0);
      break;
    case 202:
      releaseKey(HID_KEY_ARROW_UP);
      break;
    case 203:
      // Shift
      bitWrite(keyReport.modifier, 5, 0);
      break;
    case 204:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 205:
      releaseKey(HID_KEY_KEYPAD_ENTER);
      break;
    case 206:
      releaseKey(HID_KEY_KEYPAD_3);
      break;
    case 207:
      releaseKey(HID_KEY_KEYPAD_2);
      break;
    case 208:
      releaseKey(HID_KEY_KEYPAD_1);
      break;
    case 301:
      releaseKey(HID_KEY_PAGE_DOWN);
      break;
    case 302:
      releaseKey(HID_KEY_END);
      break;
    case 303:
      releaseKey(HID_KEY_DELETE);
      break;
    case 304:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 305:
      releaseKey(HID_KEY_KEYPAD_ADD);
      break;
    case 306:
      releaseKey(HID_KEY_KEYPAD_6);
      break;
    case 307:
      releaseKey(HID_KEY_KEYPAD_5);
      break;
    case 308:
      releaseKey(HID_KEY_KEYPAD_4);
      break;
    case 401:
      releaseKey(HID_KEY_PAGE_UP);
      break;
    case 402:
      releaseKey(HID_KEY_HOME);
      break;
    case 403:
      releaseKey(HID_KEY_INSERT);
      break;
    case 404:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 405:
      releaseKey(HID_KEY_KEYPAD_ADD);
      break;
    case 406:
      releaseKey(HID_KEY_KEYPAD_9);
      break;
    case 407:
      releaseKey(HID_KEY_KEYPAD_8);
      break;
    case 408:
      releaseKey(HID_KEY_KEYPAD_7);
      break;
    case 501:
      releaseKey(HID_KEY_PAUSE);
      break;
    case 502:
      releaseKey(HID_KEY_SCROLL_LOCK);
      break;
    case 503:
      releaseKey(HID_KEY_PRINT_SCREEN);
      break;
    case 504:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    case 505:
      releaseKey(HID_KEY_KEYPAD_SUBTRACT);
      break;
    case 506:
      releaseKey(HID_KEY_KEYPAD_MULTIPLY);
      break;
    case 507:
      releaseKey(HID_KEY_KEYPAD_DIVIDE);
      break;
    case 508:
      releaseKey(HID_KEY_ESCAPE);
      actOnHighButtonStates();
      break;
    default:
      releaseMode00(funPosition);
      break;
  }
}
