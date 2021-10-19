#pragma once

#include <iostream>
#include <string>
#include "CardSessions.h"

using namespace std;

// CHANGE CURRENCY CLASS

class Currency: public GiveMoney, public virtual Bankomat, public Statement {
private:
	double kazah = 174, kvacha = 7, kirgiz = 35, ukrain = 11, myanma = 777;
	string kazah_t = ".00 (казахстанский тенге)", kvacha_t = ".00 (замбийская квача)", kirgiz_t = ".00 (киргизская сома)", ukrain_t = ".00 (украинская гривна)", myanma_t = ".00 (мьянманский кьят)";

public:
	// вывод на экран
	void Print();
	// для перемены на карточке
	void MoneyOut(Card&, double);
	//выбор валюты
	int Choice();
	//запись в выписку
	void ToFileFrom(Card&, double);
};
