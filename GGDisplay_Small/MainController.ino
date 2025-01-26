
void setup() {
  // Initialize display
  Serial.begin(9600);
  Wire.begin();
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);

  // Initialize buttons
  pinMode(nextButtonPin, INPUT_PULLUP);
  pinMode(selectButtonPin, INPUT_PULLUP);

  // Initialize LED pins
  pinMode(ledDataPin, OUTPUT);
  FastLED.addLeds<WS2812B, ledDataPin, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(ledBrightness);

  // Make sure the user starts in the main menu:: 
  // Start up spash screen will replace this
  inMainMenu = true;
  //startSplashScreen();

  // Draw the initial menu
  IrReceiver.begin(IR_RECEIVE_PIN);

  drawMenu();

}

void loop() {

  // Read button states
  nextButtonPressed = digitalRead(nextButtonPin);
  selectButtonPressed = digitalRead(selectButtonPin);
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    //remoteController(decodedIRData.command);
  }
  if (nextButtonPressed) {
    // handleNext();
  }

  if (selectButtonPressed) {
    handleSelect();
  }

  // Progresses any lights that have effects
  // RotateNodes();
}


// void remoteController(int IRInput)
// {
//   /*
//   Remote :: Code


//   */



//   switch(IRInput)
//   {
//     case IR_REMOTE_UP:  // Up

//       break;
//     case IR_REMOTE_RIGHT:  // Right

//       break;
//     case IR_REMOTE_DOWN:  // Down

//       break;
//     case IR_REMOTE_LEFT:  //Left

//       break;

//     case IR_REMOTE_OK:

//       break;
//     case IR_REMOTE_HASH:
//       //toggleLights();

//     case IR_REMOTE_ASTX:
//       //toggleLightingControl();
//       break;

//     // Lighting effects when the numbers are pressed.
//     // Only if the lighting control mode is not on

//     default:
//       break;
//   }
// }





/// Tests the HE sensor given by the testing loop using the multiplexer. 
/// There are 4 groups of 4 
/// 

// bool areHESensorActive(byte SensorNbr)
// {

//   sensorStatus = digitalRead();
//   if( sensorStatus == 1) 
//   {
//     if(ledNodeStatus[ledNbr] == 1)
//       turnOffLed(ledNbr);
//   }
//   else
//   {
//     if(ledNodeStatus[ledNbr] == 0)
//       turnOnLed(ledNbr);
//   }



//   return false;
// }


