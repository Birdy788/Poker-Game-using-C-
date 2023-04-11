#include "Player.h"

#ifndef POKER_ENGINE_H
#define POKER_ENGINE_H

#pragma once

class Poker_engine
{
public:
    Poker_engine();
    ~Poker_engine();

    // This function should convert the hand into a number for simplicity reasons
    void convertHand(Player); //maybe not necessary 

    //This function should add the cards and the Host_hand into one collection
    vector<string> Collection(Player, vector<string>);//Done

    // This func return true if the player has 1 or 2 pairs
    int pairs(Player, vector<string>); //Done
    
    //This func return true if the player has 3 or 4 of a kind
    int of_kind(Player, vector<string>); //Done

    //This func return true if the player has straigth
    bool straigth(Player, vector<string>); //Done

    //This func return true if the player has a fullhouse
    bool fullhouse(Player, vector<string>); //Done

    //This func return true if the player has flush
    bool flush(Player, vector<string>); //Done

    //This func return true if the player has color
    bool color(Player, vector<string>); //Done

    // associates a hand with its rank against other hands
    int handRank(Player, vector<string>); //Done

    //This func campares the rank between the two players to determine the winner
    int compareRank(Player, Player, vector<string> Host_hand);//Final_Test

    // if hands are the same, high cards are compared to determine winner
    int compareHands(Player, Player);//Final_Test

    // tests both hands to determine what they are
    int playPoker(Player, Player);

};

#endif