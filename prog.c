#include <MD_AD9833.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define FSYNC_PIN 9
#define READ_PIN  A0
#define FREQ_PIN  A6
#define SW1_PIN   4
#define SW2_PIN   3
#define OLED_RESET -1

MD_AD9833 gen(FSYNC_PIN);
Adafruit_SH1106G display(128, 64, &Wire, OLED_RESET);

byte data[128];
long f;
int sw1, sw2;
String waveName;

void setup() {
  pinMode(SW1_PIN, INPUT_PULLUP);
  pinMode(SW2_PIN, INPUT_PULLUP);
  pinMode(READ_PIN, INPUT);

  gen.begin();

  display.begin(0x3C, true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 2);
  display.println("ossiloscope");
  display.display();
  delay(3000);
}

void loop() {
  f = map(analogRead(FREQ_PIN), 0, 1023, 0, 5000);
  sw1 = digitalRead(SW1_PIN);
  sw2 = digitalRead(SW2_PIN);

  if (sw1 == LOW && sw2 == LOW) { gen.setMode(MD_AD9833::MODE_SINE); waveName = "SINE"; }
  else if (sw1 == LOW && sw2 == HIGH) { gen.setMode(MD_AD9833::MODE_TRIANGLE); waveName = "TRIANGLE"; }
  else if (sw1 == HIGH && sw2 == LOW) { gen.setMode(MD_AD9833::MODE_SQUARE1); waveName = "SQUARE"; }
  else { gen.setMode(MD_AD9833::MODE_SQUARE2); waveName = "HF_SQUARE"; }

  gen.setFrequency(MD_AD9833::CHAN_0, f);

  for (int x = 0; x < 128; x++) {
    data[x] = analogRead(READ_PIN) / 21.8;
  }

  display.clearDisplay();
  for (int x = 1; x < 128; x++) {
    display.drawLine(x - 1, 63 - data[x - 1], x, 63 - data[x], SH110X_WHITE);
  }

  display.setCursor(0, 0);
  display.print(waveName);
  display.setCursor(60, 0);
  display.print(f);
  display.print(" Hz");
  display.display();
  delay(100);
}
