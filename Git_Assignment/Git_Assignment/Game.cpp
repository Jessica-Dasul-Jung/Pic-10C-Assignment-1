
#include "Game.h"
#include "Player.h"
using namespace std;

Game::Game() //initialize player and dealer
{
	//
	m_gamecount = 1; //count games played
	m_player = new Player (DEALER_INITIAL_MONEY, TYPE_PLAYER);
	m_dealer = new Player (PLAYER_INITIAL_MONEY, TYPE_DEALER);
}

Game::~Game()
{
	delete m_player;
	delete m_dealer;
}

int Game::convertString(string s)
{
	int size = s.size();
	int num = 0;
	int count = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (!isdigit(s[i]))
			return 0;
		if (s[i] != '0')
		{
			int d = s[i] - '0';
			num += pow(10, count)*d;
		}
		count++;
	}
	return num;
}


int Game::checkValidNum(string s) //return 0 for invalid input
{
	//not negative and less/equal to player's money, also check for valid number

	int num = convertString(s);

	if (num == 0)
		return 0;
	if (num > 0 && num <= m_player->getMoney())
	{
		return num;
	}
	else return 0;
}

void Game::askForBet()
{
	cout << "You have $" << m_player->getMoney() << "." << endl;
	cout << "Please enter bet amount." << endl;

	for (;;) //infinite loop until valid input
	{
		string betstr;
		cin >> betstr;
		cin.ignore(10000, '\n');
		int num = checkValidNum(betstr); //return num, 0 if invalid
		if (num != 0)
		{
			m_bet = num;
			return;
		}
		cout << "Please enter valid bet amount" << endl;
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

	//outcome 3: house advantage: both bust
	if (pt > 7.5 && dt > 7.5) 
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
		return;
	}
	//outcome 2:
	else if ((dt < 7.5 && pt > 7.5) || (ddif < pdif)) //player busts or dealer comes closer
	{
		cout << "Dealer wins!" << endl;
		m_player->loseMoney(m_bet);
		return;
	}
	//outcome 4: tie
	else if (pt == dt && pt < 7.5 && dt < 7.5) //no bust, same total
	{
		cout << "Tie!" << endl;
		return;
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
		storeLog();
		m_gamecount++;
		reset();
	}
	if (m_dealer->getLostAmount() >= 900)
		cout << "Dealer lost more than $900. Game ends." << endl;
	else
		cout << "Player has no money left" << endl;
	game_log(); //store in gamelog
}

void Game::game_log() //opens at end of game (player no money, or dealer lost $900)
{
	ofstream gamelog;
	gamelog.open("game_log.txt");
	gamelog << m_log;
	gamelog.close();
}

void Game::storeLog()
{
	string log = "";
	log += '\n';
	log += "------------------------------------------";
	log += '\n';
	log += "Game number: ";
	log += to_string(m_gamecount);
	log += "       Money left: $";
	log += to_string (m_player->getMoney());
	log += '\n';
	log += m_player->displayMyCard();
	log += '\n';
	log += m_dealer->displayMyCard(); //redundant
	m_log += log;
}

