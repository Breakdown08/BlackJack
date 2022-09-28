#include "House.h"

House::House() : GenericPlayer("HOUSE") {}

bool House::IsHitting() const //- ����� ���������, ����� �� ������ ��� ���� �����.���� � ������ �� ������ 16 �����, �� �� ����� ��� ���� �����.
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
void House::FlipFirstCard() //- ����� �������������� ������ ����� ������.
{
	Card* card;
	card = this->collection[0];
	card->Flip();
}