#include <stdio.h>
#include <stdbool.h>
#include "board.h"

#define ROWS 6 // Nombre de lignes
#define COLS 7 // Nombre de colonnes

char board[ROWS][COLS];

// Initialiser le plateau de jeu
void initializeBoard()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

// Afficher le plateau de jeu
void displayBoard()
{
    printf("\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; ++j)
    {
        printf("| %d ", j);
    }
    printf("|\n");
}