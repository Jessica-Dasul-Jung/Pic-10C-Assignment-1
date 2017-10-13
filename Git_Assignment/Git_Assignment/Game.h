
#ifndef GAME_H
#define GAME_H

class Player; //pointer

class Game
{
public:
	Game();
	void endGame();
	void playGame();
	void askForBet();
	void askForAnotherCard();
	void determineWinner();
	void displayCard(Player* m);
private:
	int m_gamecount;
	Player* m_player;
	Player* m_dealer;
	int m_bet;
	bool m_playerwins;

};
#endif

