void updateBrightness() {
  // Set the LED brightness
  FastLED.setBrightness(brightnessLevels[currentBrightnessIndex]);
  FastLED.show();
}

void setColor() {
  // Implement color setting based on currentColorIndex

  ledColors[currentLedIndex] = currentColorIndex;
  turnOnLed(currentLedIndex);

}

void turnOffLed(int inputLed)
{
  // Set the pin that was read off, off.
  // 
  for(int setLeds = inputLed * 7; setLeds < (inputLed * 7) + 7; setLeds++ )
  {
    leds[setLeds] = CRGB::Black; 

    ledNodeStatus[inputLed] = 0;
    AllLightsOnFlag = false;
  }
  FastLED.show();
  delay(250);
}

void turnOnLed(int inputLed)
{
    for(int setLeds = inputLed * 7; setLeds < (inputLed * 7) + 7; setLeds++ )
    {
      //TODO: FIX: Will -1 to the color fix the issue with the lights not being the right color upon selection.
      //leds[setLeds] = colours[ledColors[inputLed] - 1];
      // Demo Modes Manually Change Colors 

      if(inputLed == 0) leds[setLeds] = CRGB::Red;
      if(inputLed == 1) leds[setLeds] = CRGB::Pink;
      if(inputLed == 2) leds[setLeds] = CRGB::Gold;
      if(inputLed == 3) leds[setLeds] = CRGB::Cyan;
      if(inputLed == 4) leds[setLeds] = CRGB::Blue;
      if(inputLed == 5) leds[setLeds] = CRGB::Pink;



      //Set led node status to on
      ledNodeStatus[inputLed] = 1;
    }
    FastLED.show();
    delay(250);
}

// Function to handle the Cup Mode selection
void toggleCupMode() {
  static bool cupModeOn = false;

  cupModeOn = !cupModeOn; // Toggle the state of Cup Mode
  if (cupMode)
  {
  // Set all LEDs based on the current state of Cup Mode
    for (int i = 0; i < ActiveLEDs; i++) {
      turnOnLed(i);
      stayOnLeds[i] = 1;
    }
  }
  else {
    // Clear all Leds stay on flag, but dont force shut off
    for (int i = 0; i < ActiveLEDs; i++) {
      stayOnLeds[i] = 0;
    }
  }
}

void turnOffAllLeds() {
  for (int i = 0; i < ActiveLEDs; i++) {
    turnOffLed(i);
  }
}

void toggleLed() {

  // Toggle the state of the selected LED
  stayOnLeds[currentLedIndex] = !stayOnLeds[currentLedIndex];

  stayOnLeds[currentLedIndex] ? turnOnLed(currentLedIndex) : turnOffLed(currentLedIndex);

}

void RotateNodes()
{
  // Get Nodes that have an effect

  // Get Effect Number

  // What stage of Effect
return;
  // Apply next effect
}






