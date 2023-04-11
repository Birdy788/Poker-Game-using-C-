#include "Player.h"

Player::Player()
{
    cout<<"Ante up, let's play some cards!"<<endl;
}
Player::~Player(){
}
void Player::show_Hand(){
    for(string c : hand){
        cout<<"I have:"<<c<<endl;
    }
    
}