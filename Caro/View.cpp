#include "View.h"

void ShowSplashScreen() {
	system("cls");

	// In tieu de
	TextColor(6);
	cout << "         _  _  _       _  _  _  _    _           _    _  _  _  _    _           _  _            _   " << endl;
	cout << "      _ (_)(_)(_) _  _(_)(_)(_)(_)_ (_) _     _ (_) _(_)(_)(_)(_)_ (_)       _ (_)(_)          (_)  " << endl;
	cout << "     (_)         (_)(_)          (_)(_)(_)   (_)(_)(_)          (_)(_)    _ (_)   (_)          (_)  " << endl;
	cout << "     (_)    _  _  _ (_)          (_)(_) (_)_(_) (_)(_)          (_)(_) _ (_)      (_)          (_)  " << endl;
	cout << "     (_)   (_)(_)(_)(_)          (_)(_)   (_)   (_)(_)          (_)(_)(_) _       (_)          (_)  " << endl;
	cout << "     (_)         (_)(_)          (_)(_)         (_)(_)          (_)(_)   (_) _    (_)          (_)  " << endl;
	cout << "     (_) _  _  _ (_)(_)_  _  _  _(_)(_)         (_)(_)_  _  _  _(_)(_)      (_) _ (_)_  _  _  _(_)  " << endl;
	cout << "        (_)(_)(_)(_)  (_)(_)(_)(_)  (_)         (_)  (_)(_)(_)(_)  (_)         (_)  (_)(_)(_)(_)    " << endl;

	// In chu
	ShowConsoleCursor(false);
	GoToXY(48, 12);
	TextColor(14);
	cout << "LOADING...";
	GoToXY(40, 15);
	cout << "Just a simple caro game...";
	//In thanh loading
	TextColor(6);
	GoToXY(21, 13);
	for (int i = 0; i < 60; ++i) {
		Sleep(30);
		cout << char(219);
	}
	TextColor(15);

	// Xoa phan loading
	GoToXY(48, 12);
	cout << "                  ";
	GoToXY(40, 15);
	cout << "                                ";
	GoToXY(21, 13);
	cout << "                                                             ";
}

void ShowStartMenu() {
	Point startPosition = { 45, 12 };
	char startText[] = "Start";

	Point aboutPosition = { 45, 15 };
	char aboutText[] = "About";

	Point loadPosition = { 45, 18 };
	char loadText[] = "Load";

	Point optionsPosition = { 45, 21 };
	char optionsText[] = "Options";

	Point exitPosition = { 45, 24 };
	char exitText[] = "Exit";

	DrawFrame(startPosition, 10, 1, startText);
	DrawFrame(aboutPosition, 10, 1, aboutText);
	DrawFrame(loadPosition, 10, 1, loadText);
	DrawFrame(optionsPosition, 10, 1, optionsText);
	DrawFrame(exitPosition, 10, 1, exitText);
}

void AboutUs()
{
	//In tieu de
	system("cls");
	TextColor(6);
	cout << endl << endl;
	cout << "                           #    ######  ####### #     # #######    #     #  #####" << endl;
	cout << "                          # #   #     # #     # #     #    #       #     # #     # " << endl;
	cout << "                         #   #  #     # #     # #     #    #       #     # # " << endl;
	cout << "                        #     # ######  #     # #     #    #       #     #  ##### " << endl;
	cout << "                        ####### #     # #     # #     #    #       #     #       # " << endl;
	cout << "                        #     # #     # #     # #     #    #       #     # #     # " << endl;
	cout << "                        #     # ######  #######  #####     #        #####   ##### " << endl;

	//In thanh loading
	TextColor(6);
	ShowConsoleCursor(false);
	GoToXY(21, 12);
	for (int i = 0; i < 60; ++i) {
		Sleep(30);
		cout << char(219);
	}

	//In noi dung
	TextColor(14);
	GoToXY(35, 15);
	cout << "This is a caro game made by Group 07:";
	GoToXY(40, 18);
	cout << "Nguyen Tran Minh Khue";
	GoToXY(40, 20);
	cout << "Nguyen Trung Hau";
	GoToXY(40, 22);
	cout << "Nguyen Minh Khue";
	GoToXY(40, 24);
	cout << "Nguyen Le Thanh Khiet";
	GoToXY(35, 27);
	TextColor(15);
	system("pause");
}
