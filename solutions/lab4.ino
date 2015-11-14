/***
 * Millenium Library - Arduino Workshop
 * 
 * TITLE:        Lab #4
 * DESCRIPTION:  Servo Controls
 * AUTHOR:       Dario Schor (schor@ieee.org)
 * DATE:         November 14,2015
 *
 * This example uses the Servo librady from:
 * http://www.arduino.cc/en/Reference/Servo
 *
 * Use the serial console to enter instructions that 
 * control the servo operations. 
 *
 * The user will control the step size (in degrees)
 * and when to move forward/backwards or reset. 
 *
 * The following keys are used for controlling the 
 * operations of the servo:
 *   + Increases the step size by 1, but does not 
 *     change the servo position.
 *   - Decreases the step size by 1, but does not
 *     change the servo position.
 *   F Adds the step size to the current position and 
 *     moves the motor.
 *   B Subtracts the step size to the current position  
 *     and moves the motor.
 *   R Reset the servo position.
 *   All other keys are invalid.
 * 
 **/ 

#include <Servo.h>

//Servo Control variables
#define SERVO_PIN 3

// Define characters for controlling servo
#define INCREASE_STEP_SIZE       '+'
#define DECREASE_STEP_SIZE       '-'
#define MOVE_FORWARD             'F'
#define MOVE_BACKWARD            'B'
#define RESET_POSITION           'R'

// Variable stores current servo position. 
int currStepSize      = 1;
int currServoPosition = 0;

// Create instance of Servo object
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

  // Set the servo to the initial position. 
  myServo.write(0);

  // Print initial angle for the servo motor.
  Serial.print("Initial angle: ");
  Serial.println(myServo.read());
}


/***
 * loop()
 * Description:  Rotate servo 30 degrees every 3 seconds.
 **/
void loop()
{
  // Record the user input
  int  userInput = 0;

  // Track whether to move the servo or not.
  bool moveServo = false;

  // If there is user input available. 
  if(Serial.available())
  {
    // Read the input from the user.
    userInput = Serial.read();

    switch(userInput)
    {
      // Increase the step size by 1. 
      // Limit to 179 as that is the max for the servo.
      case INCREASE_STEP_SIZE:
        if(currStepSize + 1 <= 179)
        {
          currStepSize = currStepSize + 1;
        }
        Serial.print("Step size: ");
        Serial.println(currStepSize);
        break;  

      // Decrease the step size by 1. 
      // Limit to 0 as that is the min for the servo.
      case DECREASE_STEP_SIZE:
        if(currStepSize - 1 >= 0)
        {
          currStepSize = currStepSize - 1;
        }
        Serial.print("Step size: ");
        Serial.println(currStepSize);
        break;

      // Move the servo forward.
      case MOVE_FORWARD:
        currServoPosition = currServoPosition + currStepSize;
        if (currServoPosition > 179)
        {
          currServoPosition = 179;
        }
        moveServo = true;
        break;

      // Move the servo backwards.
      case MOVE_BACKWARD:
        currServoPosition = currServoPosition - currStepSize;
        if (currServoPosition < 0)
        {
          currServoPosition = 0;
        }
        moveServo = true;
        break;

      // Reset the servo position.
      case RESET_POSITION:
        currServoPosition = 0;
        moveServo = true;
        break;
    }

    // If the user command included a movement, then
    // update the servo position.
    if(moveServo == true)
    {
      Serial.print("Position: ");
      Serial.println(currServoPosition);
      myServo.write(currServoPosition);
    }
  }
}
