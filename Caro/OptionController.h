#pragma once
#ifndef OPTION_CONTROLLER_H
#define OPTION_CONTROLLER_H

#include "Controller.h"

int option();

void ControllOption(int& Xicon, int& Oicon, int& win, int& sizeboard, int& SttPP, int& gamewinPP, int& gamedrawPP, int& SttPC, int& gamewinPC, int& gamedrawPC);

void ChangeAllIcon(int& Xicon, int& Oicon, int& win);

void ChangeSIZEgameboard(int& sizeboard);

void ChangeRule(int& win);

void LoadWinPvP();

void LoadWinPvC();

void Statistic(int SttPP, int gamewinPP, int gamedrawPP, int SttPC, int gamewinPC, int gamedrawPC);

#endif // !OPTION_CONTROLLER_H

