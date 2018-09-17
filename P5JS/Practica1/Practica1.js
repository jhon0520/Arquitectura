var backgroundColor = 'rgb(0, 0, 0)' ;
function setup () {
canvas = createCanvas(windowWidth, windowHeight);
//var random = random(0,255);
frameRate( 4 );
}
function draw () {
//background(backgroundColor);

      
  var r = Math.trunc(random(0,255));
  var g = Math.trunc(random(0,255));
  var b = Math.trunc(random(0,255));

background(r,g,b);
console.log("R" + r + " G" + g + " B " + b);
}
