#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "eye_animation.h"   

// Konfigurasi Layar OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Posisi animasi supaya pas di tengah layar
#define ANIM_X ((SCREEN_WIDTH  - EYE_ANIM_WIDTH)  / 2)
#define ANIM_Y ((SCREEN_HEIGHT - EYE_ANIM_HEIGHT) / 2)

// Jeda antar frame (ms). Video asli ~195ms/frame kalau disebar rata di 3.12 detik.
// Kecilin angka ini kalau mau animasinya lebih cepat, gedein kalau mau lebih pelan.
#define FRAME_DELAY 150

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 alokasi gagal"));
    for (;;);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  for (int i = 0; i < EYE_ANIM_FRAME_COUNT; i++) {
    // Ambil pointer frame dari PROGMEM
    const unsigned char* frame = (const unsigned char*)pgm_read_ptr(&eye_animation_frames[i]);

    display.clearDisplay();
    display.drawBitmap(ANIM_X, ANIM_Y, frame, EYE_ANIM_WIDTH, EYE_ANIM_HEIGHT, SSD1306_WHITE);
    display.display();

    delay(FRAME_DELAY);
  }

  // Loop otomatis balik ke frame 0 (animasi diulang terus-terusan)
}
