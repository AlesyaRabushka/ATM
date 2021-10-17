#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"

//  SESSIONS CLASS
class CardSessions {

public:
	//��� ������ � ������
	static void PauseF();
};


// GIVE MONEY CLASS (TO CARD)
class GiveMoney : public CardSessions, public Bankomat {
public:
	static void MoneyOut(Card&);
};

// CHANGE CARD PIN CLASS
class ChangePin : public Bankomat{
public:
	//����� ���-���� �� ��������
	static void ChangeCardPin(Card&, int);//������������� ������ �� ���� ������ ����������� ������������ ��������� �������, � �� ��� �� ������)
};

// GET MONEY CLASS (FROM CARD)
class GetMoney : public CardSessions, public Card {
public:
	static void MoneyIn(Card&);
};

// PAYEMENT (FROM CARD)
class Payement : public Bankomat, public CardSessions {
public:
	static void Pay(Card&, Bank&);
};


//EXCHANGE CURRENCY CLASS
//class Exchange : public Bank, public CardSessions {
//
//};