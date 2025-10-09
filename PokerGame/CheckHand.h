#pragma once
#include "Player.h"
#include <array>

int tempCardValue = 0;
int counter = 0;
std::array<int, 5> temp;



// Check the straight
bool Straight(std::array<Card, 5> playerHand)
{
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetValue() != playerHand[n - 1].GetValue() + 1)
		{
			return false;
		}
	}
}

// Check the Flush
bool Flush(std::array<Card, 5> playerHand)
{
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetHand() != playerHand[n - 1].GetHand())
		{
			return false;
		}
	}
	return true;
}

// Check the Double Pair
bool DoublePair(std::array<Card, 5> playerHand)
{
	int numberOfPair = 0;
	for (int n = 1; n < playerHand.size(); n++)
	{
		if (playerHand[n].GetValue() == playerHand[n - 1].GetValue())
		{
			numberOfPair++;
		}
	}
	if (numberOfPair != 2)
	{
		return false;
	}
	return true;
}

// Check The Three Of Kind
bool ThreeOfKind(std::array<Card, 5> playerHand)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				if (playerHand[i].GetValue() == playerHand[j].GetValue() && playerHand[i].GetValue() == playerHand[k].GetValue())
				{
					tempCardValue = playerHand[i].GetValue();
					return true;
					break;
				}
			}
		}
	}
	return false;
}

//Check the Pair
bool Pair(std::array<Card, 5> playerHand)
{
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
		return true;
	}
	return false;
}