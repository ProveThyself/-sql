#include <iostream>
#include <cstdio>
#include <windows.h>
#include <fstream>


void setConsoleColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

int main(int argc, char* argv[]) {

	SetConsoleOutputCP(1251);

	if (argc < 2) {
		printf("Использование: %s <Имя файла>\n", argv[0]);
		return 1;
	}

	const char* fileName = argv[1];

	FILE* file = fopen(fileName, "r");
	if (file) {
		printf("Содержимое файла: ");
		setConsoleColor(10);
		printf("%s\n", fileName);
		setConsoleColor(7);
		char buffer[1024];
		while (fgets(buffer, sizeof(buffer), file)) {
			printf("%s", buffer);
		}
		fclose(file);
	}
	else {
		printf("Не удалось открыть файл %s\n", fileName);
	}

	return 0;
}
