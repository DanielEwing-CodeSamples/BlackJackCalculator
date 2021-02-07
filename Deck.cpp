#include "Deck.h"
#include<time.h>
#include<iostream>
#include<algorithm>


Deck::Deck() {
	for (int i = 0; i < 4; i++) {
		string tempSuit;
		if (i == 0) {
			tempSuit = "Spades";
		}
		else if (i == 1) {
			tempSuit = "Diamonds";
		}
		else if (i == 2) {
			tempSuit = "Clubs";
		}
		else if (i == 3) {
			tempSuit = "Hearts";
		}
		deckOfCards.push_back(Card(2, "Two", tempSuit));
		deckOfCards.push_back(Card(3, "Three", tempSuit));
		deckOfCards.push_back(Card(4, "Four", tempSuit));
		deckOfCards.push_back(Card(5, "Five", tempSuit));
		deckOfCards.push_back(Card(6, "Six", tempSuit));
		deckOfCards.push_back(Card(7, "Seven", tempSuit));
		deckOfCards.push_back(Card(8, "Eight", tempSuit));
		deckOfCards.push_back(Card(9, "Nine", tempSuit));
		deckOfCards.push_back(Card(10, "Ten", tempSuit));
		deckOfCards.push_back(Card(10, "Jack", tempSuit));
		deckOfCards.push_back(Card(10, "Queen", tempSuit));
		deckOfCards.push_back(Card(10, "King", tempSuit));
		deckOfCards.push_back(Card(11, "Ace", tempSuit));

	}
}

Deck::Deck(int numOfDecks) {
	for (int x = 0; x < numOfDecks; x++){
		for (int i = 0; i < 4; i++) {
			string tempSuit;
			if (i == 0) {
				tempSuit = "Spades";
			}
			else if (i == 1) {
				tempSuit = "Diamonds";
			}
			else if (i == 2) {
				tempSuit = "Clubs";
			}
			else if (i == 3) {
				tempSuit = "Hearts";
			}
			deckOfCards.push_back(Card(2, "Two", tempSuit));
			deckOfCards.push_back(Card(3, "Three", tempSuit));
			deckOfCards.push_back(Card(4, "Four", tempSuit));
			deckOfCards.push_back(Card(5, "Five", tempSuit));
			deckOfCards.push_back(Card(6, "Six", tempSuit));
			deckOfCards.push_back(Card(7, "Seven", tempSuit));
			deckOfCards.push_back(Card(8, "Eight", tempSuit));
			deckOfCards.push_back(Card(9, "Nine", tempSuit));
			deckOfCards.push_back(Card(10, "Ten", tempSuit));
			deckOfCards.push_back(Card(10, "Jack", tempSuit));
			deckOfCards.push_back(Card(10, "Queen", tempSuit));
			deckOfCards.push_back(Card(10, "King", tempSuit));
			deckOfCards.push_back(Card(11, "Ace", tempSuit));
		}
	}
}

void Deck::printDeck() {
	for (vector<Card>::iterator iter = deckOfCards.begin(); iter != deckOfCards.end(); iter++) {
		iter->printCard();
	}
}


void Deck::shuffleDeck() {
	random_shuffle(deckOfCards.begin(), deckOfCards.end());
}

Card Deck::dealCard() {									// eliminates need for discard function. Even with 6 Players and a Dealer, 52 cards
	Card tempCard = deckOfCards.front();				// is enough to ensure everyone can go bust, or lose the game by exceeding a score of 21
	deckOfCards.push_back(deckOfCards.front());			
	deckOfCards.erase(deckOfCards.begin());
	return tempCard;
}

Deck::~Deck() {

}

