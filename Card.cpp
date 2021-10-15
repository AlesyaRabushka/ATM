#include <iostream>
#include "Card.h"

//конструктор -----  ввод данных о карточке из файлика
Card::Card() {

	card_number = "no";
	card_holder = "no";
	card_pin = 0;
	card_cvv = 0;

	ifstream from_card("card.txt");
	if (from_card) {
		getline(from_card, card_number);
		getline(from_card, card_data);
		getline(from_card, card_holder);
		from_card >> card_pin;
		getline(from_card, empty);
		from_card >> card_cvv;
		getline(from_card, empty);
		from_card >> card_balance;
		
	}
	from_card.close();
}

//геттеры и сеттеры
string Card::GetCardNumber() {
	return card_number;
}
string Card::GetCardHolder() {
	return card_holder;
}
string Card::GetCardData() {
	return card_data;
}
int Card::GetCardPin() {
	return card_pin;
}
int Card::GetCardBalance() {
	return card_balance;
}
int Card::GetCardCvv() {
	return card_cvv;
}

void Card::SetCardNumber(string number) {
	this->card_number = number;
}
void Card::SetCardHolder(string holder) {
	this->card_holder = holder;
}
void Card::SetCardPin(int pin) {
	this->card_pin = pin;
}
void Card::SetCardData(string data) {
	this->card_data = data;
}

// копирование данных о карточке
void Card::CopyData() {
	ifstream from_card("card.txt");
	ofstream new_card("newcard.txt");

	if (from_card) {
		if (new_card) {
			getline(from_card, card_number);
			getline(from_card, card_data);
			getline(from_card, card_holder);
			
			from_card >> card_pin;
			getline(from_card, empty);
			from_card >> card_cvv;
			getline(from_card, empty);
			from_card >> card_balance;

			new_card << card_number << endl;
			new_card << card_data << endl;
			new_card << card_holder << endl;
			
			new_card << card_balance << endl;
			new_card << card_pin << endl;
			new_card << card_cvv << endl;
		}
	}
	from_card.close();
	new_card.close();
}
