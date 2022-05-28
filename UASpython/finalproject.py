import random


class Card:
    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit
        self.value = self.get_value()

    def get_value(self):
        if self.rank == "Ace" or self.rank == "A":
            val = 11
        # wasn't really clear on whether or not it was supposed to be just a letter or the word typed out
        # because in the deck class, the global variable has words spelled out but in the card one, it's a single letter
        elif self.rank == "Jack" or self.rank == "Queen" or self.rank == 'King' or self.rank == 'J' or self.rank == 'Q' or self.rank == 'K':
            val = 10
        else:
            val = int(self.rank)

        return val


ranks = ["Ace", "2", "3", "4", "5", "6", "7",
         "8", "9", "10", "Jack", "Queen", "King"]
suits = ["Clubs", "Diamonds", "Hearts", "Spades"]


class Deck:
    def __init__(self):
        self.cards = []
        for s in suits:
            for r in ranks:
                new_card = Card(r, s)
                self.cards.append(new_card)

    def shuffle(self):
        random.shuffle(self.cards)

    def deal_card(self):
        dealt_card = self.cards[len(self.cards) - 1]
        self.cards.pop(len(self.cards) - 1)
        return dealt_card


class Hand:
    def __init__(self):
        self.cards = []

    def add_card(self, card):
        self.cards.append(card)

    def count(self):
        return len(self.cards)

    def points(self):
        total = 0
        hasAce = False
        for c in self.cards:
            total += c.value
            # challenge part!
            if (c.rank == "Ace" or c.rank == "A"):
                hasAce = True
            if hasAce and total > 21:
                total -= 10
                hasAce = False

        return total


if __name__ == "__main__":
    deck = Deck()
    deck.shuffle()

    print("HAND")
    hand = Hand()
    for i in range(3):
        hand.add_card(deck.deal_card())

    for i in range(hand.count()):
        card = hand.cards[i]
        print(card.rank + " of " + card.suit)

    print("Hand points:", hand.points())

    # added some feedback to user :)
    if hand.points() > 21:
        print("Bust! You lose :(")
    elif hand.points() == 21:
        print("BLACKJACK!")
    else:
        print("meh")
