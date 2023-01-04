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