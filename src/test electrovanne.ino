void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(11, LOW);
  delay(5000);
  Serial.println("UUUUUUUP");
  digitalWrite(11, HIGH);
  delay(100);*/
  analogWrite(11, HIGH);

}
