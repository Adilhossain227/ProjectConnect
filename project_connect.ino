#include <ESP8266WiFi.h>
//**** you do not have to change this *********************************
char* host = "arthor.com.bd";
int ledPin = 2;
//**************************xxxxxxxxxxxxxx*****************************
//**** put your SID and auth generated from your web account here******
String SID = "your_SID";
String auth = "your_auth_key";
//*************************xxxxxxxxxxxxxxx*****************************
//**** put your wifi name and password here ******
String wifi_name = "your_wifi_name";
String wifi_pass = "your_wifi_password";
//*************************xxxxxxxxxxxxxxxx****************************
void setup() {

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  WiFi.begin(wifi_name, wifi_pass);
  Serial.println();
  Serial.print("Connecting");

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  digitalWrite( ledPin , HIGH);
  Serial.println();
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}

void loop() {
  // These are sample of[max 5] variables*****************************
  // but you can change the datatype to float,int,char,String*********
  float testvar1 = random(999);
  float testvar2 = random(999);
  float testvar3 = random(999);
  float testvar4 = random(999);
  float testvar5 = random(999);
  //**********************xxxxxxxxxxxxxxxxxxx**************************
  // Please keep this delay at least to 3 seconds or so****************
  // In the testing phase we can not handle too much robust data*******
  // Hope you understand :") ******************************************
  delay(3000);
  //*********************xxxxxxxxxxxxxxxxxxxx**************************
  // send the value of max 5 variables through the send2server function
  // if you have lessthan 5 variables just send 0 or a fixed char for-
  // the rest of the variables
  send2server(testvar1, testvar2, testvar3, testvar4, testvar5);
  //********************xxxxxxxxxxxxxxxxxxxx***************************

}
//****function to send data to server**********************************
int send2server(int var1, int var2, int var3, int var4, int var5) {
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
  }

  // This will send the request to the server
  client.print(String("GET https://connect.arthor.com.bd/peer_data/push_data.php?") +
               ("SID=") + SID + ("&") + ("auth=") + auth + ("&") + ("var1=") + var1 + ("&") +
               ("var2=") + var2 + ("&") + ("var3=") + var3 + ("&") + ("var4=") + var4 + ("&") + ("var5=") + var5 +
               " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
}
//***********************xxxxxxxxxxxxxxxxx****************************
