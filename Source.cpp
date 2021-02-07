#include"Deck.h"
#include"Player.h"
#include<chrono>

using namespace std;

int main() {
	auto startTotal = std::chrono::high_resolution_clock::now();

	const int numberOfGames = 10000;
	const int twentyOne = 21; const int sevenTeen = 17; const int sixTeen = 16; const int fifTeen = 15; // blackjack and hold values. 

	void playGames(const int blackJack, const int holdValue, const int dealHold, const int gamesToPlay);

	
	playGames(twentyOne, sevenTeen, sevenTeen, numberOfGames);
	playGames(twentyOne, sevenTeen, sixTeen, numberOfGames);
	playGames(twentyOne, sevenTeen, fifTeen, numberOfGames);
	playGames(twentyOne, sixTeen, sevenTeen, numberOfGames);
	playGames(twentyOne, sixTeen, sixTeen, numberOfGames);
	playGames(twentyOne, sixTeen, fifTeen, numberOfGames);
	playGames(twentyOne, fifTeen, sevenTeen, numberOfGames);
	playGames(twentyOne, fifTeen, sixTeen, numberOfGames);
	playGames(twentyOne, fifTeen, fifTeen, numberOfGames);

	auto finishTotal = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTimeTotal = finishTotal - startTotal;
	std::cout << "Total Run Time: " << elapsedTimeTotal.count() << " seconds.\n";
	std::system("pause");
	return 0;
}


void playGames(const int blackJack, const int holdValue, const int dealHold, const int gamesToPlay) {
	auto start = std::chrono::high_resolution_clock::now();
	int gamesIter= 0;
	Deck myDeck;
	Player Player1;
	Player Dealer;
	double playerWins = 0;
	while (gamesIter < gamesToPlay) {
		if (gamesIter % 5 == 0) {
			myDeck.shuffleDeck();
		}
		Player1.discardHand();
		Dealer.discardHand();
		Card tempCard = myDeck.dealCard();
		Player1.recieveDealtCard(tempCard);
		tempCard = myDeck.dealCard();
		Dealer.recieveDealtCard(tempCard);
		tempCard = myDeck.dealCard();
		Player1.recieveDealtCard(tempCard);
		tempCard = myDeck.dealCard();
		Dealer.recieveDealtCard(tempCard);
		if (Player1.getTotalMainHandValue() < holdValue) {
			while (Player1.getTotalMainHandValue() < holdValue) {
				tempCard = myDeck.dealCard();
				Player1.recieveDealtCard(tempCard);
			}
		}
		if (Dealer.getTotalMainHandValue() < dealHold) {  //typical rules state dealer will not draw cards with a hand value of 17 or more. 
			while (Dealer.getTotalMainHandValue() < dealHold) {
				tempCard = myDeck.dealCard();
				Dealer.recieveDealtCard(tempCard);
			}
		}
		if (Dealer.getTotalMainHandValue() > blackJack && Player1.getTotalMainHandValue() <= blackJack) {
			playerWins += 1;
		}
		else if (Player1.getTotalMainHandValue() > Dealer.getTotalMainHandValue() && Player1.getTotalMainHandValue() <= blackJack) {
			playerWins += 1;
		}
		else if (Player1.getTotalMainHandValue() == Dealer.getTotalMainHandValue()) {
			playerWins += .5;
		}
		gamesIter++;
	}
	cout << "The hold on " << holdValue << " or higher strategy while the dealer holds on " << dealHold << " has won you " << playerWins << " out of " << gamesToPlay << ". Win percentage = " << (playerWins * 100 / gamesToPlay) << "%.\n";
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTime = finish - start;
	std::cout << "Total run time for this strategy: " << elapsedTime.count() << " seconds.\n";
	std::cout << "Run time per hand played: " << (elapsedTime.count() / gamesToPlay) * 1000 << " milliseconds.\n";
	std::system("pause");
	std::cout << "\n\n\n";
}