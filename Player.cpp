#include "Player.h"

Player::Player() {
	totalMainHandValue = 0;
}
Player::Player(Card _tempCard) {
	totalMainHandValue = 0;
	recieveDealtCard(_tempCard);
}
Player::Player(Player* other) {
	this->playerHand = other->playerHand;
	this->totalMainHandValue = other->totalMainHandValue;
}

void Player::recieveDealtCard(Card _tempCard) {
	totalMainHandValue += _tempCard.getCardValue();
	playerHand.push_back(_tempCard);
	if (totalMainHandValue > 21) {
		for (vector<Card>::iterator iter = playerHand.begin(); iter != playerHand.end(); iter++) {
			if (iter->getCardValue() == 11 && totalMainHandValue > 21) { // youve busted, if there is an ace in your hand you can reduce your hand value by 10. 
				totalMainHandValue -= 10; 
			}
		}
	}
}


void Player::discardHand() {
	if (playerHand.empty() != true) {
		playerHand.erase(playerHand.begin(), playerHand.end());
		totalMainHandValue = 0;
	}

}
void Player::printHand() {
	for (vector<Card>::iterator iter = playerHand.begin(); iter != playerHand.end(); iter++) {
		iter->printCard();
	}
	//for (int i = 0; i < cardSuitList.size(); i++) {
	//	cout << "Card " << i + 1 << ": The " << cardNameList.front() << " of " << cardSuitList.front() << ".\n";
	//	cardNameList.push_back(cardNameList.front());
	//	cardNameList.pop_front();
	//	cardSuitList.push_back(cardSuitList.front());
	//	cardSuitList.pop_front();
	//}
}
int Player::getTotalMainHandValue() {
	return totalMainHandValue;
}
int Player::getDealerShowCardValue() {
	int tempCardValue = playerHand.front().getCardValue();
	return tempCardValue;
}

Player::~Player() {
}