#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
using namespace std;

// Di chuyen dau nhay man hinh den vi tri co toa do (x, y)
void GoToXY(int x, int y);

// Chinh kich thuoc man hinh console voi chieu dai la width, chieu cao la height
void ResizeConsole(int width, int height);

// Co dinh kich thuoc man hinh, khong cho nguoi dung choi bay
void FixConsoleWindow();

// Tat/bat con tro console
void ShowConsoleCursor(bool show);

void TextColor(int colorCode);

#endif // !CONSOLE_H