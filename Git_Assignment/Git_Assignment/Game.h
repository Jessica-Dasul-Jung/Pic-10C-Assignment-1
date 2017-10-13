
#ifndef GAME_H
#define GAME_H

class Player; //pointer

class Game
{
public:
	Game();
	void endGame();

private:
	int m_gamecount;
	Player* m_player;
	Player* m_dealer;

};
#endif

