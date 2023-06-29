//void pressMode09(int funPosition){
//  switch (funPosition){
//    case 101:
//      assignKeyReport(HID_KEY_ARROW_RIGHT);
//      break;
//    case 102:
//      assignKeyReport(HID_KEY_ARROW_DOWN);
//      break;
//    case 103:
//      assignKeyReport(HID_KEY_ARROW_LEFT);
//      break;
//    case 104:
//      assignKeyReport(HID_KEY_DELETE);
//      break;
//    case 105:
//      // Control
//      keyReport.modifier = keyReport.modifier + 0x10;
//      break;
//    case 106:
//      // Shortcut (Shift + F10)
//      keyReport.modifier = keyReport.modifier + 0x20;
//      assignKeyReport(HID_KEY_F10);
//      break;
//    case 107:
//      // Alt
//      keyReport.modifier = keyReport.modifier + 0x40;
//      break;
//    case 108:
//      assignKeyReport(HID_KEY_SPACE);
//      break;
//    case 109:
//      assignKeyReport(HID_KEY_SPACE);
//      break;
//    case 110:
//      // Alt
//      keyReport.modifier = keyReport.modifier + 0x04;
//      break;
//    case 111:
//      // GUI
//      keyReport.modifier = keyReport.modifier + 0x08;
//      break;
//    case 112:
//      // Control
//      keyReport.modifier = keyReport.modifier + 0x01;
//      break;
//    case 113:
//      // Control
//      keyReport.modifier = keyReport.modifier + 0x01;
//      break;
//    case 114:
//      // Control
//      keyReport.modifier = keyReport.modifier + 0x01;
//      break;
//    case 115:
//      // Control
//      keyReport.modifier = keyReport.modifier + 0x01;
//      break;
//    case 201:
//      
//      break;
//    case 202:
//      assignKeyReport(HID_KEY_ARROW_UP);
//      break;
//    case 203:
//      // Shift
//      keyReport.modifier = keyReport.modifier + 0x20;
//      break;
//    case 204:
//      assignKeyReport(HID_KEY_SLASH);
//      break;
//    case 205:
//      assignKeyReport(HID_KEY_PERIOD);
//      break;
//    case 206:
//      assignKeyReport(HID_KEY_COMMA);
//      break;
//    case 207:
//      assignKeyReport(HID_KEY_M);
//      break;
//    case 208:
//      assignKeyReport(HID_KEY_N);
//      break;
//    case 209:
//      assignKeyReport(HID_KEY_B);
//      break;
//    case 210:
//      assignKeyReport(HID_KEY_V);
//      break;
//    case 211:
//      assignKeyReport(HID_KEY_C);
//      break;
//    case 212:
//      assignKeyReport(HID_KEY_X);
//      break;
//    case 213:
//      assignKeyReport(HID_KEY_Z);
//      break;
//    case 214:
//      // Shift
//      keyReport.modifier = keyReport.modifier + 0x02;
//      break;
//    case 215:
//      // F13 for triggering macros
//      assignKeyReport(HID_KEY_F13);
//      assignKeyReport(0x7F);
//      break;
//    case 301:
//      assignKeyReport(HID_KEY_RETURN);
//      break;
//    case 302:
//      assignKeyReport(HID_KEY_RETURN);
//      break;
//    case 303:
//      assignKeyReport(HID_KEY_APOSTROPHE);
//      break;
//    case 304:
//      assignKeyReport(HID_KEY_SEMICOLON);
//      break;
//    case 305:
//      assignKeyReport(HID_KEY_L);
//      break;
//    case 306:
//      assignKeyReport(HID_KEY_K);
//      break;
//    case 307:
//      assignKeyReport(HID_KEY_J);
//      break;
//    case 308:
//      assignKeyReport(HID_KEY_H);
//      break;
//    case 309:
//      assignKeyReport(HID_KEY_G);
//      break;
//    case 310:
//      assignKeyReport(HID_KEY_F);
//      break;
//    case 311:
//      assignKeyReport(HID_KEY_D);
//      break;
//    case 312:
//      assignKeyReport(HID_KEY_S);
//      break;
//    case 313:
//      assignKeyReport(HID_KEY_A);
//      break;
//    case 314:
//      assignKeyReport(HID_KEY_CAPS_LOCK);
//      break;
//    case 315:
//      // F14 for triggering macros
//      assignKeyReport(HID_KEY_F14);
//      assignKeyReport(0x81);
//      break;
//    case 401:
//      assignKeyReport(HID_KEY_BACKSLASH);
//      break;
//    case 402:
//      assignKeyReport(HID_KEY_BRACKET_RIGHT);
//      break;
//    case 403:
//      assignKeyReport(HID_KEY_BRACKET_LEFT);
//      break;
//    case 404:
//      assignKeyReport(HID_KEY_P);
//      break;
//    case 405:
//      assignKeyReport(HID_KEY_O);
//      break;
//    case 406:
//      assignKeyReport(HID_KEY_I);
//      break;
//    case 407:
//      assignKeyReport(HID_KEY_U);
//      break;
//    case 408:
//      assignKeyReport(HID_KEY_Y);
//      break;
//    case 409:
//      assignKeyReport(HID_KEY_T);
//      break;
//    case 410:
//      assignKeyReport(HID_KEY_R);
//      break;
//    case 411:
//      assignKeyReport(HID_KEY_E);
//      break;
//    case 412:
//      assignKeyReport(HID_KEY_W);
//      break;
//    case 413:
//      assignKeyReport(HID_KEY_Q);
//      break;
//    case 414:
//      assignKeyReport(HID_KEY_TAB);
//      break;
//    case 415:
//      // F15 for triggering macros
//      assignKeyReport(HID_KEY_F15);
//      assignKeyReport(0x80);
//      break;
//    case 501:
//      assignKeyReport(HID_KEY_BACKSPACE);
//      break;
//    case 502:
//      assignKeyReport(HID_KEY_EQUAL);
//      break;
//    case 503:
//      assignKeyReport(HID_KEY_MINUS);
//      break;
//    case 504:
//      assignKeyReport(HID_KEY_0);
//      break;
//    case 505:
//      assignKeyReport(HID_KEY_9);
//      break;
//    case 506:
//      assignKeyReport(HID_KEY_8);
//      break;
//    case 507:
//      assignKeyReport(HID_KEY_7);
//      break;
//    case 508:
//      assignKeyReport(HID_KEY_6);
//      break;
//    case 509:
//      assignKeyReport(HID_KEY_5);
//      break;
//    case 510:
//      assignKeyReport(HID_KEY_4);
//      break;
//    case 511:
//      assignKeyReport(HID_KEY_3);
//      break;
//    case 512:
//      assignKeyReport(HID_KEY_2);
//      break;
//    case 513:
//      assignKeyReport(HID_KEY_1);
//      break;
//    case 514:
//      assignKeyReport(HID_KEY_GRAVE);
//      break;
//    case 515:
//      assignKeyReport(HID_KEY_ESCAPE);
//      actOnHighButtonStates();
//      break;
//    default:
//      Serial.print(F("Mode 00 key press\n"));
//      errorLight();
//      break;
//  }
//}
//
//// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
//// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
//// 2 // 4 //  // E // n // g // i // n // e // e // r   ~~~~~~~   // 2 // 4 //  // E // n // g // i // n // e // e // r 
//
//void releaseMode09(int funPosition){
//  switch (funPosition){
//    case 101:
//      releaseKey(HID_KEY_ARROW_RIGHT);
//      break;
//    case 102:
//      releaseKey(HID_KEY_ARROW_DOWN);
//      break;
//    case 103:
//      releaseKey(HID_KEY_ARROW_LEFT);
//      break;
//    case 104:
//      releaseKey(HID_KEY_DELETE);
//      break;
//    case 105:
//      keyReport.modifier = keyReport.modifier - 0x10;
//      break;
//    case 106:
//      keyReport.modifier = keyReport.modifier - 0x20;
//      releasePosition(0);
//      break;
//    case 107:
//      keyReport.modifier = keyReport.modifier - 0x40;
//      break;
//    case 108:
//      releaseKey(HID_KEY_SPACE);
//      break;
//    case 109:
//      releaseKey(HID_KEY_SPACE);
//      break;
//    case 110:
//      keyReport.modifier = keyReport.modifier - 0x04;
//      break;
//    case 111:
//      keyReport.modifier = keyReport.modifier - 0x08;
//      break;
//    case 112:
//      keyReport.modifier = keyReport.modifier - 0x01;
//      break;
//    case 113:
//      keyReport.modifier = keyReport.modifier - 0x01;
//      break;
//    case 114:
//      keyReport.modifier = keyReport.modifier - 0x01;
//      break;
//    case 115:
//      keyReport.modifier = keyReport.modifier - 0x01;
//      break;
//    case 201:
//      
//      break;
//    case 202:
//      releaseKey(HID_KEY_ARROW_UP);
//      break;
//    case 203:
//      keyReport.modifier = keyReport.modifier - 0x20;
//      break;
//    case 204:
//      releaseKey(HID_KEY_SLASH);
//      break;
//    case 205:
//      releaseKey(HID_KEY_PERIOD);
//      break;
//    case 206:
//      releaseKey(HID_KEY_COMMA);
//      break;
//    case 207:
//      releaseKey(HID_KEY_M);
//      break;
//    case 208:
//      releaseKey(HID_KEY_N);
//      break;
//    case 209:
//      releaseKey(HID_KEY_B);
//      break;
//    case 210:
//      releaseKey(HID_KEY_V);
//      break;
//    case 211:
//      releaseKey(HID_KEY_C);
//      break;
//    case 212:
//      releaseKey(HID_KEY_X);
//      break;
//    case 213:
//      releaseKey(HID_KEY_Z);
//      break;
//    case 214:
//      keyReport.modifier = keyReport.modifier - 0x02;
//      break;
//    case 215:
//      // F13 for triggering macros
//      releaseKey(HID_KEY_F13);
//      releaseKey(0x7F);
//      break;
//    case 301:
//      releaseKey(HID_KEY_RETURN);
//      break;
//    case 302:
//      releaseKey(HID_KEY_RETURN);
//      break;
//    case 303:
//      releaseKey(HID_KEY_APOSTROPHE);
//      break;
//    case 304:
//      releaseKey(HID_KEY_SEMICOLON);
//      break;
//    case 305:
//      releaseKey(HID_KEY_L);
//      break;
//    case 306:
//      releaseKey(HID_KEY_K);
//      break;
//    case 307:
//      releaseKey(HID_KEY_J);
//      break;
//    case 308:
//      releaseKey(HID_KEY_H);
//      break;
//    case 309:
//      releaseKey(HID_KEY_G);
//      break;
//    case 310:
//      releaseKey(HID_KEY_F);
//      break;
//    case 311:
//      releaseKey(HID_KEY_D);
//      break;
//    case 312:
//      releaseKey(HID_KEY_S);
//      break;
//    case 313:
//      releaseKey(HID_KEY_A);
//      break;
//    case 314:
//      releaseKey(HID_KEY_CAPS_LOCK);
//      break;
//    case 315:
//      // F14 for triggering macros
//      releaseKey(HID_KEY_F14);
//      releaseKey(0x81);
//      break;
//    case 401:
//      releaseKey(HID_KEY_BACKSLASH);
//      break;
//    case 402:
//      releaseKey(HID_KEY_BRACKET_RIGHT);
//      break;
//    case 403:
//      releaseKey(HID_KEY_BRACKET_LEFT);
//      break;
//    case 404:
//      releaseKey(HID_KEY_P);
//      break;
//    case 405:
//      releaseKey(HID_KEY_O);
//      break;
//    case 406:
//      releaseKey(HID_KEY_I);
//      break;
//    case 407:
//      releaseKey(HID_KEY_U);
//      break;
//    case 408:
//      releaseKey(HID_KEY_Y);
//      break;
//    case 409:
//      releaseKey(HID_KEY_T);
//      break;
//    case 410:
//      releaseKey(HID_KEY_R);
//      break;
//    case 411:
//      releaseKey(HID_KEY_E);
//      break;
//    case 412:
//      releaseKey(HID_KEY_W);
//      break;
//    case 413:
//      releaseKey(HID_KEY_Q);
//      break;
//    case 414:
//      releaseKey(HID_KEY_TAB);
//      break;
//    case 415:
//      // F15 for triggering macros
//      releaseKey(HID_KEY_F15);
//      releaseKey(0x80);
//      break;
//    case 501:
//      releaseKey(HID_KEY_BACKSPACE);
//      break;
//    case 502:
//      releaseKey(HID_KEY_EQUAL);
//      break;
//    case 503:
//      releaseKey(HID_KEY_MINUS);
//      break;
//    case 504:
//      releaseKey(HID_KEY_0);
//      break;
//    case 505:
//      releaseKey(HID_KEY_9);
//      break;
//    case 506:
//      releaseKey(HID_KEY_8);
//      break;
//    case 507:
//      releaseKey(HID_KEY_7);
//      break;
//    case 508:
//      releaseKey(HID_KEY_6);
//      break;
//    case 509:
//      releaseKey(HID_KEY_5);
//      break;
//    case 510:
//      releaseKey(HID_KEY_4);
//      break;
//    case 511:
//      releaseKey(HID_KEY_3);
//      break;
//    case 512:
//      releaseKey(HID_KEY_2);
//      break;
//    case 513:
//      releaseKey(HID_KEY_1);
//      break;
//    case 514:
//      releaseKey(HID_KEY_GRAVE);
//      break;
//    case 515:
////      releaseKey(HID_KEY_ESCAPE);
//      releaseAllKeys();
//      actOnHighButtonStates();
//      cycleTimeMax = 0;
//      break;
//    default:
//      releaseAllKeys();
//      break;
//  }
//}
