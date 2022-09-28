#include "Player.h"
#include "Game.h"

int main()
{
	//Card c1(TCardValue::ACE, TSuit::SPADES);
	//Card c2(TCardValue::FIVE, TSuit::SPADES);
	//Card c3(TCardValue::TEN, TSuit::SPADES);
	//Card c4(TCardValue::ACE, TSuit::HEARTS);
	Player player("Kirill");
	std::vector<Player> players;
	players.push_back(player);
	//Card* ptrCard = nullptr;
	//
	//ptrCard = &c1;
	//player.Add(ptrCard);
	//ptrCard = &c2;
	//player.Add(ptrCard);
	//ptrCard = &c3;
	//player.Add(ptrCard);
	//ptrCard = &c4;
	//player.Add(ptrCard);
	//std::cout << player << std::endl;
	Game game(players);
}


