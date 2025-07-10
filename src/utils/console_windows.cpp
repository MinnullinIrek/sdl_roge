// #include "console_windows.h"
//
// ConsoleWindows::ConsoleWindows(SHORT width, SHORT height)
//{
//	consoleOutput	= (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
//	bufferSize		= {width, height};
//	bufferCoord		= {0, 0};
//	region			= {0, 0, --width, --height};
//
//	ReadConsoleOutputA(consoleOutput, (CHAR_INFO *) buffer, bufferSize, bufferCoord, &region);
//
//	BYTE values[256];
//	GetKeyboardState(values);
//	for (int i = 0; i < 256; ++i)
//		keys[i] = values[i] & 0x0001;
// }
//
// void ConsoleWindows::fillCell(SHORT x, SHORT y, CHAR c, WORD attr)
//{
//	buffer[y][x].Attributes		= attr;
//	buffer[y][x].Char.AsciiChar	= c;
// }
//
// void ConsoleWindows::drawBuffer()
//{
//	WriteConsoleOutputA(consoleOutput, (CHAR_INFO*) buffer, bufferSize, bufferCoord, &region);
// }
//
// void ConsoleWindows::drawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows)
//{
//	SMALL_RECT region = {x, y, x + columns - 1, y + rows - 1};
//	WriteConsoleOutputA(consoleOutput, (CHAR_INFO*)buffer, bufferSize, {x, y}, &region);
// }
//
// void ConsoleWindows::fillBuffer(CHAR c, WORD attr)
//{
//	CHAR_INFO ci;
//	ci.Attributes		= attr;
//	ci.Char.AsciiChar	= c;
//
//	for(unsigned short y = 0; y < SCREEN_HEIGHT; ++y)
//		for(unsigned short x = 0; x < SCREEN_WIDTH; ++x)
//			buffer[y][x] = ci;
// }
//
// bool ConsoleWindows::isKeyDown(int key)
//{
//	return (GetAsyncKeyState(key) & 0x8000);
// }
//
// bool ConsoleWindows::isKeyPressed(int key)
//{
//	bool toggled	= keys[key];
//	keys[key]		= GetKeyState(key) & 0x0001;
//
//	return toggled != keys[key];
// }
//
// void ConsoleWindows::drawFrame(int x, int y, int w, int h, FrameType type, unsigned char attr)
//{
//	--w; --h;
//	static const char c[2][6] = {	{(char) 201, (char) 187, (char) 200, (char) 188, (char) 205, (char) 186},
//									{(char) 218, (char) 191, (char) 192, (char) 217,
//(char) 196, (char) 179}};
//
//	// Corners
//	fillCell(x,			y, c[type][0], attr); // '╔' | '┌'
//	fillCell(x + w,		y, c[type][1], attr); // '╗' | '┐'
//	fillCell(x,		y + h, c[type][2], attr); // '╚' | '└'
//	fillCell(x + w, y + h, c[type][3], attr); // '╝' | '┘'
//	for (int i = x + 1; i < x + w; ++i)
//	{
//		fillCell(i,		y, c[type][4], attr); // '═' | '─'
//		fillCell(i, y + h, c[type][4], attr); // '═' | '─'
//	}
//	for (int i = y + 1; i < y + h; ++i)
//	{
//		fillCell(x,		i, c[type][5], attr); // '║' | '│'
//		fillCell(x + w,	i, c[type][5], attr); // '║' | '│'
//	}
// }
//
// void ConsoleWindows::drawWords(int x, int y, const char* text, size_t n, unsigned char attr)
//{
//	if (n == NULL)	n = strlen(text);
//
//	for (int i = 0; i < n; ++i)
//		fillCell(x + i, y, text[i], attr);
// }
//
// void ConsoleWindows::setTitle(const char* title)
//{
//	SetConsoleTitle(title);
// }
//
// void ConsoleWindows::setWindowSize(SHORT width, SHORT height, bool adjustBuffer)
//{
//	SMALL_RECT rect = {0, 0, width, height};
//	if (adjustBuffer) SetConsoleScreenBufferSize(consoleOutput, {width, height});
//	SetConsoleWindowInfo(consoleOutput, TRUE, &rect);
// }
//
// void ConsoleWindows::showConsoleCursor(BOOL visible)
//{
//	CONSOLE_CURSOR_INFO cursorInfo;
//	GetConsoleCursorInfo(consoleOutput, &cursorInfo);
//	cursorInfo.bVisible = visible;
//	SetConsoleCursorInfo(consoleOutput, &cursorInfo);
// }
//
//
// void ConsoleWindows::gotoxy(SHORT x, SHORT y)
//{
//	SetConsoleCursorPosition(consoleOutput, {x, y});
// }
//
//
