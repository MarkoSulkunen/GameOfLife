#include "GOL.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_game
 DESCRIPTION: Reads first situation from file game.txt
	Input: struct cell board[ROWS][COLUMNS]
	Output: void
  Used global variables: struct cell
 REMARKS when using this function:
*********************************************************************/

void
read_game(struct cell board[ROWS_SIZE][COLUMNS_SIZE])
{

  FILE *fp;
  char state_c;
  int state, column,row;

  column = 0;
  row = 0;

  fp = fopen("game.txt", "r");

  while (!feof(fp)) 
    {

    fscanf(fp,"%c", &state_c);
    state = state_c - '0';

    board[row][column].current = state;

    column++;

    if (column >= COLUMNS_SIZE) 
      {
        row++;
        column = 0;

        fscanf(fp,"%c",&state_c);

        #ifdef WINDOWS
        fscanf(fp,"%c",&state_c);
        #endif
      }
    }
} /* end of read_game */