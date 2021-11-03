#include "game.h"

void initBoard(char board[][ROWS])
{
    for(int i=0; i<COLS; i++) {
        for(int j=0; j<ROWS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][ROWS])
{
    printf("    ");
    for(int x = 0; x < COLS; x++) {
        printf(" %c ", x + 'A');
    }
    printf("\n   ");
    printHorizontalBorder(COLS * 3 + 2, 1);
    printf("\n");
    for(int y = 0 ; y < ROWS; y++) {
        printf("%2d ", y + 1);
        printVerticalBorder();
        for(int x = 0; x < COLS; x++) {
            printf(" %c ", board[x][y]);
        }
        printVerticalBorder();
        printf("\n");
    }
    printf("   ");
    printHorizontalBorder(COLS * 3 + 2, 0);
    printf("\n");
}