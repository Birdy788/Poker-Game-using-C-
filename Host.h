#include "Cards.h"

#include <algorithm>

#pragma once

class Host 
{
public:
    Host();
    Cards deck;
    vector<string> Host_hand;
    void rand_shuffle(vector<string>& deck);
    void show_Hand();
};
