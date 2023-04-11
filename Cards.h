#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Cards {
private:
    vector<string> deck = {"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH",
                           "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC",
                           "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD",
                           "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS"};
public:
    Cards();

    // return a random card from the deck and remove it from the deck
    string drawCard(); 

    // return a vector of two random cards from the deck and remove them from the deck
    vector<string> drawTwoCards();

    // return a vector of three random cards from the deck and remove them from the deck
    vector<string> drawThreeCards();

    // reset the deck to its initial state of 52 cards
    void reset();
};