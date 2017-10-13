
#include "Player.h"


Player::Player(int m, int type)
{
	m_money = m;
	m_type = type;
	m_bust = false;
}

void Player::draw()
{
	m_turn++;
	while (m_want && m_total < 7.5) //while player wants card
	{

	}
}

int Player::getLostAmount() //applies to Dealer
{
	return m_lost;
}

int Player::getMoney() //applies to Player
{
	return m_money;
}

void Player::lostMoney(int money) //both player and dealer
{
	if (m_type == TYPE_PLAYER)
	{
		m_money -= money;
	}
	else //DEALER
	{
		m_lost += money;
	}
}

int Player::bust()
{
	if (m_bust)
		return m_type;
	else return 0;
}

Hand* Player::getHand()
{
	return m_hand;
}