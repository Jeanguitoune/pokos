#include "Table.h"

using namespace std;

/*Convention gestion cartes : une carte est represent�e par un doublet (val, color)
	Table correpondance :
+-----------+----------+
|    val    |   color  |
+-----+-----+----------+
|	1 A     | 0 Pique  |
|	2 2     | 1 Coeur  |
|	3 3     | 2 Carreau|
|	...     | 3 Tr�fle |
|	10 T    +----------+
|	11 J    |
|	12 Q    |
|	13 K    |
+-----------+
*/
int main(){
	int numberPlayer = 6;
	
	//instantion d'un Deck de 52 cartes
	//On place l'addresse de se Deck dans une variable pointeur sur Deck nomm�e MonDeck
	Table *MyTable = new Table(numberPlayer);

	//on initialise le deck tri� : 13 cartes de chaque couleur.
	MyTable->initDeck();

	//affichage paquet tri�
	MyTable->printDeckInorder();

	//on m�lange le paquet
	MyTable->melangerDeck();

	//on r�affiche le paquet al�atoire m�lang�
	MyTable->printDeckInorder();

	//On distribue les jeux aux joueurs
	MyTable->distribuerJeux();

	//On affiche s�quentiellement les mains qui viennent d'�tre distribu�es � chaque joueur
	MyTable->printHandsByPlayer();

	//on tire le flop
	MyTable->tirerFlop();

	//on affiche les cartes au milieux d�ja tir�es
	MyTable->printMiddleCards();

	//on r�affiche les cartes restantes du paquet
	MyTable->printDeckInorder();

	//pour �viter de refermer la console
	int t;
	scanf("%d",&t);

return 0;
}
