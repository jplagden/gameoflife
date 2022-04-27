#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define BOARDSIZEY 50
#define BOARDSIZEX 50

bool board[BOARDSIZEY][BOARDSIZEX];

//returns whether the cell is dead or alive in this round
bool dead_or_alive(int cellX, int  cellY)
{
	int i, j, alive;
	i = -1; j = -1; alive = 0;

	for (i = -1; i < 3; i++)
	{
			for (j = -1; j < 3; j++)
		{
			if (board[cellY + i][cellX + j] == true)
			{
				alive++;
			}
		}
	}
	if (alive == 2 || alive ==3){return true;}

	return false;
}

int main(int argc, char *argv[])
{

	int x = 0, y = 0;
	int max_x = 0, max_y = 0;

	int i, j;

        //selects a random state for each cell
	for (y = 0; y < BOARDSIZEY; y++)
	{
		for (x = 0; x < BOARDSIZEX; x++)
		{
			board[y][x] = rand() % 2;

		}
	}

	


        //initialize the screen
	initscr();
	noecho();
	curs_set(FALSE);
       
	//main loop
	while(1){
	clear();


	//renders the board

        for (i = 0; i <= BOARDSIZEY; i++)
	{
		for (j = 0; j <= BOARDSIZEX; j++)
			
		{
			board[i][j] = dead_or_alive(i, j);
			if (board[i][j] == true)
			{

				mvprintw(i, j, "o");
			}
			else if(board[i][j] == false) {
				mvprintw(i, j, "-");
			}
		}
	}

	refresh();
	sleep(1);

	}

	endwin();

	return 0;
}

