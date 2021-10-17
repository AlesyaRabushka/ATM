#include <iostream>
#include "Card.h"

//конструктор -----  ввод данных о карточке из файлика
Card::Card() {

	string card_number = "no";
	string card_holder = "no";
	string card_data = "no";
	int card_pin = 0;
	int card_cvv = 0;
	int card_balance;
	string empty;

	ifstream from_card("card.txt");
	if (from_card) {
		getline(from_card, card_number);
		SetNumber(card_number);
		getline(from_card, card_data);
		SetCardData(card_data);
		getline(from_card, card_holder);
		SetHolder(card_holder);
		from_card >> card_pin;
		getline(from_card, empty);
		SetCardPin(card_pin);
		from_card >> card_cvv;
		getline(from_card, empty);
		from_card >> card_balance;
		SetBalance(card_balance);

	}
	from_card.close();
}

// вывод данных о карточке
void Card::Print() {
	cout << "\tÍîěĺđ ęŕđňî÷ęč: " << GetNumber() << endl;
	cout << "\tÂëŕäĺëĺö ęŕđňî÷ęč: " << GetHolder() << endl;
	cout << "\tŃđîę ýęńďëóňŕöčč: " << GetCardData() << endl;
	Bankomat::Print();
}
