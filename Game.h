#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
	Deck deck;
	House house;
	std::vector<Player> players;
	void Play();
	Game(std::vector<Player> players);
};
//����������� ������ ��������� � �������� ��������� ������ ���� ������� � ������� ������� ����� �������. 
//� ������������ ��������� ������ ���� � ����� ��������������.