#include <string.h>
#include <SoftwareSerial.h>

#define AP_SSID "baek"
#define AP_PASS "12345678"
// #define AP_SSID "just"           // 공유기 SSID
// #define AP_PASS "justjust"       // 공유기 비번
#define DST_IP "13.124.185.67"      // MYSQL 서버 주소
SoftwareSerial dbgSerial(3, 2);   // RX, TX -> 3번, 2번 핀

char* floatToString(char* outstr, double val, byte precision, byte widthp) {
  char temp[16];    // increase this if you need more digits than 15
  byte i;
  
  temp[0]   = '\0';
  outstr[0] = '\0';
  
  if(val < 0.0) {
    strcpy(outstr, "-\0");    // print "-" sign
    val *= -1;
  }
  
  if(precision == 0) {
    strcat(outstr, ltoa(round(val),temp,10));   // prints the int part
  }
  else {
    unsigned long frac, mult = 1;
    byte padding = precision-1;
    
    while(precision--)
      mult *= 10;
    
    val += 0.5 / (float)mult;   // compute rounding factor
    strcat(outstr, ltoa(floor(val), temp, 10));   // prints the integer part without rounding
    strcat(outstr, ".\0");    // print the decimal point
    
    frac = (val-floor(val)) * mult;
    unsigned long frac1 = frac;
    
    while(frac1 /= 10)
      padding--;
    
    while(padding--)
      strcat(outstr, "0\0");    // print padding zeros
    
    strcat(outstr, ltoa(frac, temp, 10));  // print fraction part
  }
  
  // generate width space padding
  if((widthp!=0) && (widthp>=strlen(outstr))) {
    byte J = 0;
    J = widthp - strlen(outstr);
    
    for (i=0; i<J; i++) {
      temp[i] = ' ';
    }
    
    temp[i++] = '\0';
    strcat(temp, outstr);
    strcpy(outstr, temp);
  }
  
  return outstr;
}

void setup(void) {
  // 시리얼 포트 초기화
  Serial.begin(9600);
  Serial.setTimeout(5000);
  dbgSerial.begin(9600);
  Serial.println("ESP8266 connect");
  
  boolean connected = false;
  for(int i=0; i<10; i++) {
    if(connectWiFi()) {
      connected = true;
      break;
    }
  }
  
  if(!connected)
    while(1);
  delay(5000);
  
  dbgSerial.println("AT+CIPMUX=0");
  
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += DST_IP;
  cmd += "\",3306";
  Serial.println(cmd);
  dbgSerial.println(cmd);
  if(dbgSerial.find("Error")) {
    Serial.println("TCP connect error");
    return;
  }
  
  double tempC = 106.0;
  
  char test[20];
  String temp(floatToString(test, tempC, 2, 0));
  
  cmd = "GET " + String(DST_IP) + "/connect/run.php?num=106\n\r";
  dbgSerial.print("AT+CIPSEND=");
  dbgSerial.println(cmd.length());
  
  Serial.println(cmd);
  if(dbgSerial.find(">"))
    Serial.print(">");
  else {
    dbgSerial.println("AT+CIPCLOSE");
    Serial.println("connect timeout");
    delay(1000);
    return;
  }
  
  dbgSerial.print(cmd);
  delay(2000);
  
  Serial.find("+IPD");
  while(Serial.available()) {
    char c = Serial.read();
    dbgSerial.write(c);
    if(c == '\r')
      dbgSerial.print('\n');
  }
  
  Serial.println("====");
  delay(1000);
}

void loop(void)
{
  
}

boolean connectWiFi() {
  dbgSerial.println("AT+CWMODE=3");
  
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

