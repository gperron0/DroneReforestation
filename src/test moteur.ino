
 
int SENSOR_PIN = 34; // center pin of the potentiometer
 
int RPWM_Output = 25; // Arduino PWM output pin 36; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 26; // Arduino PWM output pin 39; connect to IBT-2 pin 2 (LPWM)
 
void setup()
{
  Serial.begin(115200);
  pinMode(RPWM_Output, OUTPUT);
  pinMode(LPWM_Output, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
}
 
/*void loop()
{
  int sensorValue = analogRead(SENSOR_PIN);
  //Serial.println("sensorValue :");
  //Serial.println(sensorValue);
 
  // sensor value is in the range 0 to 4095
  // the lower half of it we use for reverse rotation; the upper half for forward rotation
  //if (sensorValue &lt;= 512)
  if(sensorValue > 0 && sensorValue <= 2048)
  {
    // reverse rotation
    int reversePWM = -(sensorValue - 2047) / 2;
    analogWrite(LPWM_Output, 0);
    analogWrite(RPWM_Output, reversePWM);
    Serial.println("reverse :");
    Serial.println(reversePWM);
  }
  else
  {
    // forward rotation
    int forwardPWM = (sensorValue - 2048) / 2;
    analogWrite(RPWM_Output, 0);
    analogWrite(LPWM_Output, forwardPWM);
    Serial.println("forward :");
    Serial.println(forwardPWM);
  }
}*/
void loop()
{
  analogWrite(LPWM_Output, 0);
  analogWrite(RPWM_Output, 1000);
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
  /*delay(10000);
  analogWrite(RPWM_Output, 0);
  analogWrite(LPWM_Output, 200);*/

}
