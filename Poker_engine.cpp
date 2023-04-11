#include "Poker_engine.h"

Poker_engine::Poker_engine()
{
    cout<<"Game started!"<<endl;
}

Poker_engine::~Poker_engine()
{
    cout<<"Game ended!"<<endl;
}

vector<string> Poker_engine::Collection(Player p, vector<string> Host_hand){
    //Append all cards in one vector of strings
    vector<string> all_cards;
    for(string s : Host_hand){
        all_cards.push_back(s);
    }
    for(string s : p.hand){
        all_cards.push_back(s);
    }
    return all_cards;
}

//This func return the number of pairs in all_cards
int countPairsWithSameFirstChar(const std::vector<std::string>& vec) {
    unordered_map<char, int> charCounts;
    int pairCount = 0;
    
    // Count the number of strings that start with each character
    for (const auto& str : vec) {
        if (!str.empty()) {
            charCounts[str[0]]++;
        }
    }
    
    // Count the number of pairs with the same first character
    for (const auto& entry : charCounts) {
        int count = entry.second;
        if (count == 2) {
            pairCount++;
        }
    }
    
    return pairCount;
}

bool hasFiveEqualLastChars(const std::vector<std::string>& vec) {
    unordered_map<char, int> charCounts;
    
    // Count the number of strings with each unique last character
    for (const auto& str : vec) {
        if (!str.empty()) {
            char lastChar = str.back();
            charCounts[lastChar]++;
            if (charCounts[lastChar] >= 5) {
                return true;
            }
        }
    }
    
    return false;
}

int Poker_engine::pairs(Player p, vector<string> Host_hand){
    vector<string> all_cards = Collection(p, Host_hand);
    return countPairsWithSameFirstChar(all_cards);
}

bool Poker_engine::color(Player p, vector<string> Host_hand){
    vector<string> all_cards = Collection(p, Host_hand);
    return hasFiveEqualLastChars(all_cards);
}

int Poker_engine::of_kind(Player p, vector<string> Host_hand){
    int output=0;
    vector<string> all_cards = Collection(p, Host_hand);
    unordered_map<char, int> charCounts;
    // Count the number of strings that start with each character
    for (const auto& str : all_cards) {
        if (!str.empty()) {
            charCounts[str[0]]++;
        }
    }
    // Count the number of pairs with the same first character
    for (const auto& entry : charCounts) {
        int count = entry.second;
        if (count == 4) {
            output=4;
        }
        else if(count == 3) output=3;
    }
    return output;
}

void replaceChar(std::string& str, char to_replace, std::string replacement) {
    size_t pos = 0;
    while ((pos = str.find(to_replace, pos)) != std::string::npos) {
        str.replace(pos, 1, replacement);
        pos += replacement.length();
    }
}

bool hasStraightFive(const std::vector<std::string>& vec) {
    unordered_set<int> numbers;
    for (const std::string& str : vec) {
        int num = std::stoi(str.substr(0, 2));
        numbers.insert(num);
    }
    int count = 0;
    for (int i = 1; i <= 15; i++) {
        if (numbers.count(i)) {
            count++;
            if (count == 5) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}

//This func helps to transform all cards into numbers
void numeric_cards(vector<string>& all_cards){
    //Replace the special characters with correspond numbers 
    for(int i=all_cards.size()-1; i>=0; i--){
        if(all_cards[i][0]=='J'){
            replaceChar(all_cards[i], 'J', "11");
        }
        else if(all_cards[i][0]=='Q'){
            replaceChar(all_cards[i], 'Q', "12");
        }
        else if(all_cards[i][0]=='K'){
            replaceChar(all_cards[i], 'K', "13");
        }
        else if(all_cards[i][0]=='A'){
            replaceChar(all_cards[i], 'A', "14");
        }
        else continue;
    }
}

bool Poker_engine::straigth(Player p, vector<string> Host_hand){
    vector<string> all_cards = Collection(p, Host_hand);
    numeric_cards(all_cards);
    //check if we have a 5 staigth cards
    return hasStraightFive(all_cards);
}

bool Poker_engine::fullhouse(Player p, vector<string> Host_hand){
    if( of_kind(p, Host_hand)==3 && pairs(p, Host_hand)>=1) return true;
    else return false;
}

bool Poker_engine::flush(Player p, vector<string> Host_hand){
    if(color(p, Host_hand)==true && straigth(p,Host_hand)==true) return true;
    else return false;
}

int Poker_engine::handRank(Player p, vector<string> Host_hand){
    if(flush(p, Host_hand)) return 9;
    else if(of_kind(p, Host_hand)==4) return 8;
    else if (fullhouse(p,Host_hand)) return 7;
    else if(color(p, Host_hand)) return 6;
    else if(straigth(p,Host_hand)) return 5;
    else if(of_kind(p,Host_hand)==3) return 4;
    else if(pairs(p,Host_hand)==2) return 3;
    else if (pairs(p,Host_hand)==1) return 2;
    else return 1;
}

// This func only compares who has the highest card
int Poker_engine::compareHands(Player p1, Player p2){
    char max1=p1.hand[0][0]; char max2=p2.hand[0][0];
    if( (p1.hand[0][0]=='A' || p1.hand[1][0]=='A') && (p2.hand[0][0]!='A' && p2.hand[1][0]!='A') ) return 1;
    else if ( (p2.hand[0][0]=='A' || p2.hand[1][0]=='A') && (p1.hand[0][0]!='A' && p1.hand[1][0]!='A') ) return 2;
    else if ((p2.hand[0][0]=='A' || p2.hand[1][0]=='A') && (p1.hand[0][0]=='A' && p1.hand[1][0]=='A') ) return 0;
    else{
        if(p1.hand[1][0] > max1) max1=p1.hand[1][0];
        if(p2.hand[1][0] > max2) max2=p2.hand[1][0];
    }
    if(max1==max2) return 0;
    else return (max1 > max2) ? 1:2;
}

// This function returns the id of the winner (1 or 2)
int Poker_engine::compareRank(Player p1, Player p2, vector<string> Host_hand){
    int handRank_p1 = handRank(p1, Host_hand);
    int handRank_p2 = handRank(p2, Host_hand);
    if(handRank_p1 > handRank_p2) return 1;
    else if (handRank_p2 > handRank_p1) return 2;
    else{
        return compareHands(p1,p2);
    }
}

