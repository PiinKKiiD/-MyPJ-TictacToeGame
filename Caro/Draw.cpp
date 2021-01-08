#include "Draw.h"

void TargetButton(int whichButton, bool on)
{
	if (on) {
		TextColor(9);
	}
	else {
		TextColor(15);
	}
	Point position;
	char text[] = "";
	switch (whichButton) {
	case 0:
		position = { 45, 12 };
		DrawFrame(position, 10, 1, text);
		break;
	case 1:
		position = { 45, 15 };
		DrawFrame(position, 10, 1, text);
		break;
	case 2:
		position = { 45, 18 };
		DrawFrame(position, 10, 1, text);
		break;
	case 3:
		position = { 45, 21 };
		DrawFrame(position, 10, 1, text);
		break;
	case 4:
		position = { 45, 24 };
		DrawFrame(position, 10, 1, text);
		break;
	}
	TextColor(15);
}

void DrawFrame(Point positionToDraw, int length, int height, char text[]) {
	GoToXY(positionToDraw.x - height, positionToDraw.y - height);

	cout << char(218);

	for (int i = 0; i < length; ++i)
		cout << char(196);
	cout << char(191);

	for (int i = -height + 1; i <= height - 1; ++i) {
		GoToXY(positionToDraw.x - height, positionToDraw.y + i);
		cout << char(179);
	}

	GoToXY(positionToDraw.x - height, positionToDraw.y + height);
	cout << char(192);

	for (int i = 0; i < length; ++i)
		cout << char(196);
	cout << char(217);

	for (int i = -height + 1; i <= height - 1; ++i) {
		GoToXY(positionToDraw.x + length + 1 - height, positionToDraw.y + i);
		cout << char(179);
	}

	int alignTextToCenter = (length - strlen(text)) / 2;
	GoToXY(positionToDraw.x + alignTextToCenter, positionToDraw.y);
	cout << text;
}

void DrawChooseMapMenu() {

	Point smallMapPosition = { 45, 12 };
	char smallMapText[] = "3 x 3";

	Point mediumMapPosition = { 45, 15 };
	char mediumMapText[] = "5 x 5";

	Point largeMapPosition = { 45, 18 };
	char largeMapText[] = "10 x 10";

	DrawFrame(smallMapPosition, 10, 1, smallMapText);

	DrawFrame(mediumMapPosition, 10, 1, mediumMapText);

	DrawFrame(largeMapPosition, 10, 1, largeMapText);
}

//Draw Map
void RowHorizontal(int size) {
	for (int i = 1; i <= size * 4 + 1; i++) {
		if (i % 4 == 1) {
			cout << char(179);
		}
		else {
			cout << " ";
		}
	}
}

void RowConnerandEdge(int size, int left, int middle, int right) {
	cout << char(left);
	for (int i = 1; i <= size * 4 - 1; i++) {
		if (i % 4 == 0) {
			cout << char(middle);
		}
		else {
			cout << char(196);
		}
	}

	cout << char(right) << endl;
}

void PrintRow(int size, int num, int count) {
	if (num == 0) {
		RowConnerandEdge(size, 218, 194, 191);
		RowHorizontal(size);
		cout << " " << setfill('0') << setw(2) << count;
		cout << endl;
	}
	else if (num == size) {
		RowConnerandEdge(size, 192, 193, 217);
	}
	else {
		RowConnerandEdge(size, 195, 197, 180);
		RowHorizontal(size);
		if (count > size) {
			--count;
		}
		cout << " " << setfill('0') << setw(2) << count;
		cout << endl;
	}
}

void PrintMap(int size) {
	system("cls");
	cout << " ";
	for (int i = 65; i <= 65 + size - 1; i++) {
		cout << char(i) << "   ";
	}
	cout << endl;
	int count = 0;
	for (int i = 0; i <= size; i++) {
		count++;
		PrintRow(size, i, count);
	}
}

void DrawMap(int size, char map[15][15]) {
	PrintMap(size);
	ShowConsoleCursor(true);
	Point position = { 2, 2 };
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			GoToXY(position.y, position.x);
			cout << map[i][j];
			position.y += 4;
		}
		position.x += 2;
		position.y = 2;
	}
}

//
void DrawChooseMode()
{
	Point pvpPosition = { 45, 12 };
	char pvpText[] = "PvP";

	Point pvcPosition = { 45, 15 };
	char pvcText[] = "PvC";

	DrawFrame(pvpPosition, 10, 1, pvpText);
	DrawFrame(pvcPosition, 10, 1, pvcText);
}

void DrawChooseModeLoadGame()
{
	Point pvpPosition = { 45, 12 };
	char pvpText[] = "PvP";

	Point pvcPosition = { 45, 15 };
	char pvcText[] = "PvC";

	DrawFrame(pvpPosition, 10, 1, pvpText);
	DrawFrame(pvcPosition, 10, 1, pvcText);
}
