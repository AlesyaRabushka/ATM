#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank
{
private:
	string Bank_number;
	string Bank_holder;
	int bank_balance = 0;

public:
	Bank();
	void SetBankNumber(string);
	void SetBankHolder(string);
	void SetAccBalance(int);

	string GetAccNumber();
	string GetAccHolder();
	int GetAccBalance();
	
	//информация о счете
	void Print();
};
