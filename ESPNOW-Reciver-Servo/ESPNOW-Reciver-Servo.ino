#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Servo.h>   

Servo sg90;          
//Servo sg90two;          

typedef struct temp_struct {
  int x;
 // float y;
 // float z;
} temp_struct;

temp_struct myData;

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("X= ");
  Serial.println(myData.x);
  //Serial.print("Y= ");
  //Serial.println(myData.y);
  //Serial.print("Z= ");
  //Serial.println(myData.z);
  Serial.println();
}
 
void setup() {
  Serial.begin(115200);

  sg90.attach (D2);
  //sg90two.attach (D3);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);

}
 
void loop() {

  myData.x = map (myData.x, -1700, 1700, 0, 100) ;
 // myData.y = map (myData.y, -17000, 17000, 0, 180) ;

  sg90.write (myData.x); 
//  sg90two.write (myData.y); 

 delay (500);
 
}
