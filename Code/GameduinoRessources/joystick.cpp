/*
 * joystick.cpp
 *
 *  Created on: 2 mars 2020
 *      Author: Manuel Enzo
 */

#include "Arduino.h"
#include "joystick.h"

joystick::joystick(int aB, int aX, int aY) {
	analogPortButton = aB;
	analogPortXAxis = aY;
	analogPortYAxis = aX;
}

String joystick::horizontalDirection(){
	String right("right");
	String left("left");
	String none("none");
	
	if(analogRead(analogPortXAxis)>1000){
		return left;
	}
	if(analogRead(analogPortXAxis)<200){
		return right;
	}
	return none;
}

String joystick::verticalDirection(){
	String forward("forward");
	String backward("backward");
	String none("none");
	
	if(analogRead(analogPortYAxis)>1000){
		return backward;
	}
	if(analogRead(analogPortYAxis)<100){
		return forward;
		}
	return none;
}
bool joystick::IsPressed(){
	if(analogRead(analogPortButton)<100){
			return true;
		}
	return false;
}
