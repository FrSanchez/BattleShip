#include <stdio.h>

#pragma once

#define ESC "\x1b"
#define CSI "\x1b["

typedef struct _COORD {
    int X, Y;
} COORD;

void cls();
void enterAlternateBuffer();
void exitAlternateBuffer();
COORD getTerminalSize();
void printVerticalBorder();
void printHorizontalBorder(int sizeX, short isTop);