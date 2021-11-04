#include <iostream>
#include <cstdlib>
#include "Bankomat.h"
#include "Card.h"
#include "MenuOperations.h"
#include "CardSessions.h"
#include "Bank.h"
#include "MainScreen.h"
#include "Singleton.h"



using namespace std;

Singleton* Singleton::_instance = nullptr;

int main() {

	setlocale(LC_ALL, "rus");
	//главный экран

	Singleton* log = Singleton::instance();

	MainScreen b(log);

	//если пароль правильный РАБОТАЕМ!
	if (b.CheckPin(log)) {
		MenuOperations a;
		a.Print(log);
	}

	//если неправильный - ПОКА ПОКА приходи потом!
	else exit(1);
	log->~Singleton();
	return 0;
}
