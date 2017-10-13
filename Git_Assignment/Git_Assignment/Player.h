
#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"

class Hand;
class Card;
class Player {
public:
	// Constructor. 
	Player(int m, int type);
	void draw();

	//Accessor:
	int getLostAmount();
	int getMoney();
	Hand* getHand();
	bool getWant();
	double getTotal();

	//Mutator:
	void lostMoney(int money); //both player and dealer
	void setWant(bool want);

	//bust:
	int bust();

	void addCard();
	void clearCard();

private:
	int m_type; //DEALER, PLAYER
	int m_money; //remaining money - applies to player
	bool m_want; //whether continue to pick cards
	double m_total; //7.5
	bool m_bust;
	int m_lost; //lost aomunt - applies to dealer
	int m_turn;
	Hand* m_hand;
	vector<Card*> m_card;
};

#endif

