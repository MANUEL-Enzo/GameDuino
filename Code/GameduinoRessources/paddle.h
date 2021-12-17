/*
 * paddle.h
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */
#include <UTFT.h>

#ifndef PADDLE_H_
#define PADDLE_H_

class paddle {
public:
	paddle(UTFT scrin,int x, int y, int widthe, int heighte);
	void drawPaddle();
	void setPaddleCord(int x,int y);
	void movePaddle(int x,int y);
	UTFT screen;
	int cord_x;
	int cord_y;
	int width;
	int height;
};

#endif /* PADDLE_H_ */
