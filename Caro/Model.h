#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "Controller.h"

int GetChooseButton(int numberOfButtons);

bool CheckWin(char map[15][15], int size, Point position);

bool CheckDraw(char map[15][15], int size);

bool CheckWinOption(char map[15][15], int size, Point position);

//Doc file save game pvp (file co .s duoi)
void ReadListSaveFiles1(char listFiles[50][50], int & countFiles);

//Doc file save game pvc (file co .m duoi)
void ReadListSaveFiles2(char listFiles[50][50], int & countFiles);

// (file co .w duoi)
void ReadListWinFiles(char listFiles[50][50], int & countFiles);

//Doc file game trong Statistics (file co .d duoi)
void ReadListWinFiles2(char listFiles[50][50], int & countFiles);

#endif // !MODEL_H