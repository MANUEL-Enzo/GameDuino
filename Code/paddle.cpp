/*
 * paddle.cpp
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */

#include "paddle.h"

paddle::paddle(UTFT scrin,int x, int y, int widthe, int heighte){
	screen = scrin;
	cord_x = x;
	cord_y = y;
	cord_x1 = x+width/2;
	cord_y1 = y+height/2;
	cord_x2 = x-width/2;
	cord_y2 = y-height/2;
	width = widthe;
	height = heighte;
}

void paddle::deletePaddle(){
	screen.setColor(255,255,255);
	screen.fillRect(cord_x1,cord_y1,cord_x2,cord_y2);
}
void paddle::drawPaddle(){
	screen.setColor(0,0,0);
	screen.fillRect(cord_x1,cord_y1,cord_x2,cord_y2);
}
void paddle::setPaddleCord(int x,int y){
	cord_x = x;
	cord_y = y;
	cord_x1 = x+width/2;
	cord_y1 = y+height/2;
	cord_x2 = x-width/2;
	cord_y2 = y-height/2;
}
void paddle::movePaddle(int x,int y){
	this->deletePaddle();
	this->setPaddleCord(x,y);
	this->drawPaddle();
}
