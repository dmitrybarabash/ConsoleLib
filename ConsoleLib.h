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

#ifndef __CONSOLELIB_H__
#define __CONSOLELIB_H__

#include <windows.h>

// ������ �������
extern HANDLE hStdOut;
extern HANDLE hStdIn;

// �����
enum ConsoleColor
{
	Black         = 0,
	Blue          = 1,
	Green         = 2,
	Cyan          = 3,
	Red           = 4,
	Magenta       = 5,
	Brown         = 6,
	LightGray     = 7,
	DarkGray      = 8,
	LightBlue     = 9,
	LightGreen    = 10,
	LightCyan     = 11,
	LightRed      = 12,
	LightMagenta  = 13,
	Yellow        = 14,
	White         = 15
};

// ���������� ������ ������ �������
int GetConsoleBufferSizeX();
// ���������� ������ ������ �������
int GetConsoleBufferSizeY();
// ������������� ������ ������ ������ �������
void SetConsoleBufferSize(int x, int y);

// ���������� ������ �������
int GetConsoleSizeX();
// ���������� ������ �������
int GetConsoleSizeY();
// ������������� ������ ������ ������� � ������ �������
void SetConsoleSize(int x, int y);

// ������� �������
void ClearScreen();

// ����������/������ ��������� ������.
// ���������� ���������� ������ �������.
bool ShowCursor(bool visible);

// ������������� ������� ���� �������� � ����.
// ���������� ���������� ������� ���� �������� � ����.
unsigned SetColor(ConsoleColor text, ConsoleColor background);
unsigned SetColor(unsigned colorAttr);

// ���������� ������ � �������� �������
void GotoXY(int x, int y);

// ������� �������� ������ � �������� �������
void WriteStr(int x, int y, const char *str);

// ������� �������� ������ � �������� �������
void WriteChar(int x, int y, char ch);

// ������� �������� ������ � �������� ����������, ������� � �������� �������
void WriteChars(int x, int y, char ch, unsigned length);

// ������ ��������� �������� ���������� ���������� ��������, ������� � �������� �������
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length);


// ��� ���, ��� ������������ snake-�����
#define console_color ConsoleColor
#define get_console_buffer_size_x GetConsoleBufferSizeX
#define get_console_buffer_size_y GetConsoleBufferSizeY
#define set_console_buffer_size SetConsoleBufferSize
#define get_console_size_x GetConsoleSizeX
#define get_console_size_y GetConsoleSizeY
#define set_console_size SetConsoleSize
#define clear_screen ClearScreen
#define show_cursor ShowCursor
#define set_color SetColor
#define gotoxy GotoXY
#define write_str WriteStr
#define write_char WriteChar
#define write_chars WriteChars
#define change_text_attr ChangeTextAttr

#endif // __CONSOLELIB_H__
