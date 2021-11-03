#include <iostream>
#include "CardSessions.h"
#include <Windows.h>
#include <string>
#include "Statement.h"
#include "Exception.h"

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
	double money;
	card.CopyData();
	ofstream record_("card.txt");

	
	cout << "\tВведите сумму выдачи: ";
	cin >> money;
	try {
		if (money > card.GetBalance() || money < 0) {
			throw "\tОперация не может быть выполнена! Попробуйте ещё раз позже.";
		}
		else {

			double new_money = card.GetBalance() - money;

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
			cout << endl << "\tЗаберите ваши деньги!" << endl;
			PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				cout << "\tЗаберите ваш чек!" << endl;
				cout << "\t--------------------" << endl;
				cout << "\tКод операции: 002" << endl;
				cout << "\tСумма выдачи: " << money << endl;
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

// положить деньги на карточку
void GetMoney::MoneyIn(Card& card) {
	double money;
	cout << "\tВставьте купюру: ";
	cin >> money;
	ofstream record("card.txt");
	double new_money = card.GetBalance() + money;

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
	ToFileIn(card, money);
}

// оплата с карточки на счёт за услуги
void Payement::Pay(Card& card, Bank& bank) {
	double money;
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
						throw Exception("Неверный формат ввода", "Оплата услуг");
					}
					else {
						card.CopyData();
						ofstream record_("card.txt");
						ifstream read("newac.txt");
						
						double new_money = card.GetBalance() - money;

						if (record_) {
							record_ << card.GetNumber() << endl;
							record_ << card.GetCardData() << endl;
							record_ << card.GetHolder() << endl;
							record_ << card.GetCardPin() << endl;
							record_ << card.GetCardCvv() << endl;
							record_ << new_money << endl;
							card.SetBalance(new_money);
							ToFileFrom(card, money);
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
								cout << endl << "\tЖелаете забрать чек? " << endl;
								cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
								int k;
								cin >> k;
								switch (k) {
								case 1: {
									cout << "\tЗаберите ваш чек!" << endl << endl;
									cout << "\t--------------------" << endl;
									cout << "\tКод операции: 001" << endl;
									cout << "\tСчет получателя: " << acc_number << endl;
									cout << "\tСумма перевода: " << money << endl;
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
				catch (Exception& exception) {
					cerr << exception.what() << endl;
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
				if (new_pin > 9999) {
					throw Exception("Неверный ввод пин-код", "Смена пин-код");
				}
				card.SetCardPin(new_pin);
				cout << "\tОперация выполнена успешно!" << endl;
			}
			catch (Exception& exception) {
				cerr << exception.what() << endl;
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

