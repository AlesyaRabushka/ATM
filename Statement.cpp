#include "Statement.h"
#include "Card.h"
#include <iostream>
#include <fstream>


using namespace std;

// выписка о пополнении средств карточки
void Statement::ToFileIn(Card& card, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tПополнение средств:" << endl;
		record << "\tНомер карты: " << card.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tДоступные средства: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// выписка о снятии средств с карточки
void Statement::ToFileFrom(Card& card, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tСнятие средств:" << endl;
		record << "\tНомер карты : " << card.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tОстаток средств: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

//выписка о пополнении счета в банке
void Statement::ToFileIn(Bank& bank, int money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tПополнение счета:" << endl;
		record << "\tСчет получателя: " << bank.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tДоступные средства: " << bank.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// вывод выписки
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
