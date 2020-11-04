#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include<SPI.h>

const char *ssid     = "BULAT";
const char *password = "elveda54";
const char* host = "api.thingspeak.com";
uint8_t buff2[100];
uint8_t buff3[1];

void setup(){
  Serial.begin(115200);
  
  //SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();  //begin SPI
  delay(100);
  pinMode(0, OUTPUT);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}
void loop(){
  //Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if(!client.connect(host, httpPort)){
    Serial.println("connection failed");
  }

  //We now create a URL for request
  String url = "https://api.thingspeak.com/apps/thinghttp/send_request?api_key=L7N6P43GETMBIPWJ";

  //This will send the request to server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(1000);

  //Read all the lines of the reply from server and print to uart
  while(client.available()){
    int line = client.readBytesUntil('\r');
 Serial.print("\r\t\t");
 Serial.println(line);
// buff2  = atoi (line.substring(1, 3).c_str ());   
 for(int j=0; j<100; j++){
    buff2[j]=(uint8_t)line;
    SPI.transfer(buff2[j]);
  }
 //buff=line;
//   buff3[1] = (uint8_t)1;
   SPI.transfer(buff3[1]);
   delay(100);
   
  }
  Serial.print("connecting to ");
  Serial.println(host);
 // SPI.transfer(buff3[1]);
  
}
