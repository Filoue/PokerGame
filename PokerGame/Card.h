#pragma once
#include <string>

enum class Hand
{
	kClub, 
	kHearts, 
	kSpades, 
	kDiamonds
};

enum class Value
{
	kTwo = 2,
	kThree,
	kFour,
	kFive,
	kSix,
	kSeven,
	kHeight,
	kNine,
	kTen,
	kJack,
	kQueen,
	kKing,
	kAce
};

struct Card
{
	Hand _Hand;
	Value _Value;

	std::string ToString();

};



std::string HandToString(Hand hand);
std::string ValueToString(Value value);


