#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

void game_in_3();
void game_in_4();
void field_print(int fld[4][4], int mv);
void field_print(int fld[3][3], int mv);
void starting_sort(int fld[4][4], int& void_x, int& void_y);
void starting_sort(int fld[3][3], int& void_x, int& void_y);
bool win(int fld[4][4], int& void_x, int& void_y);
bool win(int fld[3][3], int& void_x, int& void_y);
void two_tiles_change(int fld[4][4], int& void_x, int& void_y, int& mv);
void two_tiles_change(int fld[3][3], int& void_x, int& void_y, int& mv);

void game_in_3() //3 на 3
{
	int game_field[3][3] = { { 0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
	int void_tile_x, void_tile_y;
	int moves = 0;
	starting_sort(game_field, void_tile_x, void_tile_y);
	system("cls");
	field_print(game_field, moves);
	while (!win(game_field, void_tile_x, void_tile_y)) {
		two_tiles_change(game_field, void_tile_x, void_tile_y, moves);
		field_print(game_field, moves);
	}
	cout << "ПОБЕДА!!!!" << endl << "для решения потребовалось " << moves << " ходов!" << endl;
	system("pause");
}

void game_in_4() //4 на 4
{
	int game_field[4][4] = { { 0, 1, 2, 3 }, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15} };
	int void_tile_x, void_tile_y;
	int moves = 0;
	starting_sort(game_field, void_tile_x, void_tile_y);
	system("cls");
	field_print(game_field, moves);
	while (!win(game_field, void_tile_x, void_tile_y)) {
		two_tiles_change(game_field, void_tile_x, void_tile_y, moves);
		field_print(game_field, moves);
	}
	cout << "ПОБЕДА!!!!" << endl << "для решения потребовалось " << moves << " ходов!" << endl;
	system("pause");
}

void field_print(int fld[4][4], int mv) //отрисовка поля 4 на 4
{
	system("cls");
	cout << "┌────┬────┬────┬────┐" << endl;
	//cout << "г----т----т----т----т" << endl;
	for (int i = 0; i < 4; i++) {
		if (i != 0) cout << '|' << endl << "|----t----t----t----|" << endl;
		for (int j = 0; j < 4; j++) {
			cout << "| ";
			if (fld[i][j] == 0) cout << "   ";
			else if (fld[i][j] < 10) cout << '0' << fld[i][j] << ' ';
			else cout << fld[i][j] << ' ';
		}	
	}
	cout << "|\nL----|----|----|----|" << endl;
	cout << "Ходов: " << mv << endl;
}

void field_print(int fld[3][3], int mv) //отрисовка поля 3 на 3
{
	system("cls");
	cout << "г----т----т----т" << endl;
	for (int i = 0; i < 3; i++) {
		if (i != 0) cout << '|' << endl << "|----t----t----|" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "| ";
			if (fld[i][j] == 0) cout << "   ";
			else if (fld[i][j] < 10) cout << '0' << fld[i][j] << ' ';
			else cout << fld[i][j] << ' ';
		}
	}
	cout << "|\nL----|----|----|" << endl;
	cout << "Ходов: " << mv << endl;
}

void starting_sort(int fld[4][4], int &void_x, int &void_y) { //случайная сортировка в начале
	srand(time(NULL));
	uint8_t one_tile_x, one_tile_y, two_tile_x, two_tile_y, temp;
	for (int i = 0; i < 50; i++) {
		one_tile_x = rand() % 4;
		one_tile_y = rand() % 4;
		two_tile_x = rand() % 4;
		two_tile_y = rand() % 4;
		temp = fld[one_tile_x][one_tile_y];
		fld[one_tile_x][one_tile_y] = fld[two_tile_x][two_tile_y];
		fld[two_tile_x][two_tile_y] = temp;
	}
	for (int x = 0; x < 4; x++) { //находим координаты пустой фишки, от которой потом будем отталкиваться
		for (int y = 0; y < 4; y++) {
			if (fld[x][y] == 0) {
				void_x = x;
				void_y = y;
				return;
			}
		}
	}
}

