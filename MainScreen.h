#pragma once

#include <iostream>
#include "Card.h"
#include "CardSessions.h"
#include "Singleton.h"

using namespace std;

class MainScreen: public Card, public CardSessions {
public:
	// конструктор
	MainScreen();
	MainScreen(Singleton*);

	bool CheckStr(char*, int);

	// проверка пин-кода при входе в банкомат
    bool CheckPin(Singleton*);
};
