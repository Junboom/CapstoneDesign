#include <string.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "LedControl.h"   // We always have to include the library

SoftwareSerial dbgSerial(3, 4);   // RX, TX -> 3번, 4번 핀
LiquidCrystal_I2C lcd(0x3F, 16, 2);
LedControl lc = LedControl(12, 11, 10, 8);

byte arrow[8] = {
  B00000,
  B00000,
  B01000,
  B01100,
  B01110,
  B01100,
  B01000,
  B00000
};

byte saju1[8] = {
  B00000,
  B00010,
  B00100,
  B01010,
  B10001,
  B10001,
  B00000,
  B00000
};
byte saju2[8] = {
  B01000,
  B01000,
  B01000,
  B01110,
  B01000,
  B01000,
  B01000,
  B00000
};
byte saju3[8] = {
  B11111,
  B01010,
  B10001,
  B00000,
  B11111,
  B00100,
  B00100,
  B00000
};

byte taro1[8] = {
  B00000,
  B01111,
  B01000,
  B01111,
  B01000,
  B01111,
  B00000,
  B00000
};
byte taro2[8] = {
  B01000,
  B01000,
  B01000,
  B01110,
  B01000,
  B01000,
  B01000,
  B00000
};
byte taro3[8] = {
  B11111,
  B00001,
  B11111,
  B10000,
  B11111,
  B00100,
  B11111,
  B00000
};

byte menu1[8] = {
  B00000,
  B01111,
  B01001,
  B01001,
  B01001,
  B01111,
  B00000,
  B00000
};
byte menu2[8] = {
  B00010,
  B01010,
  B01010,
  B11010,
  B01010,
  B01010,
  B00010,
  B00000
};
byte menu3[8] = {
  B01000,
  B01000,
  B01110,
  B00000,
  B11111,
  B01010,
  B01010,
  B00000
};

byte num[8] = {
  B00000,
  B11101,
  B10111,
  B11101,
  B00011,
  B01101,
  B10010,
  B01100
};

