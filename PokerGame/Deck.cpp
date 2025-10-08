#include "Deck.h"

#include <iostream>
#include <random>
#include <algorithm>

Card Deck::Draw()
{
	Card card = cards_.back();
	cards_.pop_back();

	return card;
}

void Deck::Fill()
{
	//clear the deck for making sure there isn't double cards.
	cards_.clear();

	//make a card with all the differente value and symbol for the card
	for (int hand = 0; hand < 4; hand++)
	{
		for (int value = 2; value <= 14; value++)
		{
			cards_.emplace_back(Card{ static_cast<Hand>(hand), static_cast<Value>(value) });
		}
	}

	//make all the deck shuffle with random
	std::random_device rd;
	std::mt19937 gen { rd()};
	std::ranges::shuffle(cards_, gen);

	//display all the cards
	std::ranges::for_each(cards_, [](Card c) {std::cout << c.ToString() << "\n"; });
}