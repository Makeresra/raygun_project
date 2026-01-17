// Ray Gun Mark 2 - TAM VE HATASIZ KOD

// Pin Tanımlamaları
const int redPin = 9;    // Kırmızı LED bacağı
const int greenPin = 10; // Yeşil LED bacağı (Ana Renk)
const int bluePin = 11;  // Mavi LED bacağı
const int buttonPin = 2; // Tetik Düğmesi

// Değişkenler
float wave;
int brightness;

void setup() {
  // LED Çıkışları
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Tetik Girişi
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {
  // BUTON KONTROLÜ
  if (digitalRead(buttonPin) == LOW) {
    fireRayGun(); // Ateş et
  } 
  else {
    // BEKLEME MODU (Nefes Alma Efekti)
    wave = sin(millis() * 0.002); 
    brightness = map(wave * 100, -100, 100, 20, 150); 

    analogWrite(greenPin, brightness);      
    analogWrite(bluePin, brightness / 5);   
    analogWrite(redPin, 0);                 
  }
}

// ATEŞLEME EFEKTİ FONKSİYONU
void fireRayGun() {
  for (int i = 0; i < 3; i++) {
    // 1. Patlama
    analogWrite(greenPin, 255); 
    analogWrite(bluePin, 100);  
    analogWrite(redPin, 0);
    
    delay(40); 
    
    // 2. Sönme
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
    
    delay(70); 
  }
  
  delay(120); 
} 
// Kod burada biter, bu son parantez çok önemlidir!