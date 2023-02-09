void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  delay(500); // this speeds up the simulation
  digitalWrite(12,LOW);
  delay(500);
}

/*void setup() {
  Serial.begin(115200);
  Serial.println("Mon premier programme");
  pinMode(2,OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH); //On allume la led bleue
  delay(500); //On attend pendant 500 ms
  digitalWrite(2, LOW); //On eteinds la led bleue
  delay(500); //On attend pendant 500 ms
}*/
