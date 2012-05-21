#pragma once
#include <stdio.h>
#include <stdlib.h>


enum colorTyp{
	pique = 1,
	coeur = 2,
	carreau = 3,
	trefle = 4
};
class Card
{
public:

	int val;
	int color;
	Card(void);
	~Card(void);
};

