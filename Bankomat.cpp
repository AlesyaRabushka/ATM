#include "Bankomat.h"
#include <fstream>
#include <string>
#include "Card.h"
using namespace std;

// конструктор
Bankomat::Bankomat() {

	ifstream from_card("card.txt");
	if (from_card) {
		getline(from_card, number);
		getline(from_card, card_data);
		getline(from_card, holder);
		from_card >> card_pin;
		getline(from_card, empty);
		from_card >> card_cvv;
		getline(from_card, empty);
		from_card >> balance;

	}
	from_card.close();
}


//геттеры и сеттеры
string Bankomat::GetNumber() {
	return number;
}
string Bankomat::GetHolder() {
	return holder;
}
string Bankomat::GetCardData() {
	return card_data;
}
int Bankomat::GetCardPin() {
	return card_pin;
}
int Bankomat::GetBalance() {
	return balance;
}
int Bankomat::GetCardCvv() {
	return card_cvv;
}

void Bankomat::SetNumber(string number) {
	this->number = number;
}
void Bankomat::SetHolder(string holder) {
	this->holder = holder;
}
void Bankomat::SetCardPin(int pin) {
	this->card_pin = pin;
}
void Bankomat::SetCardData(string data) {
	this->card_data = data;
}
void Bankomat::SetBalance(int balance) {
	this->balance = balance;
}

// копирование данных о карточке
void Bankomat::CopyData() {
	ifstream from_card("card.txt");
	ofstream new_card("newcard.txt");

	if (from_card) {
		if (new_card) {
			getline(from_card, number);
			getline(from_card, card_data);
			getline(from_card, holder);

			from_card >> card_pin;
			getline(from_card, empty);
			from_card >> card_cvv;
			getline(from_card, empty);
			from_card >> balance;

			new_card << number << endl;
			new_card << card_data << endl;
			new_card << holder << endl;

			new_card << balance << endl;
			new_card << card_pin << endl;
			new_card << card_cvv << endl;
		}
	}
	from_card.close();
	new_card.close();
}

// копирование данных о счете в банке
void Bankomat::CopyAccount() {
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
			new_account << na << endl;
		}
	}
	from_account.close();
	new_account.close();
}

// вывод информации на экран
void Bankomat::Print() {
	cout << "\tДоступные средства: " << GetBalance() << endl;
}