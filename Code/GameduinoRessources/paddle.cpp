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
	width = widthe;
	height = heighte;
}
void paddle::drawPaddle(){
	screen.setColor(255,255,255);
	screen.fillRect(cord_x,cord_y,cord_x+width,cord_y+height);
}
void paddle::setPaddleCord(int x,int y){
	cord_x = x;
	cord_y = y;
}
void paddle::movePaddle(int x,int y){
	setPaddleCord(x,y);
	drawPaddle();
}
