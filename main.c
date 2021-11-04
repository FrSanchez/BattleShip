#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"
#include "game.h"


// Carrier 5
// Battlship 4
// cRuiser 3
// Submarine 3
 // Destroyer 2
ShipType GameShips[] = {{'c', 5, "Carrier"}, 
{'b', 4, "Battleship"}, 
{'r', 3, "Cruiser"}, 
{'s', 3, "Submarine"}, 
{'d', 2, "Destroyer"}};


int main(int argc, char** argv)
{
    srand(time(NULL));
    COORD Size = getTerminalSize();
    // enterAlternateBuffer();
    cls();
    
    char player1[COLS][ROWS];
    char player2Boats[COLS][ROWS];
    char player2Hits[COLS][ROWS];
    initBoard(player1);
    initBoard(player2Boats);
    initBoard(player2Hits);
    printBoard(player1);
    printBoard(player2Hits);

    ShipType shipType;
    shipType.length = 5;
    shipType.type = 'c';
    // for(int i = 0; i < 5; i++) {
    //     addShip(player1, GameShips[i]);
    //     printBoard(player1);
    // }

    puts("Placing player2 ships");
    for(int i = 0; i < 5; i++) {
        addCPUShip(player2Boats, GameShips[i]);
        printBoard(player2Boats);
    }
    printBoard(player2Boats);
    printf("Press any key to exit");
    char ch = getc(stdin);
    // exitAlternateBuffer();
    return 0;
}