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

  analogWrite(greenpin, 255);
  delay(500);
  analogWrite(greenpin, 0);
  analogWrite(redpin, 255);
  delay(500);
    analogWrite(greenpin, 128);
    analogWrite(redpin, 128);
//    for(val = 177; val > 125; val--) { 
//    analogWrite(redpin, val);
//    analogWrite(greenpin, 177 - val);
//  }
  delay(500);
  analogWrite(greenpin, 0);
  analogWrite(redpin, 0);
  delay(500);
}
