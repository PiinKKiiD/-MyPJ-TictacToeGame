#pragma once
#ifndef DRAW_H
#define DRAW_H

#include "Controller.h"

void TargetButton(int whichButton, bool on);

void DrawFrame(Point positionToDraw, int length, int height, char text[]);

void DrawChooseMapMenu();

void DrawMap(int size, char map[15][15]);

void DrawChooseMode();

void DrawChooseModeLoadGame();

#endif // !DRAW_H
