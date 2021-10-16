#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>



using namespace std;

//CARD CLASS
class Card {
private:
	string card_number;
	string card_holder;
	string card_data;
	int card_pin;
	int card_balance = 0;
	int card_cvv;
	string empty;  //просто пустая строка, чтобы после считывания int можно было перейти на след строку

public:
	//конструктор --- ввод данных из файлика
	Card();

	//геттеры и сеттеры
	void SetCardNumber(string);
	void SetCardHolder(string);
	void SetCardPin(int);
	void SetCardData(string);

	string GetCardNumber();
	string GetCardHolder();
	string GetCardData();
	int GetCardPin();
	int GetCardBalance();
	int GetCardCvv();

	//  копирование данных карточки, чтобы можно было менять какое-то поле
	void CopyData();
};
