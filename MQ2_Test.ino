/* Change the threshold value with your own reading */
#define Threshold 400

#define MQ2pin A0
#define MQ7pin A1

float sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ2 and MQ7 warming up!");
  pinMode(MQ2pin, INPUT);
  pinMode(MQ7pin, INPUT);
  delay(60000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue2 = analogRead(MQ2pin); // read analog input pin 0
  sensorValue7 = analogRead(MQ7pin); // read analog input pin 1
  
  Serial.print("Sensor Value for MQ2: ");
  Serial.print(sensorValue2);

  Serial.print("Sensor Value for MQ7: ");
  Serial.print(sensorValue7);


  if(sensorValue2 > Threshold)
  {
    Serial.print(" | Smoke detected-2!");
  }
  
   if(sensorValue7 > Threshold)
  {
    Serial.print(" | Smoke detected-7!");
  }
  
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
}
