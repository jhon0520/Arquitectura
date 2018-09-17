
// the setup function runs once when you press reset or power the board
char Caracter  = ' '; // almacena el dato serie
String StringCompleto = "";
String StringArray[] ="";
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
// envía datos sólo si los recibe:
if (Serial.available() > 0) {

Caracter = Serial.read();
//Serial.println(Caracter);
StringCompleto = String(StringCompleto + Caracter);

if( Caracter =='\n'){
  Serial.println(StringCompleto);
  GuardarArreglo(StringCompleto);
}

}

}

void GuardarArreglo(String StringCompleto){
  StringArray.apend
  
}

