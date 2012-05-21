#include "Table.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

Table::Table(int nb_players)
{
	m_nbplayers = nb_players;


	ifstream fichier("src/player.txt", ios::in);
	string current_name;
	string current_cave;
	Player *current_player = NULL;
	if(!fichier.fail())
    {
		//cout << "Le fichier existe bien et est correctement ouvert !" << endl;
		for (int i=0; i<nb_players; i++)
		{
			getline(fichier, current_name);
			getline(fichier, current_cave);

			current_player = new Player(current_name, current_cave);
			m_Players.push_back(*current_player);
			current_player = NULL;
		}
	}

	/*for (int i=0; i<nb_players; i++)
	{
		cout<<"nom du joueur ?"<<endl;
		getline(cin, current_name);
		cout<<"stack de "<<current_name<<" ?"<<endl;
		getline(cin, current_cave);

		current_player = new Player(current_name, current_cave);

		m_Players.push_back(*current_player);
		current_player = NULL;
	}*/
}

void Table::initDeck()
{
	m_packet.clear();
	Card temp;
	for (int color=0; color<4; color++)//0 à 3 (carreau, trèfle, coeur, pique) 
		for (int val=1; val<14; val++)// 1 à 10 + valet, dame, roi 
		{
			temp.val = val;
			temp.color = color;
			m_packet.push_back(temp);
		} 
}
void Table::printDeckInorder(){
	vector<Card>::iterator it;
	printf("Affichage du paquet dans l'ordre, une carte par ligne\n");
	for (it=m_packet.begin(); it<m_packet.end(); it++)
		printf("(%d,%d)\n", (*it).val, (*it).color);

}

void Table::printHandsByPlayer(){
	vector<Player>::iterator it;
	printf("Affichage des mains actuelles des %d joueurs actuellement presents a la table\n", m_nbplayers);
	for (it=m_Players.begin(); it<m_Players.end(); it++)
	{
		cout<<(*it).m_name<<" a recu les cartes ("<<(*it).m_currentHand.card1.val<<","<<(*it).m_currentHand.card1.color<<") et ("
			<<(*it).m_currentHand.card2.val<<","<<(*it).m_currentHand.card2.color<<")."<<endl;
	}

}


void Table::distribuerJeux(){
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

		m_Players.at(nbPlayersDealed).m_currentHand = currentHand;
		nbPlayersDealed++;
	}

}

// On suppose a<b
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void Table::melangerDeck(){
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

void Table::tirerFlop()
{
	m_currentMiddleCards.clear();

	// A ne pas oublier !
	srand(time(NULL));
	vector<Card>::iterator it;

	int rand_number;
	Card temp;

	for(int i = 0; i<3; i++)
	{
		rand_number = rand_a_b(0,m_packet.size());
		temp = m_packet.at(rand_number);
		m_packet.erase( m_packet.begin() + rand_number);
		m_currentMiddleCards.push_back(temp);
	}
}

void Table::printMiddleCards()
{
	vector<Card>::iterator it;
	cout<<"Les cartes actuelles au centres sont :"<<endl;
	for (it=m_currentMiddleCards.begin(); it<m_currentMiddleCards.end(); it++)
	{
		cout<<"("<<(*it).val<<","<<(*it).color<<")"<<endl;
	}
	cout<<endl;
}
Table::~Table(void)
{
}
