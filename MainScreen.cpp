#include <iostream>
#include "MainScreen.h"
#include "CardSessions.h"
#include <string>

using namespace std;

// �������� �������� ������
MainScreen::MainScreen() {
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t     �������� �����!" << endl;
	cout << "\t\t\t\t\t-----------------------" << endl << endl << endl << endl;
	system("pause");
	system("cls");
}

// �������� �� ������������ ���������� ���-���� �������� 
bool MainScreen::CheckPin() {
	int old = GetCardPin();
	bool flag;
	bool next;
	for (int i = 3; i >= 1; i--)
	{
		int new_pin;
		cout << endl << endl << endl  << endl << endl << endl << endl << endl << "\t\t\t\t\t������� ���-���: ";
		cin >> new_pin;
		cout << endl << endl;

		try {
			if (new_pin >= 10000) {
				throw "\t���������! ���-��� �� ������������� ������������� �����������. ���������� ��� ��� �����!";
			}
		}
		catch (const char* exception) {
			cerr << exception << endl;
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
				cout << "\t�������� ���-���! ���������� ��� ���! �������� �������: " << i - 1 << endl;
			}
		}
	}
	if (flag == 0) {
		cout << "\t�������� ���-���. ���������� �����!" << endl;
		next = false;
	}
	cout << endl;
	return next;
	system("pause");
	system("cls");
	
}