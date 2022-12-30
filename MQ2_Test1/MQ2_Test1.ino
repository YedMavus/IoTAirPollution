/* Change the threshold value with your own reading */
#define Threshold 180

#define MQ2pin A0
#define MQ7pin A1
#define buzzOUT 9
#define LOUT 13

float sensorValue2;  //variable to store sensor value of MQ2
float sensorValue7;  //variable to store sensor value of MQ7


void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ2 and MQ7 warming up!");
  pinMode(MQ2pin, INPUT);
  pinMode(MQ7pin, INPUT);
  pinMode(buzzOUT, OUTPUT);
  pinMode(LOUT, OUTPUT);
  delay(60000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue2 = analogRead(MQ2pin); // read analog input pin 0
  sensorValue7 = analogRead(MQ7pin); // read analog input pin 1
  
  Serial.print("Sensor Value for MQ2: ");
  Serial.println(sensorValue2);

  Serial.print("Sensor Value for MQ7: ");
  Serial.println(sensorValue7);

  if(sensorValue2 > Threshold || sensorValue7 > Threshold)
  {
    Serial.println(" | Smoke detected!");
    analogWrite(buzzOUT, 127);
    digitalWrite(LOUT, HIGH);
  }
  else{
    analogWrite(buzzOUT, 0);
    digitalWrite(LOUT,LOW);
  }
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
}
