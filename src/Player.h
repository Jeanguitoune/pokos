#pragma once
#include "Card.h"
#include "Chipstack.h"

#include <vector>
using namespace std;

typedef struct hand{
	Card card1;
	Card card2;
};

class Player
{
public:
	string m_name;
	Chipstack m_chipstack;
	hand m_currentHand;

	Player(string name, string stack_cave);
	~Player(void);
};

