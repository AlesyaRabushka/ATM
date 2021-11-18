#include "Joke.h"
#include<iostream>
#include<cstdlib>

int Joke::GetRandom(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


void Joke::JokeOfTheDay() {
	system("cls");
	int r = GetRandom(1, 11);
	cout << endl << endl << "\t\t\tВНИМАНИЕ!!! Обязательное условие: читайте шутку вслух!" << endl;
	PauseF();
	system("cls");
	cout << "\t\t\t-----------------" << endl;
	cout << "\t\t\t   Шутка дня:" << endl;
	cout << "\t\t\t-----------------" << endl;
	cout << endl;

	switch (r) {
	case 11: {
		cout << "\tВстречаются как-то круг и квадрат. И круг ему говорит\n - Катись отсюда!" << endl << endl << endl;
		break;
	}
	case 1:{
		cout << "\tНепринципиальный священник начал проповедь словами «Хотите — верьте, хотите — нет»." << endl << endl << endl;
		break;
	}
	case 2: {
		cout << "\t— Приветик, дурак! — Сам ты приветик." << endl << endl << endl;
		break;
	}
	case 3: {
		cout << "\tОднажды я спросил маму: «Сколько будет 2х2?». «Много будешь знать, скоро состаришься», — ответила она. \n\t«Четыре», — сказал дедушка и заплакал." << endl << endl << endl;
		break;
	}
	case 4: {
		cout << "\tБог сумел создать целый мир всего за 6 дней по единственной причине\n – у него не было предыдущих версий и проблем совместимости." << endl << endl << endl;
		break;
	}
	case 5: {
		cout << "\tЖил—был царь. И было у него косоглазие. Пошёл он однажды куда глаза глядят и порвался." << endl << endl << endl;
		break;
	}
	case 6: {
		cout << "\tЧтобы не сидеть без денег, я прилег." << endl << endl << endl;
		break;
	}
	case 7: {
		cout << "\tМальчик так и не смог решить задачу со звездочкой, потому что запах этой дряни реально мешает." << endl << endl << endl;
		break;
	}
	case 8:{
		cout << "\tМитинг косоглазых состоялся на сорок метров левее здания городской администрации." << endl << endl << endl;
		break;
	}
	case 9: {
		cout << "\tРаньше жили бедно, а потом нас обокрали." << endl << endl << endl;
		break;
	}
	case 10: {
		cout << "\tЧтобы не сидеть без денег, я прилег." << endl << endl << endl;
		break;
	}
	}
}