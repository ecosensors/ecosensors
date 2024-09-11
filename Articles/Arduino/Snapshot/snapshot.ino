#include <Adafruit_VC0706.h> // https://github.com/adafruit/Adafruit-VC0706-Serial-Camera-Library
#include <SPI.h>
#include <SD.h>

/*
* Motion
*/
#define PIR_PIN 12 // Pin definition for the signal
#define LED 13 // Pin definition for the LED
//#define CAMERA_MOTION // To activate or not the Camera detection

/*
* SD
*/
#define chipSelect 4

setup(){
	Serial.begin(115200);
	Serial1.begin(115200);

	pinMode(PIR_PIN,INPUT_PULLUP); // Define the pin as Input
	digitalWrite(PIR_PIN,LOW); // Put to LOW pinMode(PIR_PIN,INPUT_PULLUP); // Define the pin as Input

	pinMode(LED,OUTPUT); // Define as Input
	digitalWrite(LED,LOW); // Put to low

	if (!SD.begin(chipSelect)) // see if the card is present and can be initialized:
	{ 
		Serial.println(F("Card failed, or not present"),0);
 		// don't do anything more:
 		while(1); // Do not continue
	} 
 
	if (cam.begin()){ // Try to locate the camera
		Serial.println(F("Camera Found:"),0);
	} 
	else
	{
		Serial.println(F("No camera found?"),0); 
 		while(1); // No, Do not continue
	}

	/*
	* Get the version of the Camera
	*/
	char *reply = cam.getVersion(); // Print out the camera version information
	if (reply == 0)
	{
		Serial.print(F("Failed to get version"),0);
	}
	else
	{
		Serial.print(F("Cam version: "),0);
 		Serial.println(reply,0);
	}

	// Set the picture size - you can choose one of 640x480, 320x240 or 160x120 
	// Remember that bigger pictures take longer to transmit!
 
	//cam.setImageSize(VC0706_640x480); // biggest
	cam.setImageSize(VC0706_320x240); // medium
	//cam.setImageSize(VC0706_160x120); // small

	// You can read the size back from the camera (optional, but maybe useful?)
	uint8_t imgsize = cam.getImageSize();
	Serial.print(F("Image size: "));
	if (imgsize == VC0706_640x480) Serial.println("640x480");
	if (imgsize == VC0706_320x240) Serial.println("320x240");
	if (imgsize == VC0706_160x120) Serial.println("160x120")


	#ifdef CAMERA_MOTION  // If defined or commented
		// Motion detection system can alert you when the camera 'sees' motion!
 		cam.setMotionDetect(true); // turn it on
 	#else
 		cam.setMotionDetect(false); // turn it off (default)
 	#endif
 
 	// You can also verify whether motion detection is active!
 	Serial.print("Camera Motion detection is ");
 	if (cam.getMotionDetect()) 
 	{
 		Serial.println("ON");
 	}
 	else 
 	{
 		Serial.println("OFF");
 		Serial.println("PIR sensor ON");
 		snap(); // Take a snap (Can be commented)
 	}

}

void loop(){
	// Use the MOTION of the camera
	#ifdef CAMERA_MOTION // IF camera is set to act as MOTION (NO PIR detector)
 		if (cam.motionDetected()) // If the camera detect a motion
 		{
 			Serial.println("Motion!"); 
 			cam.setMotionDetect(false); // Turn off the functionnality
 			snap(); // Take a picture and save it
 			cam.resumeVideo();
 			cam.setMotionDetect(true); // Turn on the functionnality
 		}
 	// Use the PIR sensor
 	#else
 		if(isPIRMotionDetected()==true) // Call the function isPIRMotionDetected which will
 		{ 								// will return true if the PIR sensor detect a movement
 			Serial.println("PIR!"); 
 			snap(); // take a picture and save it
 		}
 	#endif
}

boolean isPIRMotionDetected()
{
	int sensorValue = digitalRead(PIR_PIN); // Read if PIR_PIN is HIGH or LOW
	//Serial.print("SensorValue:"); Serial.println(sensorValue);
 
 	if(sensorValue == HIGH) // if the sensor value is HIGH?
 	{
 		Serial.println(F("\r\nMotition detected!!"),0);
 		digitalWrite(PIR_LED,HIGH);
 		delay(500);
 		digitalWrite(PIR_LED,LOW);
 		return true; // yes,return true
 	}
 	else
 	{
 		return false; // no,return false
 	}
}

void snap()
{
	if (! cam.takePicture())
 	{
 		Serial.println(F("Failed to snap!"),0);
 	}
 	else 
 	{
 		Serial.println(F("Picture taken!"),0);

		// Create an image with the name IMAGExx.JPG
 		// Increment the file name if it exists
 		char filename[13];
 		strcpy(filename, "IMAGE00.JPG");
 		for (int i = 0; i < 100; i++) {
 		filename[5] = '0' + i/10;
 		filename[6] = '0' + i%10;
 		
 		// create if does not exist, do not open existing, write, sync after write
 		if (! SD.exists(filename))
 		{
 			break;
 		}
 	}
 
 	File imgFile = SD.open(filename, FILE_WRITE); 	// Open the created file for writing 
 	uint16_t jpglen = cam.frameLength(); 			// Get the size of the image (frame) taken 
	Serial.print(F("Storing "),0);
 	Serial.print(jpglen, DEC,0);
 	Serial.print(F(" byte image in "),0);
 	Serial.println(filename,0);
 
 	int32_t time = millis(); 						// Init the time for save the image
 
 	byte wCount = 0; 								// Read all the data up to # bytes!
 	while (jpglen > 0) 								// For counting # of writes
 	{ 
 		uint8_t *buffer;
 		uint8_t bytesToRead = min(64 , jpglen); 	// change 32 to 64 for a speedup but may not work with all setups!
 		buffer = cam.readPicture(bytesToRead);
 		imgFile.write(buffer, bytesToRead);
 
 													// Every 2K, give a little feedback so it doesn't appear locked up
 		if(++wCount >= 64)
 		{
 			Serial.print(F("."),0);
 			wCount = 0;
 		}
 
 		//Serial.print("Read "); Serial.print(bytesToRead, DEC); Serial.println(" bytes");
 		jpglen -= bytesToRead;
 	}
 	
 	imgFile.close(); // Close the file

	time = millis() - time; 						// Print the elasped time while saving the image
 	Serial.println(F("\r\ndone!"),0);
 	Serial.print(time); Si.sprintln(F(" ms elapsed"),0);
}