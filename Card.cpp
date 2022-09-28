#include "Card.h"
#include "Funcs.h"


Card::Card(TCardValue value, TSuit suit)
{
	this->value = value;
	this->suit = suit;
}

bool Card::IsOpened()
{
	return isOpened;
}

void Card::Flip()
{
	isOpened = !isOpened;
}

TCardValue Card::GetValue()
{
	return value;
}

TSuit Card::GetSuit()
{
	return suit;
}

std::ostream& operator<< (std::ostream& out, Card* card)
{
	if (card->IsOpened())
	{
		out << CardToInt(card->GetValue()) << " of " << SuitToChar(card->GetSuit());
	}
	else
	{
		out << "XX";
	}
	return out;
}