#ifndef Deck_h
#define Deck_h
#pragma once


#include "Card.h"
#include<vector>
class Deck :
	public Card{

public:
	Deck();
	Deck(int numOfDecks);
	void printDeck(); // test function
	void shuffleDeck();
	Card dealCard(); // deals a copy of the top card to the player, places the original on the bottom of the deck.
	~Deck();

private:

	vector<Card> deckOfCards;
};

#endif Deck_h