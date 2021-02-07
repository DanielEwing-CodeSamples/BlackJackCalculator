#include "Card.h"

// Basic Class, no comment explanations required.

Card::Card() {
	cardName = "test";
	cardSuit = "test";
	cardValue = 0;
}

Card::Card(int value, string name, string suit) {
	cardValue = value;
	cardName = name;
	cardSuit = suit;
}

string Card::getCardName() {
	return cardName;
}

string Card::getCardSuit() {
	return cardSuit;
}

int Card::getCardValue() {
	return cardValue;
}

void Card::printCard() {
	cout << "The " << cardName << " of " << cardSuit << ". It's Card Value is " << cardValue << ".\n";
}

Card::~Card() {

}