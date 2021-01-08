#include "GameController.h"

void NewGame(int & Xicon, int & Oicon, int & win, int & sizeboard, int & SttPP, int & gamewinPP, int & gamedrawPP, int & SttPC, int & gamewinPC, int & gamedrawPC)
{
	system("cls");
	DrawChooseMode();
	int chooseMode = GetChooseButton(2);

	int first = ChooseFirstPlayer(chooseMode);

	char map[15][15];
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			map[i][j] = ' ';
		}
	}

	DrawMap(sizeboard, map);

	switch (chooseMode) {
	case 0:
		PvP(map, first, sizeboard, Xicon, Oicon, win, SttPP, gamewinPP, gamedrawPP);
		break;
	case 1:
		PvC(map, first, sizeboard, Xicon, Oicon, win, SttPC, gamewinPC, gamedrawPC);
		break;
	}
}

int ChooseFirstPlayer(int chooseMode) {
	GoToXY(39, 10);
	int player;
	srand(time(NULL));
	player = rand() % 2 + 1;
	TextColor(12);
	cout << "Player " << player << " will go first.";
	TextColor(6);
	GoToXY(21, 20);
	for (int i = 0; i < 60; ++i) {
		Sleep(30);
		cout << char(219);
	}
	TextColor(15);
	return player;
}

//Load Game
void ChooseModeLoadGame(int& Xicon, int& Oicon, int& win, int& SttPP, int& gamewinPP, int& gamedrawPP, int& SttPC, int& gamewinPC, int& gamedrawPC)
{
	system("cls");
	DrawChooseModeLoadGame();
	int chooseModeLoadGame = GetChooseButton(2);
	switch (chooseModeLoadGame) {
	case 0:
		LoadGamePvP(Xicon, Oicon, win, SttPP, gamewinPP, gamedrawPP);
		break;
	case 1:
		LoadGamePvC(Xicon, Oicon, win, SttPC, gamewinPC, gamedrawPC);
	}
}

void LoadGamePvP(int& Xicon, int& Oicon, int& win, int& SttPP, int& gamewinPP, int& gamedrawPP)
{
	system("cls");
	int size, turn;
	char map[15][15];

	char listSaveFiles[50][50];
	int countFiles = 0;
	ReadListSaveFiles1(listSaveFiles, countFiles);
	system("cls");
	int i;
	for (i = 0; i < countFiles; ++i) {
		GoToXY(30, i + 1);
		cout << i << ".\t" << listSaveFiles[i];
	}
	int choose;
	do {
		GoToXY(30, i + 1);
		cout << "                                            ";
		GoToXY(30, i + 1);
		cout << "Choose your save game (" << 0 << " - " << countFiles - 1 << "): ";
		cin >> choose;
		if (countFiles == 0)
			break;
		else if (choose < 0 || choose >= countFiles) {
			continue;
		}
		break;
	} while (true);

	ifstream fin(listSaveFiles[choose]);
	if (fin.fail()) {
		cout << "Invalid file save. Game will automatically closed.";
		exit(0);
	}
	fin >> size >> turn;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			fin >> map[i][j];
			switch (map[i][j]) {
			case 'N':
				map[i][j] = ' ';
			}
		}
	}
	fin.close();

	switch (size) {
	case 3:
		DrawMap(3, map);
		break;
	case 5:
		DrawMap(5, map);
		break;
	case 10:
		DrawMap(10, map);
		break;
	}
	PvP(map, turn, size, Xicon, Oicon, win, SttPP, gamewinPP, gamedrawPP);
}


void LoadGamePvC(int& Xicon, int& Oicon, int& win, int& SttPC, int& gamewinPC, int& gamedrawPC) {
	system("cls");
	int size, turn;
	char map[15][15];

	char listSaveFiles2[50][50];
	int countFiles2 = 0;
	ReadListSaveFiles2(listSaveFiles2, countFiles2);
	system("cls");
	int i;
	for (i = 0; i < countFiles2; ++i) {
		GoToXY(30, i + 1);
		cout << i << ".\t" << listSaveFiles2[i];
	}
	int choose;
	do {
		GoToXY(30, i + 1);
		cout << "                                            ";
		GoToXY(30, i + 1);
		cout << "Choose your save game (" << 0 << " - " << countFiles2 - 1 << "): ";
		cin >> choose;
		if (countFiles2 == 0)
			break;
		else if (choose < 0 || choose >= countFiles2) {
			continue;
		}
		break;
	} while (true);

	ifstream fin2(listSaveFiles2[choose]);
	if (fin2.fail()) {
		cout << "Invalid file save. Game will automatically closed.";
		exit(0);
	}
	fin2 >> size >> turn;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			fin2 >> map[i][j];
			switch (map[i][j]) {
			case 'N':
				map[i][j] = ' ';
			}
		}
	}
	fin2.close();

	switch (size) {
	case 3:
		DrawMap(3, map);
		break;
	case 5:
		DrawMap(5, map);
		break;
	case 10:
		DrawMap(10, map);
		break;
	}
	PvC(map, turn, size, Xicon, Oicon, win, SttPC, gamewinPC, gamedrawPC);
}