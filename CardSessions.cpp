#include <iostream>
#include "CardSessions.h"
#include "Card.h"
#include <string>
#include <windows.h>

using namespace std;

void CardSessions::SetMoneyAmount(int money) {
	this->money_amount = money;
}
void CardSessions::SetMoneyCurrency(string money) {
	this->money_currency = money;
}

int CardSessions::GetMoneyAmount() {
	return this->money_amount;
}
string CardSessions::GetMoneyCurrency() {
	return this->money_currency;
}

void CardSessions::PauseF() {
	cout << "\t. ";
	Sleep(1000);
	cout << "\t. ";
	Sleep(1000);
	cout << "\t. ";
	Sleep(1000);
	cout << endl;
}

// ����� ������ � ��������
void GiveMoney::MoneyOut(Card& card) {
	int money;
	card.CopyData();
	ofstream record_("card.txt");

	cout << "\t������� �����: ";
	cin >> money;
	try {
		if (money > card.GetCardBalance() || money < 0) {
			throw "\t�������� �� ����� ���� ���������! ���������� ��� ��� �����.";
		}
		else {

			int new_money = card.GetCardBalance() - money;

			if (record_) {
				record_ << card.GetCardNumber() << endl;
				record_ << card.GetCardData() << endl;
				record_ << card.GetCardHolder() << endl;
				record_ << card.GetCardPin() << endl;
				record_ << card.GetCardCvv() << endl;
				record_ << new_money << endl;
			}

			cout << "\t�������� ���� ������!" << endl;
			CardSessions::PauseF();
			cout << endl << "\t������� ������� ���? " << endl;
			cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			}
		}
	}
	catch (const char* exception) {
		cerr << exception << endl;
		ofstream record("card.txt");
		if (record) {
			record << card.GetCardNumber() << endl;
			record << card.GetCardData() << endl;
			record << card.GetCardHolder() << endl;
			record << card.GetCardPin() << endl;
			record << card.GetCardCvv() << endl;
			record << card.GetCardBalance() << endl;
		}
	}

	record_.close();
	//remove("newcard.txt");
}

// �������� ������ �� ��������
void GetMoney::MoneyIn(Card& card) {
	int money;
	cout << "\t������� �����: ";
	cin >> money;
	ofstream record("card.txt");
	int new_money = card.GetCardBalance() + money;

	if (record) {
		record << card.GetCardNumber() << endl;
		record << card.GetCardData() << endl;
		record << card.GetCardHolder() << endl;
		record << card.GetCardPin() << endl;
		record << card.GetCardCvv() << endl;
		record << new_money << endl;
	}

	record.close();
	remove("newcard.txt");
}

// ����� ������ �� ��������
void CardSessions::ChangeCardPin(Card& card, int old) {
	bool flag;
	for (int i = 3; i >= 1; i--)
	{
		cout << "\t������� ������ ���-���: ";
		int old_pin, new_pin;
		cin >> old_pin;

		if (old == old_pin) {
			flag = true;
			card.CopyData();
			ifstream read("newcard.txt");
			ofstream record("card.txt");
			cout << "\t������� ����� ���-���: ";
			try {
				cin >> new_pin;
				if (new_pin >= 10000) {
					throw "\t���������! ���-��� �� ������������� ������������� �����������. ���������� ��� ��� �����!";
				}
				card.SetCardPin(new_pin);
				cout << "\t�������� ��������� �������!" << endl;
			}
			catch (const char* exception) {
				cerr << exception << endl;
			}

			if (read) {
				if (record) {
					record << card.GetCardNumber() << endl;
					record << card.GetCardData() << endl;
					record << card.GetCardHolder() << endl;
					record << card.GetCardPin() << endl;
					record << card.GetCardCvv() << endl;
					record << card.GetCardBalance() << endl;
				}
			}
			read.close();
			record.close();
			remove("newcard.txt");
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
	}
	cout << endl;
}

// �������� ������� 
void CardSessions::ShowBalance(Card& card) {
	cout << "\t������� ������: " << card.GetCardBalance() << endl << endl;
}

void CardSessions::CopyAccount() {
	ifstream from_account("ac.txt");
	ofstream new_account("newac.txt");

	if (from_account) {
		if (new_account) {
			string ac_num, ac_hol;
			int na;
			getline(from_account, ac_num);
			new_account << ac_num << endl;
		
			getline(from_account, ac_hol);
			new_account << ac_hol << endl;

			from_account >> na;
			new_account <<na << endl;
		}
	}
	from_account.close();
	new_account.close();
}


// ������ � �������� �� ������
void Payement::Pay(Card& card) {
	int money;
	card.CopyData();
	ofstream record_("card.txt");
	CardSessions::CopyAccount();
	ofstream record("ac.txt");
	ifstream read("newac.txt");

	cout << "\t������� ����� ��������: ";
	cin >> money;
	try {

		if (money < 0) {
			throw "\t�������� �� ����� ���� ���������! ���������� ��� ��� �����.";
		}
		else {

			int new_money = card.GetCardBalance() - money;

			if (record_) {
				record_ << card.GetCardNumber() << endl;
				record_ << card.GetCardData() << endl;
				record_ << card.GetCardHolder() << endl;
				record_ << card.GetCardPin() << endl;
				record_ << card.GetCardCvv() << endl;
				record_ << new_money << endl;
			}
			
			if (read) {
				if (record) {
					string acc_number, acc_holder;
					int acc_bal;
					getline(read, acc_number);
					record << acc_number << endl;
					getline(read, acc_holder);
					record << acc_holder << endl;
					read >> acc_bal;
					record << acc_bal + money << endl;


					CardSessions::PauseF();
					cout << endl << "\t������� ������� ���? " << endl;
					cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
					int k;
					cin >> k;
					switch (k) {
					case 1: {
						cout << "\t�������� ��� ���!" << endl;
						cout << "\t��� ��������: 001" << endl;
						cout << "\t���� ����������: " << acc_number << endl;
						cout << "\t����� ��������: " << money << endl;
						CardSessions::PauseF();
						cout << endl;
						break;
					}
					case 2: {
						break;
					}
					}
				}
			}
			
		}
	}
	catch (const char* exception) {
		cerr << exception << endl;
		ofstream record("card.txt");
		if (record) {
			record << card.GetCardNumber() << endl;
			record << card.GetCardData() << endl;
			record << card.GetCardHolder() << endl;
			record << card.GetCardPin() << endl;
			record << card.GetCardCvv() << endl;
			record << card.GetCardBalance() << endl;
		}
	}

	record_.close();
	read.close();
	record.close();
}