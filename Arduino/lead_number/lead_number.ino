#include <SoftwareSerial.h>   // 시리얼통신 라이브러리 호출
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
int blueTx = 2;   // Tx (보내는핀 설정)at
int blueRx = 3;   // Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);    // 시리얼 통신을 위한 객체선언

LiquidCrystal_I2C lcd(0x3F, 16, 2);

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

int ledPin = 12;

int button1Pin = 8;
int button2Pin = 9;
int button3Pin = 10;

int switch_num = 0;   // 몇 번째 스위치인지
int switch_ctrl = 0;  // 스위치를 눌렀을 때 loop문이 한 번만 작동되도록
int switch_menu = 0;  // 어떤 메뉴인지
int in_menu = 0;      // 메뉴 안에 들어갔는지
int switch_ch = 1;    // 메뉴 안에서 몇 번째를 선택했는지

long debouncing_time = 300;   // Debouncing Time in Milliseconds
volatile unsigned long last_micros;
boolean SettingsScreen = true;

void setup()
{
  Serial.begin(9600);   // 시리얼모니터
  mySerial.begin(9600);   // 블루투스 시리얼

  lcd.init();
  lcd.backlight();

  pinMode(ledPin, OUTPUT);
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  attachInterrupt(0, debounceInterrupt, RISING);

  lcd.createChar(0, arrow);
  lcd.createChar(1, saju1);
  lcd.createChar(2, saju2);
  lcd.createChar(3, saju3);
  lcd.createChar(4, taro1);
  lcd.createChar(5, taro2);
  lcd.createChar(6, taro3);
  lcd.createChar(7, num);
}

void loop()
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
        if (switch_ch == 3) {
          menu_left();
          in_menu = 0;
        }
      }
      else if (in_menu == 0) {
        if (switch_menu == 1) {
          menu_saju();
          menu();
        }
        else if (switch_menu == 2) {
          menu_taro();
          menu();
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
      switch_num = 1;
      switch_ctrl = 1;
    }
  }
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
}

void debounceInterrupt() {
   // if((long)(micros() - last_micros) >= debouncing_time * 1000) {
   if((long)(micros() - last_micros) >= debouncing_time * 1200) {
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
  switch_menu = 1;
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

