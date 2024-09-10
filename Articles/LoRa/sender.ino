/*
* That script has been written and tested in december 2017.
* The script has not been reviewed since.
*/

#include <Keyboard.h>               // Need only to get the standard values of keyboard keys.
                                    // This will be used for a future needs
#include <SPI.h>                    // I2C
#include <Wire.h>                   // I2C
#include <Adafruit_GFX.h>           // OLED
#include <Adafruit_SSD1306.h>       // OLED
#include <RH_RF95.h>                // LoRa Radio

/*
 * Creating objects
 */

Adafruit_SSD1306 display;

/* 
 * Joystick Pin
*/
#define JX A1                       // Axe X
#define JY A0                       // Sxe Y
#define JS 13
bool snap = false;

#define MIN_PULSE 13                // Min value when the jostick it top or left
#define MAX_PULSE 1012              // Max value when the jostick it top or left

/*
 * Radio
 */
// Define pin for feather m0
#define RFM95_CS 5
#define RFM95_RST 6
#define RFM95_INT 10

#define SENT "Sent"
#define NOLISTNER "No listner"
#define FAILED "Sent failed"

#define SRFMLEN 20
char srfm[SRFMLEN];               // Variable used to send value with SRM95

int16_t packetnum = 0;            // packet counter, we increment per xmission
#define RF95_FREQ 868.0           // Change to 434.0 or other frequency, must match RX's freq!
RH_RF95 rf95(RFM95_CS, RFM95_INT);// Singleton instance of the radio driver

struct { // Joystick axis structure (2 axes per stick):
  int8_t  pin;                    // Analog pin where stick axis is connected
  int     lower;                  // Typical value in left/upper position
  int     upper;                  // Typical value in right/lower positionax

  uint8_t key1;                   // Key code to send when left/up
  uint8_t key2;                   // Key code to send when down/right
  int     value;                  // Last-read-and-mapped value (0-1023)
  int8_t  state;
} axis[] = {
  
  {A0, MAX_PULSE, MIN_PULSE, KEY_UP_ARROW, KEY_DOWN_ARROW },        // Y axis // Need #include <Keyboard.h>
  {A1, MIN_PULSE, MAX_PULSE, KEY_LEFT_ARROW  , KEY_RIGHT_ARROW  },  // X axis // Need #include <Keyboard.h>
};
#define N_AXES (sizeof(axis) / sizeof(axis[0]))

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    //Serial1.begin(9600);

     /*
     * Init the display
     */
     // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
    // init done
    display.display();                          
    delay(1000);
    // Clear the buffer.
    display.clearDisplay();                     // Clear buffer

    display.setTextColor(WHITE);              
    display.setCursor(0,0);                   
    display.println("Welcome");
    display.println("aboard SmartIdea!");       // Text to be printed
    display.display();                          // Print "Welcome aboard SametIdea!" to the LCD

    delay(9000);                                // Wait 9s (not mandatory).
    
    Serial.println(F("\r\n******************************************"), 0); // SD is not initiate yet, must be 0
    Serial.println(F("*        smart-idea.io LoRa              *"), 0);
    Serial.println(F("*               Josytick                 *"), 0);
    Serial.println(F("******************************************\r\n"), 0);
    
    Si.begin();                                 // Starting SD card as well
    
    analogReadResolution(10);                   // Sets the size (in bits) of the value returned by analogRead()
    Serial.println(F("analogReference()"),2);
    analogReference(AR_EXTERNAL);               // See https://learn.adafruit.com/adafruit-feather-m0-adalogger/adapting-sketches-to-m0#analog-references

    pinMode(JX, INPUT_PULLUP);                  // See https://learn.adafruit.com/adafruit-feather-m0-adalogger/adapting-sketches-to-m0#pin-outputs-and-pullups
    pinMode(JY, INPUT_PULLUP);
    pinMode(JS, INPUT_PULLUP);

    
    /*
    * Init LoRa / Radio
    */
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);
    while (!rf95.init()) {
      Serial.println(F("LoRa radio init failed"),2);
      
      display.print("LoRa radio init failed");
      display.display();
      //display.clearDisplay();
      while (1);
    }
    Serial.println(F("LoRa radio init OK!"),2);
    //display.setCursor(0,0);
    display.print("Radio ready");                  // Prepare text to be pinted on LCD
    
  // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
  // We need 868.0Mhz for Europe
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println(F("setFrequency failed"),2);
    while (1);
  }
  Serial.print(F("Freq at  "),2); Serial.println(RF95_FREQ,2);
  
  display.print(" ");                             // Prepare text to be pinted on LCD
  display.print(RF95_FREQ);                       // Prepare text to be pinted on LCD
  display.println("Mhz");                         // Prepare text to be pinted on LCD
  display.display();                              // Dipslay on lCD
  display.clearDisplay();                         // Clear cache
  delay(2000);                                    // Wait 2sec
 

  /*
  * Joystick 
  */

  display.setCursor(0,0);                          // Move cursor
  display.println("Init Joystick");                // Prepare text
   // Initialize joystick state...
  for(int i=0; i<N_AXES; i++)
  {
    /*
     * Somewhere,I commented to keep the original
     */
      //int value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, 0, 1023);
      int value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, MIN_PULSE, MAX_PULSE);
      //if(value > (1023 * 4 / 5))
      if(value > (MAX_PULSE * 4 / 5))
      {
        //Keyboard.press(axis[i].key2);
        axis[i].state =  1;
      }
      //else if(value < (1023 / 5))
      else if(value < (MAX_PULSE / 5))
      {
        //Keyboard.press(axis[i].key1);        
        axis[i].state = -1;
      }
      else
      {
        axis[i].state = 0;
      }
    }

    display.println("Running up now!");         // prepare tex
    display.display();                          // Show the text in LCD devise
    display.clearDisplay();
    Serial.println(F("Ready to go now!!\n"),2);
}


