
#include "Hand.h"
#include "Card.h" //fix later

Hand::Hand()
{

}

void Hand::addCard(Card* c)
{
	m_card.push_back(c);
}

void Hand::discard()
{
	m_card.empty(); //check if it works
}

double Hand::getTotal()
{
	return m_total;
}

void Hand::addTotal(double total)
{
	m_total += total;
}
