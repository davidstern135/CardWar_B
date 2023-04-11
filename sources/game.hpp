#pragma once
#include "player.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Game{
    private:
        Player &pl1;
        Player &pl2;
        string turn_log;
        string last_turn;
        string game_log;
        int turn_count;
        int draw_count;

//        void giveOutCards(Player& p1, Player p2);
    public:
        Game(Player &p1, Player &p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    };
}
