/*
 * button.h
 *
 *  Created on: 2 mars 2020
 *      Author: Manuel Enzo
 */

#ifndef BUTTON_H_
#define BUTTON_H_

class button {
public:
	button(int aPort);
	bool IsPressed();
	int analogPort;
};

#endif /* BUTTON_H_ */
