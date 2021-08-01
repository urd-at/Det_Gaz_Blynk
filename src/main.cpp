#include <Arduino.h>


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


BlynkTimer timer;

//info Lahcene
//char auth[] = "a06Nppmh1QoWNLBtWmNH0Xlox7hfnM3a";
//char ssid[] = "Idoom 4G_BDF13";
//char pass[] = "URD2021@at";

//info Boualem
char auth[] = "xOKQF41GCoD7WuPayXISXSTKn5GmFaFM";
char ssid[] = "MI 8";
char pass[] = "123456789";



#define MQ2 34
//#define MQ7 35
#define GREEN 17
#define RED 16

int sensorValueMQ2 = 0;
//int sensorValueMQ7 = 0;

void sendUptime();


void setup()
{
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
pinMode(MQ2, INPUT);
//pinMode(MQ7, INPUT);
pinMode(GREEN, OUTPUT);
pinMode(RED, OUTPUT);
 timer.setInterval(1000L, sendUptime);
 delay(3000);
}

void sendUptime()
{
 sensorValueMQ2 = analogRead(MQ2);
 //sensorValueMQ7 = analogRead(MQ7);
 Blynk.virtualWrite(V2, sensorValueMQ2);
 //Blynk.virtualWrite(V1, sensorValueMQ7);
 
 Serial.println("MQ2 Value:");
 Serial.println(sensorValueMQ2);
 //Serial.println("MQ7 Value:");
 //Serial.println(sensorValueMQ7);

 
if (sensorValueMQ2 > 500)
 {
Blynk.notify("Gas Detected!");
digitalWrite(GREEN, LOW);
digitalWrite(RED, HIGH);
delay(1000);
 }
 
else
 {
digitalWrite(GREEN, HIGH);
digitalWrite(RED, LOW);
delay(1000);
 }
 
}



void loop()

{
 Blynk.run();
 timer.run();
}