void arrowToLeft(int address) {
  lc.setLed(address, 0, 5, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 4, true);
  lc.setLed(address, 1, 5, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 3, true);
  lc.setLed(address, 2, 4, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 2, 7, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 3, 6, true);
  lc.setLed(address, 4, 1, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 5, 1, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 5, 3, true);
  lc.setLed(address, 5, 4, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 3, true);
  lc.setLed(address, 6, 4, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
}
void arrowToRight(int address) {
  lc.setLed(address, 0, 2, true);
  lc.setLed(address, 1, 1, true);
  lc.setLed(address, 1, 2, true);
  lc.setLed(address, 1, 3, true);
  lc.setLed(address, 1, 6, true);
  lc.setLed(address, 2, 0, true);
  lc.setLed(address, 2, 1, true);
  lc.setLed(address, 2, 2, true);
  lc.setLed(address, 2, 3, true);
  lc.setLed(address, 2, 4, true);
  lc.setLed(address, 2, 5, true);
  lc.setLed(address, 2, 6, true);
  lc.setLed(address, 3, 1, true);
  lc.setLed(address, 3, 2, true);
  lc.setLed(address, 3, 3, true);
  lc.setLed(address, 3, 4, true);
  lc.setLed(address, 3, 5, true);
  lc.setLed(address, 3, 6, true);
  lc.setLed(address, 4, 2, true);
  lc.setLed(address, 4, 3, true);
  lc.setLed(address, 4, 4, true);
  lc.setLed(address, 4, 5, true);
  lc.setLed(address, 4, 6, true);
  lc.setLed(address, 5, 2, true);
  lc.setLed(address, 5, 3, true);
  lc.setLed(address, 5, 4, true);
  lc.setLed(address, 5, 5, true);
  lc.setLed(address, 5, 6, true);
  lc.setLed(address, 6, 1, true);
  lc.setLed(address, 6, 2, true);
  lc.setLed(address, 6, 3, true);
  lc.setLed(address, 6, 4, true);
  lc.setLed(address, 6, 5, true);
  lc.setLed(address, 6, 6, true);
}
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

void num_print(int i, int j) {
  if (i == 0)
    zero(j);
  if (i == 1)
    one(j);
  if (i == 2)
    two(j);
  if (i == 3)
    three(j);
  if (i == 4)
    four(j);
  if (i == 5)
    five(j);
  if (i == 6)
    six(j);
  if (i == 7)
    seven(j);
  if (i == 8)
    eight(j);
  if (i == 9)
    nine(j);
}

// #define AP_SSID "baek"
// #define AP_PASS "12345678"

#define AP_SSID "DLive_A279";
#define AP_PASS "D163D2A278";

const char* host       = "13.124.185.67";
const char* streamId   = "woojae";
const char* privateKey = "YBJ11111";

const int interruptPin = 0;

const int ledPin = 8;

const int button1Pin = 5;
const int button2Pin = 6;
const int button3Pin = 7;

int devices = lc.getDeviceCount();

int switch_num = 0;   // 몇 번째 스위치인지
int switch_ctrl = 0;  // 스위치를 눌렀을 때 loop문이 한 번만 작동되도록
int switch_menu = 0;  // 어떤 메뉴인지
int in_menu = 0;      // 메뉴 안에 들어갔는지
int switch_ch = 1;    // 메뉴 안에서 몇 번째를 선택했는지

int saju_now_num = 1;
int saju_last_num = 10;
int saju_wait_num = 0;
int taro_now_num = 1;
int taro_last_num = 10;
int taro_wait_num = 0;

String line = "";

long debouncing_time = 300;   // Debouncing Time in Milliseconds
volatile unsigned long last_micros;
boolean SettingsScreen = true;

void setup(void) {
  // 시리얼 포트 초기화
  Serial.begin(9600);
  Serial.setTimeout(5000);
  dbgSerial.begin(9600);
  delay(10);
  
  Serial.println("ESP8266 connect");

  lcd.init();
  lcd.backlight();
  
  lcd.createChar(0, arrow);
  lcd.createChar(1, saju1);
  lcd.createChar(2, saju2);
  lcd.createChar(3, saju3);
  lcd.createChar(4, taro1);
  lcd.createChar(5, taro2);
  lcd.createChar(6, taro3);
  lcd.createChar(7, num);

  resetMatrix();

  pinMode(ledPin, OUTPUT);
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  attachInterrupt(interruptPin, debounceInterrupt, RISING);
  
  boolean connected = false;
  for(int i=0; i<10; i++) {
    if(connectWiFi()) {
      connected = true;
      break;
    }
  }
  
  // if(!connected)
  //  while(1);

  delay(5000);
  // dbgSerial.println("AT+CIPMUX=0");
}

void loop(void)
{
  if (switch_num == 1) {
    if (switch_ctrl == 0) {
      if (in_menu == 1) {
        choose();
      }
      else if (in_menu == 0) {
        lcd.setCursor(1,1);
        lcd.write(byte(0));
        lcd.setCursor(9,1);
        lcd.print(" ");
        switch_menu = 1;
      }
      switch_ctrl = 1;
    }
  }
  else if (switch_num == 2) {
    if (switch_ctrl == 0) {
      if (in_menu == 1) {
        if (switch_ch == 1) {
          resetMatrix();

          if (switch_menu == 1) {
            saju_wait_num = saju_last_num - saju_now_num;
            if (saju_wait_num > 0) {
              insert_db(1);

              for(int i=4; i<7; i++) {
                lcd.setCursor(i,1);
                lcd.print(" ");
              }
              for(int i=13; i<15; i++) {
                lcd.setCursor(i,1);
                lcd.print(" ");
              }
              lcd.setCursor(4,1);
              lcd.print(String(saju_now_num));
              lcd.setCursor(13,1);
              lcd.print(String(saju_wait_num));
              
              arrowToLeft(3);
              if (String(saju_now_num).length() == 1) {
                zero(2);
                zero(1);
                num_print(saju_now_num, 0);
              }
              else if (String(saju_now_num).length() == 2) {
                zero(2);
                num_print(saju_now_num/10, 1);
                num_print(saju_now_num%10, 0);
              }
              else if (String(saju_now_num).length() == 3) {
                num_print(saju_now_num/100, 2);
                num_print((saju_now_num%100)/10, 1);
                num_print(saju_now_num%10, 0);
              }
              
              saju_now_num++;
            }
          }
          else if(switch_menu == 2) {
            taro_wait_num = taro_last_num - taro_now_num;
            if (taro_wait_num > 0) {
              insert_db(3);

              for(int i=4; i<7; i++) {
                lcd.setCursor(i,1);
                lcd.print(" ");
              }
              for(int i=13; i<15; i++) {
                lcd.setCursor(i,1);
                lcd.print(" ");
              }
              lcd.setCursor(4,1);
              lcd.print(String(taro_now_num));
              lcd.setCursor(13,1);
              lcd.print(String(taro_wait_num));
              
              arrowToRight(0);
              if (String(taro_now_num).length() == 1) {
                zero(3);
                zero(2);
                num_print(taro_now_num, 1);
              }
              else if (String(taro_now_num).length() == 2) {
                zero(3);
                num_print(taro_now_num/10, 2);
                num_print(taro_now_num%10, 1);
              }
              else if (String(taro_now_num).length() == 3) {
                num_print(taro_now_num/100, 3);
                num_print((taro_now_num%100)/10, 2);
                num_print(taro_now_num%10, 1);
              }
              
              taro_now_num++;
            }
          }
        }
        else if (switch_ch == 2) {
          if(switch_menu == 1)
            insert_db(2);
          else if(switch_menu == 2)
            insert_db(4);
        }
        else if (switch_ch == 3) {
          menu_left();
        }
      }
      else if (in_menu == 0) {
        if (switch_menu == 1) {
          menu_saju();
          menu();

          saju_wait_num = saju_last_num - saju_now_num;
          for(int i=4; i<7; i++) {
            lcd.setCursor(i,1);
            lcd.print(" ");
          }
          for(int i=13; i<15; i++) {
            lcd.setCursor(i,1);
            lcd.print(" ");
          }
          lcd.setCursor(4,1);
          lcd.print(String(saju_now_num));
          lcd.setCursor(13,1);
          lcd.print(String(saju_wait_num));
        }
        else if (switch_menu == 2) {
          menu_taro();
          menu();

          taro_wait_num = taro_last_num - taro_now_num;
          for(int i=4; i<7; i++) {
            lcd.setCursor(i,1);
            lcd.print(" ");
          }
          for(int i=13; i<15; i++) {
            lcd.setCursor(i,1);
            lcd.print(" ");
          }
          lcd.setCursor(4,1);
          lcd.print(String(taro_now_num));
          lcd.setCursor(13,1);
          lcd.print(String(taro_wait_num));
        }
      }
      switch_ctrl = 1;
    }
  }
  else if (switch_num == 3) {
    if (switch_ctrl == 0) {
      if (in_menu == 1) {
        choose();
      }
      else if (in_menu == 0) {
        lcd.setCursor(1,1);
        lcd.print(" ");
        lcd.setCursor(9,1);
        lcd.write(byte(0));
        switch_menu = 2;
      }
      switch_ctrl = 1;
    }
  }
  else {
    if (switch_ctrl == 0) {
      menu_left();
      switch_ctrl = 1;
    }
  }
}

boolean connectWiFi() {
  // dbgSerial.println("AT+CWMODE=3");
  
  String cmd = "AT+CWJAP=\"";
  cmd += AP_SSID;
  cmd += "\",\"";
  cmd += AP_PASS;
  cmd += "\"";
  dbgSerial.println(cmd);
  Serial.println(cmd);
  delay(3000);
  
  if(dbgSerial.find("OK")) {
    Serial.println("OK, Connected to WiFi.");
    return true;
  }
  else {
    Serial.println("Cannot connect to the WiFi.");
    return false;
  }
}

void insert_db(int value) {
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += host;
  cmd += "\",80";
  Serial.println(cmd);
  dbgSerial.println(cmd);
  if(dbgSerial.find("Error")) {
    Serial.println("TCP connect error");
    return;
  }

  char test[20];
  String temp = "";
  temp = intToString(test, value);
  
  cmd = "GET /connect/run2.php?num=" + temp + "\r\n" + "Host: " + host + "\r\n";
  dbgSerial.print("AT+CIPSEND=");
  dbgSerial.println(cmd.length());
  
  Serial.println(cmd);
  if(dbgSerial.find(">"))
    Serial.println(">");
  else {
    dbgSerial.println("AT+CIPCLOSE");
    Serial.println("connect timeout");
    delay(1000);
    return;
  }
  
  dbgSerial.print(cmd);
  delay(2000);

  /*
  Serial.find("+IPD");
  while(Serial.available()) {
    char c = Serial.read();
    dbgSerial.write(c);
    if(c == '\r') {
      dbgSerial.print('\n');
    }
  }
  */

  line = "";
  while(dbgSerial.available()) {
    char c = dbgSerial.read();
    line += c;
    if(c == '\r') {
      Serial.println(line);
    }
  }
  
  Serial.println("====");
  delay(1000);
}

void DisplaySettings()
{
  if (digitalRead(button1Pin) == HIGH) {
    switch_num = 1;
    switch_ctrl = 0;
  }
  else if (digitalRead(button2Pin) == HIGH) {
    switch_num = 2;
    switch_ctrl = 0;
  }
  else if (digitalRead(button3Pin) == HIGH) {
    switch_num = 3;
    switch_ctrl = 0;
  }
  
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
}

void debounceInterrupt() {
   if((long)(micros() - last_micros) >= debouncing_time * 1000) {
     DisplaySettings();
     last_micros = micros();
   }
}

void menu_button() {
  lcd.createChar(0, arrow);
  lcd.createChar(1, saju1);
  lcd.createChar(2, saju2);
  lcd.createChar(3, saju3);
  lcd.createChar(4, taro1);
  lcd.createChar(5, taro2);
  lcd.createChar(6, taro3);
}

void menu_saju() {
  lcd.createChar(0, arrow);
  lcd.createChar(1, saju1);
  lcd.createChar(2, saju2);
  lcd.createChar(3, saju3);
  lcd.createChar(4, menu1);
  lcd.createChar(5, menu2);
  lcd.createChar(6, menu3);
  lcd.createChar(7, num);
}

void menu_taro() {
  lcd.createChar(0, arrow);
  lcd.createChar(1, taro1);
  lcd.createChar(2, taro2);
  lcd.createChar(3, taro3);
  lcd.createChar(4, menu1);
  lcd.createChar(5, menu2);
  lcd.createChar(6, menu3);
  lcd.createChar(7, num);
}

void menu_left() {
  lcd.clear();
  menu_button();
  lcd.setCursor(0,0);
  lcd.print("Let's Free Time!");
  lcd.setCursor(1,1);
  lcd.write(byte(0));
  lcd.setCursor(2,1);
  for (int i=1; i<=3; i++) {
    lcd.write(byte(i));
  }
  lcd.setCursor(10,1);
  for (int i=4; i<=6; i++) {
    lcd.write(byte(i));
  }
  in_menu = 0;
  switch_menu = 1;
  resetMatrix();
}

void menu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("[");
  lcd.setCursor(1,0);
  for (int i=1; i<=3; i++) {
    lcd.write(byte(i));
  }
  lcd.setCursor(4,0);
  lcd.print("]");
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(7,0);
  lcd.print("ca");
  lcd.setCursor(10,0);
  lcd.print("st");
  lcd.setCursor(13,0);
  for (int i=4; i<=6; i++) {
    lcd.write(byte(i));
  }
  lcd.setCursor(0,1);
  lcd.print("NUM:");
  
  lcd.setCursor(8,1);
  lcd.print("WAIT:");
  
  lcd.setCursor(15,1);
  lcd.write(byte(7));
  in_menu = 1;
  // switch_menu = 1;
  switch_ch = 1;
}

