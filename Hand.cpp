#include "Hand.h"

void Hand::Add(Card* card)
{
	card->Flip(); //думаю это разумно, так как изначально выданна€ карта рубашкой вниз по умолчанию
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
		if (collection[i]->GetValue() != TCardValue::ACE) //сначала считаем Ќ≈ “”«џ
		{
			sum += static_cast<int>(collection[i]->GetValue());
		}
		else //если же были тузы запоминаем их количество
		{
			countAces++;
		}
	}
	for (size_t i = 0; i < countAces; i++) // затем проход по оставшимс€ тузам если они есть
	{
		if (sum + 11 <= 21) // если будет перебор либо попадание ровно в 21 очко, то можно смело считать туз за 11 очков
		{
			sum += 11;
		}
		else // в противном случае будем считать его единицей из перечислени€
		{
			sum += static_cast<int>(TCardValue::ACE);
		}
	}
	return sum;
}