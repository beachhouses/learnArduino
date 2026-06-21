#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define trig 9
#define echo 8
#define buzzer 7 // <-- PIN BUZZER DI PIN D7

long durasi, jarak;
int countObj = 0;
bool terdeteksi = false;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED gagal diinisialisasi!"));
    for(;;); 
  }

  display.clearDisplay();
  display.display();

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT); // <-- Atur pin buzzer sebagai OUTPUT
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  durasi = pulseIn(echo, HIGH);
  jarak = durasi * 0.034 / 2;

  // Logika saat objek terdeteksi
  if (jarak < 10 && !terdeteksi) {
    countObj++;
    terdeteksi = true;
    
    // === MODIFIKASI: BUZZER BUNYI ===
    digitalWrite(buzzer, HIGH); // Buzzer menyala
    delay(100);                 // Bunyi selama 0.1 detik
    digitalWrite(buzzer, LOW);  // Buzzer mati kembali
  }

  if (jarak > 15) {
    terdeteksi = false;
  }

  // Tampilan OLED
  display.clearDisplay();      
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);     
  display.println("PENGHITUNG OBJEK");
  
  display.drawFastHLine(0, 12, 128, SSD1306_WHITE); 

  display.setTextSize(2);      
  display.setCursor(0, 25);    
  display.print("Total: ");
  display.print(countObj);

  display.display();

  delay(50); 
}