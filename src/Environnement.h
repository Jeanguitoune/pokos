#pragma once
#include "Card.h"
#include <time.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

typedef struct hand{
	Card card1;
	Card card2;
};
class Environnement
{
	public:
	vector<Card> m_packet;
	vector<hand> m_handsDealed;
	int m_nbplayers;

	void printDeckInorder();
	void printHandsInorder();
	void initDeck();
	void melangerDeck();
	void distribuerJeux();

	Environnement(int nb_players);
	~Environnement(void);
};

