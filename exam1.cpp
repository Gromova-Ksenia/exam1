#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ProcedureModule.h"
using namespace std;

void start_menu();

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    start_menu();
}

void start_menu() {
    system("chcp 65001 && cls");
    unsigned short k = 0;
    do {
        system("cls");
        cout << "Ввыберите, что вы хотите сделать:\n1) Начать игру в режиме 3х3\n2) Начать игру в режиме 4х4\n3) Выйти\nВаш выбор: ";
        cin >> k;
        if (k == 0) return;
        else if (k > 4) {
            cout << "Неверный номер. Повторите ввод." << endl;
            system("pause");
        }
    } while (k > 3);
    switch (k)
    {
    case 1:
        game_in_3();
        break;
    case 2:
        game_in_4();
        break;
    case 3:
        return;
        break;
    }
}