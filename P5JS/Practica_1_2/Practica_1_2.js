var backgroundColor = 'rgb(0, 0, 0)' ;
var value=0;

function setup () {
canvas = createCanvas(windowWidth, windowHeight);
noLoop();
}

function mousePressed() {
  redraw();
  var r = Math.trunc(random(0,255));
  var g = Math.trunc(random(0,255));
  var b = Math.trunc(random(0,255));

  background(r,g,b);
  console.log("R" + r + " G" + g + " B " + b);
}
