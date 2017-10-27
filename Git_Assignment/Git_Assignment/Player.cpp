
#include "Player.h"
#include "Card.h"
using namespace std;

Player::Player(int m, int type) //constructor
{
	m_money = m;
	m_type = type;
	m_total = 0;
}

Player::~Player() //destructor
{
	clearCard();
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

void Player::addCard()
{
	Card* playercard = new Card(); 
	m_card.push_back(playercard);

	cout << "New card: " << playercard->get_spanish_rank() << " "
		<< playercard->get_spanish_suit() << endl;

	m_total += playercard->get_rank();
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

string Player::displayMyCard()
{
	string display;
	string id;

	if (m_type == TYPE_DEALER)
	{
		id = "Dealer's";
	}
	else if (m_type == TYPE_PLAYER)
	{
		id = "Your";
	}

	display += id + " cards: " + '\n';

	int size = m_card.size();
	for (int i = 0; i < size; i++)
	{
		display += "    "  + m_card[i]->get_spanish_suit() + "  "
			+ m_card[i]->get_english_suit() + '\n';
	}

	display += '\n' + id + " total is ";
	display += m_total + '\n';
	return display;
}

void Player::winMoney(int money)
{
	m_money += money;
}

void Player::reset()
{
	m_total = 0;
}

void Player::loseMoney(int money)
{
	if (m_type == TYPE_PLAYER)
		m_money -= money;
	else
		m_lost += money;
}

void Player::setWant(bool want)
{
	m_want = want;
}


////////////////////////////////////////////////////////////
//ACCESSORS:	

bool Player::getWant()
{
	return m_want;
}

double Player::getTotal()
{
	return m_total;
}

int Player::getLostAmount() //applies to Dealer
{
	return m_lost;
}

int Player::getMoney() //applies to Player
{
	return m_money;
}

int Player::getType()
{
	return m_type;
}
