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
	ball = ball(scrin,0,0,5);
	player_paddle = paddle(scrin,100,0,5,15);
	ai_paddle = paddle(scrin,200,0,5,15);
	player_score = 0;
	ai_score = 0;
}

void pong::startGame(joystick joiestick){
	screen.clrScr();
	screen.setColor(255,255,255);
	for(int i = 0 ; i < 17 ; i++){
		screen.fillRect(157,i * 14,163,i * 14 + 7);}
	screen.printNumI(player_score,140,15);
	screen.printNumI(ai_score,180,15);
	player_paddle.drawPaddle();
	ai_paddle.drawPaddle();
	ball.drawBall();
	int starting_time = millis();
	int paddle_speed = 10;
	String forward("forward");
	String backward("backward");
	while((millis() - starting_time) < 180000){
		while(true){
			if(((ball.cord_y + (int)(ball.vector_norm * sin(ball.angle))) >= (240 - ball.radius)) && (ball.angle > 0)){
				ball.angle = - ball.angle ; }
			else if(((ball.cord_y + (int)(ball.vector_norm * sin(ball.angle))) <= ball.radius) && (ball.angle < 0)){
				ball.angle = - ball.angle ; }
			else if(((ball.cord_x - ball.radius) <= (player_paddle.cord_x +  player_paddle.width / 2)) && (((ball.cord_y + ball.radius) < (player_paddle.cord_y - player_paddle.height)) || ((ball.cord_y - ball.radius) > (player_paddle.cord_y + player_paddle.height)))){
				ball.angle = pi - ball.angle ; }
			else if(((ball.cord_x - ball.radius) >= (ai_paddle.cord_x +  ai_paddle.width / 2)) && (((ball.cord_y + ball.radius) < (ai_paddle.cord_y - ai_paddle.height)) || ((ball.cord_y - ball.radius) > (ai_paddle.cord_y + ai_paddle.height)))){
				ball.vector_x= pi - ball.angle ; }
			ball.moveBall();
			if((ball.cord_x <= player_paddle.cord_x) || (ball.cord_x >= ai_paddle.cord_x)){
				break ; }
			if(joiestick.verticalDirection() == forward){
				player_paddle.movePaddle(player_paddle.cord_x,player_paddle.cord_y + paddle_speed) ; }
			else if(joiestick.verticalDirection() == backward){
				player_paddle.movePaddle(player_paddle.cord_x,player_paddle.cord_y - paddle_speed) ; }
		}
		screen.setColor(0,0,0);
		if(ball.cord_x <= player_paddle.cord_x){
			screen.printNumI(ai_score,180,15);
			ai_score++;
			screen.setColor(255,255,255);
			screen.printNumI(ai_score,180,15); }
		else if(ball.cord_x >= ai_paddle.cord_x){
			screen.printNumI(player_score,140,15);
			player_score++;
			screen.setColor(255,255,255);
			screen.printNumI(player_score,140,15); }
	}
	screen.clrScr();
	if(player_score > ai_score){
		screen.print("Player Win"); }
	else if(player_score < ai_score){
		screen.print("AI Win"); }
	else{screen.print("Tie"); }
}

