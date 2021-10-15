#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"

//  SESSIONS CLASS
class CardSessions: public Bank {
private:
	int money_amount;
	string money_currency;

public:
	void SetMoneyAmount(int);
	void SetMoneyCurrency(string);

	int GetMoneyAmount();
	string GetMoneyCurrency();

	//смена пин-кода на карточке
	static void ChangeCardPin(Card&, int);//нестатическая ссылка на член должна указываться относительно заданного объекта, а мы его не создаём)
	static void ShowBalance(Card&);
};

// выдача наличных
class GiveMoney : public CardSessions {
public:
	static void MoneyOut();
};

// принятие деняк
class GetMoney : public CardSessions {
public:
	static void MoneyIn(Card&, int);
};