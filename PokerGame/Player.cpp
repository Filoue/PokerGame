#include "Player.h"
#include "CheckHand.h"
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

	// return for all the possible hand
	if ((Flush(playerHand) && Straight(playerHand)) && playerHand[4]._Value == Value::kAce)
	{
		std::cout << "you got a Royal Flush";
		return 10;
	}
	else if (Flush(playerHand) && Straight(playerHand))
	{
		std::cout << "you got a straight Flush";
		return 9;
	}
	else if (ThreeOfKind(playerHand) && Pair(playerHand))
	{
		std::cout << "you got a Full House";
		return 7;
	}
	else if (Flush(playerHand))
	{
		std::cout << "you got a Flush";
		return 6;
	}
	else if (Straight(playerHand))
	{
		std::cout << "you got a straight";
		return 5;
	}
	else if (ThreeOfKind(playerHand))
	{
		std::cout << "you got a three of Kind";
		return 4;
	}
	else if (DoublePair(playerHand))
	{
		std::cout << "you got a Double Pair";
	}
	else if (Pair(playerHand))
	{
		std::cout << "you got a Pair";
	}
			
}

std::string Player::Display()
{
	return std::format("{} | {} | {} | {} | {}", _hand_cards[0].ToString(), _hand_cards[1].ToString(), _hand_cards[2].ToString(), _hand_cards[3].ToString(), _hand_cards[4].ToString());
}
