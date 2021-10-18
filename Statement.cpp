#include "Statement.h"
#include "Card.h"
#include <iostream>
#include <fstream>


using namespace std;

// ������� � ���������� ������� ��������
void Statement::ToFileIn(Card& card, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\t���������� �������:" << endl;
		record << "\t����� �����: " << card.GetNumber() << endl;
		record << "\t����� ��������: " << money << endl;
		record << "\t��������� ��������: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// ������� � ������ ������� � ��������
void Statement::ToFileFrom(Card& card, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\t������ �������:" << endl;
		record << "\t����� ����� : " << card.GetNumber() << endl;
		record << "\t����� ��������: " << money << endl;
		record << "\t������� �������: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

//������� � ���������� ����� � �����
void Statement::ToFileIn(Bank& bank, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\t���������� �����:" << endl;
		record << "\t���� ����������: " << bank.GetNumber() << endl;
		record << "\t����� ��������: " << money << endl;
		record << "\t��������� ��������: " << bank.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// ����� �������
void Statement::Print() {
	ifstream read("statement.txt");

	if (read) {
		while (!read.eof()) {
			string str;
			getline(read, str);
			cout << str << endl;
		}
	}

	read.close();
}