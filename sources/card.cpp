#include "card.hpp"

#include <iostream>
using namespace std;
namespace ariel{

    Card::Card(CardRank rank1, CardShape shape1):rank(rank1),shape(shape1) {
    }
    Card::CardRank Card::getRank(){
        return this->rank;
    }
    Card::CardShape Card::getShape(){
        return this->shape;
    }
    string Card::stringCard() {
        string str="";
            switch (this->rank) {
                case CardRank::ACE:
                    str+= "Ace";
                    break;
                case CardRank::TWO:
                    str+= "2";
                    break;
                case CardRank::THREE:
                    str+= "3";
                    break;
                case CardRank::FOUR:
                    str+= "4";
                    break;
                case CardRank::FIVE:
                    str+= "5";
                    break;
                case CardRank::SIX:
                    str+= "6";
                    break;
                case CardRank::SEVEN:
                    str+="7";
                    break;
                case CardRank::EIGHT:
                    str+="8";
                    break;
                case CardRank::NINE:
                    str+="9";
                    break;
                case CardRank::TEN:
                    str+="10";
                    break;
                case CardRank::JACK:
                    str+="Jack";
                    break;
                case CardRank::QUEEN:
                    str+= "Queen";
                    break;
                case CardRank::KING:
                    str+="King";
                    break;
            }


            str+=" of ";

            switch (this->shape) {
                case CardShape::HEARTS:
                    str+= "Hearts";
                    break;
                case CardShape::DIAMONDS:
                    str+="Diamonds";
                    break;
                case CardShape::CLUBS:
                    str+="Clubs";
                    break;
                case CardShape::SPADES:
                    str+="Spades";
                    break;
            }
            return str;
    }

    void Card::printCard() {
        switch (this->rank) {
            case CardRank::ACE:
                std::cout << "Ace";
                break;
            case CardRank::TWO:
                std::cout << "2";
                break;
            case CardRank::THREE:
                std::cout << "3";
                break;
            case CardRank::FOUR:
                std::cout << "4";
                break;
            case CardRank::FIVE:
                std::cout << "5";
                break;
            case CardRank::SIX:
                std::cout << "6";
                break;
            case CardRank::SEVEN:
                std::cout << "7";
                break;
            case CardRank::EIGHT:
                std::cout << "8";
                break;
            case CardRank::NINE:
                std::cout << "9";
                break;
            case CardRank::TEN:
                std::cout << "10";
                break;
            case CardRank::JACK:
                std::cout << "Jack";
                break;
            case CardRank::QUEEN:
                std::cout << "Queen";
                break;
            case CardRank::KING:
                std::cout << "King";
                break;
        }

        std::cout << " of ";

        switch (this->shape) {
            case CardShape::HEARTS:
                std::cout << "Hearts";
                break;
            case CardShape::DIAMONDS:
                std::cout << "Diamonds";
                break;
            case CardShape::CLUBS:
                std::cout << "Clubs";
                break;
            case CardShape::SPADES:
                std::cout << "Spades";
                break;
        }
    }

}
