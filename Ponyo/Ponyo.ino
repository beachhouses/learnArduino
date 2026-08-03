#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ponyo_animation.h"   // hasil convert dari video Ponyo kamu, 24 frame 56x64px

// Konfigurasi Layar OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Posisi animasi supaya pas di tengah layar
#define ANIM_X ((SCREEN_WIDTH  - PONYO_ANIM_WIDTH)  / 2)
#define ANIM_Y ((SCREEN_HEIGHT - PONYO_ANIM_HEIGHT) / 2)

// Jeda antar frame (ms). Video asli ~98ms/frame kalau disebar rata di 2.36 detik.
// Kecilin angka ini kalau mau animasinya lebih cepat, gedein kalau mau lebih pelan.
#define FRAME_DELAY 100

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
  for (int i = 0; i < PONYO_ANIM_FRAME_COUNT; i++) {
    // Ambil pointer frame dari PROGMEM
    const unsigned char* frame = (const unsigned char*)pgm_read_ptr(&ponyo_animation_frames[i]);

    display.clearDisplay();
    display.drawBitmap(ANIM_X, ANIM_Y, frame, PONYO_ANIM_WIDTH, PONYO_ANIM_HEIGHT, SSD1306_WHITE);
    display.display();

    delay(FRAME_DELAY);
  }

  // Loop otomatis balik ke frame 0 (animasi diulang terus-terusan)
}
