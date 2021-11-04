#include "screen.h"

#ifndef __GAME_H__
#define __GAME_H__

#define COLS 10
#define ROWS 10

typedef struct _shipType{
    char type;
    int length;
    char* name;
} ShipType;

void initBoard(char board[][ROWS]);
void printBoard(char board[][ROWS]);
COORD readCoordinates();
void addShip(char board[][ROWS], ShipType shipType);
void addCPUShip(char board[][ROWS], ShipType shipType);

#endif