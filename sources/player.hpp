#pragma once
#include <vector>
#include <string>
#include "card.hpp"



using namespace std;

namespace ariel{
    class Player{
    private:
        string name;
        int playingStatus;
        int win_count;
        vector<Card> handDeck;
        vector<Card> winningDeck;
    public:
        int get_win_count();
        void add_win();
        void setStatus(bool i);
        bool getStatus();
        Card getFromHandDeck();
        void setToWinningDeck(Card card);
        void setToHandDeck(Card card);
        Player(string name);
        int stacksize();
        string getName();
        int cardesTaken();
        void getHandDeck();
        void getWinningDeck();
    };
}