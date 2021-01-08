#include "Controller.h"

int Xicon = 88, Oicon = 79, win = 1, sizeboard = 3;
int SttPP = 0, gamewinPP = 0, gamedrawPP = 0, SttPC = 0, gamewinPC = 0, gamedrawPC = 0;

int main() {
	system("cls");
	while (true) {
		TextColor(15);
		ShowSplashScreen();
		ShowStartMenu();

		ShowCursor(false);
		int chooseStartMenu = GetChooseButton(5);
		switch (chooseStartMenu) {
		case 0:
			NewGame(Xicon, Oicon, win, sizeboard, SttPP, gamewinPP, gamedrawPP, SttPC, gamewinPC, gamedrawPC);
			break;
		case 1:
			AboutUs();
			break;
		case 2:
			ChooseModeLoadGame(Xicon, Oicon, win, SttPP, gamewinPP, gamedrawPP, SttPC, gamewinPC, gamedrawPC);
			break;
		case 3:
			system("cls");
			ControllOption(Xicon, Oicon, win, sizeboard, SttPP, gamewinPP, gamedrawPP, SttPC, gamewinPC, gamedrawPC);
			break;
		case 4:
			//Exit Game
			exit(0);
		}
	}
}