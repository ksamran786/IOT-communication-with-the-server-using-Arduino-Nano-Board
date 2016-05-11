#include <SoftwareSerial.h>
SoftwareSerial esp8266(11, 12); // RX, TX
int count = 0,i=0;
char msgBuffer[64];
char msgBuffer1[64];
int msgLen = 0,msgLen1 = 0;
char commandStr[64];
char commandStr1[64];
void setup() {
// init serial communications
Serial.begin(9600);
esp8266.begin(19200);
esp8266.setTimeout(10000);
// reset WLAN
esp8266.println("AT+RST");
if (!esp8266.findUntil("ready", "ERROR")) {
Serial.println("ESP ERROR: AT+RST failed");
}
// config WLAN
esp8266.println("AT+CWMODE=1");
if (!esp8266.findUntil("OK", "ERROR")) {
Serial.println("ESP ERROR: AT+CWMODE=1 failed");
}
esp8266.println("AT+CWJAP=\"linksys\",\"samran\"");
if (!esp8266.findUntil("OK", "ERROR")) {
Serial.println("ESP ERROR: AT+CWJAP=\"Nomad_EXT\"... failed");
}
// get IP Address
esp8266.println("AT+CIFSR");
if (!esp8266.findUntil("OK", "ERROR")) {
Serial.println("ESP ERROR: AT+CIFSR");
}
// setup UDP connection
esp8266.println("AT+CIPSTART=\"UDP\",\"192.168.1.100\",9999,8888,0");
if (!esp8266.findUntil("OK", "ERROR")) {
Serial.println("ESP ERROR: AT+CIPSTART failed");
}
}
void loop() {
  if(i<100){ // so that only loop runs for 100 times
// Read the light-level value from A0 pin
int lightValue = analogRead(0);
// build message payload1^
sprintf(msgBuffer,"2981528; Seq= %d; LDR Value= %d \n", ++count, lightValue);
msgLen = strlen(msgBuffer);
// send message
sprintf(commandStr, "AT+CIPSEND=%d", msgLen);
esp8266.println(commandStr);
delay(1000);
esp8266.write(msgBuffer);
Serial.println("Sent: UDP");
Serial.println(msgBuffer);
i++;
delay(4000);}
}
