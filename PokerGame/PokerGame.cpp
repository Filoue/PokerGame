#include <iostream>
#include <array>

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "HandValue.h"

void InitSeed()
{
	srand(time(nullptr));
}


int main()
{
	Player player;
	Deck deck;

	// make the deck
	deck.Fill();

	std::cout << "Deck complete ------------------------------------------" << "\n";

	InitSeed();

	player.SetHand({ deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw() });
	player.OrderHand();

	HandValue(player);

	
	std::cout << std::format("Player one Card: {} \n", player.Display());

	return 0;
}
