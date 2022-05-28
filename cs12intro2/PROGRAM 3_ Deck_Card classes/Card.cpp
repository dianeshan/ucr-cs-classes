#include <iostream>
using namespace std;

#include "Card.h"

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char s, int r) {
    suit = tolower(s);
    rank = r;

    if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') {
        suit = 'c';
    }

    if (rank < 1 || rank > 13) {
        rank = 2;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &out, const Card &cool) {
    string newrank;
    string newsuit;

    if (cool.rank == 1) {
        newrank = "Ace";
    }
    else if (cool.rank == 11) {
        newrank = "Jack";
    }
    else if (cool.rank == 12) {
        newrank = "Queen";
    }
    else if (cool.rank == 13) {
        newrank = "King";
    }
    else {
        newrank = to_string(cool.rank);
    }
    if (cool.suit == 'c') {
        newsuit = "Clubs";
    }
    else if (cool.suit == 'd') {
        newsuit = "Diamonds";
    }
    else if (cool.suit == 'h') {
        newsuit = "Hearts";
    }
    else if (cool.suit == 's') {
        newsuit = "Spades";
    }

    out << newrank << " of " << newsuit;
    return out;
}

