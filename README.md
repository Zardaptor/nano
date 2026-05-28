# Arduino Mini Oscilloscope + Function Generator

A compact Arduino-based **Function Generator + Mini Oscilloscope** using the **AD9833 DDS module** and a **1.3" SH1106 OLED display**.

## Features

* Sine wave generation
* Triangle wave generation
* Square wave generation
* High-frequency square mode
* Real-time waveform visualization
* Frequency adjustment using potentiometer
* OLED display interface
* Compact embedded design

---

# Hardware Used

* Arduino Nano
* AD9833 DDS Function Generator Module
* SH1106 128x64 OLED Display
* Potentiometer
* Push Buttons
* Breadboard / Custom PCB

---

# Pin Configuration

## AD9833 Connections

| AD9833 | Arduino Nano |
| ------ | ------------ |
| FSYNC  | D9           |
| SCLK   | D13          |
| SDATA  | D11          |
| VCC    | 5V           |
| GND    | GND          |

---

## OLED Connections

| OLED | Arduino Nano |
| ---- | ------------ |
| SDA  | A4           |
| SCL  | A5           |
| VCC  | 5V           |
| GND  | GND          |

---

## Control Pins

| Function           | Pin |
| ------------------ | --- |
| Oscilloscope Input | A0  |
| Frequency Control  | A6  |
| Switch 1           | D4  |
| Switch 2           | D3  |

---

# Waveform Selection

| SW1  | SW2  | Output                |
| ---- | ---- | --------------------- |
| LOW  | LOW  | Sine                  |
| LOW  | HIGH | Triangle              |
| HIGH | LOW  | Square                |
| HIGH | HIGH | High Frequency Square |

---

# Libraries Required

Install these libraries from Arduino Library Manager:

```bash
MD_AD9833
Adafruit GFX Library
Adafruit SH110X
```

---

# Installation

```bash
1. Clone the repository
2. Open the .ino file in Arduino IDE
3. Install required libraries
4. Select Arduino Nano board
5. Upload the code
```

---

# Code Overview

* `MD_AD9833` handles waveform generation
* `Adafruit_SH1106G` controls the OLED display
* Analog input from `A0` is sampled and plotted
* Potentiometer controls output frequency
* Push buttons switch waveform modes

---

# Frequency Range

Current configured range:

```cpp
0 Hz – 5000 Hz
```

Can be modified here:

```cpp
f = map(analogRead(FREQ_PIN), 0, 1023, 0, 5000);
```

---

# Preview

The OLED displays:

* Selected waveform type
* Current frequency
* Real-time waveform graph

---

# Future Improvements

* Better waveform scaling
* Trigger synchronization
* FFT analysis
* Battery-powered version
* Rotary encoder interface
* Higher sampling speed
* Custom PCB optimization

---

# Author

**Suraj Kalyanaraman**
Electronics and Instrumentation Engineering
VIT University

---

# License

This project is open-source and available for educational and personal use.
