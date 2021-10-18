#include <iostream>
#include <cstdlib>
#include "Bankomat.h"
#include "Card.h"
#include "MenuOperations.h"
#include "CardSessions.h"
#include "Bank.h"
#include "MainScreen.h"


using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	MainScreen b;
	if (b.CheckPin()) {
		MenuOperations a;
		a.Print();
	}
	else exit(1);
	
	return 0;
}