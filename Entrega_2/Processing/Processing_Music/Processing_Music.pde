// Run this program only in the Java mode inside the IDE,
// not on Processing.js (web mode)!!

import processing.video.*;

Capture cam;

void setup() {
  size(640, 480);
  cam = new Capture(this, 640, 480, 30);
  cam.start();
  
}

void draw() {
  
  if(cam.available()) {
    cam.read();
    image(cam, 0, 0);
    int brightestX = 0, brightestX2=0, brightestX3=0, brightestX4=0; // X-coordinate of the brightest video pixel
    int brightestY = 0, brightestY2=0, brightestY3=0, brightestY4=0; // Y-coordinate of the brightest video pixel
    float brightestValue = 0, brightestValue2=0, brightestValue3=0, brightestValue4=0; // Brightness of the brightest video pixel
    // Search for the brightest pixel: For each row of pixels in the video image and
    // for each pixel in the yth row, compute each pixel's index in the video
    
    cam.loadPixels();
    int index = 0;
    for (int y = 0; y < cam.height; y++) {
      for (int x = 0; x < cam.width; x++) {
        
        // Get the color stored in the pixel
        
        int pixelValue = cam.pixels[index];
        
        // Determine the brightness of the pixel
        
        float pixelBrightness = brightness(pixelValue);
        
        // If that value is brighter than any previous, then store the
        // brightness of that pixel, as well as its (x,y) location
        
        if (pixelBrightness > brightestValue) {
          brightestValue = pixelBrightness;
          brightestY = y;
          brightestX= x;
          }
          
        if (pixelBrightness > brightestValue2 && pixelBrightness != brightestValue &&  (brightestY2 > brightestY+25) &&  (brightestX2 > brightestX+25)) {
          brightestValue2 = pixelBrightness;
          brightestY2 = y;
          brightestX2= x;
          }
          
         if (pixelBrightness > brightestValue3 && pixelBrightness != brightestValue && pixelBrightness != brightestValue2) {
          brightestValue3 = pixelBrightness;
          brightestY3 = y;
          brightestX3= x;
          }
         if (pixelBrightness > brightestValue4 && pixelBrightness != brightestValue && pixelBrightness != brightestValue2 && pixelBrightness != brightestValue3) {
          brightestValue4 = pixelBrightness;
          brightestY4 = y;
          brightestX4= x;
          }
          
        index++;
      }
    }
    // Draw a large, yellow circle at the brightest pixel
    fill(255, 0, 0, 128);
    ellipse(brightestX, brightestY, 20, 20);
    fill(0, 255, 0, 128);
    ellipse(brightestX2, brightestY2, 20, 20);
    fill(0, 0, 255, 128);
    ellipse(brightestX3, brightestY3, 20, 20);
    fill(125, 0, 255, 128);
    ellipse(brightestX4, brightestY4, 20, 20);
  }
}

// la idea idea es comparar los valores obtenidos previamente del profesor 
// tomar ese valor y si es distinto a este que lo grafique
