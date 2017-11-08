# Pic-10C-Assignment-1

Source Files:
-----------------------------------------------------------------------------
  Card.h
  Card.cpp: implement the Card class
  
  Game.h
  Game.cpp: implement the Game class
  
  globals.h: include all constants and c++ libraries

  Player.h
  Player.cpp:  implement the Player class.
  hw7.cpp: implement game

while these source files are in the solution, they perform no functions.
  Hand.h
  Hand.cpp
  siete_y_medio.cpp



Description of Classes:
-----------------------------------------------------------------------------

Game class:
  implement game interface.
  
  Implement each round until the game is over.
    game_over: Dealer loses $900 or Player loses all money.
  Ask player for bet and allows him/her to choose whether to continue to pick cards.
  Implement default play for dealer.
  Determine winner after each round and store round's information in log (private member).
  Reset respective variables after each round.
  
  game_log(): keeps game log after each game documenting information of each round.
    available after game is over.
  
  store two pointers to Player class: m_dealer and m_player.
  
  
-----------------------------------------------------------------------------

Player class:
  represents Player and Dealer.
  player and dealer are distinguished by their type (id) (private member: m_type).
  player and dealer's money are recorded here.
    Player: m_money: remaining money (when it reaches $0, game ends)
    Dealer: m_lost: lost money (when it reaches $900, game ends)
  
  
  store a vector of pointers to Card class.
    picked cards are stored here and cleared after each round.
    they are also recorded to be stored in game log

Card class and Hand class are implemented in provided codes.



Different test cases:
-----------------------------------------------------------------------------
For bet amount:
  need valid bet input
  more than 0, less than or equal to player's money
  integer input
  implemented a function that converts string to integer (convertString member function)
  test case: 
    100, 122, 10, 10000, dfd,  ,*
  
Asking whether player wants another card:
  need to be: 'n', 'N', 'y', or 'Y'
  test case: 
    20, n, y, N, Y, 3, d
