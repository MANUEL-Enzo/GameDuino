/*
 * joystick.h
 *
 *  Created on: 2 mars 2020
 *      Author: Manuel Enzo
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

class joystick {
public:
	joystick(int aB, int aX, int aY);
	String horizontalDirection();
	String verticalDirection();
	bool IsPressed();
	int analogPortButton;
	int analogPortXAxis;
	int analogPortYAxis;
};

#endif /* JOYSTICK_H_ */
