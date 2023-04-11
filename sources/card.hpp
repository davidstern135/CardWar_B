#pragma once
#include <iostream>
namespace ariel{
    class Card{
    public:
        enum class CardShape{ HEARTS, DIAMONDS, CLUBS, SPADES };
        enum class CardRank{TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};
    private:
        CardShape shape;
        CardRank rank;
    public:
        Card(CardRank rank,CardShape shape);
        CardRank getRank();
        CardShape getShape();
        void printCard();
        std::string stringCard();
        };
    }