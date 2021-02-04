/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 3.0.0]                                     */
/*    ���������� �������-������� ��� ������ � ��������               */
/*                                                                   */
/*    Copyright (�) 2006-2019, ������� �������                       */
/*                                                                   */
/*    E-mail:   dmitry@barabash.com                                  */
/*    Web:      http://itstep.barabash.com                           */
/*                                                                   */
/*********************************************************************/

#include <iostream>
using namespace std;

#include <windows.h>
#include "ConsoleLib.h"


// ������ �������
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

// ���������� ������ ������ �������
int GetConsoleBufferSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.X;
}

// ���������� ������ ������ �������
int GetConsoleBufferSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.Y;
}

// ������������� ������ ������ ������ �������
void SetConsoleBufferSize(int x, int y)
{
	COORD conSize = { (SHORT)x, (SHORT)y };
	SetConsoleScreenBufferSize(hStdOut, conSize);
}

// ���������� ������ �������
int GetConsoleSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Right + 1;
}

// ���������� ������ �������
int GetConsoleSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Bottom + 1;
}

// ������������� ������ ������ �������
void SetConsoleSize(int x, int y)
{
	SMALL_RECT rect = { 0, 0, (SHORT)(x - 1), (SHORT)(y - 1) };
	SetConsoleWindowInfo(hStdOut, TRUE, &rect);
}

// ������� �������
void ClearScreen()
{
   COORD coordScreen = { 0, 0 };
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;
   DWORD dwConAttr;

   // �������� ����� ���������� �������� ������� � ������� ���� �������
   GetConsoleScreenBufferInfo(hStdOut, &csbi);
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   dwConAttr = csbi.wAttributes;

   // ��������� ������� ���������
   FillConsoleOutputCharacter(hStdOut, ' ', dwConSize, coordScreen, &cCharsWritten);
   // ��������� ������� ������� ������ �������
   FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

   // ������������� ������ � ����� ������� ���� �������
   SetConsoleCursorPosition(hStdOut, coordScreen);
}

// ����������/������ ��������� ������.
// ���������� ���������� ������ �������.
bool ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci) };
	GetConsoleCursorInfo(hStdOut, &cci);

	bool prevVisible = cci.bVisible;

	cci.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &cci);

	return prevVisible;
}

// ������������� ������� ���� �������� � ����.
// ���������� ���������� ������� ���� �������� � ����.
unsigned SetColor(unsigned colorAttr)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi = { sizeof(csbi) };
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    SetConsoleTextAttribute(hStdOut, (WORD)colorAttr);

    return csbi.wAttributes;
}

// ������������� ������� ���� �������� � ����.
// ���������� ���������� ������� ���� �������� � ����.
unsigned SetColor(ConsoleColor text, ConsoleColor background)
{
    return SetColor((WORD)((background << 4) | text));
}

// ���������� ������ � �������� �������
void GotoXY(int x, int y)
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// ������� �������� ������ � �������� �������
void WriteStr(int x, int y, const char *str)
{
    GotoXY(x, y);
    cout << str << flush;
}

// ������� �������� ������ � �������� �������
void WriteChar(int x, int y, char ch)
{
	GotoXY(x, y);
	cout << ch;
}

// ������� �������� ������ � �������� ����������, ������� � �������� �������
void WriteChars(int x, int y, char ch, unsigned length)
{
	GotoXY(x, y);
	for (unsigned i = 0; i < length; i++)
		cout << ch;
}

// ������ ��������� �������� ���������� ���������� ��������, ������� � �������� �������
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length)
{
	COORD coord = { (SHORT)x, (SHORT)y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), length, coord, &dwDummy);
}
