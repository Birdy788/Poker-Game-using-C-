#include <iostream>
#include "Player.h"
#include "Poker_engine.h"

using namespace std;

int main()
{
    Host h;
    vector<Player> Players(2);
    Players[0].hand = h.deck.drawTwoCards();
    Players[1].hand = h.deck.drawTwoCards();
    h.Host_hand = h.deck.drawThreeCards();
    h.Host_hand.push_back(h.deck.drawCard());
    h.Host_hand.push_back(h.deck.drawCard());
    /*vector<string> p0{"KS", "QD"};
    vector<string> p1{"2D", "3D"};
    vector<string> ha{"10D","5S", "9D","10S", "JD"};
    Players[0].hand=p0; Players[1].hand=p1; h.Host_hand=ha;*/

    Poker_engine game;
    //game.playPoker(Players[0], Players[1]);

    cout<<"First player's Hand is:"<<endl;
    Players[0].show_Hand();
    
    cout<<"Second player's Hand is:"<<endl;
    Players[1].show_Hand();

    cout<<"Host's Hand is:"<<endl;
    h.show_Hand();

    int result= game.compareRank(Players[0],Players[1], h.Host_hand);

    cout<<"The winner is the player :"<<result<<endl;

    return 0;
}