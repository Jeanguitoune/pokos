#include "Environnement.h"


Environnement::Environnement(int nb_players)
{
	m_nbplayers = nb_players;
	initDeck();
}

void Environnement::initDeck()
{
	m_packet.clear();
	Card temp;
	for (int color=0; color<4; color++)//0 à 3 (carreau, trèfle, coeur, pique) 
		for (int val=1; val<14; val++)// 1 à 10 + valet,reine, roi 
		{
			temp.val = val;
			temp.color = color;
			m_packet.push_back(temp);
		} 
}
void Environnement::printDeckInorder(){
	vector<Card>::iterator it;
	printf("Affichage du paquet dans l'ordre, une carte par ligne\n");
	for (it=m_packet.begin(); it<m_packet.end(); it++)
		printf("(%d,%d)\n", (*it).val, (*it).color);

}

void Environnement::printHandsInorder(){
	vector<hand>::iterator it;
	printf("Affichage des mains actuelles des %d joueurs actuellement presents a la table\n", m_nbplayers);
	int Numerojoueur = 0;
	for (it=m_handsDealed.begin(); it<m_handsDealed.end(); it++)
	{
		printf("Le joueur numéro %d a reçu les cartes (%d,%d) et (%d,%d)\n", ++Numerojoueur, (*it).card1.val, (*it).card1.color, (*it).card2.val, (*it).card2.color);
	}

}


void Environnement::distribuerJeux(){
	m_handsDealed.clear();
	vector<Card>::iterator it;
	hand currentHand;
	int nbPlayersDealed=0;
	while(nbPlayersDealed < m_nbplayers)
	{
		it=m_packet.end();
		it--;
		currentHand.card1 = (*it);
		m_packet.pop_back();

		it=m_packet.end();
		it--;
		currentHand.card2 = (*it);
		m_packet.pop_back();


		m_handsDealed.push_back(currentHand);
		nbPlayersDealed++;
	}

}

// On suppose a<b
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void Environnement::melangerDeck(){
	// A ne pas oublier !
	srand(time(NULL));
	vector<Card>::iterator it;

	Card temp;
	int rand_number;
	for (it=m_packet.begin(); it<m_packet.end(); it++)
	{
		rand_number = rand_a_b(0,m_packet.size());
		temp = (*it);
		(*it) = m_packet.at(rand_number);
		m_packet[rand_number] = temp;
	}
}
Environnement::~Environnement(void)
{
}
