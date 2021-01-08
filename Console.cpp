#include "Console.h"

// Di chuyen dau nhay man hinh den vi tri co toa do (x, y)
void GoToXY(int x, int y) {
	COORD position = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // set toa do
}

// Chinh kich thuoc man hinh console voi chieu dai la width, chieu cao la height
void ResizeConsole(int width, int height) {
	HWND console = GetConsoleWindow(); // lay thong tin hien tai cua console
	RECT edge;
	GetWindowRect(console, &edge);
	MoveWindow(console, edge.left, edge.top, width, height, TRUE); // chinh kich thuoc
}

void FixConsoleWindow() {
	HWND console = GetConsoleWindow();
	LONG style = GetWindowLong(console, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(console, GWL_STYLE, style);
	RECT rectScreen;
	GetWindowRect(console, &rectScreen);
	int ConsolePosX;
	int ConsolePosY;
	int Width = rectScreen.right - rectScreen.left;
	int Height = rectScreen.bottom - rectScreen.top;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(console, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);
}

void ShowConsoleCursor(bool show) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void TextColor(int colorCode) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}