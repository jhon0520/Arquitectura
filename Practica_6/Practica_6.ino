
#include <Arduino.h>

// Código Arduino para probar el sensor pulsador (KY-004) con interrupciones

// ARDUINO UNO interrupciones en pines 2 y 3
// Arduino pin 2 --> pin S del modulo
// Arduino 5V --> pin medio del modulo
// Arduino GND --> pin - del modulo

const int LED = 13; // selecciona el pin del LED integrado
const int SWITCH_PIN = 2; // selecciona el pin para la lectura digital mediante interrupción
const int SPEED_TRANSMISSION = 9600; // selecciona la velocidad de transmisión
const int TIME_THRESHOLD = 150; // tiempo de espera antes de reconocer otra pulsación

volatile int value = LOW; // variable para almacenar el valor leído
volatile long lastPressureTime = 0; // variable para almacenar el momento de la última pulsación


// si se detecta una pulsación se enciende el LED y envía un mensaje al terminal
void interruptISR() {
  // Condicional para evitar el rebote (debounce) mediante software
  if (millis() > lastPressureTime + TIME_THRESHOLD) {
    value = !value;
    digitalWrite(LED, value);
    Serial.println(value);
    lastPressureTime = millis();
  }
}

void setup() {
  //determina el modo de los diferentes pines
  pinMode(LED, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  // apaga el LED integrado
  digitalWrite(LED, LOW);
  // adiciona la interrupción al pin del interruptor
  attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), interruptISR, RISING);

  // inicializa la comunicación serial al PC para ver los datos en el terminal
  Serial.begin(SPEED_TRANSMISSION);
}

void loop() {}



