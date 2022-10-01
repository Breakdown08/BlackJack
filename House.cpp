#include "House.h"

House::House() : GenericPlayer("HOUSE") {}

bool House::IsHitting() const
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
void House::FlipFirstCard()
{
	if (!collection.empty())
	{
		collection[0]->Flip();
	}
}