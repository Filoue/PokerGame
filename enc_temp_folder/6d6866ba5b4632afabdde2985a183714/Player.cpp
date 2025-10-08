#include "Player.h"
#include <iostream>
#include <algorithm>
#include <array>

void Player::SetHand(std::array<Card, 5> card)
{
	_hand_cards = card;
}

void Player::OrderHand()
{
	std::ranges::sort(_hand_cards, [](Card c1, Card c2) {return c1._Value < c2._Value; });
}

int Player::CheckHand()
{
	std::array<Card, 5> playerHand = _hand_cards;

		
	// check the hand of player for any hand you can have
	bool straight = true;
	bool flush = true;
	bool pair = true;
	bool doublePair = true;
	bool threeOfKind = true;

	// Check the straight
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetValue() != playerHand[n - 1].GetValue() + 1)
		{
			straight = false;
		}
	}

	// Check the Flush
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetHand() != playerHand[n - 1].GetHand())
		{
			flush = false;
		}
	}
	
	// Check the Pair and Double Pair
	int numberOfPair = 0;
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetValue() == playerHand[n -1].GetValue())
		{
			numberOfPair++;
		}
	}
	if (numberOfPair != 1)
	{
		pair = false;
	}
	else if (numberOfPair != 2)
	{
		doublePair = false;
	}

	// Check the three of kind
	for (int n = 2; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetValue() != playerHand[n - 1].GetValue() && playerHand[n - 1].GetValue() != playerHand[n - 2].GetValue())
		{
			threeOfKind = false;
		}
	}


	// return for all the possible hand
	if ((flush && straight) && playerHand[4]._Value == Value::kAce)
	{
		std::cout << "you got a Royal Flush";
	}
	else if (flush && straight)
	{
		std::cout << "you got a straight Flush";
	}
	else if (straight)
	{
		std::cout << "you got a straight";
		return 8;
	}
	else if (flush)
	{
		std::cout << "you got a Flush";
	}
	else if (doublePair && threeOfKind)
	{
		std::cout << "you got a Full House";
	}
	else if (threeOfKind)
	{
		std::cout << "you got a three of Kind";
	}
	else if (doublePair)
	{
		std::cout << "you got a Double Pair";
	}
	else if (pair)
	{
		std::cout << "you got a Pair";
	}
			
}

std::string Player::Display()
{
	return std::format("{} | {} | {} | {} | {}", _hand_cards[0].ToString(), _hand_cards[1].ToString(), _hand_cards[2].ToString(), _hand_cards[3].ToString(), _hand_cards[4].ToString());
}
