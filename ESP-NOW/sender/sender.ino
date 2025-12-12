#include <esp_now.h>
#include <WiFi.h>

#define CHANNEL 1
#define OUTPIN 13
#define INPIN 12

esp_now_peer_info_t slave;
uint8_t mac[6] = {0x00,0x00,0x00,0x00,0x00,0x00}; // Insert the hardcoded MAC address of the receiving ESP32.
uint8_t data = 1; // Data to be sent, can be any data type.
int state;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status){
  if(status == ESP_NOW_SEND_SUCCESS){
    Serial.print("Sent: ");
    Serial.println(data);
  } else {
    Serial.println("Failed to send.");
  }
}

void setup() {
  pinMode(OUTPIN,OUTPUT);
  pinMode(INPIN,INPUT);
  digitalWrite(OUTPIN,LOW);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_send_cb((esp_now_send_cb_t)OnDataSent);
  for(int i=0; i<6; i++){
    slave.peer_addr[i] = mac[i];
  }
  esp_now_add_peer(&slave);

  digitalWrite(OUTPIN,HIGH);
}

// Sends if pin 12 is HIGH.
void loop() {
  state = digitalRead(INPIN);
  if(state){
    esp_now_send(slave.peer_addr,&data,sizeof(data));
    while(1);
  }
}
