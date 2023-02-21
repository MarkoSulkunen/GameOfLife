/*********************************************************************

 1.  NAME
       GameOfLife.c

 2.  DESCRIPTION
       Game of life is the simplest evolution theory model.
       Each cell with one or no neighbors' dies, as if by loneliness.
       Each cell with four or more neighbors dies, as if by overpopulation.
       Each cell with two or three neighbors survives.
       Each cell with three neighbors becomes populated.



 3.  VERSIONS
       Original:
         14.5.2020 / Marko Sulkunen

       Version history:

**********************************************************************/

#include "GOL.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int 
main(void)
{
  struct cell board[ROWS_SIZE][COLUMNS_SIZE];

  initscr();

  move(13,30);
  printw("Start game of life?\n");

  move(15,35);
  printw("Press: y");

  char character = getch();

  if(character == 'y')
  {
    clear();
    init_game();

    read_game(board);

    display_board();
  }
  else
  {
      exit(0);
  }

  endwin();	
} /* end of main */