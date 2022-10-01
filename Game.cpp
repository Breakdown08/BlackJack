#include "Game.h"

void Game::Play()
{
	system("cls");
	for (size_t i = 0; i < this->players.size(); i++)
	{
		deck.Deal(this->players[i]);
		deck.Deal(this->players[i]);
	};
	deck.Deal(this->house);
	deck.Deal(this->house);
	house.FlipFirstCard();
	for (size_t i = 0; i < this->players.size(); i++)
	{
		std::cout << this->players[i];
	}
	std::cout << house;
	for (size_t i = 0; i < this->players.size(); i++)
	{
		deck.AdditionalCards(this->players[i]);
	};
	house.FlipFirstCard();
	deck.AdditionalCards(house);
	std::cout << house;
	std::cout << std::endl;
	for (size_t i = 0; i < this->players.size(); i++)
	{
		std::cout << this->players[i];
		if (this->players[i].GetValue() > house.GetValue() && !house.IsHitting() && !this->players[i].IsBusted())
		{
			this->players[i].Win();
		}

		else if (this->players[i].GetValue() == house.GetValue() && !house.IsHitting())
		{
			this->players[i].Push();
		}

		else if (this->players[i].IsBusted())
		{
			this->players[i].Lose();
		}

		else if (house.GetValue() > this->players[i].GetValue() && !house.IsBusted())
		{
			this->players[i].Lose();
		}

		else if (house.IsBusted() && !this->players[i].IsBusted())
		{
			this->players[i].Win();
		}

		else if (!house.IsBusted() && !this->players[i].IsBusted())
		{
			if (house.GetValue() > this->players[i].GetValue())
			{
				this->players[i].Lose();
			}
			else
			{
				this->players[i].Win();
			}
		}
	};
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].collection.clear();
	};
	house.collection.clear();
	
}

Game::Game(std::vector<Player> players) : players(players)
{
	
}
