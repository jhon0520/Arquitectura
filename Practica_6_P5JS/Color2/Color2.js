// Declara el objeto de "SerialPort" que se va a utilizar
var serial;
//var port = '/dev/cu.usbmodem1421'; // variable que indica el puerto serial utilizado por el Arduino
var port ='COM3';
var backgroundColor = 'rgb(0, 0, 0)'; // variable donde se almacena el color de fondo

function setup() {
  createCanvas(windowWidth, windowHeight);

  // Crea un objeto del tipo SerialPort
  serial = new p5.SerialPort();

  // Determina el método que se llama para listar los puertos seriales conectados
  serial.onList(portList);

  // Abre la conexión con el puerto donde está conectado el Arduino
  serial.open(port);

  // Determina el método que se llama cuando hay datos en el puerto
  serial.onData(getData);
  console.log(serial.onData(getData));
}


// Método que muestra por consola los puertos seriales conectados al PC
function portList(ports) {
  console.log('Listado de puertos seriales:');
  // recorre el listado de puertos seriales y los muestra por consola
  for (var i = 0; i < ports.length; i++) {
      console.log(ports[i]);
  }
}

// Método que llama al recibir datos desde el puerto serial
function getData() {
  
}

function draw() {
  background(backgroundColor);
}
