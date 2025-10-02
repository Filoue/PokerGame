#pragma once
#include "Player.h"

void HighCard(Player player)
{
	std::cout << "High Card";
}

void Pair(Player player)
{

	HighCard(player);
}

void DoublePair(Player player)
{
	Pair(player);
}

void ThreeOfAKing(Player player)
{
	DoublePair(player);
}

void Straight(Player player)
{
	ThreeOfAKing(player);
}

void Flush(Player player)
{
	Straight(player);
}

void FullHouse(Player player)
{
	Flush(player);
}

void FourOfAKing(Player player)
{
	FullHouse(player);
}

void StraightFlush(Player player)
{

	FourOfAKing(player);
}

void RoyalFlush(Player player)
{
	StraightFlush(player);
}

void HandValue(Player player)
{
	RoyalFlush(player);
}
