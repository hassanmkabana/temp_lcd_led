#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <dht.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;
#define DHT11_PIN 9
int led = 7;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int chk = DHT.read11(DHT11_PIN);
 lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("c");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);

  if (DHT.temperature == 28){
    digitalWrite(led, HIGH);
  }
 else {
    digitalWrite(led, LOW);
  
}

}
