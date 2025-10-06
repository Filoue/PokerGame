#pragma once
#include <array>
#include <print>

#include "Deck.h"
class Player :
    public Deck
{
public:
    // Get two cards and keep in hand
    void SetHand(std::array<Card, 5>);

    void OrderHand();

    void CheckHand();
    
    // Display the value of the card as string vaslue
    std::string Display();
private:
    std::array<Card, 5> _hand_cards;
};

