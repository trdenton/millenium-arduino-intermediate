/***
 * Millenium Library - Arduino Workshop
 * 
 * TITLE:        Example #4
 * DESCRIPTION:  Using a Servo
 * AUTHOR:       Dario Schor (schor@ieee.org)
 * DATE:         November 14,2015
 *
 * This example uses the Servo librady from:
 * http://www.arduino.cc/en/Reference/Servo
 *
 **/ 

 // Include Servo library
 #include <Servo.h>

// Define the pin where the servo is connected
#define SERVO_PIN  3

// Variable stores current servo position. 
int servoPosition = 0;

// Create instance of Serve object
Servo myServo;


/***
 * setup()
 * Description:  Initialize the Servo and Serial monitor.
 **/
void setup()
{
  // Serial interface to print the current angle.
  Serial.begin(9600);
  
  // Attach the servo to the desired pin.
  myServo.attach(SERVO_PIN);

  // Set the current angle as the intial position.
  myServo.write(0);

  // Print initial angle for the servo motor.
  servoPosition = myServo.read();
  Serial.print("Initial angle: ");
  Serial.println(servoPosition);
}

/***
 * loop()
 * Description:  Rotate servo 30 degrees every 3 seconds.
 **/
void loop()
{
  // Update the servo position.
  servoPosition = servoPosition + 30;
  if(servoPosition > 360) 
  {
    servoPosition = 0;
  }

  // Print the new angle
  Serial.print("New angle: ");
  Serial.println(servoPosition);

  // On a standard servo, this will set the angle 
  // of the shaft (in degrees), moving the shaft 
  // to that orientation.
  myServo.write(servoPosition);

  // Delay 3 seconds between movements.
  delay(3000);
}
