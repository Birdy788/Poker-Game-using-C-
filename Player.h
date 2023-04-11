#include "Host.h"

#ifndef PLAYER_H
#define PLAYER_H

//Pragma once is enough
#pragma once

class Player
{
public:
    Player();
    ~Player();
    virtual void show_Hand();
    vector<string> hand;
};

#endif