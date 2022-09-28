#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Hand
{
public:
	std::vector<Card*> collection;
	void Add(Card* card);
	void Clear();
	int GetValue() const;
};