void loop() {
  
  int i,value;
  int r = -2;
   
  /*
  * // Read joystick axes
  * KEY_UP_ARROW:     // 0xDA =218
  * KEY_RIGHT_ARROW:  // 0xD7 =215
  * KEY_DOWN_ARROW:   // 0xD9 =217
  * KEY_LEFT_ARROW:   // 0xD8 =216
  */

   // Define ehat we do, when the joystick is pressed
   if(digitalRead(JS)== LOW){
      if(!snap)
      {
        snap = true;
        display.setCursor(20,10);
        Serial.println(F("Snap snap"),2);
        display.println("Snap snap!");
        display.display();
        
        /*
         * Radio
         */
        memset(srfm,'\0',SRFMLEN);        // Clean the buffer srfm
        sprintf(srfm,"snap");             // Copy into srfm
        r = send_rf95(srfm);              // Send the vlaue of srfm
        if(r == 1)
          display.println(SENT);          // Prepare the text to be displayed
        else if(r == 0)
          display.println(NOLISTNER);
        else if(r == -1)
          display.println(FAILED);
        display.display();
        display.clearDisplay();
      }
   }
   else
   {
    snap = false;
   }

  /*
  * Read joystick axes
  */
  #ifdef TRY                      // If you  want to debug the Output of X (Xout) and Y (Yout) of the Joystick
    // DEBUG                      // add the line #define TRY, at the top of the file
    delay(500);                   
    char angle[6];                // Initiate variable
    int angle_x;
    int angle_y;
    int prevAngle_x;
    int prevAngle_y;
    delay(10);
    /*
     * Axe X
     */
    int xx = analogRead(JX);      // Read X values
    Serial.print("x=>");
    Serial.print(xx);
    Serial.print("(");
    
    angle_x = map(xx,MAX_PULSE,MIN_PULSE,0,180);  // Calculate the anlge in °
    
    Serial.print(angle_x);
    Serial.print("°)");
    Serial.print(":");
    
    /*
     * Axe Y
     */
    int yy = analogRead(JY);
    Serial.print("y=>");
    Serial.print(yy);
    Serial.print("(");
    angle_y = map(yy,MAX_PULSE,MIN_PULSE,0,180);
    prevAngle_y = angle_y;
    Serial.print(angle_y);
    Serial.println("°)");

    
  #else
    
    
    for(i=0; i<N_AXES; i++)
    {
      //value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, 0, 1023);
      value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, MIN_PULSE, MAX_PULSE); 
    
      if(axis[i].state == 1)                // Axis previously down/right? 
      {  
        //if(value < (1023 * 3 / 5))
        if(value < (MAX_PULSE * 3 / 5))     // Moved up/left past hysteresis threshold?
        {      
        //Keyboard.release(axis[i].key2);   // Release corresponding key
        Serial.print(F("Released "),2);
        display.setCursor(0,0);
        display.print("Released ");
        
        switch(axis[i].key2){
          case KEY_DOWN_ARROW:
            Serial.println(F("Down!"),2);
            display.println("Down");
            display.display();
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value rdown (released Down) to the receiver module
             */
            sprintf(srfm,"rdown");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          case KEY_RIGHT_ARROW:
            Serial.println(F("Right!"),2);
            display.println("Right");
            display.display();
            memset(srfm,'\0',SRFMLEN);
             /*
             * Radio LoRa: Send the value rright (Release right) to the receiver module
             */
            sprintf(srfm,"rright");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          default:
            Serial.println(F("Error 1!"),2);
            display.println("Error 1!");
            display.display();
            memset(srfm,'\0',SRFMLEN);
            sprintf(srfm,"error1");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
        }
        display.clearDisplay();
        axis[i].state = 0;              // The Joystick is back to is central position
      }
    } 
    else if(axis[i].state == -1)
    {    // Else axis previously up/left?
      //if(value > (1023 * 2 / 5))
      if(value > (MAX_PULSE * 2 / 5))   // Moved down/right past hysteresis threshold?
      {      
       //Keyboard.release(axis[i].key1); // Release corresponding key
        Serial.print(F("Released "),2);
        display.setCursor(0,0);
        display.print("Released ");        

        switch(axis[i].key1){
          case KEY_UP_ARROW:
            Serial.println(F("UP!"),2);
            display.println("UP");
            display.display();
            // Send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value rup (Release up) to the receiver module
             */
            sprintf(srfm,"rup");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          case KEY_LEFT_ARROW:
            Serial.println(F("Left!"),2);
            display.println("Left");
            display.display();
            //send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value rleft (Release left) to the receiver module
             */
            sprintf(srfm,"rleft");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          default:
            Serial.println(F("Error 2!"),2);
            display.println("Error 2!");
            display.display();
            //Send
            memset(srfm,'\0',SRFMLEN);
            sprintf(srfm,"error2");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
        }
        display.clearDisplay();
        axis[i].state = 0;              // and set state to neutral center zone
      }
    } // This is intentionally NOT an 'else' -- state CAN change twice here!

    if(!axis[i].state)
    {                // Axis previously in neutral center zone?
      //if(value > (1023 * 4 / 5))
      if(value > (MAX_PULSE * 4 / 5))
      {
        //Keyboard.press(axis[i].key2);   // Press corresponding key
        Serial.print(F("Pressed "),2);
        display.setCursor(0,0);
        display.print("Pressed ");
        switch(axis[i].key2){
          case KEY_DOWN_ARROW:
            Serial.println(F("Down!"),2);
            display.println("Down");
            display.display();
            //send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value down (Move down) to the receiver module
             */
            sprintf(srfm,"down");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          case KEY_RIGHT_ARROW:
            Serial.println(F("Right!"),2);
            display.println("Right");
            display.display();
            // send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value right (Move right) to the receiver module
             */
            sprintf(srfm,"right");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          default:
            Serial.println(F("Error 3!"),2);
            display.println("Error 3!");
            display.display();
            // Send
            memset(srfm,'\0',SRFMLEN);
            sprintf(srfm,"error3");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
        }
        display.clearDisplay();
        axis[i].state = 1;              // and set state to down/right
      }
      //else if(value < (1023 / 5))
      else if(value < (MAX_PULSE / 5))
      {   // Else axis moved up/left?
        //Keyboard.press(axis[i].key1);   // Press corresponding key
        Serial.print(F("Pressed "),2);
        display.setCursor(0,0);
        display.print("Pressed ");
        //Serial.println(axis[i].key1);
        switch(axis[i].key1){
          case KEY_UP_ARROW:
            Serial.println(F("UP!"),2);
            display.println("UP");
            display.display();
            // send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value up (Move up) to the receiver module
             */
            sprintf(srfm,"up");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          case KEY_LEFT_ARROW:
            Serial.println(F("Left!"),2);
            display.println("Left");
            display.display();
            // send
            memset(srfm,'\0',SRFMLEN);
            /*
             * Radio LoRa: Send the value left (Move left) to the receiver module
             */
            sprintf(srfm,"left");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
          break;
          default:
            Serial.println(F("Error 4!"),2);
            display.println("Error 4!");
            display.display();
            // Send
            memset(srfm,'\0',SRFMLEN);
            sprintf(srfm,"error4");
            r = send_rf95(srfm);
            if(r == 1)
              display.println(SENT);
            else if(r == 0)
              display.println(NOLISTNER);
            else if(r == -1)
              display.println(FAILED);
            display.display();
        }
        display.clearDisplay();
        axis[i].state = -1;             // and set state to up/left
      }
    }
    axis[i].value = value; // Save for later
  }
  #endif
 
}

