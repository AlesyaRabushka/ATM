#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"

//  SESSIONS CLASS
class CardSessions : public Bank, public Card {
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

	//для вывода с паузой
	static void PauseF();
	static void CopyAccount();
};


// GIVE MONEY CLASS (TO CARD)
class GiveMoney : public CardSessions {
public:
	static void MoneyOut(Card&);
};


// GET MONEY CLASS (FROM CARD)
class GetMoney : public CardSessions {
public:
	static void MoneyIn(Card&);
};

// PAYEMENT (GROM CARD)
class Payement : public GetMoney {
	static void Pay(Card&);
};

//EXCHANGE CURRENCY CLASS
class Exchange : public Bank, public CardSessions {

};