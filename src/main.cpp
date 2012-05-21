#include "Environnement.h"
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
	//instantion d'un Deck de 52 cartes
	//On place l'addresse de se Deck dans une variable pointeur sur Deck nomm�e MonDeck
	Environnement *MonEnvironnement = new Environnement(6);

	//affichage paquet tri�
	MonEnvironnement->printDeckInorder();

	//on m�lange le paquet
	MonEnvironnement->melangerDeck();

	//on r�affiche le paquet al�atoire m�lang�
	MonEnvironnement->printDeckInorder();

	//On distribue les jeux aux joueurs
	MonEnvironnement->distribuerJeux();

	//On affiche s�quentiellement les mains qui viennent d'�tre distribu�es � chaque joueur
	MonEnvironnement->printHandsInorder();

	//pour �viter de refermer la console
	int t;
	scanf("%d",&t);

return 0;
}
