#include <stdio.h>
#include <stdbool.h>
#include "game.h"

#define ROWS 6 // Nombre de lignes
#define COLS 7 // Nombre de colonnes
char board[ROWS][COLS];
// Placer le jeton dans la colonne choisie
bool dropToken(int col, char token)
{
    for (int i = ROWS - 1; i >= 0; --i)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = token;
            return true;
        }
    }
    return false;
}

// Vérifier s'il y a un gagnant
bool checkWinner(char token)
{
    // Vérifier les lignes
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS - 3; ++j)
        {
            if (board[i][j] == token &&
                board[i][j + 1] == token &&
                board[i][j + 2] == token &&
                board[i][j + 3] == token)
            {
                return true;
            }
        }
    }

    // Vérifier les colonnes
    for (int i = 0; i < ROWS - 3; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == token &&
                board[i + 1][j] == token &&
                board[i + 2][j] == token &&
                board[i + 3][j] == token)
            {
                return true;
            }
        }
    }

    // Vérifier les diagonales ascendantes
    for (int i = 3; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS - 3; ++j)
        {
            if (board[i][j] == token &&
                board[i - 1][j + 1] == token &&
                board[i - 2][j + 2] == token &&
                board[i - 3][j + 3] == token)
            {
                return true;
            }
        }
    }

    // Vérifier les diagonales descendantes
    for (int i = 3; i < ROWS; ++i)
    {
        for (int j = 3; j < COLS; ++j)
        {
            if (board[i][j] == token &&
                board[i - 1][j - 1] == token &&
                board[i - 2][j - 2] == token &&
                board[i - 3][j - 3] == token)
            {
                return true;
            }
        }
    }

    return false;
}

// Vérifier s'il y a un match nul
bool checkTie()
{
    for (int i = 0; i < COLS; ++i)
    {
        if (board[0][i] == ' ')
        {
            return false;
        }
    }
    return true;
}
