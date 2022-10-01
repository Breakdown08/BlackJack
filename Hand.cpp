#include "Hand.h"

void Hand::Add(Card* card)
{
	collection.push_back(card);
}
void Hand::Clear()
{
	collection.clear();
}
int Hand::GetValue() const
{
	int sum = 0;
	int countAces = 0;
	for (size_t i = 0; i < collection.size(); i++)
	{
		if (collection[i]->GetValue() != TCardValue::ACE)
		{
			sum += static_cast<int>(collection[i]->GetValue());
		}
		else
		{
			countAces++;
		}
	}
	for (size_t i = 0; i < countAces; i++)
	{
		if (sum + 11 <= 21)
		{
			sum += 11;
		}
		else
		{
			sum += static_cast<int>(TCardValue::ACE);
		}
	}
	return sum;
}