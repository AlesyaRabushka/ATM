#include <iostream>
#include "Card.h"
#include "MainOperations.h"
#include "CardSessions.h"


using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	while (true) {
		Menu();
		int k;
		cin >> k;
		Card card;
		switch (k) {
		case 1: {
			CardSessions::ShowBalance(card);
			break;
		}
		case 4: {
			CardSessions::ChangeCardPin(card, card.GetCardPin());
			break;
		}
		case 5: {
			GetMoney::MoneyIn(card, card.GetCardBalance());
		}


		}

	}


	return 0;
}