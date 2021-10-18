#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"
#include "Statement.h"

//  SESSIONS CLASS
class CardSessions {

public:
	//��� ������ � ������
	static void PauseF();
};


// GIVE MONEY CLASS (FROM CARD)
class GiveMoney : public CardSessions, public Statement {
public:
	static void MoneyOut(Card&);
};

// CHANGE CARD PIN CLASS
class ChangePin : public Bankomat{
public:
	//����� ���-���� �� ��������
	static void ChangeCardPin(Card&, int);//������������� ������ �� ���� ������ ����������� ������������ ��������� �������, � �� ��� �� ������)
};

// GET MONEY CLASS (TO CARD)
class GetMoney : public CardSessions, public Statement {
public:
	static void MoneyIn(Card&);
};

// PAYEMENT (FROM CARD)
class Payement : public CardSessions, public Statement {
public:
	static void Pay(Card&, Bank&);
};
