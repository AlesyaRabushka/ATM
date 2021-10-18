#include <iostream>
#include "MenuOperations.h"
#include "CardSessions.h"

using namespace std;

// ����� ���� �����
void MenuOperations::Print() {

	while (true) {
		cout << "\t�������� ��������:" << endl;
		cout << "\t1 - ������ ���������� �����" << endl;
		cout << "\t2 - ������ ��������" << endl;
		cout << "\t3 - �������� ��������" << endl;
		cout << "\t4 - ����� ���-����" << endl;
		cout << "\t5 - �������� �� ��������" << endl;
		cout << "\t6 - ��������� �� ���� � �����" << endl;
		cout << "\t7 - �������� ���� ��� ����" << endl;
		cout << "\t8 - ������������ �������" << endl;
		cout << "\t0 - ������� ����� � ��������� ������" << endl;
		int k;
		cin >> k;
		Card card;
		Bank bank;

		switch (k) {
		case 1: {
			system("cls");
			card.Print();
			cout << endl;
			break;
		}
		case 2: {
			system("cls");
			GiveMoney::MoneyOut(card);
			break;
		}
		case 3: {
			system("cls");
			int a;
			cout << "\t�������� ��������:" << endl;
			cout << "\t1 - ���� ������" << endl;
			cout << "\t2 - ������ �������� ����������� ������" << endl;
			cin >> a;
			switch (a)
			{
			case 1: {
				Currency::Print();
				break;
			}
			case 2: {
				int i = Choice();
				Currency::MoneyOut(card, i);
				break;
			}
			default:
				cout << "\t�������� ����� ��������! ���������� ��� ���." << endl;
				break;
			}
			break;
		}
		case 4: {
			system("cls");
			ChangePin::ChangeCardPin(card, card.GetCardPin());
			break;
		}
		case 5: {
			system("cls");
			GetMoney::MoneyIn(card);
			cout << endl;
			break;
		}
		case 6: {
			system("cls");
			Payement::Pay(card, bank);
			break;
		}
		case 7: {
			system("cls");
			bank.Print();
			cout << endl;
			break;
		}
		case 8: {
			system("cls");
			cout << "\t\t �������: " << endl;
			Statement::Print();
			break;
		}
		case 0: {
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t �������� ���� �����!" << endl;
			CardSessions::PauseF();
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t �������, ��� ������������ ��� ��������!" << endl;
			cout << endl << endl << endl << endl << endl << endl << endl;
			exit(0);
		}
		}
	}
}