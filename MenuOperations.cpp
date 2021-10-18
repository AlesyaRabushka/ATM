#include <iostream>
#include "MenuOperations.h"
#include "CardSessions.h"

using namespace std;

// метод всей проги
void MenuOperations::Print() {

	while (true) {
		cout << "\tВыберите операцию:" << endl;
		cout << "\t1 - Данные банковской карты" << endl;
		cout << "\t2 - Выдача наличных" << endl;
		cout << "\t3 - Валютные операции" << endl;
		cout << "\t4 - Смена пин-кода" << endl;
		cout << "\t5 - Добавить на карточку" << endl;
		cout << "\t6 - Перевести на счет в банке" << endl;
		cout << "\t7 - Показать инфу про счёт" << endl;
		cout << "\t8 - Предоставить выписку" << endl;
		cout << "\t0 - Забрать карту и закончить работу" << endl;
		int k;
		cin >> k;
		Card card;
		Bank bank;

		switch (k) {
		case 1: {
			system("cls");
			card.Print();
			cout << endl;
			break;
		}
		case 2: {
			system("cls");
			GiveMoney::MoneyOut(card);
			break;
		}
		case 3: {
			system("cls");
			int a;
			cout << "\tВыберите операцию:" << endl;
			cout << "\t1 - Курс валюты" << endl;
			cout << "\t2 - Выдача наличных иностранной валюты" << endl;
			cin >> a;
			switch (a)
			{
			case 1: {
				Currency::Print();
				break;
			}
			case 2: {
				int i = Choice();
				Currency::MoneyOut(card, i);
				break;
			}
			default:
				cout << "\tНеверный номер операции! Попробуйте еще раз." << endl;
				break;
			}
			break;
		}
		case 4: {
			system("cls");
			ChangePin::ChangeCardPin(card, card.GetCardPin());
			break;
		}
		case 5: {
			system("cls");
			GetMoney::MoneyIn(card);
			cout << endl;
			break;
		}
		case 6: {
			system("cls");
			Payement::Pay(card, bank);
			break;
		}
		case 7: {
			system("cls");
			bank.Print();
			cout << endl;
			break;
		}
		case 8: {
			system("cls");
			cout << "\t\t Выписка: " << endl;
			Statement::Print();
			break;
		}
		case 0: {
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t Заберите вашу карту!" << endl;
			CardSessions::PauseF();
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t Спасибо, что воспользовались нашим банкоматом!" << endl;
			cout << endl << endl << endl << endl << endl << endl << endl;
			exit(0);
		}
		}
	}
}
