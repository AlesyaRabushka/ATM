#include <iostream>
#include "MainScreen.h"
#include "CardSessions.h"
#include <string>

using namespace std;

// заствака главного экрана
MainScreen::MainScreen() {
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t     Вставьте карту!" << endl;
	cout << "\t\t\t\t\t-----------------------" << endl << endl << endl << endl;
	system("pause");
	system("cls");
}

// проверка на правильность введенного пин-кода карточки 
bool MainScreen::CheckPin() {
	int old = GetCardPin();
	bool flag;
	bool next;
	for (int i = 3; i >= 1; i--)
	{
		int new_pin;
		cout << endl << endl << endl  << endl << endl << endl << endl << endl << "\t\t\t\t\tВведите пин-код: ";
		cin >> new_pin;
		cout << endl << endl;

		try {
			if (new_pin > 9999) {
				throw Exception("Недопустимый ввод пин-код", "Ввод пин-код");
			}
		}
		catch (Exception& exception) {
			cerr << exception.what() << endl;
		}

		if (old == new_pin) {
			flag = true;
			next = true;
			system("cls");
			break;
		}

		else {
			flag = 0;
			if (i - 1 == 0) break;
			else {
				system("cls");
				cout << endl << endl << "\t\t\tНеверный пин-код! Попробуйте ещё раз! Осталось попыток: " << i - 1 << endl;
			}
		}
	}
	if (flag == 0) {
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\tНеверный пин-код. Попробуйте позже!" << endl;
		next = false;
	}
	cout << endl;
	return next;
	system("pause");
	system("cls");
	
}
