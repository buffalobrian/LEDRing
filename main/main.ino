

#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);
uint16_t brightness = 255;
uint32_t green = strip.Color(255,0,0);
uint32_t red   = strip.Color(0,255,0);
uint32_t blue  = strip.Color(0,0,255);
uint32_t white = strip.Color(255,255,255);
uint32_t pink  = strip.Color(50, 255, 180);

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}

// Have to make it circular with drop off on the sides of the brightest LEDs
// If index is negative, add 45, or greater than 45, subtract 45
void circular(uint16_t width, uint32_t color, uint16_t milliseconds) {
  for(uint16_t i = 0; i < strip.numPixels()-5; i++) {
    strip.setPixelColor(i, color);
    strip.setPixelColor(i+1, color);
    strip.setPixelColor(i+2, color);
    strip.show();
    strip.setPixelColor(i, 0);
    strip.setPixelColor(i+1, 0);
    strip.setPixelColor(i+2, 0);
    delay(milliseconds);
  }
}

//Blinks r -> g -> b for long exposure shots
void rgb(uint16_t seconds){
  uint16_t milliseconds = seconds*1000;
  
  //wait 4 seconds before looping
  delay(3000);
  //show white to signify loop start
  uniform(white);
  delay(1000);
  
  //loop through rgb
  uniform(red);
  delay(milliseconds/3);
  uniform(green);
  delay(milliseconds/3);
  uniform(blue);
}

//Blinks c -> y -> m for long exposure shots
void cym(){

}

void halfandhalf(uint32_t left_color, uint32_t right_color) {
  // left
  for (uint16_t i = 3; i < strip.numPixels() / 2 - 5; i++) {
    strip.setPixelColor(i, left_color);
  }
  // right
  for (uint16_t i = strip.numPixels() / 2 + 5; i < strip.numPixels() - 5; i++) {
    strip.setPixelColor(i, right_color);
  }
  strip.show();
}

void loop() {
  //circular(3, white, 100);
  halfandhalf(green,pink);
}
