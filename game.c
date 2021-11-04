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
            char *color = reset;
            switch(board[x][y]) {
                case '-':
                    color = HBLU; break;
                case 'c':
                    color = RED; break;
                case 's':
                    color = GRN; break;
                case 'd':
                    color = YEL; break;
                case 'r':
                    color = CYN; break;
                case 'b':
                    color = MAG; break;
            }
            printf(" %s%c" reset " ", color, board[x][y]);
        }
        printVerticalBorder();
        printf("\n");
    }
    printf("   ");
    printHorizontalBorder(COLS * 3 + 2, 0);
    printf("\n");
}

COORD readCoordinates(const char* message)
{
    COORD answer; 
    answer.X = -1;
    answer.Y = -1;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    

    do {
        printf(message);
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

int createShipArray(COORD newShip, COORD ship[], int shipLength, char c)
{
    for(int i = 0; i < shipLength; i++) {
        COORD cI; 
        if (c=='R') {
            cI.X = newShip.X + i;
            cI.Y = newShip.Y;
            ship[i] = cI;
        } else {
            cI.X = newShip.X;
            cI.Y = newShip.Y + i;
            ship[i] = cI;
        }
        if (ship[i].X < 0 || ship[i].X >= COLS || ship[i].Y <0 || ship[i].Y >= ROWS) {
            return 0;
        }
    }
    return 1;
}

int isSpaceAvailable(char board[][ROWS], COORD ship[], ShipType shipType) 
{
    for(int i = 0 ; i < shipType.length; i++) {
        if(board[ship[i].X][ship[i].Y] != '-') {
            return 0;
        }
    }
    return 1;
}

void stampShip(char board[][ROWS], COORD ship[], ShipType shipType) 
{
    for(int i = 0 ; i < shipType.length; i++) {
        board[ship[i].X][ship[i].Y] = shipType.type;
    }
}

void addShip(char board[][ROWS], ShipType shipType)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    char c = '\0';
    short empty = 1;
    COORD ship[shipType.length];

    puts(shipType.name);
    do {
        empty = 1;
        COORD newShip = readCoordinates("Enter coordinates for tip of the ship: ");
        do {
            printf("The ship extends to the (R)ight or (D)down? (R/D) ");
            lineSize = getline(&buffer, &len, stdin);
            c = buffer[0] & 0xDF;
        } while(c!='R' && c!='D' );

        printf("Checking...");
        if (createShipArray(newShip, ship, shipType.length, c) && 
            isSpaceAvailable(board, ship, shipType)) {
                    puts("...valid");
        } else {
            empty = 0;
            puts("...invalid");
        }
    } while(!empty);

    stampShip(board, ship, shipType);
}

void addCPUShip(char board[][ROWS], ShipType shipType)
{
    COORD ship[shipType.length];
    do {
    int x = rand() % COLS;
    int y = rand() % ROWS;
    int dir = rand() % 2;
    char c = dir ? 'R' : 'D';
    COORD newShip = {x,y};
    printf("Evaluating %s tip (%d,%d), dir %c\n", shipType.name, x, y, c);
    if (createShipArray(newShip, ship, shipType.length, c) && 
            isSpaceAvailable(board, ship, shipType)) {
                stampShip(board, ship, shipType);
            return;
            }
    } while(1==1);
}

