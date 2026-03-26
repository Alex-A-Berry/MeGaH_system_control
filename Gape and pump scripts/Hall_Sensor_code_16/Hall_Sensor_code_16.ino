// the setup routine runs once when you press reset:
void setup() {
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
//data collection frequency ~x milliseconds
int freq = 1000 ; 
bool label = true;
void loop(){
  
    //print out column headers
    while(label){ //runs once
        label=false;
  }
// the loop routine runs over and over again forever:   
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int sensorValue5 = analogRead(A4);
  int sensorValue6 = analogRead(A5);
  int sensorValue7 = analogRead(A6);
  int sensorValue8 = analogRead(A7);
  int sensorValue9 = analogRead(A8);
  int sensorValue10 = analogRead(A9);
  int sensorValue11 = analogRead(A10);
  int sensorValue12 = analogRead(A11);
  int sensorValue13 = analogRead(A12);
  int sensorValue14 = analogRead(A13);
  int sensorValue15 = analogRead(A14);
  int sensorValue16 = analogRead(A15);
  delay(1);

  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float mussel1 = sensorValue * (5.0 / 1023.0);
  float mussel2 = sensorValue2 * (5.0 / 1023.0);
  float mussel3 = sensorValue3 * (5.0 / 1023.0);
  float mussel4 = sensorValue4 * (5.0 / 1023.0);
  float mussel5 = sensorValue5 * (5.0 / 1023.0);
  float mussel6 = sensorValue6 * (5.0 / 1023.0);
  float mussel7 = sensorValue7 * (5.0 / 1023.0);
  float mussel8 = sensorValue8 * (5.0 / 1023.0);
  float mussel9 = sensorValue9 * (5.0 / 1023.0);
  float mussel10 = sensorValue10 * (5.0 / 1023.0);
  float mussel11 = sensorValue11 * (5.0 / 1023.0);
  float mussel12 = sensorValue12 * (5.0 / 1023.0);
  float mussel13 = sensorValue13 * (5.0 / 1023.0);
  float mussel14 = sensorValue14 * (5.0 / 1023.0);
  float mussel15 = sensorValue15 * (5.0 / 1023.0);
  float mussel16 = sensorValue16 * (5.0 / 1023.0);
  // print out the value you read:

  Serial.print(mussel1);
  Serial.print(",");
  Serial.print(mussel2);
  Serial.print(",");
  Serial.print(mussel3);
  Serial.print(",");
  Serial.print(mussel4);
  Serial.print(",");
  Serial.print(mussel5);
  Serial.print(",");
  Serial.print(mussel6);
  Serial.print(",");
  Serial.print(mussel7);
  Serial.print(",");
  Serial.print(mussel8);
  Serial.print(",");
  Serial.print(mussel9);
  Serial.print(",");
  Serial.print(mussel10);
  Serial.print(",");
  Serial.print(mussel11);
  Serial.print(",");
  Serial.print(mussel12);
  Serial.print(",");
  Serial.print(mussel13);
  Serial.print(",");
  Serial.print(mussel14);
  Serial.print(",");
  Serial.print(mussel15);
  Serial.print(",");
  Serial.println(mussel16);
  delay(freq);
}
