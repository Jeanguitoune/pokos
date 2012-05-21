#include "Table.h"
using namespace std;

/*Convention gestion cartes : une carte est representée par un doublet (val, color)
	Table correpondance :
+-----------+----------+
|    val    |   color  |
+-----+-----+----------+
|	1 A     | 0 Pique  |
|	2 2     | 1 Coeur  |
|	3 3     | 2 Carreau|
|	...     | 3 Tréfle |
|	10 T    +----------+
|	11 J    |
|	12 Q    |
|	13 K    |
+-----------+
*/
int main(){
	int numberPlayer = 6;
	
	//instantion d'un Deck de 52 cartes
	//On place l'addresse de se Deck dans une variable pointeur sur Deck nommée MonDeck
	Table *MyTable = new Table(numberPlayer);

	//on initialise le deck trié : 13 cartes de chaque couleur.
	MyTable->initDeck();

	//affichage paquet trié
	MyTable->printDeckInorder();

	//on mélange le paquet
	MyTable->melangerDeck();

	//on réaffiche le paquet aléatoire mélangé
	MyTable->printDeckInorder();

	//On distribue les jeux aux joueurs
	MyTable->distribuerJeux();

	//On affiche séquentiellement les mains qui viennent d'être distribuées à chaque joueur
	MyTable->printHandsByPlayer();

	//on tire le flop
	MyTable->tirerFlop();

	//on affiche les cartes au milieux déja tirées
	MyTable->printMiddleCards();

	//on réaffiche les cartes restantes du paquet
	MyTable->printDeckInorder();

	//pour éviter de refermer la console
	int t;
	scanf("%d",&t);

return 0;
}
