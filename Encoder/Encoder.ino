#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>
#include <Encod_er.h>
#include <Button.h>

#define PIN 5 // номер порта к которому подключен модуль
#define count_led 16 // количество светодиодов 
int i,mode=0;
long posr=0,posg=0,posb=0;

Button encoderA (2, 4); // сигнал A
Button encoderB (8, 4); //  сигнал B
Button encoderButton(10, 40); // кнопка

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors

void setup() {
  Serial.begin(9600); // инициализируем порт, скорость 9600
  pixels.begin();
  pixels.show(); // Устанавливаем все светодиоды в состояние "Включено"
  Timer1.initialize(250); // инициализация таймера 1, период 250 мкс
  Timer1.attachInterrupt(timerInterrupt, 250); // задаем обработчик прерываний
}

void loop() {
   //кнопка энкодера
 if(encoderButton.flagClick == true) {
    encoderButton.flagClick = false;
    mode++;
    Serial.println(mode);
 }
 if(mode>2)
 mode=0;


  //повороты энкодера red mode
   if(mode==0){
   if( encoderA.flagClick == true ) {
    encoderA.flagClick= false;
      if( encoderB.flagPress == true) {
        // против часовой стрелки
        if (posr>20)
        posr=20;
        else
        posr++;
      }
      else {
        // по часовой стрелке
        if (posr<1)
        posr = 0;
        else 
        posr--;
      }
  }
   } 

    //повороты энкодера green mode
   if(mode==1){
   if( encoderA.flagClick == true ) {
    encoderA.flagClick= false;
      if( encoderB.flagPress == true) {
        // против часовой стрелки
        if (posg>20)
        posg=20;
        else
        posg++;
      }
      else {
        // по часовой стрелке
        if (posg<1)
        posg = 0;
        else 
        posg--;
      }
  } 
    }

     //повороты энкодера blue mode
   if(mode==2){
   if( encoderA.flagClick == true ) {
    encoderA.flagClick= false;
      if( encoderB.flagPress == true) {
        // против часовой стрелки
        if (posb>20)
        posb=20;
        else
        posb++;
      }
      else {
        // по часовой стрелке
        if (posb<1)
        posb = 0;
        else 
        posb--;
      }
  } 
   }
     for(i=0; i<16;i++){
          pixels.setPixelColor(i, pixels.Color(posr*5,posg*5,posb*5)); //выключаем светодиоды дальше значения potring
       }
  pixels.show();
   
}

// обработчик прерывания 250 мкс
void timerInterrupt() {
  encoderA.filterAvarage(); // вызов метода фильтрации
  encoderB.filterAvarage(); // вызов метода фильтрации
  encoderButton.filterAvarage(); // вызов метода фильтрации 
}
