/*
 * pong.h
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */
#include <ball.h>
#include <paddle.h>
#include <UTFT.h>
#include <joystick.h>

#ifndef PONG_H_
#define PONG_H_

class pong {
public:
	pong(UTFT scrin);
	void startGame(joystick joiestick);
	UTFT screen;
};
#endif /* PONG_H_ */
