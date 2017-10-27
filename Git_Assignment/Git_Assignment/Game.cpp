
#include "Game.h"
#include "Player.h"
using namespace std;

Game::Game() //initialize player and dealer
{
	m_gamecount = 1; //count games played
	m_player = new Player (DEALER_INITIAL_MONEY, TYPE_DEALER);
	m_dealer = new Player (PLAYER_INITIAL_MONEY, TYPE_PLAYER);
}

Game::~Game()
{
	delete m_player;
	delete m_dealer;
}

void Game::askForBet()
{
	cout << "You have $" << m_player->getMoney() << "." << endl;
	cout << "Please enter bet amount." << endl;

	int bet;
	for (;;) //infinite loop until valid input
	{
		cin >> bet;
		if (bet > 0 && bet <= m_player->getMoney()) //not negative and less/equal to player's money
		{
			cout << "Bet amount: " << bet << endl;
			m_bet = bet;
			return;
		}
		else cout << "Please enter valid bet amount" << endl;
	}
}

void Game::askForAnotherCard()
{
	char want;
	while (m_player->getTotal() <= 7.5 && m_dealer->getTotal() <= 7.5) //second part redundant?
	{
		cout << "Your total: " << m_player->getTotal() << endl;
		cout << "Do you want another card? (Y/N)" << endl;

		for (;;) //infinite loop until valid input
		{
			cin >> want;
			if (want == 'Y' || want == 'y')
			{
				m_player->setWant(true);
				return;
			}
			else if (want == 'N' || want == 'n')
			{
				m_player->setWant(false);
				return;
			}
			else cout << "Please enter valid input." << endl;
		} //end of for loop
	}
}

void Game::reset() 
{
	m_player->clearCard();
	m_dealer->clearCard();

	m_player->reset();
	m_dealer->reset();
}

void Game::determineWinner() //for busting outcome
{
	double pt = m_player->getTotal();
	double dt = m_dealer->getTotal();

	double pdif = 7.5 - pt;
	double ddif = 7.5 - dt;

	cout << "Your total: " << pt << endl;
	cout << "Dealer's total: " << dt << endl;

	//outcome 3: house advantage
	if (pt > 7.5 && dt > 7.5) //both bust
	{
		cout << "Dealer wins! - House Advantage" << endl;
		m_player->loseMoney(m_bet);
		return;
	}
	//outcome 1:
	else if ((pt < 7.5 && dt > 7.5) || (pdif < ddif)) //dealer busts or player comes closer
	{
		cout << "Player wins!" << endl;
		m_player->winMoney(m_bet);
		m_dealer->loseMoney(m_bet);
	}
	//outcome 2:
	else if ((dt < 7.5 && pt > 7.5) || (ddif < pdif)) //player busts or dealer comes closer
	{
		cout << "Dealer wins!" << endl;
		m_player->loseMoney(m_bet);
		//more specs
	}

	//outcome 4: tie
	else if (pt == dt && pt < 7.5 && dt < 7.5) //no bust, same total
	{
		cout << "Tie!" << endl;
		//tie
	}
}

void Game::playGame()
{
	while (m_player->getMoney() != 0 && m_dealer->getLostAmount() < 900) //ending condition
 	{
		cout << "Game number: " << m_gamecount << endl;
		cout << "Money left: " << m_player->getMoney() << endl;
		cout << "Dealer lost " << m_dealer->getLostAmount() << endl;

		askForBet();
		//player's turn:
		do //add card, ask for card
		{
			m_player->addCard();
			askForAnotherCard();
		} while (m_player->getWant() && m_player->getTotal() < 7.5);

		//dealer's turn:
		cout << "Dealer's turn: " << endl;
		while (m_dealer->getTotal() < 7.5)
		{
			m_dealer->addCard();
		}

		determineWinner(); //done one round
		cout << "----------------------------------------------------------------" << endl;
		m_gamecount++;
		reset();
	}
	if (m_dealer->getLostAmount() >= 900)
		cout << "Dealer lost more than $900. Game ends." << endl;
	else
		cout << "Player has no money left" << endl;
}

void Game::game_log()
{
	string log;
	log += "------------------------------------------\n";
	log += "Game number: " + m_gamecount;
	log += "       Money left: $" + m_player->getMoney() + '\n';

	log += m_player->displayMyCard();
	log += m_dealer->displayMyCard(); //redundant

	ofstream gamelog;

	gamelog.open("game_log.txt");
	gamelog << log;
	gamelog.close();
}