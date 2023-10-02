#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


//Alarm Pendeteksi hujan
const int sensorPin = A0;    //inisialisasi pin button
const int buzzer = 7;      //inisialisasi pin buzzer


void setup(){
Serial.begin (9600);
lcd.init();
lcd.backlight();
lcd.clear();
pinMode(buzzer, OUTPUT);
pinMode(sensorPin, INPUT);
}

void loop() {
int nilaiSensor = analogRead(sensorPin);
Serial.print ("A0 : ");
Serial.println (nilaiSensor);
delay (1000);

if (nilaiSensor <= 500){
  Serial.println(". Hujan Turun");
  digitalWrite (buzzer, HIGH);
  lcd.setCursor(5, 0);
  lcd.print("A0 : ");
  lcd.print(nilaiSensor);
  lcd.setCursor(4, 1);
  lcd.print("Hujan Turun");
  delay(5000);
  lcd.clear();  
  }

else {
  Serial.println(". belum hujan");
  digitalWrite (buzzer, LOW);
  lcd.setCursor(5, 0);
  lcd.print("A0 : ");
  lcd.print(nilaiSensor);
  lcd.setCursor(4, 1);
  lcd.print("belum hujan");
  delay(3000);
  lcd.clear();  
 
}
}
