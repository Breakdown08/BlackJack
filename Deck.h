#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <random>
#include <ctime>        
#include <cstdlib>      
#include <algorithm>    
#include <iterator>    

class Deck : Hand
{
private:
	int myrandom(int i) { return std::rand() % i; };
public:
	Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};


