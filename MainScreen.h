#pragma once

#include <iostream>
#include "Card.h"
#include "CardSessions.h"

using namespace std;

class MainScreen: public Card, public CardSessions {
public:
	// �����������
	MainScreen();

	// �������� ���-���� ��� ����� � ��������
    bool CheckPin();
};