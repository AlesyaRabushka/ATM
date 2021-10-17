#include <iostream>
#include "CardSessions.h"
#include <Windows.h>
#include <string>

using namespace std;

// пауза
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

	
	cout << "\tВведите сумму выдачи: ";
	cin >> money;
	try {
		if (money > card.GetBalance() || money < 0) {
			throw "\tОперация не может быть выполнена! Попробуйте ещё раз позже.";
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

			
			PauseF();
			cout << "\tЗаберите ваши деньги!" << endl <<  endl;
			PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				PauseF();
				cout << "\tЗаберите ваш чек!" << endl;
				cout << "\tКод операции: 002" << endl;
				cout << "\tСумма выдачи: " << money << endl;
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
	//remove("newcard.txt");
}

// положить деньги на карточку
void GetMoney::MoneyIn(Card& card) {
	int money;
	cout << "\tВсавьте купюру: ";
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
	cout << "\tОдобрено! Операция выполнена успешно!" << endl;
	record.close();
}

// оплата с карточки на счёт за услуги
void Payement::Pay(Card& card, Bank& bank) {
	int money;
	bank.CopyAccount();
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

								cout << "\tТекущий баланс на счёте: " << acc_bal + money << endl;

								PauseF();
								cout << endl << "\tЖелаете забрать чек? " << endl;
								cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
								int k;
								cin >> k;
								switch (k) {
								case 1: {
									PauseF();
									cout << "\tЗаберите ваш чек!" << endl << endl;
									cout << "\tКод операции: 001" << endl;
									cout << "\tСчет получателя: " << acc_number << endl;
									cout << "\tСумма перевода: " << money << endl;
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

// сменить пароль на карточке
void ChangePin::ChangeCardPin(Card& card, int old) {
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
				cout << "\tОперация выполнена успешно!" << endl;
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
				cout << "\tНеверный пин-код! Попробуйте ещё раз! Осталось попыток: " << i - 1 << endl;
			}
		}
	}
	if (flag == 0) {
		cout << "\tНеверный пин-код. Попробуйте позже!" << endl;
	}
	cout << endl;
}
