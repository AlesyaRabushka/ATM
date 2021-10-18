#pragma once

#include <iostream>
#include "Card.h"
#include "CardSessions.h"

using namespace std;

class MainScreen: public Card, public CardSessions {
public:
	// конструктор
	MainScreen();

	// проверка пин-кода при входе в банкомат
    bool CheckPin();
};