// We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 ***** Please set the number of devices you have *****
 But the maximum default of 8 MAX72XX wil also work.
*/

LedControl lc = LedControl(7, 6, 5, 8);

/* we always wait a bit between updates of the display */
// unsigned long delaytime = 500;

/*
 This time we have more than one device. 
 But all of them have to be initialized 
 individually.
*/

// we have already set the number of devices when we created the LedControl
int devices = lc.getDeviceCount();

void zero(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 6, true);
  lc.setLed(address, 4, 1, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 6, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void one(int address) {
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 1, 3, true);
  lc.setLed(address, 1, 4, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 3, true);
  lc.setLed(address, 2, 4, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 5, 3, true);
  lc.setLed(address, 5, 4, true);
  lc.setLed(address, 6, 3, true);
  lc.setLed(address, 6, 4, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void two(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 7, 1, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
  lc.setLed(address, 7, 6, true);
}
void three(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void four(int address) {
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 4, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 2, 3, true);
  lc.setLed(address, 2, 4, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 4, 1, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 5, 3, true);
  lc.setLed(address, 5, 4, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 7, 5, true);
}
void five(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 0, 6, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 4, 6, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void six(int address) {
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 3, true);
  lc.setLed(address, 1, 4, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 3, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 4, 1, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void seven(int address) {
  lc.setLed(address, 0, 1, true);
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 3, 6, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 4, 6, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 4, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void eight(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
  lc.setLed(address, 7, 4, true);
  lc.setLed(address, 7, 5, true);
}
void nine(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 0, 3, true);
  lc.setLed(address, 0, 4, true);
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 3, 6, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 4, 6, true);
  lc.setLed(address, 5, 4, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 6, 3, true);
  lc.setLed(address, 6, 4, true);
  lc.setLed(address, 7, 2, true);
  lc.setLed(address, 7, 3, true);
}

void setup() {
  // we have to init all devices in a loop
  for(int address=0; address<devices; address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address, 8);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

void loop() {
  six(0);
  nine(1);
  seven(2);
  eight(3);
}

