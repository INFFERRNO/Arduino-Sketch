#include <Wire.h>
#include "RTClib.h"
#include <TM1628.h>

RTC_DS1307 rtc;
TM1628 dvdLED(9, 8, 7); // объявление пинов D-9 C-8 S-7


void setup () {
  dvdLED.begin(ON, 7); //запуск дисплея на яркости 2
  Wire.begin(); 
  rtc.begin(); //запуск часов реального времени      
  }




void loop () {
  //анимация
  for(int i=0;i<8;i++){
      dvdLED.setLEDon(i);
      delay(40);
      dvdLED.setLEDon(17);
      dvdLED.setLEDon(18);
    }
    
  for(int i=0;i<8;i++){
      dvdLED.setLEDoff(i);
      delay(40);
      dvdLED.setLEDoff(17);
      dvdLED.setLEDoff(18);
    } 
    
  DateTime now = rtc.now(); //получение данных из часов реального времени
  dvdLED.setTime(now.hour(),now.minute(),now.second()); //вывод времени на дисплей
  }

/*  порядок светодиодов:
    LED_SE0 0x00
    LED_SE1 0x01
    LED_SE2 0x02
    LED_SE3 0x03
    LED_SE4 0x04
    LED_SE5 0x05
    LED_SE6 0x06
    LED_SE7 0x07
    LED_DVD 0x08
    LED_VCD 0x09
    LED_MP3 0x0A
    LED_PLY 0x0B
    LED_PAU 0x0C
    LED_PBC 0x0D
    LED_RET 0x0E
    LED_DTS 0x0F
    LED_DDD 0x10
    LED_CL1 0x11
    LED_CL2 0x12
*/
