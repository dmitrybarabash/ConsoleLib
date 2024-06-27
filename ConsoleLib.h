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

#ifndef __CONSOLELIB_H__
#define __CONSOLELIB_H__

#include <windows.h>

// Console handles
extern HANDLE hStdOut;
extern HANDLE hStdIn;

// Colors
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
	White         = 15,

	black         = 0,
	blue          = 1,
	green         = 2,
	cyan          = 3,
	red           = 4,
	magenta       = 5,
	brown         = 6,
	light_gray    = 7,
	dark_gray     = 8,
	light_blue    = 9,
	light_green   = 10,
	light_cyan    = 11,
	light_red     = 12,
	light_magenta = 13,
	yellow        = 14,
	white         = 15
};

// Gets a width of console buffer
int GetConsoleBufferSizeX();
// Gets a height of console buffer
int GetConsoleBufferSizeY();
// Set a size of console buffer
void SetConsoleBufferSize(int x, int y);

// Gets a width of console
int GetConsoleSizeX();
// Gets a height of console
int GetConsoleSizeY();
// Set a size of console and console buffer
void SetConsoleSize(int x, int y);

// Clears console
void ClearScreen();

// Shows/hides cursor.
// Gets a previous visibility of cursor.
bool ShowCursor(bool visible);

// Sets a current foreground and background colors.
// Gets a previous foreground and background colors as a color attribute.
unsigned SetColor(ConsoleColor text, ConsoleColor background);
unsigned SetColor(unsigned colorAttr);

// Moves the cursor to the specified coordinates
void GotoXY(int x, int y);

// Prints the string at the specified coordinates
void WriteStr(int x, int y, const char *str);

// Prints the character at the specified coordinates
void WriteChar(int x, int y, char ch);

// Prints the number of the character starting at the specified position
void WriteChars(int x, int y, char ch, unsigned length);

// Changes the text attributes of the specified number of characters, starting at the specified position
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length);


// For those who prefer the snake style
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
