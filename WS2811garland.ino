#include <Adafruit_NeoPixel.h>

#define PIN 11                // Pin connected to the NeoPixel strip
#define NUM_PIXELS 49         // Number of pixels in the strip (adjusted for the broken one)
#define BRIGHTNESS 64         // Brightness level (25% of max brightness)
#define PAUSE_DURATION 250    // Pause duration in milliseconds between updates

// Define colors using RGB format
const uint32_t COLORS[] = {
    strip.Color(255, 0, 0),    // Red
    strip.Color(0, 255, 0),    // Green
    strip.Color(255, 215, 0),  // Gold
    strip.Color(0, 0, 255)     // Blue
};

const int NUM_COLORS = sizeof(COLORS) / sizeof(COLORS[0]);  // Number of defined colors

Adafruit_NeoPixel strip(NUM_PIXELS, PIN, NEO_RGB + NEO_KHZ400);

// Array to store the current color index of each pixel
int pixelColors[NUM_PIXELS];

void setup() {
    strip.begin();
    strip.setBrightness(BRIGHTNESS);
    Serial.begin(9600);

    initializeStrip();
    strip.show();  // Display the initial configuration
}

void loop() {
    int pixelIndex = random(1, NUM_PIXELS - 1);  // Random pixel, excluding the first and last
    int newColorIndex = chooseNewColor(pixelIndex);

    Serial.printf("Updating pixel %d to color index %d\n", pixelIndex, newColorIndex);
    strip.setPixelColor(pixelIndex, COLORS[newColorIndex]);
    strip.show();

    pixelColors[pixelIndex] = newColorIndex;  // Update the color index
    delay(PAUSE_DURATION);
}

void initializeStrip() {
    int colorIndex = 0;

    for (int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, COLORS[colorIndex]);
        pixelColors[i] = colorIndex;
        Serial.printf("Setting pixel %d to color index %d\n", i, colorIndex);

        colorIndex = (colorIndex + 1) % NUM_COLORS;  // Cycle through the colors
    }
}

int chooseNewColor(int pixelIndex) {
    // Get adjacent and current pixel color indices
    int currentColor = pixelColors[pixelIndex];
    int prevColor = pixelColors[pixelIndex - 1];
    int nextColor = pixelColors[pixelIndex + 1];

    Serial.printf("Adjacent colors: Prev: %d, Current: %d, Next: %d\n", prevColor, currentColor, nextColor);

    // Determine valid new colors
    int availableColors[NUM_COLORS];
    int validColorCount = 0;

    for (int i = 0; i < NUM_COLORS; i++) {
        if (i != currentColor && i != prevColor && i != nextColor) {
            availableColors[validColorCount++] = i;
            Serial.printf("Adding color index %d to valid options\n", i);
        }
    }

    if (validColorCount == 0) {
        Serial.println("No valid colors found; falling back to the current color.");
        return currentColor;  // Fallback if no valid colors found (unlikely in this setup)
    }

    // Select a random valid color
    int selectedColor = availableColors[random(validColorCount)];
    return selectedColor;
}
