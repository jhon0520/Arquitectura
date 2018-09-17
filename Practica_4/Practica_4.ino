int redpin = 11; // pin Rojo
int greenpin = 10; // pin Verde
int laserpin = 12; // pin laser
int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(laserpin, OUTPUT);
}

void loop() {

  
  digitalWrite(laserpin, HIGH);
  delay(500);
  digitalWrite(laserpin, LOW);
  delay(500);
}
