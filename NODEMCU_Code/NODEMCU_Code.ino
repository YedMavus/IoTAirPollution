#include <ESP8266WiFi.h>
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  WiFi.begin("YedMavus", "abcd1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(" .. ");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected");
  Serial.println(WiFi.localIP());
}

void loop() { // run over and over
//  if (Serial.available()) {
//    Serial.write(Serial.read());
//  }
}
