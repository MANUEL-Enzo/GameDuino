/*
 * ball.h
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */
#include <UTFT.h>

#ifndef BALL_H_
#define BALL_H_

class ball {
public:
	ball(UTFT scrin,int x,int y,int diametre);
	void drawBall();
	void moveBall(float angl);
	UTFT screen;
	float angle;
	float vector_norm;
	int radius;
	int cord_x;
	int cord_y;
private:
	int vector_x;
	int vector_y;
};

#endif /* BALL_H_ */
