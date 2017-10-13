
#include "Card.h"
#include "globals.h"
#include "Hand.h"
#include "Player.h"



void playTurn()
{

}

void playGame(int gamecount)
{

}


void endGame()
{
	//clear screen
	
}


int main()
{
	int gamecount = 1; //count games played
	Player dealer(DEALER_INITIAL_MONEY, TYPE_DEALER);
	Player player(PLAYER_INITIAL_MONEY, TYPE_PLAYER);

	while (player.getMoney() != 0 && dealer.getLostAmount() < 900) //ending condition
	{
		int bet = 0;
		cout << "You have $" << player.getMoney() << "." << endl;
		cout << "Please enter bet amount." << endl;
		
		for (;;) //infinite loop until valid input
		{
			cin >> bet;
			if (bet > 0 && bet <= player.getMoney()) //not negative and less/equal to player's money
			{
				cout << "Bet amount: " << bet << endl;
				break;
			}
			else cout << "Please enter valid bet amount" << endl;
		}

			Card* playercard = new Card(); //dynamically allocate
			player.getHand()->addCard(playercard);

			cout << "New card: " << playercard->get_spanish_rank() << " "
				<< playercard->get_spanish_suit() << endl;

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



void game_log()
{
	
}
