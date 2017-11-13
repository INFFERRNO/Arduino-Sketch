#include <Adafruit_NeoPixel.h>
#define PIN 6 // номер порта к которому подключен модуль
#define count_led 24 // количество светодиодов 
#define potr A0 //red потенциометр
#define potg A1 //зеленый потенциометр
#define potb A2 //синий потенциометр
#define potring A3 //кольцо потенциометр
int i,pr,pg,pb,pring,butt;
const int buttonPin = 5;     // номер входа, подключенный к кнопке
int buttonState = 0;         // переменная для хранения состояния кнопки



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors
void setup() {
  pinMode(potr, INPUT); // пин с потенциометром r - вход
  pinMode(potg, INPUT); // пин с потенциометром g - вход
  pinMode(potb, INPUT); // пин с потенциометром b - вход
  pinMode(potring, INPUT); // пин с потенциометром кольца - вход
  pinMode(buttonPin, INPUT); // инициализируем пин, подключенный к кнопке, как вход  
  pixels.begin();
  Serial.begin(9600);
  pixels.show(); // Устанавливаем все светодиоды в состояние "Включено"
}
void loop() {
   buttonState = digitalRead(buttonPin); // считываем значения с входа кнопки
   

  
  pr = analogRead(potr) / 16; // считываем напряжение с потенциометра r, будет получено число от 0 до 1023, делим его на 4, получится число в диапозоне 0-255 (дробная часть будет отброшена)
  pg = analogRead(potg) / 16; // считываем напряжение с потенциометра g, будет получено число от 0 до 1023, делим его на 4, получится число в диапозоне 0-255 (дробная часть будет отброшена)
  pb = analogRead(potb) / 16; // считываем напряжение с потенциометра b, будет получено число от 0 до 1023, делим его на 4, получится число в диапозоне 0-255 (дробная часть будет отброшена)
  pring = analogRead(potring) / 42; // считываем напряжение с потенциометра ring, будет получено число от 0 до 1023, делим его на 42, получится число в диапозоне 0-24 (дробная часть будет отброшена)

if (buttonState == HIGH) // проверяем нажата ли кнопка, если нажата, то buttonState будет HIGH
  {   
    for(i=0; i<24;i++){
          pixels.setPixelColor(i, pixels.Color(255,255,255)); //выключаем светодиоды дальше значения potring
       }
  }

else{  
for(i=0; i<pring;i++){
          pixels.setPixelColor(i, pixels.Color(pr,pg,pb)); //выдаем результат на rgb кольцо
       }
       

   
for(i=pring; i<24;i++){
          pixels.setPixelColor(i, pixels.Color(0,0,0)); //выключаем светодиоды дальше значения potring
       }

}
        
pixels.show();
}
