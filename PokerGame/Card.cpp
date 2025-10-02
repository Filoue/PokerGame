#include "Card.h"
#include <print>

std::string Card::ToString()
{
	return std::format("{} of {}", ValueToString(_Value), HandToString(_Hand));
}

std::string HandToString(Hand hands)
{

	switch (hands)
	{
	case Hand::kClub: return "Club";
	case Hand::kHearts: return "Hearts";
	case Hand::kSpades: return "Spades";
	case Hand::kDiamonds: return "Diamonds";
	}
}

std::string ValueToString(Value value)
{
	switch (value)
	{
	case Value::kTwo:
		return "two";
	case Value::kThree:
		return "three";
	case Value::kFour:
		return "four";
	case Value::kFive:
		return "five";
	case Value::kSix:
		return "six";
	case Value::kSeven:
		return "seven";
	case Value::kHeight:
		return "height";
	case Value::kNine:
		return "nine";
	case Value::kTen:
		return "ten";
	case Value::kJack:
		return "jack";
	case Value::kQueen:
		return "queen";
	case Value::kKing:
		return "king";
	case Value::kAce:
		return "ace";
	}

}