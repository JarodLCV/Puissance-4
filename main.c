#include <stdio.h>
#include <stdbool.h>
#include "game.c"
#include "board.c"

#define ROWS 6 // Nombre de lignes
#define COLS 7 // Nombre de colonnes

char board[ROWS][COLS];

int main()
{
    int col;
    char currentPlayer = 'R';

    initializeBoard();

    do
    {
        displayBoard();

        printf("\nJoueur %c, choisissez une colonne (0-%d) : ", currentPlayer, COLS - 1);
        scanf("%d", &col);

        if (col < 0 || col >= COLS || board[0][col] != ' ')
        {
            printf("Choix invalide. Réessayez.\n");
            continue;
        }

        if (!dropToken(col, currentPlayer))
        {
            printf("Colonne pleine. Réessayez.\n");
            continue;
        }

        if (checkWinner(currentPlayer))
        {
            displayBoard();
            printf("\nJoueur %c a gagné !\n", currentPlayer);
            break;
        }

        if (checkTie())
        {
            displayBoard();
            printf("\nMatch nul !\n");
            break;
        }

        currentPlayer = (currentPlayer == 'R') ? 'Y' : 'R';

    } while (1);

    return 0;
}