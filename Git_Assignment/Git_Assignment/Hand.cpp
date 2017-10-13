
#include "Hand.h"
#include "Card.h" //fix later

Hand::Hand()
{

}

void Hand::addCard(Card* c)
{
	m_card.push_back(c);
}
