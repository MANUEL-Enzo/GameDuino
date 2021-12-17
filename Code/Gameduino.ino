#include <UTFT.h>
#include <button.h>
#include <joystick.h>
#include <pong.h>
#include <ball.h>
#include <paddle.h>

UTFT myGLCD(ITDB32S,38,39,40,41);

joystick joystick(56,54,55);

button A(58);
button B(59);

extern uint8_t BigFont[];

const int BUZZER = 8;

int menu_location = 1;

void setup(){
  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
  myGLCD.clrScr();
}

void loop(){
  myGLCD.setColor(255,255,255);
  myGLCD.print("Gameduino",100,10);
  if(menu_location == 1){
    myGLCD.setColor(255,0,0);
    myGLCD.print("PONG",50,110);
    myGLCD.drawRect(10,40,149,199);
    myGLCD.setColor(255,255,255);
    myGLCD.print("SNAKE",200,110);
    myGLCD.drawRect(169,40,309,199);
   }
  else if(menu_location == -1){
    myGLCD.setColor(255,255,255);
    myGLCD.print("PONG",50,110);
    myGLCD.drawRect(10,40,149,199);
    myGLCD.setColor(255,0,0);
    myGLCD.print("SNAKE",200,110);
    myGLCD.drawRect(169,40,309,199);
  }
  if(B.IsPressed()){
    menu_location = -1*menu_location;
    delay(250);
  }
  if(A.IsPressed()){
    if(menu_location == 1){
      pong pong(myGLCD);
      pong.startGame(joystick);}
    else{
      while(true){
      myGLCD.clrScr();
      myGLCD.setColor(255, 0, 0);
      playGame();}
      }
  }
}

int snakeDir=1;

struct gameItem{
  int X;
  int Y;
};

String horizontal;
String vertical;

int gameItemSize=4;
unsigned int snakeSize=5;

gameItem snake[100];
gameItem snakeFood;

void draw(){
  drawSnake();
  drawFood();
}

void drawSnake(){
  for(int i=0;i<snakeSize;i++){
    myGLCD.drawRect(snake[i].X,snake[i].Y,snake[i].X+5,snake[i].Y+5);
  }
}

void drawFood(){
    snakeFood.X=random(2,320);
    snakeFood.Y=random(2,240);
    myGLCD.fillCircle(snakeFood.X,snakeFood.Y,4);
 
    }
    
void handleColisions(){
  if(snake[0].X==snakeFood.X && snake[0].Y == snakeFood.Y) {
    snakeSize++;
    drawFood();    
  }
else {
    for (int i = 1; i < snakeSize; i++) {
      if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y) {
          myGLCD.clrScr();
          myGLCD.setColor(255, 0, 0);
          delay(50);
      }
    }
  }

  if ((snake[0].X < 1) || (snake[0].Y < 1) || (snake[0].X > 320) || (snake[0].Y > 240)) {
    myGLCD.clrScr();
    myGLCD.setColor(255, 0, 0);
    delay(50);
  }
}

void handleInput(){
  if(joystick.horizontalDirection()=="left" && snakeDir !=1){
    snakeDir=0;
  }
  if(joystick.horizontalDirection()=="right" && snakeDir!=0){
    snakeDir=1;
  }
  if( joystick.verticalDirection()=="forward" && snakeDir!=3){
    snakeDir=2;
  }
  if( joystick.verticalDirection()=="backward" && snakeDir!=2){
    snakeDir=3;
  }
}

void updateValues() {
 
  for (int i = snakeSize - 1; i > 0; i--) {
    snake[i] = snake[i - 1];
  }

  
  //gauche
  if (snakeDir == 0) {

    snake[0].X -= gameItemSize;
  }
  //droite
  else if (snakeDir == 1) {

    snake[0].X += gameItemSize;
  }

  //bas
  else if (snakeDir == 3) {

    snake[0].Y += gameItemSize;
  }

  //haut
  else if (snakeDir == 2) {

    snake[0].Y -= gameItemSize;
  }

}

void playGame() {
  handleColisions();
  handleInput();
  updateValues();
  
  draw();
  delay(50);
}
