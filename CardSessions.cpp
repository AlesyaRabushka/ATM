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
				cout << "\tЗаберите ваш чек!" << endl;
				cout << "\tКод операции: 002" << endl;
				cout << "\tСумма выдачи: " << money << endl;
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
		card.SetCardBalance(new_money);
	}

	record.close();
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
					throw "\tОтклонено! Пин-код не соответствует установленным требованиям. Попробуйте ещё раз позже!";
				}
				card.SetCardPin(new_pin);
				cout << "\tОпреация выполнена успешно!" << endl;
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

// оплата с карточки на счёт за услуги
void Payement::Pay(Card& card) {
	int money;
	CardSessions::CopyAccount();
	ofstream record("ac.txt");
	cout << "\tВведите пин-код: ";
	int pin;
	cin >> pin;
	for (int i = 3; i >= 1; i--) {
		if (i - 1 == 0) break;
		else {
			if (pin != card.GetCardPin()) {
				cout << pin << endl;
			}
			else if(pin == card.GetCardPin()) {
				cout << "\tВведите сумму перевода: ";
				cin >> money;
				try {

					if (money < 0) {
						throw "\tОперация не может быть выполнена! Попробуйте ещё раз позже.";
					}
					else {
						card.CopyData();
						ofstream record_("card.txt");
						ifstream read("newac.txt");
						
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
								cout << acc_number << endl;
								record << acc_number << endl;
								getline(read, acc_holder);
								record << acc_holder << endl;
								read >> acc_bal;
								record << acc_bal + money << endl;
								

								cout << "\tТекущий баланс на счёте: " << acc_bal + money << endl;

								CardSessions::PauseF();
								cout << endl << "\tЖелаете забрать чек? " << endl;
								cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
								int k;
								cin >> k;
								switch (k) {
								case 1: {
									cout << "\tЗаберите ваш чек!" << endl;
									cout << "\tКод операции: 001" << endl;
									cout << "\tСчет получателя: " << acc_number << endl;
									cout << "\tСумма перевода: " << money << endl;
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
						record_.close();
						read.close();
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
			}
			break;
		}
	}
	
	record.close();
}
