#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

void setup () {
  Serial.begin(57600);
  Wire.begin();
  rtc.begin();
  
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}




void loop () {

  digitalClockDisplay();  
  delay(1000);

}


void digitalClockDisplay(){
  DateTime now = rtc.now();
}


