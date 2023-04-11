#include "Host.h"

Host::Host()
{
    cout<<"Welcome to the most illustrious game of poker, where the thrill of the cards meets the sophistication of strategy. Take your seat among the elite and prepare to indulge in a night of high-stakes, heart-pumping action. Let the games begin."<<endl<<endl;
}

void Host::rand_shuffle(vector<string>& deck){
    random_shuffle(deck.begin(), deck.end());
}

void Host::show_Hand(){
    for(string c : Host_hand){
        cout<<"I have:"<<c<<endl;
    }
}