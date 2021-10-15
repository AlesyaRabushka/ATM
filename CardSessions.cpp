#include <iostream>
#include "CardSessions.h"
#include "Card.h"

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


void GiveMoney::MoneyOut() {
	cout << "\t�������� ������: " << GetMoneyAmount() << endl;
}

void GetMoney::MoneyIn() {
	//�������� �����, ��� ���� ����� 5 ��� 5 ������ � ��� �����
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
					throw "\t���-��� �� ������������� ������������� �����������. ���������� ��� ��� �����!";
				}
				card.SetCardPin(new_pin);
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
			else{
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
	cout << "������� ������: " << card.GetCardBalance() << endl;
}