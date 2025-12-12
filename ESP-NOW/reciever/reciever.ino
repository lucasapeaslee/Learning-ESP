#include <esp_now.h>
#include <WiFi.h>

#define CHANNEL 1
#define LED 2

uint8_t newData;

void setup() {
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_recv_cb((esp_now_recv_cb_t)OnDataRecv);
}

// Writes pin 2 HIGH when data is sent.
void loop() {
  if(newData){
    digitalWrite(LED,HIGH);
  }
}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len){
  Serial.print("Received: ");
  Serial.println(*data);
  memcpy(&newData,data,sizeof(newData)); // Since the callback function requires a pointer to the sent data, I write the data to a new variable "newData" to be manipulated.
}
