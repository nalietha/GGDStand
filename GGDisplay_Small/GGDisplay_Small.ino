#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <FastLED.h>
#include <IRremote.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
SSD1306AsciiWire oled;

#define I2C_ADDRESS 0x3C  // I2C Address for the oled display

// Button pins 
const int nextButtonPin = 2; // Digital Pin 02 // LEFT BUTTON
const int selectButtonPin = 3; // Digital Pin 03 // RIGHT BUTTON

// LED pins and FAST LED inits
const int ledDataPin = 12; // Digital Pin 12

// Screen Inits values
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER

// LED Declartions
// TODO: Can this be made to detect how many led nodes are connected? 
#define NUM_LEDS 112
// ONLY CHANGE THIS VALUE THE REST IS CALCULATED WHEN USING JEWELS
// TODO: change the calcs to a changeable number, if more nodes are created 
  // i.e. The 6 led spin node in dev

CRGB leds[NUM_LEDS];

const byte ledNodes = (NUM_LEDS / 7);
byte ledNodeStatus[NUM_LEDS / 7];
/// ledColors is the array that stores what led is set to what color.  
byte ledColors[NUM_LEDS / 7];
/// ActiveLEDs is how many nodes are currently implemented. 
byte ActiveLEDs = NUM_LEDS / 7;

// Hall Effect Sensors data pin
byte hallPins = 7;
byte sensorStatus = 0;

// IR Remote 
#define IR_RECEIVE_PIN NULL

#define IR_REMOTE_1 69
#define IR_REMOTE_2 70
#define IR_REMOTE_3 71
#define IR_REMOTE_4 68
#define IR_REMOTE_5 64
#define IR_REMOTE_6 67
#define IR_REMOTE_7 7
#define IR_REMOTE_8 21
#define IR_REMOTE_9 9
#define IR_REMOTE_0 25
#define IR_REMOTE_HASH 13
#define IR_REMOTE_ASTX 22
#define IR_REMOTE_UP 24
#define IR_REMOTE_DOWN 82
#define IR_REMOTE_LEFT 8
#define IR_REMOTE_RIGHT 90
#define IR_REMOTE_OK 28


// Menu items
const char* menuItems[] = {"Mode", "Color", "Brightness", "Turn on All LEDs"};
const int menuItemsCount = sizeof(menuItems) / sizeof(menuItems[0]);
int currentMenuIndex = 0;
bool inMainMenu = false;

// Mode menu items
const char* modeItems[] = {"Cup Mode", "Turn on...", "Back"};
const int modeItemsCount = sizeof(modeItems) / sizeof(modeItems[0]);
int currentModeIndex = 0;
bool inModeMenu = false;

// Lighting Effects Menu


// Brightness levels
const int brightnessLevels[] = {0, 64, 128, 192, 255};
const char* brightnessLvlWords[] = {"Off","Low","Medium","High","Max", "Back"};
const int brightnessLevelsCount = sizeof(brightnessLevels) / sizeof(brightnessLevels[0]);
int currentBrightnessIndex = 0;
bool inBrightnessMenu = false;
byte ledBrightness = 64; // Default brightness


// Color selection
const char* colorOptions[] = {"Red", "Green", "Blue", "Yellow", "Purple", "Cyan", "White", "Back"};
const uint32_t colours[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Cyan, CRGB::White };
const int colorOptionsCount = sizeof(colorOptions) / sizeof(colorOptions[0]);
int currentColorIndex = 0;
bool inColorMenu = false;
bool inLedSelectionMenu = false;
int currentLedIndex = 0;

// Button states
bool nextButtonPressed = false;
bool selectButtonPressed = false;
unsigned long nextButtonPressTime = 0; // Used to calcuate a long press


bool cupMode = false;
bool stayOnLeds[NUM_LEDS / 7];
bool AllLightsOnFlag = false;



