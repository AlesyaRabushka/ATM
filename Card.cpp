#include <iostream>
#include "Card.h"

//����������� -----  ���� ������ � �������� �� �������
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

// ����� ������ � ��������
void Card::Print() {
	cout << "\t����� ��������: " << GetNumber() << endl;
	cout << "\t�������� ��������: " << GetHolder() << endl;
	cout << "\t���� �����������: " << GetCardData() << endl;
	Bankomat::Print();
}