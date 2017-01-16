#include <ncurses.h>
#include <stdlib.h>

#define HERO '@';

void initializeGame();
void gameLoop();
void endGame();


int main() {
  initializeGame();
  gameLoop();
  endGame();
  return 0;
}

void initializeGame(){
  initscr();
  noecho();
  cbreak();
  //parseLevel
  getRandom(&y,&x);

}

void gameLoop(){
  char input;
  do{
    input = getch();
    refresh();

  }while(input!= 'q');
}

void endGame(){
  endwin();
}

void movecURSOR(char input){

  getygetx
  switch (input){
    case 'w':
      ypos--;
      break;
    case 'a':
      xpos--;
      break;
    case 's':
      ypos++;
      break;
    case 'd':
      xpos++;
      break;
    default:
      break;
  }
  //collision detection
  atpos = mvinch(ypos,xpos);
  mvaddch(y,x-1,'X');
  mvaddch(yold,xold.' ');
  move(y,x);

  mvaddcd(ypos,xpos, HERO);

  if (atpos == 'X'){
    printMSg("Encountered and object");
    move(oldy,oldx);
  }
}

void getRandom(int * y, int* x){
  int ymax, xmax;
  getmaxyx(stdscr, ymax,xmax);
  //create random x and y
}
