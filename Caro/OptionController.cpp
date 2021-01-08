#include "OptionController.h"

int option()
{
	int m;

	system("cls");
	
	//Print Option content
	GoToXY(30, 2);
	cout << " -------------- OPTION --------------";
	GoToXY(30, 4);
	cout << "1 . Change icon. ";
	GoToXY(30, 6);
	cout << "2 . Change rules.";
	GoToXY(30, 8);
	cout << "3 . Change size of gameboard.";
	GoToXY(30, 10);
	cout << "4 . Statistic. ";
	GoToXY(30, 13);
	cout << " ====>> ";
	cin >> m;

	//Enter until enter correctly
	while (m != 1 && m != 2 && m != 3 && m != 4) {
		GoToXY(30, 15);
		cout << "                                  ";
		GoToXY(30, 15);
		cout << "Choose again.";
		GoToXY(30, 13);
		cout << "                            ";
		GoToXY(30, 13);
		cout << " ====>> ";
		cin >> m;
	}
	return m;
}

void ControllOption(int& Xicon, int& Oicon, int& win, int& sizeboard, int& SttPP, int& gamewinPP, int& gamedrawPP, int& SttPC, int& gamewinPC, int& gamedrawPC)
{
	int i = option();
	if (i == 0)
		option();
	else
		if (i == 1)
			ChangeAllIcon(Xicon, Oicon, win);
		else
			if (i == 3)
				ChangeSIZEgameboard(sizeboard);
			else
				if (i == 2)
					ChangeRule(Xicon, Oicon, win);
				else
					Statistic(SttPP, gamewinPP, gamedrawPP, SttPC, gamewinPC, gamedrawPC);
}

int changeIconX()
{
	int i;
	system("cls");
	GoToXY(30, 2);
	cout << "--- CHANGE ICON ---";
	GoToXY(30, 4);
	cout << "1 . " << char(1);
	GoToXY(30, 6);
	cout << "2 . " << char(2);
	GoToXY(30, 8);
	cout << "3 . " << char(3);
	GoToXY(30, 10);
	cout << "4 . " << char(4);
	GoToXY(30, 12);
	cout << "5 . " << char(11);
	GoToXY(30, 14);
	cout << "6 . " << char(12);
	GoToXY(30, 18);
	cout << "Change X into : ";
	cin >> i;

	//Change Icon X
	if (i == 5)
		i = 11;
	else
		if (i == 6)
			i = 12;
		else
			i = i;
	return i;
}

int ChangeIconO()
{
	int j;

	system("cls");
	
	GoToXY(30, 2);
	cout << "--- CHANGE ICON ---";
	GoToXY(30, 4);
	cout << "1 . " << char(1);
	GoToXY(30, 6);
	cout << "2 . " << char(2);
	GoToXY(30, 8);
	cout << "3 . " << char(3);
	GoToXY(30, 10);
	cout << "4 . " << char(4);
	GoToXY(30, 12);
	cout << "5 . " << char(11);
	GoToXY(30, 14);
	cout << "6 . " << char(12);
	GoToXY(30, 18);
	cout << "Change O into : ";
	cin >> j;

	//Change Icon O
	if (j == 5)
		j = 11;
	else
		if (j == 6)
			j = 12;
		else
			j = j;
	return j;
}

void ChangeAllIcon(int& Xicon, int &Oicon, int win)
{
	Oicon = ChangeIconO();
	Xicon = changeIconX();

	//Enter until enter correctly
	if (Oicon == Xicon)
	{
		GoToXY(30, 20);
		cout << "X and O are the same icons. Choose again !!";
		GoToXY(30, 22);
		system("pause");
		ChangeAllIcon(Xicon, Oicon, win);
	}
}

void ChangeSIZEgameboard(int& sizeboard)
{
	system("cls");
	DrawChooseMapMenu();
	int chooseMapMenu = GetChooseButton(3);
	if (chooseMapMenu == 0) {
		sizeboard = 3;
	}
	else if (chooseMapMenu == 1) {
		sizeboard = 5;
	}
	else {
		sizeboard = 10;
	}

}

