#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"

using namespace std;

// ����� �� �����
void Currency::Print() {
	cout << "\t���� �����" << endl << endl;
	cout << "\t" << kazah << kazah_t << endl;
	cout << "\t" << kvacha << kvacha_t << endl;
	cout << "\t" << kirgiz << kirgiz_t << endl;
	cout << "\t" << ukrain << ukrain_t << endl;
	cout << "\t" << myanma << myanma_t << endl;

	system("pause");
	system("cls");
}

// ����� �����
int Currency::Choice() {
	int a, value = 0;
	cout << "\t�������� ������" << endl << endl;
	cout << "\t1 - " << kazah << kazah_t << endl <<  "\t*����������� ��������� �����: 1740 �����" << endl;
	cout << "\t2 - " << kvacha << kvacha_t << endl << "\t*����������� ��������� �����: 70 ����" << endl;;
	cout << "\t3 - " << kirgiz << kirgiz_t << endl << "\t*����������� ��������� �����: 350 ���" << endl;;
	cout << "\t4 - " << ukrain << ukrain_t << endl << "\t*����������� ��������� �����: 110 ������" << endl;;
	cout << "\t5 - " << myanma << myanma_t << endl << "\t*����������� ��������� �����: 7770 ����" << endl;;
	cin >> a;
	cout << "\t������� �����, ������� ������� ����� (� ��������� ������): " << endl;
	cin >> value;

	switch (a)
	{
	case 1: {
		
		if (value < 1740) {
			cout << "\t����������� ��������� �����: 1740 �����. ���������� ��� ���!" << endl;
			break;
		}
			value /= kazah;
		
			break;
	}
	case 2: {
		if (value < 70) {
			cout << "\t����������� ��������� �����: 70 ����. ���������� ��� ���!" << endl;
			break;
		}
		value /= kvacha;
		break;
	}
	case 3: {
		if (value < 350) {
			cout << "\t����������� ��������� �����: 350 ���. ���������� ��� ���!" << endl;
			break;
		}
		value /= kirgiz;
		break;
	}
	case 4: {
		if (value < 110) {
			cout << "\t����������� ��������� �����: 110 ������. ���������� ��� ���!" << endl;
			break;
		}
		value /= ukrain;
		break;
	}
	case 5: {
		if (value < 7770) {
			cout << "\t����������� ��������� �����: 7770 ����. ���������� ��� ���!" << endl;
			break;
		}
		value /= myanma;
		break;
	}
	default:
		cout << "\t�������� ����� ��������! ���������� ��� ���." << endl;
		break;
	}

	return value;
}

// ����� � �������� 
void Currency::MoneyOut(Card& card,int money) {
	ofstream record_("card.txt");

	
	card.CopyData();
	try {
		if (money > card.GetBalance() || money < 0) {
			throw "\t�������� �� ����� ���� ���������! ���������� ��� ��� �����.";
		}
		else {

			int new_money = card.GetBalance() - money;

			if (record_) {
				record_ << card.GetNumber() << endl;
				record_ << card.GetCardData() << endl;
				record_ << card.GetHolder() << endl;
				record_ << card.GetCardPin() << endl;
				record_ << card.GetCardCvv() << endl;
				record_ << new_money << endl;
			}

			cout << "" << endl;
			PauseF();
			cout << "\t�������� ���� ������!" << endl << endl;
			PauseF();
			cout << endl << "\t������� ������� ���? " << endl;
			cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				cout << "\t�������� ��� ���!" << endl << endl;
				cout << "\t--------------------" << endl;
				cout << "\t��� ��������: 003" << endl;
				cout << "\t����� ������: " << money << endl;
				cout << "\t--------------------" << endl;
				PauseF();
				cout << endl;
				break;

			}
			case 2: {
				break;
			}
			}
		}
	}
	catch (const char* exception) {
		cerr << exception << endl << endl;
		ofstream record("card.txt");
		if (record) {
			record << card.GetNumber() << endl;
			record << card.GetCardData() << endl;
			record << card.GetHolder() << endl;
			record << card.GetCardPin() << endl;
			record << card.GetCardCvv() << endl;
			record << card.GetBalance() << endl;
		}
	}

	record_.close();
}