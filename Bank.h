#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bankomat.h"

using namespace std;

// BANK CLASS
class Bank: public Bankomat
{
public:
	// ����������� 
	Bank();
	// ����� �� �����
	void Print();
};