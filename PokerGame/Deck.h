#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	void Fill();

	Card Draw();
private:
	std::vector<Card> cards_;
};

