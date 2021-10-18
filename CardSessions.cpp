#include <iostream>
#include "CardSessions.h"
#include <Windows.h>
#include <string>
#include "Statement.h"

using namespace std;

// �����
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

	
	cout << "\t������� ����� ������: ";
	cin >> money;
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
				card.SetBalance(new_money);
			}

			
			PauseF();
			cout << endl << "\t�������� ���� ������!" << endl;
			PauseF();
			cout << endl << "\t������� ������� ���? " << endl;
			cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				cout << "\t�������� ��� ���!" << endl;
				cout << "\t--------------------" << endl;
				cout << "\t��� ��������: 002" << endl;
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

	ToFileFrom(card, money);
	record_.close();
	//remove("newcard.txt");
}

// �������� ������ �� ��������
void GetMoney::MoneyIn(Card& card) {
	int money;
	cout << "\t�������� ������: ";
	cin >> money;
	ofstream record("card.txt");
	int new_money = card.GetBalance() + money;

	if (record) {
		record << card.GetNumber() << endl;
		record << card.GetCardData() << endl;
		record << card.GetHolder() << endl;
		record << card.GetCardPin() << endl;
		record << card.GetCardCvv() << endl;
		record << new_money << endl;
		card.SetBalance(new_money);
	}
	cout << endl;
	PauseF();
	cout << "\t��������! �������� ��������� �������!" << endl;
	record.close();
	ToFileIn(card, money);
}

// ������ � �������� �� ���� �� ������
void Payement::Pay(Card& card, Bank& bank) {
	int money;
	bank.CopyAccount();
	ofstream record("ac.txt");
	cout << "\t������� ���-���: ";
	int pin;
	cin >> pin;
	for (int i = 3; i >= 1; i--) {
		if (i - 1 == 0) break;
		else {
			if (pin != card.GetCardPin()) {
				cout << pin << endl;
			}
			else if(pin == card.GetCardPin()) {
				cout << "\t������� ����� ��������: ";
				cin >> money;
				try {

					if (money < 0) {
						throw "\t�������� �� ����� ���� ���������! ���������� ��� ��� �����.";
					}
					else {
						card.CopyData();
						ofstream record_("card.txt");
						ifstream read("newac.txt");
						
						int new_money = card.GetBalance() - money;

						if (record_) {
							record_ << card.GetNumber() << endl;
							record_ << card.GetCardData() << endl;
							record_ << card.GetHolder() << endl;
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
								bank.SetBalance(acc_bal + money);
								ToFileIn(bank, money);
								

								PauseF();
								cout << endl << "\t������� ������� ���? " << endl;
								cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
								int k;
								cin >> k;
								switch (k) {
								case 1: {
									cout << "\t�������� ��� ���!" << endl << endl;
									cout << "\t--------------------" << endl;
									cout << "\t��� ��������: 001" << endl;
									cout << "\t���� ����������: " << acc_number << endl;
									cout << "\t����� ��������: " << money << endl;
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
						record_.close();
						read.close();
					}
				}
				catch (const char* exception) {
					cerr << exception << endl;
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
			}
			break;
		}
	}
	
	record.close();
	//system("cls");
}

// ������� ������ �� ��������
void ChangePin::ChangeCardPin(Card& card, int old) {
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
					record << card.GetNumber() << endl;
					record << card.GetCardData() << endl;
					record << card.GetHolder() << endl;
					record << card.GetCardPin() << endl;
					record << card.GetCardCvv() << endl;
					record << card.GetBalance() << endl;
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
