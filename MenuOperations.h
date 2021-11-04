#pragma once
#include <iostream>
#include "Card.h"
#include "CardSessions.h"
#include "Bank.h"
#include "Currency.h"
#include "Statement.h"


using namespace std;

// MENU OPERATIONS CLASS
class MenuOperations: virtual public Card, virtual public Bank, public GiveMoney , public GetMoney, public ChangePin, public Currency, public Payement, public Statement{

public:
	//основное меню программы
	void Print(Singleton*);
}; 
