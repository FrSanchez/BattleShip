#include "screen.h"
#include "game.h"

void printStatusLine(const char* const pszMessage, COORD const Size)
{
    printf(CSI "%d;1H", Size.Y);
    printf(CSI "K"); // clear the line
    printf(pszMessage);
}

int main(int argc, char** argv)
{
    COORD Size = getTerminalSize();
    enterAlternateBuffer();
    cls();
    
    char player1[COLS][ROWS];
    char player2[COLS][ROWS];
    initBoard(player1);
    initBoard(player2);
    printBoard(player1);
    printBoard(player2);
    
    // printStatusLine("Press any key to exit", Size);
    printf("Press any key to exit");
    char ch = getchar();
    exitAlternateBuffer();
    return 0;
}