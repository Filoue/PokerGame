#include <iostream>
#include <array>

#include "Player.h"
#include "Deck.h"
#include "Card.h"

int main()
{
	Player player;
	Deck deck;

	// make the deck
	deck.Fill();

	std::cout << "Deck complete ------------------------------------------" << "\n";


	player.SetHand({ deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw() });
	player.OrderHand();

	player.CheckHand();

	
	std::cout << std::format("Player one Card: {} \n", player.Display());

	return 0;
}
