#include "House.h"

House::House() : GenericPlayer("HOUSE") {}

bool House::IsHitting() const //- метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
{
	if (this->GetValue() <= 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void House::FlipFirstCard() //- метод переворачивает первую карту дилера.
{
	Card* card;
	card = this->collection[0];
	card->Flip();
}