#include "GOL.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_neighbors
 DESCRIPTION: Counts neighbors of cells
	Input: struct cell board[ROWS][COLUMNS], int i, int j
	Output: Integer
  Used global variables: struct cell
 REMARKS when using this function:
*********************************************************************/

int 
count_neighbors(struct cell board[ROWS_SIZE][COLUMNS_SIZE], int row, int column)  
{
  int neighbor = 0;

  if (row - 1 >= 0 && column - 1 >= 0)
  {
    if (board[row-1][column-1].current >= 1)
      neighbor++;
  }

  if (row - 1 >= 0)
  {
    if(board[row-1][column].current >= 1)
      neighbor++;
  }

  if (row - 1 >= 0 && column + 1 < 30)
  {
    if(board[row-1][column+1].current >= 1)
      neighbor++;
  }

  if (column - 1 >= 0)
  {
    if(board[row][column-1].current >= 1)
      neighbor++;
  }

  if (column + 1 < 30)
  {
    if(board[row][column+1].current >= 1)
      neighbor++;
  }

  if (row + 1 < 30 && column - 1 >=0)
  {
    if(board[row+1][column-1].current >= 1)
      neighbor++;
  }

  if (row + 1 < 30)
  {
    if(board[row+1][column].current >= 1)
      neighbor++;
  }

  if (row + 1 < 30 && column + 1 < 30)
  {
    if(board[row+1][column+1].current >= 1)
      neighbor++;
  }

  return neighbor;
} /* end of count_neighbors */