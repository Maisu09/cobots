#include <Wifi.h>
#include <HTTPClient.h>

// wifi
const char* ssid = "cobot";
const char* password = "0000";

// Server
const char* IP = "192.168.0.199";
const int PORT = 9999;

IPAddress LOCAL_IP(192, 168, 0, 199);
IPAddress GATEWAY(192, 168, 0, 1);
IPAddress SUBNET(255, 255, 255, 0);

WebServer.server(PORT);

void setup() {
  Serial.begin(115200);
  WiFi.config(LOCAL_IP, GATEWAY, SUBNET);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WI-FI")
  }
  Serial.print("Connected to Wi-Fi with IP: ")
  Serial.println(IP);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
