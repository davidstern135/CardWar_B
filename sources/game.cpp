#include "player.hpp"
#include "game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>



using namespace std;
namespace ariel {
    Game::Game(Player &p1, Player &p2) : pl1(p1), pl2(p2) {
        //checking the players are not playing with someone else before the game.
        if(pl1.getStatus()==true){
            throw invalid_argument("player 1 is already playing a different game!");
        }
        if(pl2.getStatus()==true){
            throw invalid_argument("player 2 is already playing a different game!");
        }
        this->turn_log="";
        this->turn_count=0;
        this->draw_count=0;
        this->last_turn="";
        this->pl1.setStatus(true);
        this->pl2.setStatus(true);
        vector <Card> fullDeck;
        //making a not shuffled deck.
        for (int shape = 0; shape < 4; shape++) {//creating the deck.
            for (int rank = 0; rank < 13; rank++) {
                fullDeck.push_back(Card((ariel::Card::CardRank) rank, (ariel::Card::CardShape) shape));
            }
        }
//        std::mt19937 random{std::random_device{}()};
        std::shuffle(fullDeck.begin(), fullDeck.end(), std::random_device());// Shuffling the deck.


        for (int i = 0; i < 26; i++) {//handing out the players their cards.
            this->pl1.setToHandDeck(fullDeck.back());
            fullDeck.pop_back();
            this->pl2.setToHandDeck(fullDeck.back());
            fullDeck.pop_back();
        }
    }


    void Game::playTurn() {
        if (&pl1 == &pl2)//checking for the same player.
            throw invalid_argument("same player is not allowed.");
        if (pl1.stacksize() == 0) {//if they are out of cards the game ended.
            throw invalid_argument("the game has ended!");
        }
        this->turn_count++;//counting turns.
        vector <Card> p1_table;
        vector <Card> p2_table;
        bool tie = true;
        this->last_turn = "";

        while (tie) {
            p1_table.push_back(this->pl1.getFromHandDeck());
            p2_table.push_back(this->pl2.getFromHandDeck());
            this->last_turn +=
                    pl1.getName() + " played " + p1_table.back().stringCard() + " " + pl2.getName() + " played " +
                    p2_table.back().stringCard() + ". ";
            if (p1_table.back().getRank() == p2_table.back().getRank()) {
                if (pl1.stacksize() > 0) {// checking the hand deck isn't empty.
                    p1_table.push_back(this->pl1.getFromHandDeck());//one card upside down.
                    p2_table.push_back(this->pl2.getFromHandDeck());
                }
                this->draw_count++;
                this->last_turn += "draw!. ";
                if (pl1.stacksize() == 0) {
                    while (p1_table.size() > 0) {
                        this->pl1.setToWinningDeck(p1_table.back());
                        p1_table.pop_back();
                        this->pl2.setToWinningDeck(p2_table.back());
                        p2_table.pop_back();
                    }
                    tie = false;

                }

            }
            else if (p1_table.back().getRank() == Card::CardRank::ACE) {
                if (p2_table.back().getRank() == Card::CardRank::TWO) {//two ia better then ace.
                    while (p1_table.size() > 0) {//two wins ace and moving all to player with the two.
                        this->pl2.setToWinningDeck(p1_table.back());
                        p1_table.pop_back();
                        this->pl2.setToWinningDeck(p2_table.back());
                        p2_table.pop_back();
                        tie = false;

                    }
                    this->pl2.add_win();
                    this->last_turn += pl2.getName() + " wins.\n";
                }
                else {       //p2_table.back().getRank()!=Card::CardRank::TWO
                    while (p1_table.size() > 0) {//ace is better them anything that isn't two
                        this->pl1.setToWinningDeck(p1_table.back());
                        p1_table.pop_back();
                        this->pl1.setToWinningDeck(p2_table.back());
                        p2_table.pop_back();
                        tie = false;

                    }
                    this->pl1.add_win();
                    this->last_turn += pl1.getName() + " wins.\n";
                }

            }
            else if (p2_table.back().getRank() == Card::CardRank::ACE) {
                if (p1_table.back().getRank() == Card::CardRank::TWO) {//two ia better then ace.
                    while (p1_table.size() > 0) {//two wins ace and moving all to player with the two.
                        this->pl1.setToWinningDeck(p1_table.back());
                        p1_table.pop_back();
                        this->pl1.setToWinningDeck(p2_table.back());
                        p2_table.pop_back();
                        tie = false;
                    }
                    this->pl1.add_win();
                    this->last_turn += pl1.getName() + " wins.\n";
                }
                else {       //p1_table.back().getRank()!=Card::CardRank::TWO
                    while (p1_table.size() > 0) {//ace is better them anything that isn't two
                        this->pl2.setToWinningDeck(p1_table.back());
                        p1_table.pop_back();
                        this->pl2.setToWinningDeck(p2_table.back());
                        p2_table.pop_back();
                        tie = false;


                    }
                    this->pl2.add_win();
                    this->last_turn += pl2.getName() + " wins.\n";

                }

            } else if (p1_table.back().getRank() > p2_table.back().getRank()) {
                while (p1_table.size() > 0) {//moving everything to player 1.
                    this->pl1.setToWinningDeck(p1_table.back());
                    p1_table.pop_back();
                    this->pl1.setToWinningDeck(p2_table.back());
                    p2_table.pop_back();
                    tie = false;

                }
                this->pl1.add_win();
                this->last_turn += pl1.getName() + " wins.\n";
            }
            else {//p1_table.back().getRank()<p2_table.back().getRank()
                while (p1_table.size() > 0) {//moving everything to player 2.
                    this->pl2.setToWinningDeck(p1_table.back());
                    p1_table.pop_back();
                    this->pl2.setToWinningDeck(p2_table.back());
                    p2_table.pop_back();
                    tie = false;


                }
                this->pl2.add_win();
                this->last_turn += pl2.getName() + " wins.\n";

            }
//            pl1.getHandDeck();
        }
        if (pl1.stacksize()==0){
            pl1.setStatus(false);
            pl2.setStatus(false);
        }

        this->turn_log += this->last_turn;
//        cout<<this->pl1.stacksize()<<endl;
    }

