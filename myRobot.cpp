#include "WPILib.h"

/**
 * FRC Robot Team #4930 The Electric Mayhem
 * @link www.nicholsrobotics.org
 * @uses WindRiver FRC SimpleRobot Class
 * @goal (1) Initalize motors and two joysticks.
 * @goal (2) Drive robot using Tank Drive
 * @goal (3) Move robot forwad during autonomous mode.
 * @goal (4) Get C++ code compiled and running on the 2013 robot's cRIO.
 * @author Jon Kiddy
 * @version 0.0.2 2014-02-01
 */ 
class Robot4930 : public SimpleRobot
{
	// Initilize robot drive system.
	RobotDrive robotChasis;
	
	// Initilize right joystick on gamepad.
	Joystick rightStick;
	
	// Initilize left joystick on gamepad.
	Joystick leftStick;

public:
	Robot4930():
		// Initialization List
		robotChasis(1, 2),
		rightStick(1),
		leftStick(2)
	{
		robotChasis.SetExpiration(0.1);
		robotChasis.SetInvertedMotor(robotChasis.kRearLeftMotor, true);
		robotChasis.SetInvertedMotor(robotChasis.kRearRightMotor, true);
		robotChasis.SetInvertedMotor(robotChasis.kFrontLeftMotor, true);
		robotChasis.SetInvertedMotor(robotChasis.kFrontRightMotor, true);
	}

	/**
	 * Autonomous
	 * @goal Drive forward half speed for two seconds then stop.
	 */
	void Autonomous()
	{
		robotChasis.SetSafetyEnabled(false);
		
		// Drive forward.
		robotChasis.TankDrive(0.5, 0.5);
		
		// Wait two seconds.
		Wait(2.0);
		
		// Stop the robot.
		robotChasis.Drive(0.0, 0.0);
	}

	/**
	 * Operator Control
	 * @goal Setup motors to be controlled by joystick in Tank Drive mode.
	 * @note The wait command is in place to allow other asynchronous threads the time to run.
	 * @note 5 ms delay won't effect performance since Driver Station updates are sent at 20 ms intervals.
	 */
	void OperatorControl()
	{
		robotChasis.SetSafetyEnabled(true);
		
		// The Field & Driver Station control this variable.
		while (IsOperatorControl())
		{
			// Robot driving is handed over to the Drive Station Operator.
			robotChasis.TankDrive(leftStick.GetY(), rightStick.GetY());
			
			// Wait five thousandths of a second before proceeding with the while loop.
			Wait(0.005);
		}
		
	}
	
	/**
	 * Test Mode (Driver Station Control)
	 * @note This function is intentionally left blank and is required for the Driver Station.
	 */
	void Test() {
		
	}
};

START_ROBOT_CLASS(Robot4930);