void choose() {
  if (switch_ch == 1) {
    if (switch_num == 3) {
      lcd.setCursor(6,0);
      lcd.print(" ");
      lcd.setCursor(9,0);
      lcd.write(byte(0));
      lcd.setCursor(12,0);
      lcd.print(" ");
      switch_ch = 2;
    }
  }
  else if (switch_ch == 2) {
    if (switch_num == 1) {
      lcd.setCursor(6,0);
      lcd.write(byte(0));
      lcd.setCursor(9,0);
      lcd.print(" ");
      lcd.setCursor(12,0);
      lcd.print(" ");
      switch_ch = 1;
    }
    else if (switch_num == 3) {
      lcd.setCursor(6,0);
      lcd.print(" ");
      lcd.setCursor(9,0);
      lcd.print(" ");
      lcd.setCursor(12,0);
      lcd.write(byte(0));
      switch_ch = 3;
    }
  }
  else if (switch_ch == 3) {
    if (switch_num == 1) {
      lcd.setCursor(6,0);
      lcd.print(" ");
      lcd.setCursor(9,0);
      lcd.write(byte(0));
      lcd.setCursor(12,0);
      lcd.print(" ");
      switch_ch = 2;
    }
  }
}

void resetMatrix() {
  for(int address=0; address<devices; address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address, 8);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

char* intToString(char* outstr, int val) {
  char temp[16];    // increase this if you need more digits than 15
  temp[0]   = '\0';
  outstr[0] = '\0';
  
  strcat(outstr, ltoa(val,temp,10));    // prints the int part

  return outstr;
}

