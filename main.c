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
    char currentPlayer = 'R'; // TODO: Choisir le joueur qui commence

    initializeBoard();

    do
    {
        displayBoard();

        printf("\nJoueur %c, choisissez une colonne (0-%d) : ", currentPlayer, COLS - 1);
        scanf("%d", &col);

        if (col < 0 || col >= COLS || board[0][col] != ' ')
        {
            printf("Choix invalide. R%cessayez.\n", 130);
            continue;
        }

        if (!dropToken(col, currentPlayer))
        {
            printf("Colonne pleine. R%cessayez.\n", 130);
            continue;
        }

        if (checkWinner(currentPlayer))
        {
            displayBoard();
            printf("\nJoueur %c a gagn%c !\n", currentPlayer, 130);
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
