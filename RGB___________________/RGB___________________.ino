#include <Adafruit_NeoPixel.h>
#define PIN 5 // номер порта к которому подключен модуль
#define count_led 24 // количество светодиодов 
int i;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors
void setup() {
  pixels.begin();
  Serial.begin(9600);
  pixels.show(); // Устанавливаем все светодиоды в состояние "Выключено"
}
void loop() {
for(i=0; i<24;i++){
pixels.setPixelColor(i, pixels.Color(10,1,0));
}
pixels.show();
}
