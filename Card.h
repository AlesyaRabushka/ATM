#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bankomat.h"

using namespace std;

//CARD CLASS
class Card: virtual public Bankomat{

public:
	//конструктор --- ввод данных из файлика
	Card();
	// вывод на экран
	void Print(Singleton*) override;
};
