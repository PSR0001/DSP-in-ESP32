#include<Arduino.h>


void setup(){
   Serial.begin(250000);
   delay(1000);
   Serial.println();
   Serial.println();
   Serial.println();
    Serial.print("ESP32 Starts");
    

}
void loop(){
   Serial.println(getCpuFrequencyMhz());
   delay(5000);
}