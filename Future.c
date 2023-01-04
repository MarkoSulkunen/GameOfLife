#include "GOL.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: future_board
 DESCRIPTION: Calculates future board situation and makes it current
	Input: struct cell board[ROWS][COLUMNS]
	Output: void
  Used global variables: struct cell
 REMARKS when using this function:
*********************************************************************/

void
future_board(struct cell board[ROWS_SIZE][COLUMNS_SIZE])
{
  int row, column;

  for(row = 0; row < ROWS_SIZE; row++) 
    {
      for(column = 0; column < COLUMNS_SIZE; column++) 
        {
          board[row][column].neighbor = count_neighbors(board, row, column);
        }
    }
  for (row = 0; row < ROWS_SIZE; row++)
    {
      for (column = 0; column < COLUMNS_SIZE; column++)
        {
          if (board[row][column].current >= 1 )
            {
              if (board[row][column].neighbor <= 1 || board[row][column].neighbor >= 4)
                {
                  board[row][column].future = 0;
                }
            }
          else if (board[row][column].current == 0 && board[row][column].neighbor == 3)
            {
              board[row][column].future = 1;
            }
          else
          {
             board[row][column].future = board[row][column].current;
          }
        }
    }
  for (row = 0; row < ROWS_SIZE; row++)
    {
      for (column = 0; column < COLUMNS_SIZE; column++)
        {
          board[row][column].current = board[row][column].future;
        }
   }

  display_board(board);
} /* end of future_board */