#include "Player.h"
#include <iostream>
#include <algorithm>

void Player::SetHand(std::array<Card, 5> card)
{
	_hand_cards = card;
}

void Player::OrderHand()
{
	std::ranges::sort(_hand_cards, [](Card c1, Card c2) {return c1._Value < c2._Value; });
}

void Player::CheckHand()
{
	Card c1 = _hand_cards[0], c2 = _hand_cards[1], c3 = _hand_cards[2], c4 = _hand_cards[3], c5 = _hand_cards[4];
	if (c1._Hand == c2._Hand && c2._Hand == c3._Hand && c3._Hand == c4._Hand && c4._Hand == c5._Hand)
	{
		if (c5._Value == Value::kAce && c4._Value == Value::kKing && c3._Value == Value::kQueen && c2._Value == Value::kJack && c1._Value == Value::kTen )
		{
			std::cout << "you got a Royal Flush";
		}
		else
		{
			std::cout << "you got a Flush";
		}
	}
	else if (true)
	{

	}
	else if (c1._Value == c2._Value || c2._Value == c3._Value || c3._Value == c4._Value || c4._Value == c5._Value)
	{
		std::cout << "you got a pair";
	}
}

std::string Player::Display()
{
	return std::format("{} | {} | {} | {} | {}", _hand_cards[0].ToString(), _hand_cards[1].ToString(), _hand_cards[2].ToString(), _hand_cards[3].ToString(), _hand_cards[4].ToString());
}
