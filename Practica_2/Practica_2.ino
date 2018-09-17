const int SWITCH_PIN = 2; // selecciona el pin para la lectura digital mediante interrupción
int pulsador=0;              //almacena el estado del botón
int estado=0;                //0=led apagado, 1=led encendido
int pulsadorAnt=8           //almacena el estado anterior del boton

const int LED = 13; // selecciona el pin del LED integrado
// método que se llama cuando se detecta la interrupción y el valor pasa de LOW a HIGH
void interruptISR() {
   state = !state;
}

void setup() {
 Serial.begin(9600);
 //determina el modo de los diferentes pines
 pinMode(SWITCH_PIN, INPUT_PULLUP);
  // adiciona la interrupción al pin del interruptor
 attachInterrupt(digitalPinToInterrupt(SWITCH_PIN), interruptISR, RISING);
 pinMode(LED, OUTPUT);
}

void loop() {
  pulsador = digitalRead(SWITCH_PIN); //lee si el botón está pulsado
  
  if((pulsador==HIGH)&&(pulsadorAnt==LOW)){  //si el boton es pulsado y antes no lo estaba
    estado=1-estado;
    //Serial.println(estado);
    delay(40);               //pausa de 40 ms
  }
  pulsadorAnt=pulsador;      //actualiza el nuevo estado del boton        
  
  if(estado==1) {            //si el estado es 1
    digitalWrite(2, HIGH);   //se enciende el led
    Serial.println(estado);
  }
  else{                      //si el estado es 0
    digitalWrite(2, LOW);    //se apaga el led
    Serial.println(estado);
  }
}
