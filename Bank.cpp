#include <iostream>
#include "Bank.h"
#include <fstream>
#include <string>

using namespace std;

Bank::Bank() {
	bank_number = "no";
	bank_holder = "no";
	bank_balance = 0;

	ifstream from_acc("ac.txt");
	if (from_acc) {
		getline(from_acc, bank_number);
		getline(from_acc, bank_holder);
		from_acc >> bank_balance;
	}
	from_acc.close();
}

void Bank::SetBankBalance(int balance) {
	this->bank_balance = balance;
}
void Bank::SetBankHolder(string holder) {
	this->bank_holder = holder;
}
void Bank::SetBankNumber(string number) {
	this->bank_number = number;
}

string Bank::GetBankNumber() {
	return bank_number;
}
string Bank::GetBankHolder() {
	return bank_holder;
}
int Bank::GetBankBalance() {
	return bank_balance;
}

void Bank::Print() {
	cout << "\tНомер счёта: " << Bank::GetBankNumber() << endl;
	cout << "\tДосупные средства: " << Bank::GetBankBalance() << endl << endl;
}
