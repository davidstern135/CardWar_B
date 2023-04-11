#include "player.hpp"
#include <iostream>



namespace ariel {
    Player::Player(std::string name) {
        this->name = name;
        this->playingStatus= false;
        this->win_count=0;
    }
    void Player::setStatus(bool i) {
        this->playingStatus=i;

    }
    void Player::add_win() {
        this->win_count++;
    }
    int Player::get_win_count() {
        return this->win_count;
    }
    bool Player::getStatus() {
        return this->playingStatus;

    }
    ariel::Card Player::getFromHandDeck() {
        ariel::Card card = this->handDeck.back();
        this->handDeck.pop_back();
        return card;

    }
    void Player::setToWinningDeck(ariel::Card card){
        this->winningDeck.push_back(card);
    }
    void Player::setToHandDeck(ariel::Card card) {
        this->handDeck.push_back(card);

    }
     int Player::stacksize() {
        return this->handDeck.size();
    }
    string Player::getName(){
        return this->name;
    }
//    void setPlayingStatus(int status){
//        if(status!=0 && status!=1)
//    }

    int Player::cardesTaken() {
        return this->winningDeck.size();
    }
    void Player::getWinningDeck() {
        for(int i = 0;i<this->winningDeck.size();i++){
            this->winningDeck.at((unsigned)i).printCard();
            if(i!=(this->winningDeck.size()-1))
            cout<<", ";

        }
    }
    void Player::getHandDeck() {
        for(int i = 0;i<this->handDeck.size();i++){
            this->handDeck.at((unsigned)i).printCard();
            if(i!=(this->handDeck.size()-1))
                cout<<", ";

        }
    }

}