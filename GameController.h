#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Controller.h"

void NewGame(int& Xicon, int& Oicon, int& win, int& sizeboard, int& SttPP, int& gamewinPP, int& gamedrawPP, int& SttPC, int& gamewinPC, int& gamedrawPC);

int ChooseFirstPlayer(int choosemode);

void ChooseModeLoadGame(int& Xicon, int& Oicon, int& win, int& SttPP, int& gamewinPP, int& gamedrawPP, int& SttPC, int& gamewinPC, int& gamedrawPC);

void LoadGamePvP(int& Xicon, int& Oicon, int& win, int& SttPP, int& gamewinPP, int& gamedrawPP);

void LoadGamePvC(int& Xicon, int& Oicon, int& win, int&SttPc, int& gamewinPC, int& gamedrawPC);

#endif // !GAME_CONTROLLER_H
