#pragma once
#include <iostream>
#include "CardSessions.h"

using namespace std;

class Joke: public CardSessions{
public:

	static int GetRandom(int, int);
	static void JokeOfTheDay();
};

