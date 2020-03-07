/*
 * button.cpp
 *
 *  Created on: 2 mars 2020
 *      Author: Manuel Enzo
 */

#include "Arduino.h"
#include "button.h"

button::button(int aPort) {
	analogPort = aPort;
}
bool button::IsPressed() {
	if(analogRead(analogPort)>1000){
		return true;
	}
	return false;
}
