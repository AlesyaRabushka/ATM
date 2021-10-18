#pragma once
#include <iostream>
#include <string>

using namespace std;

// MAIN CLASS FOR ATM
class Bankomat
{
private:
	string number;
	string holder;
	string card_data;
	int card_pin;
	int balance = 0;
	int card_cvv;
	string empty;  //просто пустая строка, чтобы после считывания int можно было перейти на след строку

public:
	// конструктор
	Bankomat();

	//геттеры и сеттеры
	void SetNumber(string);
	void SetHolder(string);
	void SetCardPin(int);
	void SetCardData(string);
	void SetBalance(int);

	string GetNumber();
	string GetHolder();
	string GetCardData();
	int GetCardPin();
	int GetBalance();
	int GetCardCvv();

	//  копирование данных карточки, чтобы можно было менять какое-то поле
	void CopyData();
	void CopyAccount();

	// вывод на экран данных
	virtual void Print() = 0;
};

