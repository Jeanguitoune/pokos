#pragma once
#include "Player.h"


#include "time.h"
#include <map>
using namespace std;

class Table
{
	public:
	vector<Card> m_packet;
	vector<Player> m_Players;
	
	vector<Card> m_currentMiddleCards;

	int m_nbplayers;

	void printDeckInorder();
	void printHandsByPlayer();
	void initDeck();
	void melangerDeck();
	void distribuerJeux();
	void tirerFlop();
	void printMiddleCards();

	Table(int nb_players);
	~Table(void);
};

