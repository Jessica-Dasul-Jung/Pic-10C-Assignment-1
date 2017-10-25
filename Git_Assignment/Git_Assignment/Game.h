
#ifndef GAME_H
#define GAME_H

class Player; //pointer

class Game
{
public:
	Game(); //constructor
	~Game(); //destructor
	void endGame();
	void playGame();
	void askForBet();
	void askForAnotherCard();
	void determineWinner();
	string displayCard(Player* m);
	void reset();
	void game_log();
private:
	int m_gamecount;
	Player* m_player;
	Player* m_dealer;
	int m_bet;
	bool m_playerwins;

};
#endif

