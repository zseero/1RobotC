#pragma config(Sensor, S1,     sonar,          sensorSONAR)
#pragma config(Sensor, S4,     sound,          sensorSoundDB)
#pragma config(Motor,  motorA,          middle,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          right,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          left,          tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turn(int amount) {
	amount = amount * -1;
	if (amount >= 0) {
		nSyncedMotors = synchBC;
		nSyncedTurnRatio = -100;
		nMotorEncoder[motorB] = 0;
		motor[motorB] = 40;
		int turnamount = (amount / 90) * 165;
		while (nMotorEncoder[motorB] < turnamount) {}
		motor[motorB] = 0;
	}
	if (amount < 0) {
		nSyncedMotors = synchCB;
		nSyncedTurnRatio = -100;
		nMotorEncoder[motorC] = 0;
		motor[motorC] = 40;
		int turnamount = (amount / 90) * 165 * -1;
		while (nMotorEncoder[motorC] < turnamount) {}
		motor[motorC] = 0;
	}
	nSyncedMotors = synchNone;
	wait1Msec(500);
}

void move(int amount) {
	int a = 50;
	if (amount < 0) { a = a * -1; }
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = +100;
	nMotorEncoder[motorB] = 0;
	motor[motorB] = a;
	int turnamount = amount * 100;
	while (nMotorEncoder[motorB] < turnamount) {}
	motor[motorB] = 0;
	nSyncedMotors = synchNone;
	wait1Msec(500);
}

task main()
{
	wait1Msec(1000);
	while (true) {
		motor[left] = 50;
		motor[right] = 50;
		wait1Msec(250);

		while (SensorValue(sound) < 60 && SensorValue(sonar) > 20) {}
		if (SensorValue(sonar) > 20) { move(-4); }

		motor[left] = 20;
		motor[right] = -20;
		wait1Msec(250);

		while (SensorValue(sound) < 60) {}
	}
}
