#ifndef Player_h
#define Player_h

#pragma once


#include"Card.h"
#include<vector>

class Player
{
private:
	int totalMainHandValue;
	vector<Card> playerHand;


public:
	Player();
	Player(Player* other);
	Player(Card _tempCard);
	void recieveDealtCard(Card _tempCard);

	void discardHand();
	void printHand(); 
	int getTotalMainHandValue();
	int getDealerShowCardValue(); // the dealer only shows one of their cards. Depending on which card they show, the same starting hand might be played differently. 

	~Player();
};

#endif Player_h