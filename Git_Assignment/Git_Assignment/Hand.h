
#ifndef HAND_H
#define HAND_H

#include "globals.h"
using namespace std;

class Card;
class Hand {
public:
	// A vector of Cards
	Hand();
	void addCard(Card* c); //fix??
	void discard();

	double getTotal();
	void addTotal(double total);
	// You decide what functions you'll need...

private:
	vector<Card*> m_card; //change: change into class later?
	double m_total;
	// You decide what fields you'll need...
};

#endif