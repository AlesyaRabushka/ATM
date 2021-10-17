#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank
{
private:
	string bank_number;
	string bank_holder;
	int bank_balance = 0;

public:
	Bank();
	void SetBankNumber(string);
	void SetBankHolder(string);
	void SetBankBalance(int);

	string GetBankNumber();
	string GetBankHolder();
	int GetBankBalance();

	void Print();
};
