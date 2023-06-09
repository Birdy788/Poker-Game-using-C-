#include "Cards.h"

Cards::Cards()
{
 
    // initialize random seed
    srand(time(0));
    
}

string Cards::drawCard(){
        int index = rand() % deck.size();
        string card = deck[index];
        deck.erase(deck.begin() + index);
        return card;
}

vector<string> Cards::drawTwoCards() {
        vector<string> cards;
        for (int i = 0; i < 2; i++) {
            cards.push_back(drawCard());
        }
        return cards;
}

vector<string> Cards::drawThreeCards() {
        vector<string> cards;
        for (int i = 0; i < 3; i++) {
            cards.push_back(drawCard());
        }
        return cards;
}

void Cards::reset() {
        deck = {"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH",
                "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC",
                "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD",
                "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS"};
}