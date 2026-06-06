#include <Servo.h>

// Definisi Pin
const int trigPin = 11;
const int echoPin = 12;
const int servoPin = 13;
const int ledHijau = 7;  // Pin untuk LED Hijau
const int ledMerah = 8;  // Pin untuk LED Merah

Servo servo;

// Definisi Variabel
long duration;
int distance;

// Batas jarak dekat (dalam centimeter)
const int batasJarakDekat = 8; 

void setup() {
  Serial.begin(9600);

  // Pengaturan Pin Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Pengaturan Pin LED
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  // Pengaturan Awal Servo
  servo.attach(servoPin);
  servo.write(90); // Posisi awal servo turun/menutup
  
  // Kondisi Awal: LED Merah NYALA, LED Hijau MATI
  digitalWrite(ledMerah, HIGH);
  digitalWrite(ledHijau, LOW);
  
  delay(2000);
}

void loop() {
  // Kirim pulsa ke trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan gelombang
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak dalam cm
  distance = duration * 0.034 / 2;

  // Menampilkan jarak ke Serial Monitor
  Serial.print("Jarak Terdeteksi: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika pergerakan dan lampu indikator
  if (distance > 0 && distance <= batasJarakDekat) { 
    // JIKA OBJEK DEKAT (SERVO TERANGKAT)
    servo.write(180);           // Angkat servo
    digitalWrite(ledHijau, HIGH); // LED Hijau NYALA
    digitalWrite(ledMerah, LOW);  // LED Merah MATI
    
    delay(3000);                // Tahan selama 3 detik
  } else {
    // JIKA TIDAK ADA OBJEK (SERVO TURUN / KONDISI STANDBY)
    servo.write(90);            // Turunkan servo
    digitalWrite(ledHijau, LOW);  // LED Hijau MATI
    digitalWrite(ledMerah, HIGH); // LED Merah NYALA (kembali standby)
  }

  delay(200); 
}
