#include "GOL.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: init_game
 DESCRIPTION: Initializes gameboard and writes first situation to file game.txt
	Input: void
	Output: void
  Used global variables: struct cell
 REMARKS when using this function:
*********************************************************************/
void
init_game()
{
  int row, column;
  struct cell board[ROWS_SIZE][COLUMNS_SIZE] = {0, 0};

   for(row = 0; row < ROWS_SIZE; row++) 
    {
      for(column = 0; column < COLUMNS_SIZE; column++) 
        {
          board[row][column].current = 0;
        }
    }

  board[12][13].current = 1;
  board[13][13].current = 1;
  board[14][13].current = 1;
  board[15][11].current = 1;
  board[15][12].current = 1;
  board[15][13].current = 1;
  board[12][16].current = 1;
  board[13][16].current = 1;
  board[14][16].current = 1;
  board[20][21].current = 1;
  board[21][21].current = 1;
  board[22][21].current = 1;
  board[21][23].current = 1;
  board[21][23].current = 1;
  board[21][23].current = 1;
  board[4][25].current = 1;
  board[4][26].current = 1;
  board[4][27].current = 1;
  board[27][4].current = 1;
  board[27][5].current = 1;
  board[27][6].current = 1;

  FILE *filePointer; 
  filePointer = fopen("game.txt", "w");
  filePointer = fopen("game.txt", "a");


  if (filePointer == NULL)
    {
      perror("game.txt");
      exit(1);
    }

  for(row = 0; row < ROWS_SIZE; row++) 
    {
      for(column = 0; column < COLUMNS_SIZE; column++) 
        {
          if(board[row][column].current == 1)
            {
              fprintf(filePointer, "%d", 1);
            } 
          else if (board[row][column].current == 0)
            {
              fprintf(filePointer, "%d", 0);
            }
        }
      fprintf(filePointer, "\n");
    }

  fclose(filePointer);
} /* end of init_game */