#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "Controller.h"

int GetChooseButton(int numberOfButtons);

bool CheckWin(char map[15][15], int size, Point position);

bool CheckDraw(char map[15][15], int size);

bool CheckWinOption(char map[15][15], int size, Point position);

void ReadListSaveFiles1(char listFiles[50][50], int & countFiles);

void ReadListSaveFiles2(char listFiles[50][50], int & countFiles);

void ReadListWinFiles(char listFiles[50][50], int & countFiles);


void ReadListWinFiles2(char listFiles[50][50], int & countFiles);

#endif // !MODEL_H