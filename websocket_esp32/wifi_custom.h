#ifndef _WIFI_CUSTOM_H
#define _WIFI_CUSTOM_H

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti WiFiMulti;
WebSocketsServer webSocket = WebSocketsServer(81);
#define USE_SERIAL Serial
#define ssid "vivo 1816"
#define password "12345PSR"

char *sliceString(char *str, int start, int end)
{
  int i;
  int size = (end - start) + 1; // memory allocate size
  char *output = (char *)malloc(size * sizeof(char));

  for (i = 0; start <= end; start++, i++)
  {
    output[i] = str[start];
  }
  output[size] = '\0';
  return output;
}



void GPIOS(uint8_t *payload)
{

  // here data = "GPIO15 : ON"
  int pin_num = atoi(sliceString((char *)payload, 4, 5));
  char *value = sliceString((char *)payload, 9, 12);

  String Value = *(&value);
  pinMode(pin_num, OUTPUT);

  if (Value == "ON_"){digitalWrite(pin_num, HIGH);}
  else if (Value == "OFF"){digitalWrite(pin_num, LOW);}
  else{USE_SERIAL.println("else");}
}


// void webpage()
// {
//   server.send(200,"text/html", webpageCode);
// }


//Oscilloscope Code
void Oscilloscope(){
  // osciloscope code
  unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= interval)
  {
    String value_analog = "oscilloscope "+(String)analogRead(34);
    // webSocket.broadcastTXT(itoa(value_a, buffer_analogread, 10));
    webSocket.broadcastTXT(value_analog);
    //  USE_SERIAL.println(value_analog);
    previousMillis = currentMillis;
    // value_a = 0;
  }

}

void hexdump(const void *mem, uint32_t len, uint8_t cols = 16)
{
  const uint8_t *src = (const uint8_t *)mem;
  USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
  for (uint32_t i = 0; i < len; i++)
  {
    if (i % cols == 0)
    {
      USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
    }
    USE_SERIAL.printf("%02X ", *src);
    src++;
  }
  USE_SERIAL.printf("\n");
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{

  switch (type)
  {
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
  //String payloadString = (const char *)payload;

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


#endif