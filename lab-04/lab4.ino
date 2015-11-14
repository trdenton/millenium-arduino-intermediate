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

    // TODO - Use the user input to control the motor.
    // If the user presses + increase the step size by 1.
    // If the user presses - decrease the step size by 1.
    // If the user presses R reset the position of the servo.
    // If the user presses F move the servo forward by the
    //    step size specified.
    // If the user presses B move the servo backwards by the
    //    step size specified.
  }
}
