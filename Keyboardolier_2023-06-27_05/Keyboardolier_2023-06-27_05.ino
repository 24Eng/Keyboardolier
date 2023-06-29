/*
  Includes Adafruit's "Adafruit_PCF8575," BluefruitLE nRF51, and "NeoPixle" libraries. Please support Adafruit by buying their merch.

  This project was designed on a "Feather 32u4 Bluefruit LE" board
  https://www.adafruit.com/product/2829

  Keyboardolier by Brian McEvoy
  24 Hour Engineer
  https://www.24hourengineer.com/
*/

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "BluefruitConfig.h"
#include "keycode.h"

#define FACTORYRESET_ENABLE         0
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
// Create the bluefruit object
// ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

typedef struct {
  uint8_t modifier;   /**< Keyboard modifier keys  */
  uint8_t reserved;   /**< Reserved for OEM use, always set to 0. */
  uint8_t keycode[6]; /**< Key codes of the currently pressed keys. */
} hid_keyboard_report_t;

// Report that send to Central every scanning period
hid_keyboard_report_t keyReport = { 0, 0, { 0 } };

// Report sent previously. This is used to prevent sending the same report over time.
// Notes: HID Central intepretes no new report as no changes, which is the same as
// sending very same report multiple times. This will help to reduce traffic especially
// when most of the time there is no keys pressed.
// - Init to different with keyReport
hid_keyboard_report_t previousReport = { 0, 0, { 1 } };


#include <Adafruit_PCF8575.h>
Adafruit_PCF8575 pcf;

#include <Adafruit_NeoPixel.h>

#include "Keyboard.h"

// Declare the pins
const int addressableLEDs = 6;
const int keyboardRowCount = 5;
const int keyboardRowPins[keyboardRowCount] = {9, 10, 11, 12, 13};
const int keyboardColumnCount = 15;
const int modeButtons[] = {A0, A1, A2, A3};

Adafruit_NeoPixel pixels(7, addressableLEDs, NEO_GRB + NEO_KHZ800);

// Delcare some variables
int maxBrightness = 10;
//bool risingEdges[keyboardRowCount][keyboardColumnCount];
//bool fallingEdges[keyboardRowCount][keyboardColumnCount];
bool buttonStates[keyboardRowCount][keyboardColumnCount];
bool previousButtonStates[keyboardRowCount][keyboardColumnCount];
int risingEdgeQueue[6];
int fallingEdgeQueue[6];
int risingEdgeCounter = 0;
int fallingEdgeCounter = 0;
bool risingEdgeOccured = false;
bool fallingEdgeOccured = false;

long fullCycleTimer = 0;
int cycleTimeMax = 0;
int currentMode = 0;


void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip
  pixels.clear(); // Set all pixel colors to 'off'
  startupLightShow(1);

  if ( !ble.begin(VERBOSE_MODE) ) {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  if ( FACTORYRESET_ENABLE ) {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ) {
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println(F("Requesting Bluefruit info:"));
  /* Print Bluefruit information */
  ble.info();

  /* Change the device name to make it easier to find */
  Serial.println(F("Setting device name to '24Eng Keyboard': "));
  if (! ble.sendCommandCheckOK(F( "AT+GAPDEVNAME=24Eng Keyboard" )) ) {
    error(F("Could not set device name?"));
  }

  /* Enable HID Service */
  Serial.println(F("Enable HID Service (including Keyboard): "));
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION)) {
    if ( !ble.sendCommandCheckOK(F( "AT+BleHIDEn=On" ))) {
      error(F("Could not enable Keyboard"));
    }
  } else {
    if (! ble.sendCommandCheckOK(F( "AT+BleKeyboardEn=On"))) {
      error(F("Could not enable Keyboard"));
    }
  }

  /* Add or remove service requires a reset */
  Serial.println(F("Performing a SW reset (service changes require a reset): "));
  if (! ble.reset() ) {
    error(F("Couldn't reset??"));
  }
  startupLightShow(2);

  //  while (!Serial) { delay(10); }
  Serial.begin(115200);
  //  Serial.println(F("24Eng Keyboardolier"));
  startupLightShow(3);

  if (!pcf.begin(0x20, &Wire)) {
    Serial.println(F("Couldn't find PCF8575"));
    while (1);
  }

  startupLightShow(4);

  // Set all the IO expander's pins to inputs and activate their built-in pullup resistors
  for (uint8_t p = 0; p < 16; p++) {
    pcf.pinMode(p, INPUT_PULLUP);
  }

  for(int i=0;i<4;i++){
    pinMode(modeButtons[i], INPUT_PULLUP);
  }

  for (int i = 0; i < keyboardRowCount; i++) {
    pinMode(keyboardRowPins[i], OUTPUT);
    digitalWrite(keyboardRowPins[i], HIGH);
  }

  startupLightShow(5);
  startupLightShow(6);
  startupLightShow(0);
}

void loop() {
  currentMode = scanMode();
//  if(currentMode != 15){
    scanKeys();
    if(fallingEdgeOccured && (currentMode != 8)){
      actOnFallingEdges();
    }
    if(risingEdgeOccured){
      actOnRisingEdges();
    }
    if((fallingEdgeOccured || risingEdgeOccured)){
      sendTypedMessage();
    }
    
//    if(currentMode != 8){
//      actOnFallingEdges();
//    }
//    sendTypedMessage();
//  }else{
//    lightCircle();
//  }
  
}
