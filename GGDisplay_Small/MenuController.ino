// void handleModeSelect() {
//   if (currentModeIndex == 0) { // Cup Mode
//     toggleCupMode();
//   } else if (currentModeIndex == 1) { // Turn on...
//     inLedSelectionMenu = true;
//     drawLedSelectionMenu();
//   } else if (currentModeIndex == modeItemsCount - 1) { // "Back" option
//     inModeMenu = false;
//     drawMenu();
//   }
//   delay(200); // Debounce delay
// }

void handleSelect() {
  if (inMainMenu) {
    if (currentMenuIndex == 0) {
      inMainMenu = false;
      inModeMenu = true;
      drawModeMenu();
    } else if (currentMenuIndex == 1) {
      inMainMenu = false;
      inBrightnessMenu = true;
      drawBrightnessMenu();
    } else if (currentMenuIndex == 2) {
      inMainMenu = false;
      inLedSelectionMenu = true;
      drawLedSelectionMenu();
    } else if (currentMenuIndex == 3) {
      turnOffAllLeds();
      drawMenu();
    }
  } else if (inModeMenu) {
    if (currentModeIndex == modeItemsCount - 1) { // Back
      inModeMenu = false;
      inMainMenu = true;
      drawMenu();
    } else if (currentModeIndex == 0) { // Cup Mode
      toggleCupMode();
    } else if (currentModeIndex == 1) { // Turn on...
      inModeMenu = false;
      inLedSelectionMenu = true;
      drawLedSelectionMenu();
    }
  } else if (inLedSelectionMenu) {
    if (currentLedIndex == ActiveLEDs) { // Back
      inLedSelectionMenu = false;
      inMainMenu = true;
      drawMenu();
    } else {
      inLedSelectionMenu = false;
      inColorMenu = true;
      drawColorMenu();
    }
  } else if (inColorMenu) {
    if (currentColorIndex == colorOptionsCount - 1) { // Back
      inColorMenu = false;
      inLedSelectionMenu = true;
      drawLedSelectionMenu();
    } else {
      setColor();
    }
  }
}

// Helper function to draw a menu with scrolling
void drawScrollableMenu(const char* header, const char* menuItems[], int itemCount, int currentIndex, int visibleItems) {
  oled.clear();
  oled.setCursor(0, 0);
  oled.println(header);
  oled.println();

  int startIndex = 0;
  int endIndex = visibleItems;

  if (currentIndex >= visibleItems - 1 && currentIndex < itemCount - 1) {
    startIndex = currentIndex - (visibleItems - 2);
    endIndex = startIndex + visibleItems;
  } else if (currentIndex >= itemCount - 1) {
    startIndex = itemCount - visibleItems;
    endIndex = itemCount;
  }

  for (int i = startIndex; i < endIndex; i++) {
    if (i == currentIndex) {
      oled.print("> ");  // Draw pointer
    } else {
      oled.print("  ");  // Empty space for alignment
    }
    oled.println(menuItems[i]);
  }
  //oled.display();



  
}

void drawMenu() {
  drawScrollableMenu("Main Menu", menuItems, menuItemsCount, currentMenuIndex, 4);
}

void drawModeMenu() {
  drawScrollableMenu("Mode Menu", modeItems, modeItemsCount, currentModeIndex, 4);
}

void drawBrightnessMenu() {
  static const char* brightnessMenuItems[] = {"Off","Low","Medium","High","Max", "Back"};
  drawScrollableMenu("Brightness", brightnessMenuItems, brightnessLevelsCount + 1, currentBrightnessIndex, 4);
}

void drawLedSelectionMenu() {
  static const char* ledSelectionMenuItems[] = {"LED 01", "LED 02", "LED 03", "LED 04","LED 05","LED 06","LED 07","LED 08","LED 09","LED 10","LED 11","LED 12","LED 13","LED 14","LED 15","LED 16" "Back"};
  drawScrollableMenu("Select LED", ledSelectionMenuItems, ActiveLEDs + 1, currentLedIndex, 4);
}

void drawColorMenu() {
  drawScrollableMenu("Select Color", colorOptions, colorOptionsCount, currentColorIndex, 4);
}


