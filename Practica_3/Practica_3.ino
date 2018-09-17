int PinFotoresistencia = 0;
int PinTouch = 2;
int ValueTouch =0;
int ValueFotoresistencia = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PinTouch, INPUT);
}

void loop() {
  //ValueTouch = digitalRead(PinTouch);
  int value = digitalRead(PinTouch);
  ValueTouch = map(value, 0, 1, 0, 1023);
  ValueFotoresistencia = analogRead(PinFotoresistencia);
  delay(100);
  Serial.print(ValueTouch);
  Serial.print(" ");
  Serial.println(ValueFotoresistencia);
  //Serial.println(ValueFotoresistencia);

}
