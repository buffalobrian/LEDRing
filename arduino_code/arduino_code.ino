

#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);
uint16_t brightness = 255;
uint16_t last_LED_index = 45;
uint16_t first_quarter = 11;
uint16_t third_quarter = 34;
uint32_t green = strip.Color(255,0,0);
uint32_t red   = strip.Color(0,255,0);
uint32_t blue  = strip.Color(0,0,255);
uint32_t white = strip.Color(255,255,255);
uint32_t pink  = strip.Color(50, 255, 180);
uint32_t black = 0;
uint32_t grey  = strip.Color(0, 0, 0);

// Have to make it circular with drop off on the sides of the brightest LEDs
// If index is negative, add 45, or greater than 45, subtract 45
void circular(uint16_t width, uint32_t color, uint16_t milliseconds) {
  for(uint16_t i = 0; i < last_LED_index + 1; i++) {
    for(uint16_t j = i; j < i + width; j++) {
      if(j > last_LED_index){
        strip.setPixelColor(j - last_LED_index - 1, color);
      } else {
        strip.setPixelColor(j, color);
      }
    }
    strip.show();
    for(uint16_t j = i; j < i + width; j++) {
      if(j > last_LED_index){
        strip.setPixelColor(j - last_LED_index - 1, black);
      } else {
        strip.setPixelColor(j, black);
      }
    }
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
  for (uint16_t i = third_quarter - 7; i < third_quarter + 7; i++) {
    strip.setPixelColor(i, left_color);
  }
  // right
  for (uint16_t i = first_quarter - 7; i < first_quarter + 7; i++) {
    strip.setPixelColor(i, right_color);
  }
  strip.show();
}

void uniform(uint32_t color) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) strip.setPixelColor(i, color);
  strip.show();
}

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}

void loop() {
  circular(5, white, 50);
  //halfandhalf(green,pink);
  //uniform(white);
  
  //Code to turn off LED lights
  //uniform(black);
  //strip.setPixelColor(0, 0);
  //strip.show();
}
