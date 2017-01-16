#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define character "@"
#define wall '#'
#define space " "

void moveChar(char input, int currentY, int currentX);
void updateScreen(int updateY,int updateX);
int canMove(int toGoY, int toGoX);

int main()
{

	int maxY;
	int maxX;
	int currentY;
	int currentX;

	char input;

	initscr();
	noecho();
	getmaxyx(stdscr,maxY,maxX);

	mvprintw(3,3,"Max screen is %d : %d \n", maxX, maxY);
	getch();

	erase();
	mvprintw(1,1,character);
	currentY = 1;
	currentX = 1;
	mvprintw(6,8, "#");
	move(1,1);


	input = getch();

	while(input != 'q')
	{
		moveChar(input, currentY, currentX);
		currentY = getcury(stdscr);
		currentX = getcurx(stdscr);
		input = getch();
	}

	getch();

	endwin();
	return 0;
}



void moveChar(char input, int currentY, int currentX)
{

	switch(input)
	{
		case 'a':
			updateScreen(currentY, currentX-1 );
		break;

		case 'w':
			updateScreen(currentY-1, currentX );
		break;

		case 's':
			updateScreen(currentY +1, currentX );
		break;

		case 'd':
			updateScreen(currentY, currentX +1);
		break;
	}
	
}

void updateScreen(int updateY, int updateX)
{

	if (canMove(updateY, updateX) == 1)
	{
		printw(space);
		mvprintw(updateY, updateX, character);
		move(updateY, updateX);
	}
}

int canMove(int toGoY, int toGoX)
{
	int currentX = getcurx(stdscr);
	int currentY = getcury(stdscr);

	char value = (char)mvinch(toGoY, toGoX);
	move(currentY, currentX);

	if(value == wall)
	{
		return 0;
	}


	return 1;
}
