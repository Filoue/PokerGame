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
	std::array<int, 5> temp;

	int tempCardValue = 0;
	int counter = 0;
		
	// check the hand of player for any hand you can have
	bool straight = true;
	bool flush = true;
	bool pair = false;
	bool doublePair = true;
	bool threeOfKind = false;

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
	if (numberOfPair != 2)
	{
		doublePair = false;
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++) 
		{
			for (int k = j + 1; k < 5; k++)
			{
				if (playerHand[i].GetValue() == playerHand[j].GetValue() && playerHand[i].GetValue() == playerHand[k].GetValue())
				{
					threeOfKind = true;
					tempCardValue = playerHand[i].GetValue();
					break;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (playerHand[i].GetValue() != tempCardValue)
		{
			temp[counter] = playerHand[i].GetValue();
			counter++;
		}
	}
	if (temp[0] == temp[1])
	{
		pair = true;
	}
	

	// return for all the possible hand
	if ((flush && straight) && playerHand[4]._Value == Value::kAce)
	{
		std::cout << "you got a Royal Flush";
		return 10;
	}
	else if (flush && straight)
	{
		std::cout << "you got a straight Flush";
		return 9;
	}
	else if (threeOfKind && pair)
	{
		std::cout << "you got a Full House";
		return 7;
	}
	else if (flush)
	{
		std::cout << "you got a Flush";
		return 6;
	}
	else if (straight)
	{
		std::cout << "you got a straight";
		return 5;
	}
	else if (threeOfKind)
	{
		std::cout << "you got a three of Kind";
		return 4;
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
