#include "GenericPlayer.h"


std::string GenericPlayer::GetName() const
{
	return name;
}
GenericPlayer::GenericPlayer(std::string name)
{
	this->name = name;
}
bool GenericPlayer::IsBusted() const
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
void GenericPlayer::Bust()
{
	if (GenericPlayer::IsBusted())
	{
		std::cout << name << " is busted!" << std::endl;
	}
}
std::ostream& operator<< (std::ostream& out, GenericPlayer& gplayer)
{
out << "Name: " << gplayer.GetName() << std::endl;
out << "cards: ";
for (size_t i = 0; i < gplayer.collection.size(); i++)
{
	out << gplayer.collection[i] << ", ";
}
out << std::endl << "score: " << gplayer.GetValue() << std::endl;
return out;
}