#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Deck.h"

Deck::Deck() {
    char s;
    int r;

    for (unsigned int i = 0; i < 4; ++i) {
        if (i == 3) {
            s = 'c';
        }
        else if (i == 2) {
            s = 'd';
        }
        else if (i == 1) {
            s = 'h';
        }
        else if (i == 0) {
            s = 's';
        }
        for (unsigned int j = 13; j > 0; --j) {
            r = j;
            theDeck.push_back(Card(s, r));
        }
    }
}

//draw from back of vector
Card Deck::dealCard() {
    Card dealtCard;
    
    dealtCard = theDeck.at(theDeck.size() - 1);

    theDeck.pop_back();

    dealtCards.push_back(dealtCard);

    return dealtCard;
}

//use shuffle deck algorithm
//remove things in dealtcards by calling clear()
void Deck::shuffleDeck() {
    unsigned int deckS;

    deckS = deckSize();

    if (deckS < 52) {
        for (unsigned int i = 0; i < dealtCards.size(); ++i) {
            theDeck.push_back(dealtCards.at(i));
        }
    }

    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());

}

unsigned Deck::deckSize() const {
    return theDeck.size();
}