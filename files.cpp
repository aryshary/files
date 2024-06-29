#include <iostream>
#include <Windows.h>
#include <fstream>

#define O cout
#define E endl

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    O << "РОБОТА З ФАЙЛАМИ" << E;

    //ЗАПИС
    /*ofstream file("test.txt");
    if (file) O << "Все добре! Файл існує!" << E;
    else {
        O << "Файл не знайдено!" << E;
        return 1;
    }
    O << "====================" << E;

    O << "Введіть будь-яку інформацію, вона буде автоматично збережена у файл. Зупинка процеса +" << E;
    char txt[20];
    int row = 1;
    do {
        O << row << ") ";
        cin.getline(txt, 20);
        if (*txt == '+') break;
        file << txt << E;
        row++;
    }while (*txt != '+');
    cout << "процес завершився!" << E;
    file.close();*/

    //ЗЧИТУВАННЯ
    /*ifstream f("text.txt");
    if (!f.is_open()) {
        O << "Файл не знайдено!" << E;
        return 1;
    }
    char txt[20];
    int row = 0;
    do {
        row++;
        f.getline(txt, 20);
        O << row << ") " << txt << E;
    } while (f);
    f.close();*/

    //ДОЗАПИС
    /*ofstream file("test.txt", ios::app);
    if (!file) {
        O << "Файл не знайдено!" << E;
        return 1;
    }
    char txt[20];
    int row = 0;
    cout << "Ви робите дозапис до файлу до тих пір, поки не введено *\n" << E;
    while (*txt != '*') {
        row++;
        O << row << ") ";
        cin.getline(txt, 20);
        if (*txt == '*') break;
        file << txt << E;
    }
    O << "Процес завершився!" << E;
    file.close();*/



    ifstream file("text.txt");
    if (!file) {
        O << "Файл не знайдено!" << E;
        return 1;
    }

    char txt[20];
    int rah = 0;
    string num;
    bool end = false;
    while (file) {
        file.getline(txt, 20);
        for (int i = 0; txt[i] != '\0'; i++) {
            if (isdigit(txt[i])) {
                num += txt[i];

                if (!end) {
                    rah++;
                    end = true;
                }
                else end = false;
            }

            if (txt[i] == ' ') {
                cout << num << endl;
                num = "";
            }
        }
        /*for (char i: txt) {
            if (txt[i] >= '0' && txt[i] <= '9') cout << txt[i] << endl;
        }*/
    }
    cout << "Кількість чисел " << rah << endl;
    file.close();
}