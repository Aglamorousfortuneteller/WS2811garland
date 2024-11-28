# NeoPixel Color Animation

This project demonstrates how to control an Adafruit NeoPixel strip to create a dynamic color animation. The code initializes a strip of RGB LEDs, assigns alternating colors to the LEDs, and then updates the colors randomly while avoiding repetition or adjacent matching colors.

---

## Features

- **Dynamic Color Animation:** Randomly changes the colors of the NeoPixel LEDs.
- **Color Restrictions:** Ensures no adjacent LEDs have the same color.
- **Brightness Control:** Adjusts brightness to 25% of the maximum for comfortable viewing.
- **Debugging Outputs:** Provides detailed debugging messages via the serial monitor.

---

## Hardware Requirements

- [Adafruit NeoPixel](https://www.adafruit.com/category/168) LED strip with at least 49 LEDs.
- Arduino-compatible microcontroller.
- Power supply appropriate for the number of LEDs.
- Jumper wires and connectors as needed.

---

## Software Requirements

- Arduino IDE (version 1.8.0 or later recommended).
- [Adafruit NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel).

---

## Setup

1. Connect the NeoPixel strip to your microcontroller:
   - **DIN (Data Input):** Pin 11 (adjustable in the code).
   - **5V:** Power source.
   - **GND:** Common ground.

2. Open the code in the Arduino IDE.

3. Install the Adafruit NeoPixel Library if not already installed:
   - In the Arduino IDE, go to `Sketch -> Include Library -> Manage Libraries`.
   - Search for "Adafruit NeoPixel" and install it.

4. Upload the code to your Arduino.

5. Open the Serial Monitor (`Ctrl+Shift+M`) at a baud rate of 9600 to view debugging messages.

---

## Configuration

### Adjustable Parameters
- `PIN`: The microcontroller pin connected to the NeoPixel data input.
- `NUM_PIXELS`: Number of LEDs in the strip (set to 49; adjust as needed).
- `BRIGHTNESS`: Brightness level of the LEDs (0–255, currently set to 64 for 25% brightness).
- `PAUSE_DURATION`: Time in milliseconds between updates (default: 250 ms).

---

## How It Works

1. **Initialization:**
   - The strip is initialized with alternating colors (red, green, gold, blue).

2. **Animation Loop:**
   - A random LED is selected.
   - A new color is chosen for the LED, ensuring it is different from its neighbors and its current color.
   - The LED's color is updated, and the strip is refreshed.

3. **Debugging:**
   - The Serial Monitor outputs details about the pixel updates and color selection process.

---

## Example Output

When running, you will see messages like the following in the Serial Monitor:



---

## Acknowledgments

This project is inspired in part by the code and ideas from [geekquixotic's Holiday Garland](https://github.com/geekquixotic/holidaygarland).
