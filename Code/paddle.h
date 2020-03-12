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
	void deletePaddle();
	void drawPaddle();
	void setPaddleCord(int x,int y);
	void movePaddle();
	UTFT screen;
	int cord_x;
	int cord_y;
	int width;
	int height;
private:
	int cord_x1;
	int cord_y1;
	int cord_x2;
	int cord_y2;
};

#endif /* PADDLE_H_ */
