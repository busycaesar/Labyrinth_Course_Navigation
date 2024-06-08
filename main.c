#pragma config(StandardModel, "RVW SQUAREBOT")

#define K_SPEED 127
#define K_TURN_DISTANCE 372

void moveForward(int distance){

  //Clear Encoders
  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[leftEncoder] < distance)
  {

  	if(SensorValue[touchSensor] == 1) {
    	motor[rightMotor] = 0;
    	motor[leftMotor] = 0;
  	}

    motor[rightMotor] = K_SPEED;
    motor[leftMotor] = K_SPEED;

   }

}

void turnLeft(){

	SensorValue[rightEncoder] = 0;

  while(SensorValue(rightEncoder) < K_TURN_DISTANCE)
	{

	  if(SensorValue[touchSensor] == 1) {
    	motor[rightMotor] = 0;
    	motor[leftMotor] = 0;
  	}

		//Turn Left
		motor[rightMotor] = K_SPEED;
		motor[leftMotor]  = -K_SPEED;
	}

}

void turnRight(){

	SensorValue[leftEncoder] = 0;

  while(SensorValue(leftEncoder) < K_TURN_DISTANCE)
	{

  	if(SensorValue[touchSensor] == 1) {
    	motor[rightMotor] = 0;
    	motor[leftMotor] = 0;
  	}

		//Turn Right
		motor[rightMotor] = -K_SPEED;
		motor[leftMotor]  = K_SPEED;
	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(1000);

	moveForward(5300);
	turnLeft();
	moveForward(3400);
	turnLeft();
	moveForward(5300);
	turnRight();
	moveForward(1500);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
