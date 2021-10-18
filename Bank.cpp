#include <iostream>
#include "Bank.h"
#include <fstream>
#include <string>

using namespace std;

Bank::Bank() {
	string bank_number = "no";
	string bank_holder = "no";
	int bank_balance = 0;

	ifstream from_acc("ac.txt");
	if (from_acc) {
		getline(from_acc, bank_number);
		SetNumber(bank_number);
		getline(from_acc, bank_holder);
		SetHolder(bank_holder);
		from_acc >> bank_balance;
		SetBalance(bank_balance);

	}
	from_acc.close();
}

void Bank::Print() {
	cout << "\tНомер счета: " << GetNumber() << endl;
	cout << "\tВладелец счета: " << GetHolder() << endl;
	cout << "\tДоступные средства: " << GetBalance() << endl;
}
