#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <WiFiClientSecure.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include "html_doc.h"
#include <arduinoFFT.h>
#include "fft.h"
#include "wifi_custom.h"


//RTOS Define
#define app_cpu 0


TaskHandle_t Task;
//Task1code: blinks an LED every 1000 ms
void dspLoop( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
  } 
}






// WebServer server(80);

void setup()
{
  USE_SERIAL.begin(250000);
  delay(1000);
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();
  for (uint8_t t = 4; t > 0; t--)
  {
    USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  WiFiMulti.addAP(ssid, password);

  while (WiFiMulti.run() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(100);
  }
  Serial.print(F("IP Address : "));
  Serial.println(WiFi.localIP());

  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQ));
  //    server.on("/", webpage);
  //    server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

    xTaskCreatePinnedToCore(   //use xTaskCreate() in Vanilla Free RTOS
    dspLoop,               //Function to be called
    "loop2",            //Name a TASK
    1024,                    // Stack Size (for esp32, words in Free RTOS
    NULL,                    //parameter to pass to function
    1,                       //Priority of the task (0 to configMax_PRIORITIES - 1)
    &Task,                    //Task Handel
    app_cpu);  

}

void loop()
{
  webSocket.loop();
  // server.handleClient();
  // Serial.print("ESP32 Frequency: ");
  // Serial.println(getCpuFrequencyMhz());


  // Fft code
  // Reset bandValues[]
  for (int i = 0; i < NUM_BANDS; i++)
  {
    bandValues[i] = 0;
  }

  // Sample the audio pin
  for (int i = 0; i < SAMPLES; i++)
  {
    newTime = micros();
    vReal[i] = analogRead(34); 
    vImag[i] = 0;
    while ((micros() - newTime) < sampling_period_us){ /* Do Nothing */ }
    // Serial.print("[DEBUG] : VReal Variable Value : ");
    // Serial.println(vReal[i]);
  }

  // Compute FFT
  FFT.DCRemoval(); //DC voltage remoe
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD); //windowing is a part of DSP
  FFT.Compute(FFT_FORWARD);
  FFT.ComplexToMagnitude();

  // Analyse FFT results
  for (int i = 2; i < (SAMPLES / 2); i++)
  { 
    if (vReal[i] > NOISE)
    { 

      // Serial.print("[DEBUG] : VReal Variable Value : ");
      // Serial.println(vReal[i]);

      // 16 bands
      if (i <= 2)
        bandValues[0] += (int)vReal[i];
      if (i > 2 && i <= 3)
        bandValues[1] += (int)vReal[i];
      if (i > 3 && i <= 5)
        bandValues[2] += (int)vReal[i];
      if (i > 5 && i <= 7)
        bandValues[3] += (int)vReal[i];
      if (i > 7 && i <= 9)
        bandValues[4] += (int)vReal[i];
      if (i > 9 && i <= 13)
        bandValues[5] += (int)vReal[i];
      if (i > 13 && i <= 18)
        bandValues[6] += (int)vReal[i];
      if (i > 18 && i <= 25)
        bandValues[7] += (int)vReal[i];
      if (i > 25 && i <= 36)
        bandValues[8] += (int)vReal[i];
      if (i > 36 && i <= 50)
        bandValues[9] += (int)vReal[i];
      if (i > 50 && i <= 69)
        bandValues[10] += (int)vReal[i];
      if (i > 69 && i <= 97)
        bandValues[11] += (int)vReal[i];
      if (i > 97 && i <= 135)
        bandValues[12] += (int)vReal[i];
      if (i > 135 && i <= 189)
        bandValues[13] += (int)vReal[i];
      if (i > 189 && i <= 264)
        bandValues[14] += (int)vReal[i];
      if (i > 264)
        bandValues[15] += (int)vReal[i];
    }
  }

  // Process the FFT data into bar heights
  for (byte band = 0; band < NUM_BANDS; band++)
  {

    // Scale the bars for the display
    int barHeight = bandValues[band] / AMPLITUDE;
    if (barHeight > TOP)
        barHeight = TOP;

    // Small amount of averaging between frames
    barHeight = ((oldBarHeights[band] * 1) + barHeight) / 2;

    // Move peak up
    if (barHeight > peak[band])
    {
      peak[band] = min(TOP, barHeight);
    }
    String fft_string = "fft "+String(barHeight) + " " + String(band);
    // Serial.println(fft_string);

    webSocket.broadcastTXT(fft_string);
    oldBarHeights[band] = barHeight;
  }
}
















