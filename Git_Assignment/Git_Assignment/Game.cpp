
#include "globals.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"
using namespace std;

Game::Game() //initialize player and dealer
{
	int gamecount = 1; //count games played
	m_player = new Player (DEALER_INITIAL_MONEY, TYPE_DEALER);
	m_dealer = new Player (PLAYER_INITIAL_MONEY, TYPE_PLAYER);
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

void Game::playGame()
{
	while (m_player->getMoney() != 0 && m_dealer->getLostAmount() < 900) //ending condition
	{
		askForBet();
		m_player->addCard();


		char want;
		while (player.getHand()->getTotal() <= 7.5 && dealer.getHand()->getTotal() <= 7.5)
		{
			cout << "Your total: " << player.getHand()->getTotal() << endl;
			cout << "Do you want another card? (Y/N)" << endl;
			for (;;)
			{
				cin >> want;
				if (want == 'Y' || want == 'y')
				{
					player.setWant(true);
					break;
				}
				else if (want == 'N' || want == 'n')
				{
					player.setWant(false);
					break;
				}
			} //end of for loop


		}

		//busting outcome: (out of while loop)
		double playertotal = player.getHand()->getTotal();
		double dealertotal = dealer.getHand()->getTotal();

		if (playertotal > 7.5 && dealertotal > 7.5) //both bust
		{

		}
		else if (playertotal > 7.5)
		{
		}
		else if (dealertotal > 7.5)
		{

		}
	}





}


}
