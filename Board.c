#include "GOL.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: display_board
 DESCRIPTION: displays current board situation
	Input: struct cell board[ROWS][COLUMNS]
	Output: void
  Used global variables: struct cell
 REMARKS when using this function:
*********************************************************************/

void
display_board(struct cell board[ROWS_SIZE][COLUMNS_SIZE])
{
  int row, column;

  clear();
  start_color();
  init_pair (2, COLOR_BLACK, COLOR_WHITE);
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(3,COLOR_BLACK, COLOR_WHITE);
  bkgd (COLOR_PAIR (2));

  for(row = 0; row < ROWS_SIZE; row++) 
    {
      for(column = 0; column < COLUMNS_SIZE; column++) 
        {
          if(board[row][column].current == 1)
            {            
             attron(COLOR_PAIR(1));
             printw("|_|");
             attroff(COLOR_PAIR(1));
            } 
          else
            {
              attron(COLOR_PAIR(3));
              printw("|_|");
              attroff(COLOR_PAIR(3));
            }
        }

      printw("\n");
    }

  refresh();
  sleep(1);

  future_board(board);
} /* end of display_board */