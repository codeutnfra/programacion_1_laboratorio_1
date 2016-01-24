#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utn.h"
#include "game.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

#define __unix__

/**
 * \brief Clears screen using ANSI escape sequences.
 * \param void
 * \return void
 *
 */
void clear(void)
{
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif

}

/**
 * \brief Perform a delay
 * \param ms Amount of miliseconds
 * \return void
 *
 */
void mySleep(int ms)
{
    #ifdef __unix__
        usleep(ms*1000);
    #else
        sleep(ms);
    #endif
}

 /**
 * \brief Greets player.
 * \param void
 * \return void
 *
 */

void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    showDate();
    mySleep(2000);

}

/**
 * \brief Initializes the game's board
 * \param board This array that represent the game's board
 * \return void
 *
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(int board[DIM][DIM])
{
    // TODO
    int dsquared = (DIM * DIM);
    int numbersArray[DIM * DIM];
    int n = 0;
    int i,j;
    int temp;
    int d = DIM;

    for ( i = 0; i < dsquared; i++)
    {
        numbersArray[i] = i;
    }

    // two for loops to mix numbersArray
    for ( i = 0; i < dsquared; i++)
    {
        for ( j = i+1; j < dsquared-1; j++)
        {
            if (getNumeroAleatorio(0 , 1, 0))
            {
                temp = numbersArray[i];
                numbersArray[i] = numbersArray[j];
                numbersArray[j] = temp;
            }
        }
    }

    // two for loops to iterate through 2d array - rows/columns
    for ( i = 0; i < d; i++)
    {
        for ( j = 0; j < d; j++)
        {
            // this will initialize the matrix with the numbers of numbersArray
            board[i][j] = numbersArray[n];
            n = n + 1;
        }
    }




}


/**
 * \brief Prints the board in its current state.
 * \param board This array that represent the game's board
 * \param moveCount Quantity of movements
 * \return void
 *
 */
void draw(int board[DIM][DIM], int moveCount)
{
    // TODO nested loops to draw board initialized above

    // initialize variables
    int i,j;
    int d = DIM;

    // iterate over rows
    printf("_________________________________\n\n");
    printf(" Movements: %3d\n", moveCount);
    printf("_________________________________\n\n");
    for (i = 0; i < d; i++)
    {
        // iterate over columns
        for (j = 0; j < d; j++)
        {

            // print the number of the tile except for the 0 tile
            if (board[i][j] > 0)
            {
                printf("| %2d ", board[i][j]);
            }

            // for 0 tile, print the space for tiles to move
            if (board[i][j] == 0)
            {
                printf("| __ ");
            }
        }
        // print two lines after each row to make board
        printf("|\n\n");
    }
}


 /**
 * \brief If is possible moves tile to the empty space
 * \param board This array that represent the game's board
 * \return If  moves tile and returns 1, else returns 0.
 *
 */
int move(int tile, int board[DIM][DIM])
{
    // TODO
    // search board for user tile
    // iterate through rows to find tile
    int i,j;
    int blankspace;
    int d = DIM;
    int x,y;

    blankspace = 0;

    for (i = 0; i < d; i++)
    {
        // iterate through columns to find blankspace
        for (j = 0; j < d; j++)
        {
            if(board[i][j] == blankspace)
            {
                x=i;
                y=j;
                break;
            }

        }
    }

    for (i = 0; i < d; i++)
    {
        // iterate through columns to find tile
        for (j = 0; j < d; j++)
        {
            // if user entered tile that exists on the board
            if(tile == board[i][j])
            {
                // test if tile is adjacent to blankspace
                if (((x == (i - 1)) && (j == y)) ||  ((x == (i + 1)) && (j == y)) ||
                ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
                {
                    // printf("before:  tile %d, blankspace %d\n", tile, blankspace)

                    // swap tile with blankspace if tile is adjacent to blankspace
                    board[x][y] = tile;
                    board[i][j] = blankspace;

                    // printf("The position of the tile is board[%d][%d] = %2d.  Tile is %d\n", i, j, board[i][j], tile);
                    // printf("Blankspace position is: board[%d][%d] = %d\n", x, y, blankspace);

                    return 1;
                }
            }
        }
    }
    return 0;
}


/**
 * \brief Analise if board is in winning configuration
 * \param board This array that represent the game's board
 * \return Returns 1 if game is won, else returns 0.
 *
 */
int won(int board[DIM][DIM])
{
    // TODO
    // initializes variables
    int n = 0;
    int i,j;
    int d = DIM;
    int lastItem = (DIM*DIM)-1;
    // iterates through board
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            // creates counter
            n = n + 1;

            //if is the last place then break
            if(n == lastItem)
            {
                return 1;
            }
            // if any tile != counter, counting from 0, return 0
            if (board[i][j] != n)
            {
                return 0;
            }
        }
    }
    // otherwise, all tiles count up from 0, game won
    return 1;
}



/**
 * \brief Show the courrent date time
 * \param void
 * \return void
 *
 */
void showDate(void)
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
    puts(buffer);

}


