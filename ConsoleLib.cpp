/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 3.0.1]                                     */
/*    A library of wrapper functions for the Console Windows API.    */
/*                                                                   */
/*    Copyright (c) 2006-2024, Dmitry Barabash                       */
/*                                                                   */
/*    E-mail:   dmitry@barabash.com                                  */
/*    Web:      https://www.barabash.com                             */
/*                                                                   */
/*********************************************************************/

#include <iostream>
using namespace std;

#include <windows.h>
#include "ConsoleLib.h"


// Console handles
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

int GetConsoleBufferSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.X;
}

// Gets a height of console buffer
int GetConsoleBufferSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.Y;
}

// Set a size of console buffer
void SetConsoleBufferSize(int x, int y)
{
	COORD conSize = { (SHORT)x, (SHORT)y };
	SetConsoleScreenBufferSize(hStdOut, conSize);
}

// Gets a width of console
int GetConsoleSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Right + 1;
}

// Gets a height of console
int GetConsoleSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Bottom + 1;
}

// Set a size of console and console buffer
void SetConsoleSize(int x, int y)
{
	SMALL_RECT rect = { 0, 0, (SHORT)(x - 1), (SHORT)(y - 1) };
	SetConsoleWindowInfo(hStdOut, TRUE, &rect);
}

// Clears console
void ClearScreen()
{
   COORD coordScreen = { 0, 0 };
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;
   DWORD dwConAttr;

   // Get the total number of console characters and the current colour of the console
   GetConsoleScreenBufferInfo(hStdOut, &csbi);
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   dwConAttr = csbi.wAttributes;

   // Fill the console with spaces
   FillConsoleOutputCharacter(hStdOut, ' ', dwConSize, coordScreen, &cCharsWritten);
   // Fill the console with the current console colour
   FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

   // Move the cursor in the upper left corner of the console
   SetConsoleCursorPosition(hStdOut, coordScreen);
}

// Shows/hides cursor.
// Gets a previous visibility of cursor.
bool ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci) };
	GetConsoleCursorInfo(hStdOut, &cci);

	bool prevVisible = cci.bVisible;

	cci.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &cci);

	return prevVisible;
}

// Sets a current foreground and background colors.
// Gets a previous foreground and background colors as a color attribute.
unsigned SetColor(unsigned colorAttr)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi = { sizeof(csbi) };
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    SetConsoleTextAttribute(hStdOut, (WORD)colorAttr);

    return csbi.wAttributes;
}

// Sets a current foreground and background colors.
// Gets a previous foreground and background colors as a color attribute.
unsigned SetColor(ConsoleColor text, ConsoleColor background)
{
    return SetColor((WORD)((background << 4) | text));
}

// Moves the cursor to the specified coordinates
void GotoXY(int x, int y)
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// Prints the string at the specified coordinates
void WriteStr(int x, int y, const char *str)
{
    GotoXY(x, y);
    cout << str << flush;
}

// Prints the character at the specified coordinates
void WriteChar(int x, int y, char ch)
{
	GotoXY(x, y);
	cout << ch;
}

// Prints the number of the character starting at the specified position
void WriteChars(int x, int y, char ch, unsigned length)
{
	GotoXY(x, y);
	for (unsigned i = 0; i < length; i++)
		cout << ch;
}

// Changes the text attributes of the specified number of characters, starting at the specified position
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length)
{
	COORD coord = { (SHORT)x, (SHORT)y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), length, coord, &dwDummy);
}