void starting_sort(int fld[3][3], int& void_x, int& void_y) { //случайная сортировка в начале
	srand(time(NULL));
	uint8_t one_tile_x, one_tile_y, two_tile_x, two_tile_y, temp;
	for (int i = 0; i < 50; i++) {
		one_tile_x = rand() % 3;
		one_tile_y = rand() % 3;
		two_tile_x = rand() % 3;
		two_tile_y = rand() % 3;
		temp = fld[one_tile_x][one_tile_y];
		fld[one_tile_x][one_tile_y] = fld[two_tile_x][two_tile_y];
		fld[two_tile_x][two_tile_y] = temp;
	}
	for (int x = 0; x < 3; x++) { //находим координаты пустой фишки, от которой потом будем отталкиваться
		for (int y = 0; y < 3; y++) {
			if (fld[x][y] == 0) {
				void_x = x;
				void_y = y;
				return;
			}
		}
	}
}

bool win(int fld[4][4], int& void_x, int& void_y) {
	if (void_x == 3 && void_y == 3) { //Проверка для положения фишек 14-15
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if ((fld[x][y] != 0) && (fld[x][y] != (4 * x + y + 1))) return false; //игра не завершена
			}
		}
		return true;
	}
	if (void_x == 0 && void_y == 0) {
		for (int x = 0; x < 4; x++) { //Проверка для положения фишек 15-14
			for (int y = 0; y < 4; y++) {
				if (fld[x][y] != (4 * x + y)) return false; //игра не завершена
			}
		}
		return true;
	}
	return false;
}

bool win(int fld[3][3], int& void_x, int& void_y) {
	if (void_x == 2 && void_y == 2) { //Проверка для положения фишек 14-15
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if ((fld[x][y] != 0) && (fld[x][y] != (3 * x + y + 1))) return false; //игра не завершена
			}
		}
		return true;
	}
	if (void_x == 0 && void_y == 0) {
		for (int x = 0; x < 3; x++) { //Проверка для положения фишек 15-14
			for (int y = 0; y < 3; y++) {
				if (fld[x][y] != (3 * x + y)) return false; //игра не завершена
			}
		}
		return true;
	}
	return false;
}

void two_tiles_change(int fld[4][4], int& void_x, int& void_y, int &mv) {
	switch (_getch()) //ожидание нажатия
	{
	case 72: //вверх
		if (void_x != 3) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x + 1][void_y];
			fld[void_x + 1][void_y] = temp;
			void_x++;
			mv++;
		}
		break;
	case 80: //вниз
		if (void_x != 0) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x - 1][void_y];
			fld[void_x - 1][void_y] = temp;
			void_x--;
			mv++;
		}
		break;
	case 75: //влево 
		if (void_y != 3) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x][void_y + 1];
			fld[void_x][void_y + 1] = temp;
			void_y++;
			mv++;
		}
		break;
	case 77: //вправо
		if (void_y != 0) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x][void_y - 1];
			fld[void_x][void_y - 1] = temp;
			void_y--;
			mv++;
		}
		break;
	}
}

void two_tiles_change(int fld[3][3], int& void_x, int& void_y, int& mv) {
	switch (_getch()) //ожидание нажатия
	{
	case 72: //вверх
		if (void_x != 2) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x + 1][void_y];
			fld[void_x + 1][void_y] = temp;
			void_x++;
			mv++;
		}
		break;
	case 80: //вниз
		if (void_x != 0) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x - 1][void_y];
			fld[void_x - 1][void_y] = temp;
			void_x--;
			mv++;
		}
		break;
	case 75: //влево 
		if (void_y != 2) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x][void_y + 1];
			fld[void_x][void_y + 1] = temp;
			void_y++;
			mv++;
		}
		break;
	case 77: //вправо
		if (void_y != 0) {
			int temp = fld[void_x][void_y];
			fld[void_x][void_y] = fld[void_x][void_y - 1];
			fld[void_x][void_y - 1] = temp;
			void_y--;
			mv++;
		}
		break;
	}
}