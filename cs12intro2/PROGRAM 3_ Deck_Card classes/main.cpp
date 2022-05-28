#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
	srand(2222);
	string yOrN;
	string filename;
	int numOfCards;
	double numOfDeals;
	ofstream outFS;
	int monteCarlo;
	int i = 0;
	int j = 0;
	double counter = 0.0;
	vector<Card> hand;

	cout << "Do you want to output all hands to a file? (Yes/No) ";
	cin >> yOrN;
	cout << endl;

	//if they want to output to file have input of file name
	if (yOrN == "Yes") {
		cout << "Enter name of output file: ";
		cin >> filename;
		cout << endl;

		outFS.open(filename);
		if (!outFS.is_open()) {
			cout << "Could not open file " << filename << endl;
			return 1;
		}
		cout << "Enter number of cards per hand: ";
		cin >> numOfCards;
		cout << endl;

		cout << "Enter number of deals (simulations): ";
		cin >> numOfDeals;
		cout << endl;

		Deck diane;
		while (i < numOfDeals) {

			diane.shuffleDeck();
			for (j = 0; j < numOfCards; ++j) {
				hand.push_back(diane.dealCard());
			}
			if (hasPair(hand)) {
				++counter;
				outFS << "Found Pair!! ";
			}
			for (int k = 0; k < numOfCards; ++k) {
				if (k < numOfCards - 1) {
					outFS << hand.at(k) << ", ";
				}
				else {
					outFS << hand.at(k) << endl;
				}
			}
			hand.clear();
			++i;
		} 

		monteCarlo = (counter / numOfDeals) * 100;

		cout << "Chances of receiving a pair in a hand of " << numOfCards << " cards is: " << monteCarlo << "%" << endl;

		outFS.close();
	}
	else {
		cout << "Enter number of cards per hand: ";
		cin >> numOfCards;
		cout << endl;

		cout << "Enter number of deals (simulations): ";
		cin >> numOfDeals;
		cout << endl;

		Deck shan;
		while (i < numOfDeals) {

			shan.shuffleDeck();
			for (j = 0; j < numOfCards; ++j) {
				hand.push_back(shan.dealCard());
			}
			if (hasPair(hand)) {
				++counter;
			}
			hand.clear();
			++i;
		} 

		monteCarlo = (counter / numOfDeals) * 100;

		cout << "Chances of receiving a pair in a hand of " << numOfCards << " cards is: " << monteCarlo << "%" << endl;
	}

	return 0;
}

bool hasPair(const vector<Card> &hand) {

	for (unsigned int i = 0; i < hand.size(); ++i) {
		for (unsigned int j = i + 1; j < hand.size(); ++j) {
			if (hand.at(i).getRank() == hand.at(j).getRank()) {
				return true;
			}
		}
	}
	return false;
}

ostream & operator<<(ostream &o, const vector<Card> &hand) {
	string newrank;
	string newsuit;

	for (unsigned int i = 0; i < hand.size(); ++i) {
		if (hand.at(i).getRank() == 1) {
        	newrank = "Ace";
    	}
		else if (hand.at(i).getRank() == 11) {
			newrank = "Jack";
		}
		else if (hand.at(i).getRank() == 12) {
			newrank = "Queen";
		}
		else if (hand.at(i).getRank() == 13) {
			newrank = "King";
		}
		else {
			newrank = to_string(hand.at(i).getRank());
		}

		if (hand.at(i).getSuit() == 'c') {
			newsuit = "Clubs";
		}
		else if (hand.at(i).getSuit() == 'd') {
			newsuit = "Diamonds";
		}
		else if (hand.at(i).getSuit() == 'h') {
			newsuit = "Hearts";
		}
		else if (hand.at(i).getSuit() == 's') {
			newsuit = "Spades";
		}

		o << newrank << " of " << newsuit;
	}


	return o;
}