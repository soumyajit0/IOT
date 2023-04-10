#include<ESP8266WiFi.h>;
#include<WiFiClient.h>;
#include<ThingSpeak.h>;
const char* ssid="TMK-Student";
const char* password="12345678";
WiFiClient client;
unsigned long myChannelNumber=2072549;
const char * myWriteAPIkey="SPNGZVC5V2ZCQS4F";
const char * myReadAPIkey="XHTLFNLAX0AEPC5U";
int led_1;
int led2=D1;
int ldr=A0;
int val=0;
void setup() {
  Serial.begin(115200);
  
  pinMode(led2,OUTPUT);
  WiFi.begin(ssid,password);
  ThingSpeak.begin(cliet);
}

void loop() {
  val=analogRead(ldr);
  Serial.println(val);
  ThingSpeak.writeField(myChannelNumber,1,val,myWriteAPIkey);
  led_1=ThingSpeak.readIntField(myChannelNumber,1,myReadAPIkey);
  Serial.println(led_1);
  if(led_1<200)
  {
    digitalWrite(led2,HIGH);
  }
  else
  {
    digitalWrite(led2,LOW);
  }
  delay(15000);
}
