#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include "html_doc.h"
#include <arduinoFFT.h>


WiFiMulti WiFiMulti;
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

#define USE_SERIAL Serial
#define ssid "vivo 1816"
#define password "12345PSR"
#define SAMPLES         1024          // Must be a power of 2
#define SAMPLING_FREQ   40000         // Hz, must be 40000 nyquiest Criteria
#define AMPLITUDE       1000          // roun
#define AUDIO_IN_PIN    25  
#define NUM_BANDS       16 
#define NOISE           500           //Noise 
#define TOP             500           // set the Top Value
unsigned int sampling_period_us;
byte peak[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};              // The length of these arrays must be >= NUM_BANDS
int oldBarHeights[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bandValues[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double vReal[SAMPLES];
double vImag[SAMPLES];
unsigned long newTime;
arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);



// Function Prototype
//void webpage();
char *sliceString(char *str, int start, int end);
void GPIOS(uint8_t* payload);
char buffer_analogread[20];
char buffer_fft[100];




void hexdump(const void *mem, uint32_t len, uint8_t cols = 16) {
  const uint8_t* src = (const uint8_t*) mem;
  USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
  for(uint32_t i = 0; i < len; i++) {
    if(i % cols == 0) {
      USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
    }
    USE_SERIAL.printf("%02X ", *src);
    src++;
  }
  USE_SERIAL.printf("\n");
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    
    switch(type) {
        case WStype_DISCONNECTED:
            webSocket.sendTXT(num, "Disconnected");
            USE_SERIAL.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                USE_SERIAL.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

              // send message to client
            webSocket.sendTXT(num, "Connected");
            }              
            break;
        case WStype_TEXT:
            USE_SERIAL.printf("[%u] get Text: %s\n", num, payload);
            GPIOS(payload);
//            String payloadString = (const char *)payload;
            
            break;
        case WStype_BIN:
            USE_SERIAL.printf("[%u] get binary length: %u\n", num, length);
            hexdump(payload, length);
            break;
        case WStype_ERROR:      
        case WStype_FRAGMENT_TEXT_START:
        case WStype_FRAGMENT_BIN_START:
        case WStype_FRAGMENT:
        case WStype_FRAGMENT_FIN:
      break;
    }

}

unsigned long previousMillis = 0;
int interval = 100;
int value_a = 0;



void setup() {
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(250000);

    delay(1000);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();
    
      for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

    WiFiMulti.addAP(ssid,password);

    while(WiFiMulti.run() != WL_CONNECTED) {
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
    
}

void loop() {
    webSocket.loop();
//    server.handleClient();
//    unsigned long currentMillis = millis(); 
    //osciloscope code
//      if ((unsigned long)(currentMillis - previousMillis) >= interval){
//    value_a = analogRead(34);
//    webSocket.broadcastTXT(itoa(value_a,buffer2,10));
//    USE_SERIAL.println(value_a);
//      previousMillis = currentMillis;
//      value_a =0;
//      }

  // Fft code 
  // Reset bandValues[]
  for (int i = 0; i<NUM_BANDS; i++){
    bandValues[i] = 0;
  }

  // Sample the audio pin
  for (int i = 0; i < SAMPLES; i++) {
    newTime = micros();
    vReal[i] = analogRead(34); // A conversion takes about 9.7uS on an ESP32
    vImag[i] = 0;
    while ((micros() - newTime) < sampling_period_us) { /* chill */ }
    // delay(1);
    //   Serial.print("--------------------------------------");
    // Serial.println(vReal[i]);
  }

  // Compute FFT
  FFT.DCRemoval();
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(FFT_FORWARD);
  FFT.ComplexToMagnitude();

// Analyse FFT results
  for (int i = 2; i < (SAMPLES/2); i++){       // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the amplitude.
    if (vReal[i] > NOISE) {                    // Add a crude noise filter
          // Serial.println("=======================");
          //     Serial.println(vReal[i]);
    //16 bands, 12kHz top band
      if (i<=2 )           bandValues[0]  += (int)vReal[i];
      if (i>2   && i<=3  ) bandValues[1]  += (int)vReal[i];
      if (i>3   && i<=5  ) bandValues[2]  += (int)vReal[i];
      if (i>5   && i<=7  ) bandValues[3]  += (int)vReal[i];
      if (i>7   && i<=9  ) bandValues[4]  += (int)vReal[i];
      if (i>9   && i<=13 ) bandValues[5]  += (int)vReal[i];
      if (i>13  && i<=18 ) bandValues[6]  += (int)vReal[i];
      if (i>18  && i<=25 ) bandValues[7]  += (int)vReal[i];
      if (i>25  && i<=36 ) bandValues[8]  += (int)vReal[i];
      if (i>36  && i<=50 ) bandValues[9]  += (int)vReal[i];
      if (i>50  && i<=69 ) bandValues[10] += (int)vReal[i];
      if (i>69  && i<=97 ) bandValues[11] += (int)vReal[i];
      if (i>97  && i<=135) bandValues[12] += (int)vReal[i];
      if (i>135 && i<=189) bandValues[13] += (int)vReal[i];
      if (i>189 && i<=264) bandValues[14] += (int)vReal[i];
      if (i>264          ) bandValues[15] += (int)vReal[i];
    }
  }

  // Process the FFT data into bar heights
  for (byte band = 0; band < NUM_BANDS; band++) {

    // Scale the bars for the display
    int barHeight = bandValues[band] / AMPLITUDE;

    // Serial.println(bandValues[band]);
    // delay(2);

    // int barHeight = bandValues[band];
    if (barHeight > TOP) barHeight = TOP;

    // Small amount of averaging between frames
    barHeight = ((oldBarHeights[band] * 1) + barHeight) / 2;

    // Serial.println(barHeight);
    // delay(2);
    // Move peak up
    if (barHeight > peak[band]) {
      peak[band] = min(TOP, barHeight);
    }
    String fft_string = String(barHeight)+ " " + String(band);
    // Serial.println(fft_string);
    
  //  webSocket.broadcastTXT(itoa(fft_string,buffer_fft,10));
   webSocket.broadcastTXT(fft_string);
   oldBarHeights[band] = barHeight;
  }

}


//void webpage()
//{
//  server.send(200,"text/html", webpageCode);
//}

void GPIOS(uint8_t* payload){
 
 // here data = "GPIO15 : ON"
  int pin_num = atoi(sliceString((char*)payload,4,5));
  char* value = sliceString((char*)payload,9,12);

  String Value = *(&value);
  pinMode(pin_num,OUTPUT);
  if(Value == "ON_"){digitalWrite(pin_num,HIGH);}
  else if(Value == "OFF"){digitalWrite(pin_num,LOW);}
  else{USE_SERIAL.println("else");}
}
char *sliceString(char *str, int start, int end){
    int i;
    int size = (end - start) + 1; // memory allocate size
    char *output = (char *)malloc(size * sizeof(char));

    for (i = 0; start <= end; start++, i++){
        output[i] = str[start]; 
    }
    output[size] = '\0';
    return output;
}