int send_rf95(char* val)
{
  int16_t cx = display.getCursorX();
  int16_t cy = display.getCursorY();
  display.setCursor(100,0);
  display.print("Tx");              // Display a Tx while sending
  display.display();
  
  int result = -2;
  Serial.print(F("\tData: "),2);
  Serial.println(val,2);
  // itoa(packetnum++, val + strlen(val), 10);          // No need for me to add sum of packet
  //Serial.print("Sending "); Serial.println(radiopacket);
  val[strlen(val)] = '\0';
  
  Serial.print(F("\tSending "),2); 
  Serial.print(val,2);
  Serial.println(F(" ..."),2);
  delay(10);
  /*
   * Sending
   */
  rf95.send((uint8_t *)val, 20);

  Serial.println(F("\tWaiting for packet to complete..."),2);
  delay(10);
  rf95.waitPacketSent();
  // Now wait for a reply
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  //uint8_t len = strlen(buf); // for testing test

  Serial.println(F("\tWaiting for reply..."),2);
  delay(10);
  if (rf95.waitAvailableTimeout(1000))
  {
    
    if (rf95.recv(buf, &len))           // If the reviever get the data, it should
    {                                   // send and aknowlegment
      Serial.print(F("\tReply: "),2);
      Serial.println((char*)buf,2);        // Content of the akn
      Serial.print(F("\tRSSI: "),2);
      Serial.print(rf95.lastRssi(), DEC,2);// RSSI
      Serial.println("",2);
      result = 1;
    }
    else
    {
      Serial.println(F("\tReceive failed"),2);
      result = -1;
    }
  }
  else
  {
    // No reply
    Serial.println(F("\tIs there a listener around?"),2);
    result = 0;
  }
  //delay(1000);
  display.setCursor(100,0);
  display.print("--");          // Trace the Tx
  display.display();
  display.setCursor(cx,cy);     // Put back the cursor at it previous state
  return result;
}