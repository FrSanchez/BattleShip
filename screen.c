#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "screen.h"

void enterAlternateBuffer()
{
    printf(CSI "?1049h");
}

void cls()
{
    printf(CSI "2J");
}

void exitAlternateBuffer()
{
    printf(CSI "?1049l");
}

COORD getTerminalSize()
{
    COORD Size;
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    Size.X = ts.ts_cols;
    Size.Y = ts.ts_lines;
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    Size.X = ts.ws_col;
    Size.Y = ts.ws_row;
#endif /* TIOCGSIZE */
    return Size;
}

void printVerticalBorder()
{
    printf(ESC "(0"); // Enter Line drawing mode
    printf(CSI "104;93m"); // bright yellow on bright blue
    printf("x"); // in line drawing mode, \x78 -> \u2502 "Vertical Bar"
    printf(CSI "0m"); // restore color
    printf(ESC "(B"); // exit line drawing mode
}

void printHorizontalBorder(int sizeX, short isTop)
{
    printf(ESC "(0"); // Enter Line drawing mode
    printf(CSI "104;93m"); // Make the border bright yellow on bright blue
    printf(isTop ? "l" : "m"); // print left corner 

    for (int i = 1; i < sizeX - 1; i++)
        printf("q"); // in line drawing mode, \x71 -> \u2500 "HORIZONTAL SCAN LINE-5"

    printf(isTop ? "k" : "j"); // print right corner
    printf(CSI "0m");
    printf(ESC "(B"); // exit line drawing mode
}