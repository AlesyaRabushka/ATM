#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bankomat.h"


using namespace std;

//CARD CLASS
class Card: public Bankomat{

public:
	//����������� --- ���� ������ �� �������
	Card();
	// ����� �� �����
	void Print();
};