#pragma once
#include "Funcs.h"
#include "Enums.h"
#include <iostream>
class Card
{
private:
	TSuit suit;
	TCardValue value;
	bool isOpened = false;
public:
	Card(TCardValue value, TSuit suit);
	~Card() {}

	friend std::ostream& operator<< (std::ostream& out, const Card* card);

	bool IsOpened();

	void Flip();

	TCardValue GetValue();

	TSuit GetSuit();
};

std::ostream& operator<< (std::ostream& out, Card* card);