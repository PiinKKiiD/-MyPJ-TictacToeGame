#include "Model.h"

int GetChooseButton(int numberOfButtons) {
	int choose = 0;
	TargetButton(choose, true);
	while (true) {
		if (_kbhit()) {
			TargetButton(choose, false);
			char key = _getch();
			switch (key) {
			case 13:
				return choose;
			case 72: // up arrow
				if (choose - 1 >= 0) {
					--choose;
				}
				else {
					choose = numberOfButtons - 1;
				}
				break;
			case 80: // down arrow
				if (choose + 1 <= numberOfButtons - 1) {
					++choose;
				}
				else {
					choose = 0;
				}
				break;
			}
			TargetButton(choose, true);
		}
	}
	ShowCursor(true);
}

bool CheckWin(char map[15][15], int size, Point position) {
	if (size == 3) {
		if (map[0][0] != ' ' && map[0][0] == map[0][1] && map[0][1] == map[0][2])
			return true;
		if (map[1][0] != ' ' && map[1][0] == map[1][1] && map[1][1] == map[1][2])
			return true;
		if (map[2][0] != ' ' && map[2][0] == map[2][1] && map[2][1] == map[2][2])
			return true;
		if (map[0][0] != ' ' && map[0][0] == map[1][0] && map[1][0] == map[2][0])
			return true;
		if (map[0][1] != ' ' && map[0][1] == map[1][1] && map[1][1] == map[2][1])
			return true;
		if (map[0][2] != ' ' && map[0][2] == map[1][2] && map[1][2] == map[2][2])
			return true;
		if (map[0][0] != ' ' && map[0][0] == map[1][1] && map[1][1] == map[2][2])
			return true;
		if (map[0][2] != ' ' && map[0][2] == map[1][1] && map[1][1] == map[2][0])
			return true;
	}
	else {
		// dong
		char current = map[position.x][position.y];

		int count = 0;
		bool back = false, front = false;

		for (int i = position.y - 1; i >= 0; --i) {
			if (map[position.x][i] == current) {
				++count;
			}
			else if (map[position.x][i] != ' ' && map[position.x][i] != current) {
				back = true;
				break;
			}
		}

		for (int i = position.y + 1; i < size; ++i) {
			if (map[position.x][i] == current) {
				++count;
			}
			else if (map[position.x][i] != ' ' && map[position.x][i] != current) {
				front = true;
				break;
			}
		}

		if (count > 4 || (count == 4 && (!back || !front))) {
			return true;
		}


		// cot
		count = 0;
		front = back = false;

		for (int i = position.x + 1; i < size; ++i) {
			if (current == map[i][position.y]) {
				++count;
			}
			else if (map[i][position.y] != ' ' && map[i][position.y] != current) {
				front = true;
				break;
			}
		}
		for (int i = position.x - 1; i >= 0; --i) {
			if (current == map[i][position.y]) {
				++count;
			}
			else if (map[i][position.y] != ' ' && map[i][position.y] != current) {
				back = true;
				break;
			}
		}

		if (count > 4 || (count == 4 && (!back || !front))) {
			return true;
		}

		// cheo phai
		count = 0;
		front = false;
		back = false;
		int step = 1;
		while (true) {
			char next = map[position.x + step][position.y + step];
			if (next == current) {
				++count;
			}
			else if (next != ' ' && next != current) {
				front = true;
				break;
			}
			else if (next == ' ') {
				break;
			}
			++step;
			if (position.x + step == size || position.y + step == size) {
				break;
			}
		}
		step = 1;
		while (true) {
			char prev = map[position.x - step][position.y - step];
			if (prev == current) {
				++count;
			}
			else if (prev != ' '&& prev != current) {
				back = true;
				break;
			}
			else if (prev == ' ') {
				break;
			}
			++step;
			if (position.x - step == -1 || position.y - step == -1) {
				break;
			}

		}

		if (count > 4 || (count == 4 && (!back || !front))) {
			return true;
		}

		count = 0;
		front = back = false;
		step = 1;
		while (true) {
			char next = map[position.x + step][position.y - step];
			if (next == current) {
				++count;
			}
			else if (next != ' ' && next != current) {
				front = true;
				break;
			}
			else if (next == ' ') {
				break;
			}
			++step;
			if (position.x + step == size || position.y - step == -1) {
				break;
			}
		}
		step = 1;
		while (true) {
			char prev = map[position.x - step][position.y + step];
			if (prev == current) {
				++count;
			}
			else if (prev != ' '&& prev != current) {
				back = true;
				break;
			}
			else if (prev == ' ') {
				break;
			}
			++step;
			if (position.x - step == -1 || position.y + step == size) {
				break;
			}

		}

		if (count > 4 || (count == 4 && (!back || !front))) {
			return true;
		}

	}
	return false;
}

bool CheckDraw(char map[15][15], int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (map[i][j] == ' ')
				return false;
	return true;
}

