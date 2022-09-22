#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

enum class TSuit
{
	CLUBS, //КРЕСТИ
	DIAMONDS, //БУБИ
	HEARTS, //ЧЕРВИ
	SPADES //ПИКИ
};

enum class TCardValue : int
{
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};

class Card
{
private:
	TSuit suit;
	TCardValue value;
	bool isOpened = false;
public:
	Card(TCardValue value, TSuit suit)
	{
		this->value = value;
		this->suit = suit;
	}

	bool IsOpened()
	{
		return isOpened;
	}

	void Flip()
	{
		isOpened = !isOpened;
	}

	TCardValue GetValue()
	{
		return value;
	}

	int GetSuit()
	{
		return (int)value;
	}
};

class Hand
{
public:
	vector<Card*> collection;
	void Add(Card* card) 
	{
		collection.push_back(card);
	}
	void Clear()
	{
		collection.clear();
	}
	int GetValue() const
	{
		int sum = 0;
		int countAces = 0;
		for (size_t i = 0; i < collection.size(); i++)
		{
			if (collection[i]->GetValue() != TCardValue::ACE) //сначала считаем НЕ ТУЗЫ
			{
				sum += static_cast<int>(collection[i]->GetValue());
			}
			else //если же были тузы запоминаем их количество
			{
				countAces++;
			}
		}
		for (size_t i = 0; i < countAces; i++) // затем проход по оставшимся тузам если они есть
		{
			if (sum + 11 <= 21) // если будет перебор либо попадание ровно в 21 очко, то можно смело считать туз за 11 очков
			{
				sum += 11;
			}
			else // в противном случае будем считать его единицей из перечисления
			{
				sum += static_cast<int>(TCardValue::ACE);
			}
		}
		return sum;
	}
};

class GenericPlayer: public Hand
{
private:
	string name;
public:
	string GetName() const
	{
		return name;
	}
	GenericPlayer(string name)
	{
		this->name = name;
	}
	virtual bool IsHitting() = 0;
	bool IsBusted() const
	{
		if (this->GetValue() > 21)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Bust()
	{
		if (IsBusted())
		{
			cout << name << " is busted!" << endl;
		}
	}
};

class Player : public GenericPlayer
{
	virtual bool IsHitting() const
	{
		string answer;
		if (!IsBusted())
		{
			cout << "Do you need one more card? ('yes' or any word)" << endl;
			cin >> answer;
			if (answer == "yes")
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	void Win() const
	{
		cout << this->GetName() << " is WON" << endl;
	}
	void Lose() const
	{
		cout << this->GetName() << " is LOSE" << endl;
	}
	void Push() const
	{
		cout << this->GetName() << " is PUSH" << endl;
	}
};

class House : public GenericPlayer
{
	virtual bool IsHitting() const //- метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
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
	void FlipFirstCard() //- метод переворачивает первую карту дилера.
	{
		Card* card;
		card = this->collection[0];
		card->Flip();
	}
};

int main()
{
	//cout << someCard.IsOpened() << endl;
	//someCard.Flip();
	//cout << someCard.IsOpened() << endl;
	//someCard.Flip();
	//cout << someCard.IsOpened() << endl;
	//someCard.Flip();
	//cout << someCard.IsOpened() << endl;
	//cout << endl << endl;
	//cout << someCard.GetValue() << endl;

	Card c1(TCardValue::ACE, TSuit::SPADES);
	Card c2(TCardValue::FIVE, TSuit::SPADES);
	Card c3(TCardValue::TEN, TSuit::SPADES);
	Card c4(TCardValue::ACE, TSuit::HEARTS);
	Hand hand;
	Card* ptrCard = nullptr;
	
	ptrCard = &c1;
	hand.Add(ptrCard);
	ptrCard = &c2;
	hand.Add(ptrCard);
	ptrCard = &c3;
	hand.Add(ptrCard);
	ptrCard = &c4;
	hand.Add(ptrCard);

	cout << "in hand: " << hand.GetValue() << endl;

}


/*5. Написать перегрузку оператора вывода для класса Card.
Если карта перевернута рубашкой вверх(мы ее не видим), 
вывести ХХ, если мы ее видим, вывести масть и номинал карты.
Также для класса GenericPlayer написать перегрузку оператора вывода, 
который должен отображать имя игрока и его карты, а также общую сумму очков его карт.*/