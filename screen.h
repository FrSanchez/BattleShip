#include <stdio.h>
#include "ansi-colors.h"
#ifndef __SCREEN_H__
#define __SCREEN_H__

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

#endif