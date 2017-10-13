
#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"

class Player {
public:
	// Constructor. 
	//    Assigns initial amount of money
	Player(int m, int type);
	void draw();

	int getLostAmount();


	// You decide what functions you'll need...

private:
	int m_type;
	int m_money;
	bool m_want;
	double m_total;
	bool m_bust;
	int m_lost;
};

#endif

