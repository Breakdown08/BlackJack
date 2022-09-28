#include "Deck.h"
#include "Funcs.h"
//#include <vector>       // std::vector
Deck::Deck()
{
	Populate();
	Shuffle();
}

void Deck::Populate()
{
	std::cout << "START POPULATE" << std::endl;
	TSuit suits[4] = {TSuit::CLUBS, TSuit::DIAMONDS, TSuit::HEARTS, TSuit::SPADES};
	TCardValue values[13] = 
	{
		TCardValue::ACE,
		TCardValue::TWO,
		TCardValue::THREE,
		TCardValue::FOUR,
		TCardValue::FIVE,
		TCardValue::SIX,
		TCardValue::SEVEN,
		TCardValue::EIGHT,
		TCardValue::NINE,
		TCardValue::TEN,
		TCardValue::JACK,
		TCardValue::QUEEN,
		TCardValue::KING,
	};
	for (size_t i = 0; i < 13; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			this->Add(new Card(values[i], suits[j]));
		}
	}
}

void Deck::Shuffle()
{
	std::srand(unsigned(std::time(0)));
	std::shuffle(this->collection.begin(), this->collection.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!this->collection.empty())
	{
		aHand.Add(this->collection[0]);
		this->collection.erase(this->collection.begin());
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	if (!aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
	}
}
