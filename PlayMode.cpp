#include "PlayMode.h"

int PvP(char map[15][15], int first, int size, int Xicon, int Oicon, int win, int& SttPP, int& gamewinPP, int& gamedrawPP)
{
	bool turn = first - 1;
	int x = 2, y = 2;
	int row = 0, column = 0;
	int notificationColumn;
	int result = 3;
	Point position;
	
	//Lay vi tri in hieu lenh game tuy vao size
	if (size == 3) {
		notificationColumn = 20;
	}
	else if (size == 5) {
		notificationColumn = 35;
	}
	else {
		notificationColumn = 60;
	}

	GoToXY(notificationColumn, 3);
	TextColor(11);
	cout << "Player " << first << " turn.";
	TextColor(15);

	ShowConsoleCursor(true);
	
	while (true) {
		if (_kbhit()) {
			int key = _getch();

			switch (key) {
			
			//Enter esc
			case 27:
				return 3;

			//Save Game -> Enter 's'
			case 's': {
				Point savedposi = { 1, size * 2 + 4 };
				char text[] = "";
				DrawFrame(savedposi, 50, 1, text);
				GoToXY(savedposi.x, savedposi.y);
				char saveLocation[40];
				ofstream fout;
				while (true) {
					cin.getline(saveLocation, 43);
					int temp = strlen(saveLocation);
					saveLocation[temp] = '.';
					saveLocation[temp + 1] = 's';
					saveLocation[temp + 2] = '\0';

					fout.open(saveLocation);
					if (!fout.fail()) {
						GoToXY(savedposi.x, savedposi.y - 2);
						cout << "                                         ";
						break;
					}
					GoToXY(savedposi.x, savedposi.y);
					cout << "                                        ";
					GoToXY(savedposi.x, savedposi.y - 2);
					TextColor(12);
					cout << "Invalid file name. Please enter again.";
					GoToXY(savedposi.x, savedposi.y);
					TextColor(15);
				}
				fout << size << " " << int(turn + 1) << endl;
				for (int i = 0; i < size; ++i) {
					for (int j = 0; j < size; ++j)
						if (map[i][j] == ' ') {
							fout << 'N' << ' ';
						}
						else {
							fout << map[i][j] << ' ';
						}
					fout << endl;
				}
				fout.close();

				GoToXY(notificationColumn, 2);
				TextColor(12);
				cout << "Game has been saved.        ";
				GoToXY(0, savedposi.y - 1);
				cout << "                                                         " << endl;
				cout << "                                                         " << endl;
				cout << "                                                         ";
				TextColor(15);
				break;
			}
			
			//Enter
			case 13:
				//Enter checked cell
				if (map[row][column] != ' ') {
					GoToXY(notificationColumn, 2);
					TextColor(12);
					cout << "Can not check this cell.";
					TextColor(15);
				}
				else {
					//Check
					if (turn) {
						cout << char(Xicon);
						map[row][column] = char(Xicon);
					}
					else {
						cout << char(Oicon);
						map[row][column] = char(Oicon);
					}

					position = { row, column };

					//Check Win
					if (win == 1)
					{
						if (CheckWin(map, size, position) || CheckDraw(map, size)) {
							char saveLocation[40];
							if (CheckWin(map, size, position)) {
								result = turn;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Win  ");
								int countwin = SttPP - gamedrawPP + 49;
								saveLocation[3] = char(countwin);

							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw ");
								int countdraw = gamedrawPP + 49;
								saveLocation[4] = char(countdraw);
							}

							ofstream fout3;
							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'w';
							saveLocation[temp + 2] = '\0';

							fout3.open(saveLocation);
							fout3 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout3 << 'N' << ' ';
									else
										fout3 << map[i][j] << ' ';
								fout3 << endl;
							}
							fout3.close();
							SttPP++;
						}
					}

					else
					{
						if (CheckWinOption(map, size, position) || CheckDraw(map, size)) {
							char saveLocation[40];
							if (CheckWinOption(map, size, position)) {
								result = turn;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Win with special rule  ");
								int countwin = SttPP - gamedrawPP + 49;
								saveLocation[21] = char(countwin);
							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw with special rule  ");
								int countdraw = gamedrawPP + 49;
								saveLocation[22] = char(countdraw);
							}
							ofstream fout4;
							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'w';
							saveLocation[temp + 2] = '\0';

							fout4.open(saveLocation);
							fout4 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout4 << 'N' << ' ';
									else
										fout4 << map[i][j] << ' ';
								fout4 << endl;
							}
							fout4.close();
							SttPP++;
						}
					}

					if (result == 0) {
						system("cls");
						GoToXY(20, 5);
						TextColor(12);
						cout << "First Player win." << endl;
						TextColor(15);
						gamewinPP++;
						GoToXY(20, 7);
						system("pause");
						return result;
					}
					else if (result == 1)
					{
						system("cls");
						GoToXY(20, 5);
						TextColor(12);
						cout << "Second Player win." << endl;
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					else if (result == 2) {
						system("cls");
						GoToXY(20, 5);
						TextColor(12);
						cout << "Draw." << endl;
						gamedrawPP++;
						TextColor(15);
						GoToXY(20, 7);
						system("pause");
						return result;
					}

					turn = !turn;
					TextColor(11);
					GoToXY(notificationColumn, 3);
					cout << "Player " << turn + 1 << " turn.";
					TextColor(15);
				}
				break;

			//Di chuyen phim
			case 72:
				if (y - 2 >= 2) {
					y -= 2;
					--row;
				}
				GoToXY(60, 2);
				cout << "                                         ";
				break;

			case 80:
				if (y + 2 <= size * 2) {
					y += 2;
					++row;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                         ";
				break;

			case 75:
				if (x - 4 >= 2) {
					x -= 4;
					--column;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                          ";
				break;

			case 77:
				if (x + 4 <= size * 4) {
					x += 4;
					++column;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                          ";
				break;
			}
			GoToXY(x, y);
		}
	}
}

int PvC(char map[15][15], int first, int size, int Xicon, int Oicon, int win, int& SttPC, int& gamewinPC, int& gamedrawPC)
{
	bool turn = first - 1;
	int x = 2, y = 2;
	int row = 0, column = 0;
	int count = 0, result = 3;
	int notificationColumn;
	Point position;

	//Lay vi tri in hieu lenh game tuy vao size
	if (size == 3) {
		notificationColumn = 20;
	}
	else if (size == 5) {
		notificationColumn = 35;
	}
	else {
		notificationColumn = 60;
	}
	GoToXY(notificationColumn, 3);
	TextColor(11);
	cout << "Player " << " turn.";
	TextColor(15);

	ShowConsoleCursor(true);
	while (true) {
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
				
			//Exit
			case 27:
				return 3;

			//Save Game
			case 's': {
				Point savedposi2 = { 1, size * 2 + 4 };
				char text[] = "";
				DrawFrame(savedposi2, 50, 1, text);
				GoToXY(savedposi2.x, savedposi2.y);
				char saveLocation2[40];
				ofstream fout2;
				while (true) {
					cin.getline(saveLocation2, 43);
					int temp = strlen(saveLocation2);
					saveLocation2[temp] = '.';
					saveLocation2[temp + 1] = 'm';
					saveLocation2[temp + 2] = '\0';

					fout2.open(saveLocation2);
					if (!fout2.fail()) {
						GoToXY(savedposi2.x, savedposi2.y - 2);
						cout << "                                         ";
						break;
					}
					GoToXY(savedposi2.x, savedposi2.y);
					cout << "                                        ";
					GoToXY(savedposi2.x, savedposi2.y - 2);
					TextColor(12);
					cout << "Invalid file name. Please enter again.";
					TextColor(15);
					GoToXY(savedposi2.x, savedposi2.y);
				}
				fout2 << size << " " << int(turn + 1) << endl;
				for (int i = 0; i < size; ++i) {
					for (int j = 0; j < size; ++j)
						if (map[i][j] == ' ') {
							fout2 << 'N' << ' ';
						}
						else {
							fout2 << map[i][j] << ' ';
						}
					fout2 << endl;
				}
				fout2.close();

				GoToXY(notificationColumn, 2);
				TextColor(12);
				cout << "Game has been saved.        ";
				GoToXY(0, savedposi2.y - 1);
				cout << "                                                         " << endl;
				cout << "                                                         " << endl;
				cout << "                                                         ";
				TextColor(15);
				break;
			}

			// Enter
			case 13:
				//Enter checked cell
				if (map[row][column] != ' ') {
					GoToXY(notificationColumn, 2);
					TextColor(12);
					cout << "Cannot check this cell.";
					TextColor(15);
				}

				else {
					//Check X
					cout << char(Xicon);
					map[row][column] = char(Xicon);
					position = { row, column };

					//Check Win, Draw -> Save Game
					if (win == 1)
					{
						if (CheckWin(map, size, position) || CheckDraw(map, size)) {
							char saveLocation[40];
							ofstream fout5;
							if (CheckWin(map, size, position)) {
								result = 0;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Player Win  ");
								int countwin = SttPC - gamedrawPC + 49;
								saveLocation[10] = char(countwin);
							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw  ");
								int countdraw = gamedrawPC + 49;
								saveLocation[4] = char(countdraw);
							}

							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'd';
							saveLocation[temp + 2] = '\0';

							fout5.open(saveLocation);
							fout5 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout5 << 'N' << ' ';
									else
										fout5 << map[i][j] << ' ';
								fout5 << endl;
							}
							fout5.close();
							SttPC++;
						}
					}
					else
					{
						if (CheckWinOption(map, size, position) || CheckDraw(map, size)) {

							char saveLocation[40];
							if (CheckWinOption(map, size, position)) {
								result = turn;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Win With Special Rule  ");
								int countwin = SttPC - gamedrawPC + 49;
								saveLocation[21] = char(countwin);
							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw With Special Rule  ");
								int countdraw = gamedrawPC + 49;
								saveLocation[22] = char(countdraw);
							}
							ofstream fout6;
							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'd';
							saveLocation[temp + 2] = '\0';

							fout6.open(saveLocation);
							fout6 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout6 << 'N' << ' ';
									else
										fout6 << map[i][j] << ' ';
								fout6 << endl;
							}
							fout6.close();
							SttPC++;
						}
					}

					if (result == 0) {
						system("cls");
						GoToXY(20, 5);
						gamewinPC++;
						TextColor(12);
						cout << "Player wins.";
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					else if (result == 1) {
						system("cls");
						GoToXY(20, 5);
						TextColor(12);
						cout << "Computer wins.";
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					else if (result == 2) {
						system("cls");
						GoToXY(20, 5);
						gamedrawPC++;
						TextColor(12);
						cout << "Draw." << endl;
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}

					//Computer plays
					GoToXY(notificationColumn, 3);
					cout << "                                    ";
					GoToXY(notificationColumn, 3);
					TextColor(11);
					cout << "Computer is playing... ";
					TextColor(15);
					int temp1, temp2;

					GoToXY(row, column);
					do
					{
						//go to location random for computer
						temp1 = (1 + (rand() % (size - 1))) * 4;
						temp2 = (1 + (rand() % (size - 1))) * 2;

						//set x
						if (temp1 + x <= size * 4)
						{
							x += temp1;
							column += (temp1 / 4);
						}
						else if (x - temp1 >= 2)
						{
							x = x - temp1;
							column -= (temp1 / 4);
						}

						//set y
						if (temp2 + y <= size * 2)
						{
							y += temp2;
							row += (temp2 / 2);
						}
						else if (y - temp2 >= 2)
						{
							y -= temp2;
							row -= (temp2 / 2);
						}
					} while (map[row][column] != ' ');

					GoToXY(x, y);
					Sleep(300);

					//Check O
					cout << char(Oicon);
					map[row][column] = char(Oicon);
					position = { row, column };

					//Check Win, Draw -> Save Game
					if (win == 1)
					{
						if (CheckWin(map, size, position) || CheckDraw(map, size)) {

							char saveLocation[40];
							if (CheckWin(map, size, position)) {
								result = 1;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Win  ");
								int countwin = SttPC - gamedrawPC + 49;
								saveLocation[3] = char(countwin);
							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw  ");
								int countdraw = gamedrawPC + 49;
								saveLocation[4] = char(countdraw);
							}
							ofstream fout7;
							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'd';
							saveLocation[temp + 2] = '\0';

							fout7.open(saveLocation);
							fout7 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout7 << 'N' << ' ';
									else
										fout7 << map[i][j] << ' ';
								fout7 << endl;
							}
							fout7.close();
							SttPC++;
						}
					}
					else
					{
						if (CheckWinOption(map, size, position) || CheckDraw(map, size)) {

							char saveLocation[40];
							if (CheckWinOption(map, size, position)) {
								result = turn;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Win With Special Rule  ");
								int countwin = SttPC - gamedrawPC + 49;
								saveLocation[21] = char(countwin);
							}

							else if (CheckDraw(map, size)) {
								result = 2;
								strcpy_s(saveLocation, "");
								strcat_s(saveLocation, "Draw With Special Rule  ");
								int countdraw = gamedrawPC + 49;
								saveLocation[22] = char(countdraw);
							}
							ofstream fout8;
							int temp = strlen(saveLocation);
							saveLocation[temp] = '.';
							saveLocation[temp + 1] = 'd';
							saveLocation[temp + 2] = '\0';

							fout8.open(saveLocation);
							fout8 << size << " " << int(turn + 1) << endl;
							for (int i = 0; i < size; ++i) {
								for (int j = 0; j < size; ++j)
									if (map[i][j] == ' ')
										fout8 << 'N' << ' ';
									else
										fout8 << map[i][j] << ' ';
								fout8 << endl;
							}
							fout8.close();
							SttPC++;
						}
					}
					if (result == 0) {
						system("cls");
						GoToXY(20, 5);
						gamewinPC++;
						TextColor(12);
						cout << "Player wins." << endl;
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					else if (result == 1) {
						system("cls");
						GoToXY(20, 5);
						TextColor(12);
						cout << "Computer wins." << endl;
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					else if (result == 2) {
						system("cls");
						GoToXY(20, 5);
						gamedrawPC++;
						TextColor(12);
						cout << "Draw." << endl;
						GoToXY(20, 7);
						TextColor(15);
						system("pause");
						return result;
					}
					GoToXY(notificationColumn, 3);
					cout << "                                    ";
					GoToXY(notificationColumn, 3);
					TextColor(11);
					cout << "Player turn. ";
				}
				break;

				//Di chuyen phim
			case 72:
				if (y - 2 >= 2) {
					y -= 2;
					--row;
				}
				GoToXY(60, 2);
				cout << "                                         ";
				break;
			case 80:
				if (y + 2 <= size * 2) {
					y += 2;
					++row;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                         ";
				break;
			case 75:
				if (x - 4 >= 2) {	//di chuyen qua trai
					x -= 4;
					--column;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                          ";
				break;
			case 77:
				if (x + 4 <= size * 4) {	//di chuyen qua phai
					x += 4;
					++column;
				}
				GoToXY(notificationColumn, 2);
				cout << "                                          ";
				break;
			}
			GoToXY(x, y);
		}
	}
}