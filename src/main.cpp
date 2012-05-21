#include "Environnement.h"
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
	//instantion d'un Deck de 52 cartes
	//On place l'addresse de se Deck dans une variable pointeur sur Deck nommée MonDeck
	Environnement *MonEnvironnement = new Environnement(6);

	//affichage paquet trié
	MonEnvironnement->printDeckInorder();

	//on mélange le paquet
	MonEnvironnement->melangerDeck();

	//on réaffiche le paquet aléatoire mélangé
	MonEnvironnement->printDeckInorder();

	//On distribue les jeux aux joueurs
	MonEnvironnement->distribuerJeux();

	//On affiche séquentiellement les mains qui viennent d'être distribuées à chaque joueur
	MonEnvironnement->printHandsInorder();

	//pour éviter de refermer la console
	int t;
	scanf("%d",&t);

return 0;
}
