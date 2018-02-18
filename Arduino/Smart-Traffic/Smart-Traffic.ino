/* TurnStyle Traffic Express
Colin Barber */

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT); // red
  pinMode(8, OUTPUT); // right 
  pinMode(9, OUTPUT); // left

}

int check = 0;

void loop() {

// touch sensor

  int sensorValue = analogRead(A0);
  if (sensorValue >= 1000) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);                      
    digitalWrite(9, HIGH);    
  }
  else {
    digitalWrite (7, HIGH);
    digitalWrite(8, LOW);                      
    if (check < 2) digitalWrite(9, LOW);
  }


// light sensor

  int sensorValue2 = analogRead(A1);
  if (sensorValue2 >= 1000) {
    switch (check) {
    case 0:
    digitalWrite(9, LOW); 
    check++;
    delay (550);
    break;
    case 1:
    digitalWrite(9, LOW); 
    check--;
    delay (550);
    break;
    case 2: 
    check++;
    delay (550);
    break;
    case 3:
    digitalWrite(9, HIGH); 
    check++;
    delay (550);
    break;
    case 4: 
    digitalWrite(9, LOW);
    check = 0;
    break;
  }}
  else {
    switch (check) {
    case 0: 
    digitalWrite (9, LOW);
    break;
    case 1:
    digitalWrite(9, LOW); 
    check++;
    delay (550);
    break;
    case 2: 
    digitalWrite(9, HIGH);
    check++;
    delay (550);
    break;
    case 3:
    digitalWrite(9, HIGH); 
    check--;
    delay (550);
    break;
    case 4: 
    check--;
    delay (550);
    break;
  }
  }
    Serial.print(check);
    Serial.println();


}
