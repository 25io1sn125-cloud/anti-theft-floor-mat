#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   

#define PIEZO_PIN A0
#define BUZZER_PIN 8
#define LED_PIN 7

int threshold = 300;   

void setup() {
  lcd.init();           
  lcd.backlight();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIEZO_PIN, INPUT);

  lcd.setCursor(0, 0);
  lcd.print(" Anti-Theft Mat ");
  lcd.setCursor(0, 1);
  lcd.print("   Initializing  ");
  delay(2000);
  lcd.clear();
}

void loop() {

  int sensorValue = analogRead(PIEZO_PIN);

 
  lcd.setCursor(0, 0);
  lcd.print("Sensor: ");
  lcd.print(sensorValue);
  lcd.print("   ");  

 
  if (sensorValue > threshold) {

    lcd.setCursor(0, 1);
    lcd.print(" INTRUDER ALERT! ");

    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000); 
    delay(800);
    noTone(BUZZER_PIN);
    delay(500);

  } else {

    lcd.setCursor(0, 1);
    lcd.print("  Area Secure    ");

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(150);
}