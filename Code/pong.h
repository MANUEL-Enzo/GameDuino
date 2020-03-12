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
	ball ball;
	paddle player_paddle;
	paddle ai_paddle;
	int player_score;
	int ai_score;
};
#endif /* PONG_H_ */
