// Declara el objeto de "SerialPort" que se va a utilizar
var serial;
//var port = '/dev/cu.usbmodem1421'; // variable que indica el puerto serial utilizado por el Arduino
var port ='COM3';
// change the data rate to whatever you wish
var options = { baudrate: 9600};
//let inByte;

var backgroundColor = 'rgb(0, 0, 0)'; // variable donde se almacena el color de fondo

function setup() {
  createCanvas(windowWidth, windowHeight);

  // Crea un objeto del tipo SerialPort
  serial = new p5.SerialPort();

  // Determina el método que se llama para listar los puertos seriales conectados
  serial.onList(portList);

  // Abre la conexión con el puerto donde está conectado el Arduino
  serial.open(port,options);

  // Determina el método que se llama cuando hay datos en el puerto
  serial.onData(getData);
  noLoop();
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
  inByte = serial.read();
   //println("inByte: " + inByte);
   if(inByte =="49"){
     var num = 1;
     console.log(num);
     redraw();
     var r = Math.trunc(random(0,255));
     var g = Math.trunc(random(0,255));
     var b = Math.trunc(random(0,255));
     //var backgroundColor = (r,g,b);
     draw(r,g,b);
   }if(inByte =="48"){
     var num = 0;
     console.log(num);
     redraw();
     //var backgroundColor = 'rgb(0, 0, 0)';
     draw(0,0,0);
   }
   inData = inByte;
}

function serialError(err) {
  println('Something went wrong with the serial port. ' + err);
}

function draw(r,g,b) {
  
  background(r,g,b);
}
