#pragma once
#include <iostream>
#include <string>

using namespace std;

// MAIN CLASS FOR ATM
class Bankomat
{
private:
	string number;
	string holder;
	string card_data;
	int card_pin;
	int balance = 0;
	int card_cvv;
	string empty;  //������ ������ ������, ����� ����� ���������� int ����� ���� ������� �� ���� ������

public:
	// �����������
	Bankomat();

	//������� � �������
	void SetNumber(string);
	void SetHolder(string);
	void SetCardPin(int);
	void SetCardData(string);
	void SetBalance(int);

	string GetNumber();
	string GetHolder();
	string GetCardData();
	int GetCardPin();
	int GetBalance();
	int GetCardCvv();

	//  ����������� ������ ��������, ����� ����� ���� ������ �����-�� ����
	void CopyData();
	void CopyAccount();

	// ����� �� ����� ������
	void Print();
};

