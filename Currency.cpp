#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"

using namespace std;

// вывод на экран
void Currency::Print() {
	cout << "\tКУРС ВАЛЮТ" << endl << endl;
	cout << "\t" << kazah << kazah_t << endl;
	cout << "\t" << kvacha << kvacha_t << endl;
	cout << "\t" << kirgiz << kirgiz_t << endl;
	cout << "\t" << ukrain << ukrain_t << endl;
	cout << "\t" << myanma << myanma_t << endl;

	system("pause");
	system("cls");
}

// обмен валют
int Currency::Choice() {
	int a, value = 0;
	cout << "\tВЫБЕРИТЕ ВАЛЮТУ" << endl << endl;
	cout << "\t1 - " << kazah << kazah_t << endl <<  "\t*минимальная доступная сумма: 1740 тенге" << endl;
	cout << "\t2 - " << kvacha << kvacha_t << endl << "\t*минимальная доступная сумма: 70 квач" << endl;;
	cout << "\t3 - " << kirgiz << kirgiz_t << endl << "\t*минимальная доступная сумма: 350 сом" << endl;;
	cout << "\t4 - " << ukrain << ukrain_t << endl << "\t*минимальная доступная сумма: 110 гривен" << endl;;
	cout << "\t5 - " << myanma << myanma_t << endl << "\t*минимальная доступная сумма: 7770 кьят" << endl;;
	cin >> a;
	cout << "\tВведите сумму, которую желаете снять (в выбранной валюте): " << endl;
	cin >> value;

	switch (a)
	{
	case 1: {
		
		if (value < 1740) {
			cout << "\tМинимальная доступная сумма: 1740 тенге. Попробуйте еще раз!" << endl;
			break;
		}
			value /= kazah;
		
			break;
	}
	case 2: {
		if (value < 70) {
			cout << "\tМинимальная доступная сумма: 70 квач. Попробуйте еще раз!" << endl;
			break;
		}
		value /= kvacha;
		break;
	}
	case 3: {
		if (value < 350) {
			cout << "\tМинимальная доступная сумма: 350 сом. Попробуйте еще раз!" << endl;
			break;
		}
		value /= kirgiz;
		break;
	}
	case 4: {
		if (value < 110) {
			cout << "\tМинимальная доступная сумма: 110 гривен. Попробуйте еще раз!" << endl;
			break;
		}
		value /= ukrain;
		break;
	}
	case 5: {
		if (value < 7770) {
			cout << "\tМинимальная доступная сумма: 7770 кьят. Попробуйте еще раз!" << endl;
			break;
		}
		value /= myanma;
		break;
	}
	default:
		cout << "\tНеверный номер операции! Попробуйте еще раз." << endl;
		break;
	}

	return value;
}

// снять с карточки 
void Currency::MoneyOut(Card& card,int money) {
	ofstream record_("card.txt");

	
	card.CopyData();
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

			cout << "" << endl;
			PauseF();
			cout << "\tЗаберите ваши деньги!" << endl << endl;
			PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				cout << "\tЗаберите ваш чек!" << endl << endl;
				cout << "\t--------------------" << endl;
				cout << "\tКод операции: 003" << endl;
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

	record_.close();
}