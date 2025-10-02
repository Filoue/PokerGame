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

std::string Player::Display()
{
	return std::format("{} | {} | {} | {} | {}", _hand_cards[0].ToString(), _hand_cards[1].ToString(), _hand_cards[2].ToString(), _hand_cards[3].ToString(), _hand_cards[4].ToString());
}
