
void setup() {
  pinMode(7, OUTPUT);
  pinMode(0, INPUT);
}

void loop() {
  int buttState = analogRead(A0);
 
  if (buttState >= 500){
    digitalWrite(6, HIGH);   
    delay(400);                    
    digitalWrite(6, LOW);    
    delay(400);
    digitalWrite(6, HIGH);   
    delay(400);                    
    digitalWrite(6, LOW);    
    delay(400);
    digitalWrite(6, HIGH);   
    delay(400);                    
    digitalWrite(6, LOW);    
    delay(400);
    digitalWrite(6, HIGH);   
    delay(400);                    
    digitalWrite(6, LOW);    
    delay(400);
    digitalWrite(6, HIGH);   
    delay(400);                    
    digitalWrite(6, LOW);    
    delay(400);        
  }
  else digitalWrite(6, LOW);
}
