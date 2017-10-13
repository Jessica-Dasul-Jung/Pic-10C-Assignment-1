
#include "Player.h"
#include "Card.h"
#include "globals.h"
using namespace std;

Player::Player(int m, int type)
{
	m_money = m;
	m_type = type;
	m_bust = false;
	m_total = 0;
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

void Player::addCard()
{
	Card* playercard = new Card(); 
	m_card.push_back(playercard);

	cout << "New card: " << playercard->get_spanish_rank() << " "
		<< playercard->get_spanish_suit() << endl;

	m_total += playercard->get_rank();

	if (m_total > 7.5)
		bust(); //fix
}

void Player::clearCard()
{
	int size = m_card.size();
	for (int i = 0; i < size; i++)
	{
		delete m_card[i];
	}
	m_card.clear();
}

void Player::displayCard()
{

}