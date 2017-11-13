#include <Adafruit_NeoPixel.h>
#define PIN 6 // номер порта к которому подключен модуль
#define count_led 24 // количество светодиодов 
#include <SPI.h>
#include <MFRC522.h> // библиотека "RFID".
#define SS_PIN 53
#define RST_PIN 5
int i,k;
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;  // для храниения номера метки в десятичном формате
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();  //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init();     // инициализация MFRC522 / Init MFRC522 card.
  pixels.begin();
  pixels.show();
}

void loop() {

  // Поиск новой метки
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Выбор метки
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  uidDec = 0;
  // Выдача серийного номера метки.
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  Serial.println("Card UID: ");
  Serial.println(uidDec); // Выводим UID метки в консоль.
  
   for(k=0; k<24;k++){
pixels.setPixelColor(k, pixels.Color(5,5,5));
     } 
    
  if (uidDec == 881769662) // Сравниваем Uid метки, если он равен заданому то серва открывает.
  {
       for(k=0; k<24;k++){
pixels.setPixelColor(k, pixels.Color(5,0,0));
     } 
  }
   
   if (uidDec == 287481812) // Сравниваем Uid метки, если он равен заданому то серва открывает.
  {
       for(k=0; k<24;k++){
pixels.setPixelColor(k, pixels.Color(0,5,0));
     } 
  }
  pixels.show();  
}



