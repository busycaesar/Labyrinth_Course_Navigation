#pragma config(StandardModel, "RVW SQUAREBOT")
#pragma config(Sensor, in1,    lightSensor,    sensorReflection)

#define K_SPEED 127
#define K_TURN_DISTANCE 340
#define BLACK_THRESHOLD 500

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

void followBlackLine() {
    //Clear Encoders
    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;

    while(true) {

        if(SensorValue[touchSensor] == 1) {
            motor[rightMotor] = 0;
            motor[leftMotor] = 0;
            break;
        }

        int leftSensorValue = SensorValue[lightSensor];
        wait1Msec(50); // Small delay to prevent rapid changes
        int rightSensorValue = SensorValue[lightSensor];

        // Determine where the black line is based on sensor readings
        if (leftSensorValue < BLACK_THRESHOLD && rightSensorValue < BLACK_THRESHOLD) {
            motor[rightMotor] = K_SPEED;
            motor[leftMotor] = K_SPEED;
        } else if (leftSensorValue < BLACK_THRESHOLD) {
						turnLeft();
        } else if (rightSensorValue < BLACK_THRESHOLD) {
						turnRight();
        } else {
            // Neither sensor detects black (adjust as needed)
            motor[rightMotor] = 0;
            motor[leftMotor] = 0; // Go straight by default
        }
    }
}

task main(){

	wait1Msec(1000);
	moveForward(1000);
	followBlackLine();

}
