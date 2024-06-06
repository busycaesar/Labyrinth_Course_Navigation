#pragma config(StandardModel, "RVW SQUAREBOT")
#pragma config(Sensor, S1,     sonarSensor,    sensorSONAR)

// Function to move the robot forward until it detects a wall
void moveAheadUntilWall(int time) {
	motor[rightMotor] = 127;  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;  // Motor on port3 is run at full (127) power forward
	wait1Msec(time);
	motor[rightMotor] = 0;    // Stop the right motor
	motor[leftMotor]  = 0;    // Stop the left motor
}

// Function to turn the robot left
void turnLeft() {
	motor[rightMotor] = 127;  // Right motor runs forward
	motor[leftMotor]  = -127; // Left motor runs backward
	wait1Msec(630);          // Robot runs previous code for the specified time in milliseconds
	motor[rightMotor] = 0;    // Stop the right motor
	motor[leftMotor]  = 0;    // Stop the left motor
}

// Function to turn the robot right
void turnRight() {
	motor[rightMotor] = -127; // Right motor runs backward
	motor[leftMotor]  = 127;  // Left motor runs forward
	wait1Msec(630);          // Robot runs previous code for the specified time in milliseconds
	motor[rightMotor] = 0;    // Stop the right motor
	motor[leftMotor]  = 0;    // Stop the left motor
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(1000); // Robot waits for 1000 milliseconds before executing program

	moveAheadUntilWall(9000);
	turnLeft();
	moveAheadUntilWall(5500);
	turnLeft();
	moveAheadUntilWall(9000);
	turnRight();
	moveAheadUntilWall(4000);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
