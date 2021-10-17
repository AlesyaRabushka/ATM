#include <iostream>
#include "Bank.h"
#include <fstream>
#include <string>

using namespace std;

Bank::Bank() {
	Bank_number = "no";
	Bank_holder = "no";
	bank_balance = 0;

	ifstream from_acc("ac.txt");
	if (from_acc) {
		getline(from_acc, Bank_number);
		getline(from_acc, Bank_holder);
		from_acc >> bank_balance;
	}
	from_acc.close();
}

void Bank::SetAccBalance(int balance) {
	this->bank_balance = balance;
}
void Bank::SetBankHolder(string holder) {
	this->Bank_holder = holder;
}
void Bank::SetBankNumber(string number) {
	this->Bank_number = number;
}

string Bank::GetAccNumber() {
	return Bank_number;
}
string Bank::GetAccHolder() {
	return Bank_holder;
}
int Bank::GetAccBalance() {
	return bank_balance;
}

void Bank::Print() {
	cout << "\tНомер счёта: " << Bank::GetAccNumber() << endl;
	cout << "\tДосупные средства: " << Bank::GetAccBalance() << endl << endl;
}
