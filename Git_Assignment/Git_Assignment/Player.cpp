
#include "Player.h"

/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m, int type)
{
	m_money = m;
	m_type = type;
	m_bust = false;
}

void Player::draw()
{
	while (m_want && m_total < 7.5) //while player wants card
	{

	}
}

int Player::getLostAmount() //applies to Dealer
{
	return m_lost;
}