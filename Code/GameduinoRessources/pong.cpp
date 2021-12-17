/*
 * pong.cpp
 *
 *  Created on: 17 janv. 2020
 *      Author: Manuel Enzo
 */

#include "pong.h"
#include "paddle.h"
#include "ball.h"
#include "joystick.h"

#define pi 3.14159265

pong::pong(UTFT scrin){
	screen = scrin;
}

void pong::startGame(joystick joiestick){
	screen.setColor(255,255,255);
	ball ball(screen,159,119,5);
	paddle player_paddle(screen,10,119,5,20);
	paddle ai_paddle(screen,309,119,5,20);
	int player_score = 0;
	int ai_score = 0;
	ball.drawBall();
	int paddle_speed = 6;
	String forward("forward");
	String backward("backward");
	int ai_random_freeze = millis() + random(0,101);
	int ai_direction = 1;
	while(ai_score<5 && player_score<5){
		while(true){
		randomSeed(analogRead(57));
		screen.clrScr();
		screen.setColor(255,255,255);
		screen.printNumI(player_score,130,10);
		screen.printNumI(ai_score,189,10);
		screen.fillRect(156,0,161,7);
		screen.fillRect(156,14,161,21);
		screen.fillRect(156,28,161,35);
		screen.fillRect(156,42,161,49);
		screen.fillRect(156,56,161,63);
		screen.fillRect(156,70,161,77);
		screen.fillRect(156,84,161,91);
		screen.fillRect(156,98,161,105);
		screen.fillRect(156,112,161,119);
		screen.fillRect(156,126,161,133);
		screen.fillRect(156,140,161,147);
		screen.fillRect(156,154,161,161);
		screen.fillRect(156,168,161,175);
		screen.fillRect(156,182,161,189);
		screen.fillRect(156,196,161,203);
		screen.fillRect(156,210,161,217);
		screen.fillRect(156,224,161,231);
		screen.fillRect(156,238,161,239);
		player_paddle.drawPaddle();
		ai_paddle.drawPaddle();
			if((ball.cord_y + ball.radius - (int)(ball.vector_norm * sin(ball.angle))) >= 239){
				ball.angle = -1*ball.angle ; }
			else if((ball.cord_y - ball.radius - (int)(ball.vector_norm * sin(ball.angle))) <= 0){
				ball.angle = -1*ball.angle ; }
			else if(((ball.cord_x - ball.radius) <= (player_paddle.cord_x + player_paddle.width)) && ((ball.cord_y + ball.radius) > (player_paddle.cord_y)) && ((ball.cord_y - ball.radius) < (player_paddle.cord_y + player_paddle.height))){
				ball.angle = pi - ball.angle ;
				if(joiestick.verticalDirection() == backward){ball.angle = ball.angle-pi/10;}
				else if(joiestick.verticalDirection() == forward){ball.angle = ball.angle+pi/10;}
				if(ball.angle>pi){ball.angle=-pi/3;}
				else if(ball.angle>pi/3){ball.angle=pi/3;}
				else if(ball.angle<-pi/3){ball.angle=-pi/3;}}
			else if((ball.cord_x + ball.radius >= ai_paddle.cord_x) && ((ball.cord_y + ball.radius) > ai_paddle.cord_y) && ((ball.cord_y - ball.radius) < (ai_paddle.cord_y + ai_paddle.height))){
				ball.angle= pi - ball.angle ; }
			Serial.println(millis());
			Serial.println(ai_random_freeze);
			if(ai_random_freeze<millis()){
				ai_random_freeze = millis() + random(0,101);
				if(ball.cord_y < ai_paddle.cord_y){ai_direction = -1;}
				else if(ball.cord_y > ai_paddle.cord_y+ ai_paddle.height){ai_direction = 1;}
				else{ai_direction = 0;}}
			else{if(ai_paddle.cord_y+ai_direction*paddle_speed<0){ai_paddle.movePaddle(ai_paddle.cord_x,0);}
			else if(ai_paddle.cord_y+ai_paddle.height+ai_direction*paddle_speed>239){ai_paddle.movePaddle(ai_paddle.cord_x,239-ai_paddle.height);}
			else{ai_paddle.movePaddle(ai_paddle.cord_x,ai_paddle.cord_y+ai_direction*paddle_speed);}}
			ball.moveBall(ball.angle);
			if((ball.cord_x <= player_paddle.cord_x+player_paddle.width) || (ball.cord_x >= ai_paddle.cord_x)){
				break ; }
			if(joiestick.verticalDirection() == backward){
				if((player_paddle.cord_y+player_paddle.height+paddle_speed)>239){player_paddle.movePaddle(player_paddle.cord_x,239-player_paddle.height);}
				else{player_paddle.movePaddle(player_paddle.cord_x,player_paddle.cord_y + paddle_speed);}}
			else if(joiestick.verticalDirection() == forward){
				if((player_paddle.cord_y-paddle_speed)<0){player_paddle.movePaddle(player_paddle.cord_x,0);}
				else{player_paddle.movePaddle(player_paddle.cord_x,player_paddle.cord_y - paddle_speed);}}
			delay(5);
		}
		screen.setColor(0,0,0);
		if(ball.cord_x <= 50){ai_score++;}
		else{player_score++;}
		ball.cord_x = 159;
		ball.cord_y = 119;
		ball.angle = -pi/4+random(0,1001)*pi/2000;
		delay(5);
	}
	screen.clrScr();
	screen.setColor(255,255,255);
	if(player_score > ai_score){
		screen.print("Player Win",90,110); }
	else{
		screen.print("AI Win",110,110); }
	delay(3000);
	screen.clrScr();
}

