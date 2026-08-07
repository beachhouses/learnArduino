#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {

  // Scene 1
  lcd.setCursor(4, 0);
  lcd.print("Temanku");
  delay(900);

  lcd.setCursor(0, 1);
  lcd.print("semua");
  delay(700);

  lcd.setCursor(6, 1);
  lcd.print("pada");
  delay(850);

  lcd.setCursor(11, 1);
  lcd.print("jahat");
  delay(700);

  lcd.clear();

  // Scene 2
  lcd.setCursor(4, 0);
  lcd.print("Tante..");
  delay(1000);

  lcd.setCursor(1, 0);
  lcd.print("aku lagi susah");
  delay(1000);

  lcd.setCursor(1, 1);
  lcd.print("mereka");
  delay(900);

  lcd.setCursor(9, 1);
  lcd.print("ga ada");
  delay(2300);

  lcd.clear();

  // Scene 3
  lcd.setCursor(1, 0);
  lcd.print("coba kalau");
  delay(1000);

  lcd.setCursor(6, 1);
  lcd.print("lagi jaya");
  delay(2000);

  lcd.clear();

  // Scene 4
  lcd.setCursor(2, 0);
  lcd.print("aku di puja");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("pujanya");
  delay(1300);

  lcd.setCursor(8, 1);
  lcd.print("tantee..");
  delay(2000);

  lcd.clear();

  // Scene 5
  lcd.setCursor(1, 0);
  lcd.print("sudah");
  delay(1000);

  lcd.setCursor(7, 0);
  lcd.print("terbiasa");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("terjadi");
  delay(1000);

  lcd.setCursor(8, 1);
  lcd.print("tantee..");
  delay(1000);

  lcd.clear();

  // Scene 6
  lcd.setCursor(2, 0);
  lcd.print("teman datang");
  delay(1300);

  lcd.setCursor(2, 1);
  lcd.print("ketika lagi");
  delay(1500);

  lcd.clear();

  // Scene 7
  lcd.setCursor(3, 0);
  lcd.print("butuh");
  delay(500);

  lcd.setCursor(8, 1);
  lcd.print("saja");
  delay(1300);

  lcd.clear();

  // Scene 8
  lcd.setCursor(1, 0);
  lcd.print("coba kalau");
  delay(1000);

  lcd.setCursor(5, 1);
  lcd.print("lagi susah");
  delay(2000);

  lcd.clear();

  // Scene 9
  lcd.setCursor(2, 0);
  lcd.print("mereka semua");
  delay(2000);

  lcd.setCursor(1, 1);
  lcd.print("menghilang");
  delay(800);

  lcd.setCursor(11, 1);
  lcd.print("....");
  delay(2900);

  lcd.clear();

  // Credit
  lcd.setCursor(0, 0);
  lcd.print("peii");
  delay(6000);

  lcd.clear();
}