    void Game::printLastTurn(){
        cout<<this->last_turn<<endl;
    }
    void Game::playAll(){
        if(pl1.stacksize()==0){
            throw "the game has ended!";
        }
        else{
            while(this->pl1.stacksize()!=0) {
                this->playTurn();
            }

        }
    }
    void Game::printWiner(){
        if(this->pl1.cardesTaken()+this->pl2.cardesTaken()==52){
            if(this->pl1.cardesTaken()>this->pl2.cardesTaken()){
                cout<<this->pl1.getName()<<endl;
            }
            else if((this->pl1.cardesTaken()<this->pl2.cardesTaken())){
                cout<<this->pl2.getName()<<endl;
            }
            else{
                cout<<"draw, no winner!";
            }
        }
        else{
            string name;
            if(this->pl1.cardesTaken()>this->pl2.cardesTaken()){
                name =this->pl1.getName()+" is winning";
            }
            else if((this->pl1.cardesTaken()<this->pl2.cardesTaken())){
                name =this->pl2.getName()+" is winning";
            }
            else{
                name ="no one has an advantage.";
            }
            cout<<"For now "+name+" but the game is not over!\n";
        }
    }
    void Game::printLog(){
        cout<<this->turn_log<<endl;
    }
    void Game::printStats(){
        if(this->turn_count!=0) {
            double win_rate_pl1 = (((1.0 * this->pl1.get_win_count()) / this->turn_count) * 100);
            double win_rate_pl2 = (((1.0 * this->pl2.get_win_count()) / this->turn_count) * 100);
            double draw_rate = (((1.0 * this->draw_count) / this->turn_count) * 100);
            cout << this->pl1.getName() << " won " << this->pl1.get_win_count() << " out of " << this->turn_count
                 << " turns. which is " << win_rate_pl1 << "% of the game. " << this->pl1.getName() << " won " <<
                 this->pl1.cardesTaken() << " cards." << endl;
            cout << this->pl2.getName() << " won " << this->pl2.get_win_count() << " out of " << this->turn_count
                 << " turns. which is " << win_rate_pl2 << "% of the game. " << this->pl2.getName() << " won " <<
                 this->pl2.cardesTaken() << " cards." << endl;
            cout << "we had " << this->draw_count << " draws which is " << draw_rate << "% of the total turns."
                 << endl;
        }

    }
}

