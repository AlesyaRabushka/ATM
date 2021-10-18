#pragma once

#include <iostream>
#include <string>
#include "CardSessions.h"

using namespace std;

// CHANGE CURRENCY CLASS

class Currency: public GiveMoney, public virtual Bankomat {
private:
	int kazah = 174, kvacha = 7, kirgiz = 35, ukrain = 11, myanma = 777;
	string kazah_t = ".00 (������������� �����)", kvacha_t = ".00 (���������� �����)", kirgiz_t = ".00 (���������� ����)", ukrain_t = ".00 (���������� ������)", myanma_t = ".00 (����������� ����)";

public:
	// ����� �� �����
	void Print();
	// ��� �������� �� ��������
	void MoneyOut(Card&, int);
	//����� ������
	int Choice();
};
