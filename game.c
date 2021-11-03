#include <stdlib.h>
#include <string.h>
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

COORD readCoordinates()
{
    COORD answer; 
    answer.X = -1;
    answer.Y = -1;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    

    do {
        printf("Enter your coordinates: ");
        lineSize = getline(&buffer, &len, stdin);
        char delim[] = " ";

        char *ptr = strtok(buffer, delim);

        while (ptr != NULL)
        {
            char v = ptr[0] & 0xDF;
            if(answer.X < 0 && v >= 'A' && v <= (COLS + 'A')) {
                answer.X = v - 'A';
            }
            int val = atoi(ptr);
            if (answer.Y < 0 && val > 0 && val <= ROWS) {
                answer.Y = val - 1;
            }
            ptr = strtok(NULL, delim);
        }
    } while (answer.X < 0 || answer.Y < 0);
    free(buffer);
    return answer;
}