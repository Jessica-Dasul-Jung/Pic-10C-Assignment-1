
#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"

using namespace std;
class Card;
class Player {
public:
	Player(int m, int type); //Constructor
	~Player(); //Destructor

	//Accessor:
	int getLostAmount();
	int getMoney();
	bool getWant();
	double getTotal();
	int getType();

	//Mutator:
	void setWant(bool want);

	//money:
	void lostMoney(int money); //both player and dealer
	void winMoney(int money);
	void loseMoney(int money);

	//action:
	void addCard();
	string displayMyCard();

	//clean-up:
	void reset();
	void clearCard();

private:
	int m_type; //DEALER, PLAYER
	int m_money; //remaining money - applies to player
	bool m_want; //whether continue to pick cards
	double m_total; //7.5
	int m_lost; //lost aomunt - applies to dealer
	vector<Card*> m_card;
};

#endif

