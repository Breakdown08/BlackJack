#pragma once
#include "Hand.h"

class GenericPlayer : public Hand
{
private:
	std::string name;
public:
	std::string GetName() const;
	GenericPlayer(std::string name);
	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	void Bust();
	friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& gplayer);
};
std::ostream& operator<< (std::ostream& out, GenericPlayer& gplayer);
