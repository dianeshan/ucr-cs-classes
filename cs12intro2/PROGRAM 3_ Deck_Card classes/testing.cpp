#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Deck(vector<Card> ) {
//     string suit;
//     int cardValueNum;

//     for (unsigned int i = 0; i < 4; ++i) {
//         if (i == 0) {
//             suit = " of Clubs";
//         }
//         else if (i == 1) {
//             suit = " of Diamonds";
//         }
//         else if (i == 2) {
//             suit = " of Hearts";
//         }
//         else if (i == 3) {
//             suit = " of Spades";
//         }
//         for (unsigned int j = 0; j < 13; ++j) {
//             cardValueNum = j + 1;
//             if (cardValueNum == 1) {
//                 theDeck.push_back("Ace" + suit);
//             }
//             else if (cardValueNum > 1 && cardValueNum < 11) {
//                 theDeck.push_back(cardValueNum + suit);
//             }
//             else {
//                 if (cardValueNum == 11) {
//                     theDeck.push_back("Jack" + suit);
//                 }
//                 else if (cardValueNum == 12) {
//                     theDeck.push_back("Queen" + suit);
//                 }
//                 else if (cardValueNum == 11) {
//                     theDeck.push_back("King" + suit);
//                 }
//             }
//         }
//     }
// }

//     if (suit == 'c') {
//         // suitName = "Clubs";
//     }
//     else if (suit == 'd') {
//         // suitName = "Diamonds";
//     }
//     else if (suit == 'h') {
//         // suitName = "Hearts";
//     }
//     else if (suit == 's') {
//         // suitName = "Spades";
//     }

void shuffleDeck() {
    for (unsigned int i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }

    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());

}

int main() {

    

    return 0;
}