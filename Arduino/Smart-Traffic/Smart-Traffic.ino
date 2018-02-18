/* TurnStyle Traffic Express
Colin Barber */

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT); // red
  pinMode(8, OUTPUT); // right 
  pinMode(9, OUTPUT); // left

}

bool trafficState = LOW;
bool held = LOW;
int check = 0;
bool flip = LOW;

void loop() {

// touch sensor

  int sensorValue = analogRead(A0);
  
  if (sensorValue >= 1000) {
    if (held == LOW){
    trafficState = !trafficState;
    held = HIGH;}   
  }
  else {
    held = LOW;
  }
if (trafficState == HIGH) {  
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);                      
    digitalWrite(9, HIGH);    
  }
  else {
    digitalWrite (7, HIGH);
    digitalWrite(8, LOW);                      
    if (check <2) digitalWrite(9, LOW);

  int sensorValue2 = analogRead(A1);
  if (sensorValue2 >= 1000) {
    switch (check) {
    case 0: 
    check++;
    delay (560);
    break;
    case 1: 
    check--;
    delay (560);
    break;
    case 2:
    flip = HIGH; 
    digitalWrite(9, HIGH);
    check++;
    delay (560);
    break;
    case 3:
    if (flip == HIGH){
       check--;
    }
    else {
    digitalWrite(9, LOW);
    check = 0;
    delay (560);}
    break;
  }}
  else {
    switch (check) {
    case 0: 
    digitalWrite (9, LOW);
    break;
    case 1: 
    check++;
    delay (560);
    break;
    case 2:
    flip = LOW; 
    digitalWrite(9, HIGH);
    check++;
    delay (560);
    break;
    case 3:
    if (flip == HIGH){ 
      check--;
      delay (560);}
    else {
      check = 0;
    }
    break;
  }
  }
    Serial.print("check = ");
    Serial.print(check);
    Serial.println();

    Serial.print("flip = ");
    Serial.print(flip);
    Serial.println();

  
  }

// light sensor

 

}
