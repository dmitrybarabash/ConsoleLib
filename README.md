# ConsoleLib

A simple library of wrapper functions for the Console Windows API.

Example how to use some of library features:
```c++
#include <conio.h>
#include "consolelib.h"

int main()
{
	const int Esc = 27;
	const int Up = 72;
	const int Left = 75;
	const int Right = 77;
	const int Down = 80;

	ShowCursor(false);
	SetColor(Yellow, Black);
	ClearScreen();

	int x = GetConsoleSizeX() / 2;
	int y = GetConsoleSizeY() / 2;

	int key;

	do
	{
		WriteChar(x, y, '+');

		key = _getch();
		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			WriteChar(x, y, ' ');

			switch (key)
			{
			case Up:
				if (y > 0) y--;
				break;
			case Left:
				if (x > 0) x--;
				break;
			case Right:
				if (x < GetConsoleSizeX() - 1) x++;
				break;
			case Down:
				if (y < GetConsoleSizeY() - 1) y++;
				break;
			}
		}
	}
	while (key != Esc);

	ShowCursor(true);
	SetColor(LightGray, Black);
	ClearScreen();

	return 0;
}
```

Or the same with snake style:
```c++
#include <conio.h>
#include "consolelib.h"

int main()
{
	const int Esc = 27;
	const int Up = 72;
	const int Left = 75;
	const int Right = 77;
	const int Down = 80;

	show_cursor(false);
	set_color(yellow, black);
	clear_screen();

	int x = get_console_size_x() / 2;
	int y = get_console_size_y() / 2;

	int key;

	do
	{
		write_char(x, y, '+');

		key = _getch();
		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			write_char(x, y, ' ');

			switch (key)
			{
			case Up:
				if (y > 0) y--;
				break;
			case Left:
				if (x > 0) x--;
				break;
			case Right:
				if (x < get_console_size_x() - 1) x++;
				break;
			case Down:
				if (y < get_console_size_y() - 1) y++;
				break;
			}
		}
	}
	while (key != Esc);

	show_cursor(true);
	set_color(light_gray, black);
	clear_screen();

	return 0;
}
```
