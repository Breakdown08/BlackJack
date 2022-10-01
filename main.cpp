#include "Player.h"
#include "Game.h"

int playersCount;

int main()
{
	std::vector<Player> players;
	std::string wannaAgain;
	std::cout << "Input a count of players: ";
	std::cin >> playersCount;
	for (size_t i = 0; i < playersCount; i++)
	{
		std::string playerName;
		std::cout << "Input " << i + 1 << " player name:";
		std::cin >> playerName;
		Player player(playerName);
		players.push_back(player);
	}
	Game game(players);
	game.Play();
	std::cout << "Do you want to play again??" << std::endl;
	std::cin >> wannaAgain;
	while (wannaAgain == "yes")
	{
		game.deck.Init();
		game.Play();
		std::cout << "Do you want to play again??" << std::endl;
		std::cin >> wannaAgain;
	}
}


