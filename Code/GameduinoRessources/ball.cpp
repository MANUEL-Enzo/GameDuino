/*
 * ball.cpp
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */
#include "ball.h"
#define pi 3.14159265

ball::ball(UTFT scrin,int x, int y,int rayon) {
	screen = scrin;
	cord_x = x;
	cord_y = y;
	radius = rayon;
	angle = -pi/4+random(0,101)*pi/200 ;
	vector_norm = 6;
	vector_x = cos(angle) * vector_norm;
	vector_y = sin(angle) * vector_norm;
}
void ball::drawBall(){
	screen.setColor(255,255,255);
	screen.fillCircle(cord_x,cord_y,radius);
}
void ball::moveBall(float angl){
	vector_x = cos(angle) * vector_norm;
	vector_y = sin(angle) * vector_norm;
	cord_x += vector_x ;
	cord_y -= vector_y ;
	this->drawBall();
}

