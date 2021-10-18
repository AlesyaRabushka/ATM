#pragma once
#include <iostream>
#include "Bankomat.h"
#include "Card.h"
#include"Bank.h"

using namespace std;

// CARD STATEMENT CLASS
class Statement: public virtual Card, public virtual Bankomat{
public:
	static void ToFileIn(Card&, int);
	static void ToFileFrom(Card&, int);
	static void ToFileIn(Bank&, int);

	static void Print();
};

