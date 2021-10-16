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

// снять деньги с карточки
void GiveMoney::MoneyOut(Card& card) {
	int money;
	card.CopyData();
	ofstream record_("card.txt");
	
	cout << "\tВведите сумму: ";
	cin >> money;
	try {
		if (money > card.GetCardBalance() || money < 0) {
			throw "\tОперация не может быть выполнена! Попробуйте ещё раз позже.";
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

			cout << "\tЗаберите ваши деньги!" << endl;
			CardSessions::PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
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

// положить деньги на карточку
void GetMoney::MoneyIn(Card& card) {
	int money;
	cout << "\tВведите сумму: ";
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

// смена пароля на корточке
void CardSessions::ChangeCardPin(Card& card, int old) {
	bool flag;
	for (int i = 3; i >= 1; i--)
	{
		cout << "\tВведите старый пин-код: ";
		int old_pin, new_pin;
		cin >> old_pin;

		if (old == old_pin) {
			flag = true;
			card.CopyData();
			ifstream read("newcard.txt");
			ofstream record("card.txt");
			cout << "\tВведите новый пин-код: ";
			try {
				cin >> new_pin;
				if (new_pin >= 10000) {
					throw "\tПин-код не соответствует установленным требованиям. Попробуйте ещё раз позже!";
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
			else {
				cout << "\tНеверный пин-код! Попробуйте ещё раз! Осталось попыток: " << i - 1 << endl;
			}
		}
	}
	if (flag == 0) {
		cout << "\tНеверный пин-код. Попробуйте позже!" << endl;
	}
	cout << endl;
}

// проверка баланса 
void CardSessions::ShowBalance(Card& card) {
	cout << "\tТекущий баланс: " << card.GetCardBalance() << endl << endl;
}

//void CardSessions::CopyAccount() {
//	ifstream from_account("account.txt");
//	ofstream new_account("newaccount.txt");
//
//	if (from_account) {
//		if (new_account) {
//			getline(from_account, card_number);
//			getline(from_account, card_data);
//			getline(from_account, card_holder);
//
//			from_account >> card_pin;
//			getline(from_account, empty);
//			from_account >> card_cvv;
//			getline(from_account, empty);
//			from_account >> card_balance;
//
//			new_account << card_number << endl;
//			new_account << card_data << endl;
//			new_account << card_holder << endl;
//
//			new_account << card_balance << endl;
//			new_account << card_pin << endl;
//			new_account << card_cvv << endl;
//		}
//	}
//	from_account.close();
//	new_account.close();
//}

// пока не сделала!!!!!!
// оплата с карточки за услуги
void Payement::Pay(Card& card) {
	int money;
	card.CopyData();
	ofstream record_("card.txt");

	cout << "\tВведите сумму: ";
	cin >> money;
	try {
		if (money > card.GetCardBalance() || money < 0) {
			throw "\tОперация не может быть выполнена! Попробуйте ещё раз позже.";
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

			cout << "\tЗаберите ваши деньги!" << endl;
			CardSessions::PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
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




	ofstream record("account.txt");
	if (record) {
		
	}

	record.close();
}
