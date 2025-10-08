#include <iostream>
#include <array>

#include "Player.h"
#include "Deck.h"
#include "Card.h"

int main()
{
	int playerOne;
	Player player;
	Deck deck;

	// make the deck
	deck.Fill();

	std::cout << "Deck complete ------------------------------------------" << "\n";

	Card c = { Hand::kClub, Value::kTwo };

	//player.SetHand({ deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw(), deck.Draw() });
	player.SetHand(
		{
			{
				{Hand::kClub, Value::kTen},
				{Hand::kDiamonds, Value::kTen},
				{Hand::kClub, Value::kTen},
				{Hand::kClub, Value::kQueen},
				{Hand::kClub, Value::kQueen}
			}
		}
	);
	player.OrderHand();

	playerOne = player.CheckHand();


	std::cout << std::format("Player one Card: {} \n", player.Display());

	return 0;
}
