#include "Player.h"

bool Player::IsHitting() const
{
	std::string answer;
	if (!IsBusted())
	{
		std::cout << GetName() << ", do you need one more card? ('yes' or any word)" << std::endl;
		std::cin >> answer;
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
void Player::Win() const
{
	std::cout << this->GetName() << " is WON" << std::endl;
}
void Player::Lose() const
{
	std::cout << this->GetName() << " is LOSE" << std::endl;
}
void Player::Push() const
{
	std::cout << this->GetName() << " is PUSH" << std::endl;
}