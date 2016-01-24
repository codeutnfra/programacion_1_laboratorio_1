/******************************************************************
* Programa: Ejemplo Clase 10
*
* Objetivo:
*   And now it's time to play. The Game of Fifteen is a puzzle played
*   on a square, two-dimensional board with numbered tiles that slide.
*   The goal of this puzzle is to arrange the board's tiles from
*   smallest to largest, left to right, top to bottom, with an empty
*   space in board's bottom-right corner, as in the below.
*
*        1  2  3
*
*        4  5  6
*
*        7  8  _
*
*   The game will start mixed:
*
*        7  5  3
*
*        6  2  4
*
*        1  8  _
*
* Aspectos a destacar:
*   Utilización simple de matrices
*   Compresión de un ejercicio en ingles.
*   Manejo de fecha y hora.
*
* Version: 0.1 del 06 enero de 2016
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utn.h"
#include "game.h"



int main()
{
    // board, whereby board[i][j] represents row i and column j
    int board[DIM][DIM];
    int moveCount=0;
    int tile;

    // greet player
    greet();

    // initialize the board
    init(board);

    // accept moves until game is won
    while (1)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(board,moveCount);

        // check for win
        if (won(board))
        {
            printf("You WIN!!!\n");
            break;
        }

        // prompt for move
        tile = getInt("Tile to move: ");

        if (tile == -1)
        {
            printf("\nBye.\n");
            break;
        }

        // move if possible, else report illegality
        if (!move(tile,board))
        {
            printf("\nIllegal move.\n");
            mySleep(500);
        }
        moveCount++;
        // mySleep for animation's sake
        mySleep(200);
    }

    // that's all folks
    return 0;
}
