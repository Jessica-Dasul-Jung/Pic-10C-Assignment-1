
#ifndef GAME_H
#define GAME_H

#include "globals.h"
using namespace std;

class Player; //pointer

class Game
{
public:
	Game(); //constructor
	~Game(); //destructor
	void playGame();
	void askForBet();
	void askForAnotherCard();
	void determineWinner();
	void reset();
	void game_log();
	int checkValidNum(string s);
	int convertString(string s);
	void storeLog();
private:
	int m_gamecount;
	Player* m_player;
	Player* m_dealer;
	int m_bet;
	string m_log;
};
#endif

