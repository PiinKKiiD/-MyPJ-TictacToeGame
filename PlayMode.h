#pragma once
#ifndef PLAY_MODE_H
#define PLAY_MODE_H

#include "Controller.h"

int PvP(char map[15][15], int first, int size, int Xicon, int Oicon, int win, int& SttPP, int& gamewinPP, int& gamedrawPP);

int PvC(char map[15][15], int first, int size, int Xicon, int Oicon, int win, int& SttPC, int& gamewinPC, int& gamedrawPC);

#endif