void ChangeRule(int& Xicon, int& Oicon, int& win)
{
	system("cls");
	GoToXY(30, 2);
	cout << "============= CHANGE RULE =============";
	GoToXY(30, 4);
	cout << "1. Being Blocked DoubleHead Cannot Win.";
	GoToXY(30, 6);
	cout << "2. Being Blocked DoubleHead Still Win.";
	GoToXY(30, 8);
	cout << "---->> ";
	cin >> win;

	//Enter until enter correctly
	while (win != 1 && win != 2)
	{
		GoToXY(30, 10);
		cout << "                                  ";
		GoToXY(30, 10);
		cout << "============= Choose Again!! =============";
		GoToXY(30, 8);
		cout << "                             ";
		GoToXY(30, 8);
		cout << "---->> ";
		cin >> win;
	}
}

void Statistic(int & SttPP, int & gamewinPP, int & gamedrawPP, int & SttPC, int & gamewinPC, int & gamedrawPC)
{
	system("cls");
	DrawChooseMode();
	int chooseMode = GetChooseButton(2);
	if (chooseMode == 0)
	{
		system("cls");
		GoToXY(30, 2);
		cout << "------------ Total player 1 wins :     " << gamewinPP << " ------------";
		GoToXY(30, 4);
		cout << "------------ Total player 2 wins :     " << SttPP - gamewinPP - gamedrawPP << " ------------";
		GoToXY(30, 6);
		cout << "------------ Total draw          :     " << gamedrawPP << " ------------";
		GoToXY(30, 8);
		cout << "------------ Total played game   :     " << SttPP << " ------------";

		GoToXY(30, 10);
		cout << setw(3) << "# NO" << "                    " << "Result";

		LoadWinPvP();
	}
	else
	{
		system("cls");
		GoToXY(30, 2);
		cout << "------------ Total player wins :     " << gamewinPC << " ------------";
		GoToXY(30, 4);
		cout << "------------ Total Computer wins :     " << SttPC - gamewinPC - gamedrawPC << " ------------";
		GoToXY(30, 6);
		cout << "------------ Total draw          :     " << gamedrawPC << " ------------";
		GoToXY(30, 8);
		cout << "------------ Total played game   :     " << SttPC << " ------------";

		GoToXY(30, 10);
		cout << setw(3) << "# NO" << "                    " << "Result";

		LoadWinPvC();
	}
}


void LoadWinPvP() {
	int size, turn;
	char map[15][15];
	char listSaveFiles[50][50];
	int countFiles = 0;
	ReadListWinFiles(listSaveFiles, countFiles);
	int i;
	for (i = 0; i < countFiles; i++) {
		GoToXY(30, i + 12);
		cout << i << ".                    " << listSaveFiles[i];
	}
	int choose;
	do {
		GoToXY(30, i + 14);
		cout << "                                            ";
		GoToXY(30, i + 14);
		cout << "Choose your game (" << 0 << " - " << countFiles - 1 << "): ";
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
		GoToXY(30, i + 16);
		cout << "Invalid file. Game will automatically closed.";
		Sleep(1000);
		exit(0);
	}
	fin >> size >> turn;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			map[i][j] = ' ';
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

	int notificationColumn;
	switch (size) {
	case 3:
		DrawMap(3, map);
		notificationColumn = 20;
		break;
	case 5:
		DrawMap(5, map);
		notificationColumn = 35;
		break;
	case 10:
		DrawMap(10, map);
		notificationColumn = 60;
		break;
	}
	GoToXY(notificationColumn, 3);
	system("pause");
}


void LoadWinPvC() {
	int size, turn;
	char map[15][15];

	char listSaveFiles[50][50];
	int countFiles = 0;
	ReadListWinFiles2(listSaveFiles, countFiles);

	int i;
	for (i = 0; i < countFiles; i++) {
		GoToXY(30, i + 12);
		cout << i << ".                    " << listSaveFiles[i];
	}
	int choose;
	do {
		GoToXY(30, i + 14);
		cout << "                                            ";
		GoToXY(30, i + 14);
		cout << "Choose your game (" << 0 << " - " << countFiles - 1 << "): ";
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
		GoToXY(30, i + 16);
		cout << "Invalid file. Game will automatically closed.";
		Sleep(1000);
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

	int notificationColumn;
	switch (size) {
	case 3:
		DrawMap(3, map);
		notificationColumn = 20;
		break;
	case 5:
		DrawMap(5, map);
		notificationColumn = 35;
		break;
	case 10:
		DrawMap(10, map);
		notificationColumn = 60;
		break;
	}
	GoToXY(notificationColumn, 3);
	system("pause");
}