bool CheckWinOption(char map[15][15], int size, Point position)
{
	if (size == 3) {
		if (map[0][0] != ' ' && map[0][0] == map[0][1] && map[0][1] == map[0][2])
			return true;
		if (map[1][0] != ' ' && map[1][0] == map[1][1] && map[1][1] == map[1][2])
			return true;
		if (map[2][0] != ' ' && map[2][0] == map[2][1] && map[2][1] == map[2][2])
			return true;
		if (map[0][0] != ' ' && map[0][0] == map[1][0] && map[1][0] == map[2][0])
			return true;
		if (map[0][1] != ' ' && map[0][1] == map[1][1] && map[1][1] == map[2][1])
			return true;
		if (map[0][2] != ' ' && map[0][2] == map[1][2] && map[1][2] == map[2][2])
			return true;
		if (map[0][0] != ' ' && map[0][0] == map[1][1] && map[1][1] == map[2][2])
			return true;
		if (map[0][2] != ' ' && map[0][2] == map[1][1] && map[1][1] == map[2][0])
			return true;
	}
	else {
		// dong
		char current = map[position.x][position.y];

		int count = 0;
		bool back = false, front = false;

		for (int i = position.y - 1; i >= 0; --i) {
			if (map[position.x][i] == current) {
				++count;
			}
			else if (map[position.x][i] != ' ' && map[position.x][i] != current) {
				back = true;
				break;
			}
		}

		for (int i = position.y + 1; i < size; ++i) {
			if (map[position.x][i] == current) {
				++count;
			}
			else if (map[position.x][i] != ' ' && map[position.x][i] != current) {
				front = true;
				break;
			}
		}

		if (count >= 4) {
			return true;
		}


		// cot
		count = 0;
		front = back = false;

		for (int i = position.x + 1; i < size; ++i) {
			if (current == map[i][position.y]) {
				++count;
			}
			else if (map[i][position.y] != ' ' && map[i][position.y] != current) {
				front = true;
				break;
			}
		}
		for (int i = position.x - 1; i >= 0; --i) {
			if (current == map[i][position.y]) {
				++count;
			}
			else if (map[i][position.y] != ' ' && map[i][position.y] != current) {
				back = true;
				break;
			}
		}

		if (count >= 4) {
			return true;
		}

		// cheo phai
		count = 0;
		front = false;
		back = false;
		int step = 1;
		while (true) {
			char next = map[position.x + step][position.y + step];
			if (next == current) {
				++count;
			}
			else if (next != ' ' && next != current) {
				front = true;
				break;
			}
			else if (next == ' ') {
				break;
			}
			++step;
			if (position.x + step == size || position.y + step == size) {
				break;
			}
		}
		step = 1;
		while (true) {
			char prev = map[position.x - step][position.y - step];
			if (prev == current) {
				++count;
			}
			else if (prev != ' '&& prev != current) {
				back = true;
				break;
			}
			else if (prev == ' ') {
				break;
			}
			++step;
			if (position.x - step == -1 || position.y - step == -1) {
				break;
			}

		}

		if (count >= 4) {
			return true;
		}

		count = 0;
		front = back = false;
		step = 1;
		while (true) {
			char next = map[position.x + step][position.y - step];
			if (next == current) {
				++count;
			}
			else if (next != ' ' && next != current) {
				front = true;
				break;
			}
			else if (next == ' ') {
				break;
			}
			++step;
			if (position.x + step == size || position.y - step == -1) {
				break;
			}
		}
		step = 1;
		while (true) {
			char prev = map[position.x - step][position.y + step];
			if (prev == current) {
				++count;
			}
			else if (prev != ' '&& prev != current) {
				back = true;
				break;
			}
			else if (prev == ' ') {
				break;
			}
			++step;
			if (position.x - step == -1 || position.y + step == size) {
				break;
			}

		}

		if (count >= 4) {
			return true;
		}

	}
	return false;
}

void ReadListSaveFiles1(char listFiles[50][50], int & countFiles) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char searchPath[] = "./*.s";
	countFiles = 0;
	hFind = ::FindFirstFile(searchPath, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				int i;
				for (i = 0; i < strlen(FindFileData.cFileName); ++i) {
					listFiles[countFiles][i] = FindFileData.cFileName[i];
				}
				listFiles[countFiles][i] = '\0';
				++countFiles;
			}
		} while (::FindNextFile(hFind, &FindFileData));
		::FindClose(hFind);
	}
}

void ReadListSaveFiles2(char listFiles[50][50], int & countFiles) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char searchPath[] = "./*.m";
	countFiles = 0;
	hFind = ::FindFirstFile(searchPath, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				int i;
				for (i = 0; i < strlen(FindFileData.cFileName); ++i) {
					listFiles[countFiles][i] = FindFileData.cFileName[i];
				}
				listFiles[countFiles][i] = '\0';
				++countFiles;
			}
		} while (::FindNextFile(hFind, &FindFileData));
		::FindClose(hFind);
	}
}

void ReadListWinFiles(char listFiles[50][50], int & countFiles) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char searchPath[] = "./*.w";
	countFiles = 0;
	hFind = ::FindFirstFile(searchPath, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				int i;
				for (i = 0; i < strlen(FindFileData.cFileName); ++i) {
					listFiles[countFiles][i] = FindFileData.cFileName[i];
				}
				listFiles[countFiles][i] = '\0';
				++countFiles;
			}
		} while (::FindNextFile(hFind, &FindFileData));
		::FindClose(hFind);
	}
}

void ReadListWinFiles2(char listFiles[50][50], int & countFiles) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char searchPath[] = "./*.d";
	countFiles = 0;
	hFind = ::FindFirstFile(searchPath, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				int i;
				for (i = 0; i < strlen(FindFileData.cFileName); ++i) {
					listFiles[countFiles][i] = FindFileData.cFileName[i];
				}
				listFiles[countFiles][i] = '\0';
				++countFiles;
			}
		} while (::FindNextFile(hFind, &FindFileData));
		::FindClose(hFind);
	}
}

