#include <iostream>
#include "Card.h"
#include "MenuOperations.h"
#include "CardSessions.h"
#include "Bank.h"


using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	while (true) {
		Menu();
		int k;
		cin >> k;
		Card card;
		Bank bank;
		 
		switch (k) {
		case 1: {
			card.Print();
			cout << endl;
			break;
		}
		case 4: {
			ChangePin::ChangeCardPin(card, card.GetCardPin());
			break;
		}
		case 5: {
			GetMoney::MoneyIn(card);
			cout << endl;
			break;
		}
		case 2: {
			GiveMoney::MoneyOut(card);
			break;
		}
		case 6: {
			Payement::Pay(card, bank);
			break;
		}
		case 7: {
			bank.Print();
			cout << endl;
			break;
		}

		}

	}


	return 0;
}
