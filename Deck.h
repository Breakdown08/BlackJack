#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <random>
#include <ctime>        
#include <cstdlib>      
#include "Funcs.h"
#include <algorithm>    
#include <iterator>    

class Deck : public Hand
{
public:
	Deck();
	void Populate();
	void Shuffle();
	void Init();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};


