#include "Joke.h"
#include<iostream>
#include<cstdlib>

int Joke::GetRandom(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


void Joke::JokeOfTheDay() {
	system("cls");
	int r = GetRandom(1, 11);
	cout << endl << endl << "\t\t\t��������!!! ������������ �������: ������� ����� �����!" << endl;
	PauseF();
	system("cls");
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t   ����� ���:" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << endl;

	switch (r) {
	case 11: {
		cout << "\t����������� ���-�� ���� � �������. � ���� ��� �������\n - ������ ������!" << endl << endl << endl;
		break;
	}
	case 1:{
		cout << "\t���������������� ��������� ����� ��������� ������� ������� � ������, ������ � ���." << endl << endl << endl;
		break;
	}
	case 2: {
		cout << "\t� ��������, �����! � ��� �� ��������." << endl << endl << endl;
		break;
	}
	case 3: {
		cout << "\t������� � ������� ����: �������� ����� 2�2?�. ������ ������ �����, ����� ������������, � �������� ���. \n\t�������, � ������ ������� � ��������." << endl << endl << endl;
		break;
	}
	case 4: {
		cout << "\t��� ����� ������� ����� ��� ����� �� 6 ���� �� ������������ �������\n � � ���� �� ���� ���������� ������ � ������� �������������." << endl << endl << endl;
		break;
	}
	case 5: {
		cout << "\t������ ����. � ���� � ���� ����������. ����� �� ������� ���� ����� ������ � ��������." << endl << endl << endl;
		break;
	}
	case 6: {
		cout << "\t����� �� ������ ��� �����, � ������." << endl << endl << endl;
		break;
	}
	case 7: {
		cout << "\t������� ��� � �� ���� ������ ������ �� ����������, ������ ��� ����� ���� ����� ������� ������." << endl << endl << endl;
		break;
	}
	case 8:{
		cout << "\t������ ���������� ��������� �� ����� ������ ����� ������ ��������� �������������." << endl << endl << endl;
		break;
	}
	case 9: {
		cout << "\t������ ���� �����, � ����� ��� ��������." << endl << endl << endl;
		break;
	}
	case 10: {
		cout << "\t����� �� ������ ��� �����, � ������." << endl << endl << endl;
		break;
	}
	}
}