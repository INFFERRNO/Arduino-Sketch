#include <DS1307RTC.h>
#include <TM1628.h>
#include <TM16XXFonts.h>
#include <RTClib.h>
#include <TM1628.h>
#include <Wire.h>
#include "RTClib.h"

TM1628 dvdLED(9, 8, 7); 
RTC_DS1307 rtc;
// обьявление портов: DIO - порт D9, CLK - D8, STB - D7

void setup() {
  dvdLED.begin(ON, 2);
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
   digitalClockDisplay();  
   delay(1000);
}

void digitalClockDisplay(){
   DateTime now = rtc.now();
   for(int i=0;i<19;i++){
      dvdLED.setLEDon(i);
      delay(25);    
    }
    
    for(int i=0;i<19;i++){
      dvdLED.setLEDoff(i);
      delay(25);    
    } 

}

/* sequence of LEDs:
   порядок светодиодов:
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

