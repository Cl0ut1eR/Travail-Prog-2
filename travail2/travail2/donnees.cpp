#include "donnees.h"

Donnees::Donnees()
{
	AjouterLesProduitsAVendre();
}

void Donnees::AjouterLesProduitsAVendre()
{
	produitsAVendre[0].InitialiserProduit("obj1", "feuxfous fuseboum", "feux d'artifices invulnérables aux sorts", 7);
	produitsAVendre[1].InitialiserProduit("obj2", "leurre explosif", "sert à faire diversion", 6);
	produitsAVendre[2].InitialiserProduit("bon6", "berlingot de fièvre", "confiserie qui fait monter la température et provoque des furoncles sur les fesses", 2);
	produitsAVendre[3].InitialiserProduit("bon1", "chocogrenouille", "confiserie qui prend la forme d'une grenouille qui saute", 1);
	produitsAVendre[4].InitialiserProduit("bon2", "dragée surprise de Bertie Crochue", "dragée existant en plusieurs saveurs: chocolat, foie, tripe, sang de gobelin, fraise, gazon, …", 2);
	produitsAVendre[5].InitialiserProduit("bon3", "boite à flemme", "confiserie dont la première moitié rend malade et la deuxième est un antidote", 4);
	produitsAVendre[6].InitialiserProduit("bon4", "pastille de gerbe", "confiserie qui fait vomir", 2);
	produitsAVendre[7].InitialiserProduit("bon5", "bulle baveuse", "gomme produisant des bulles mauves", 1);
	produitsAVendre[8].InitialiserProduit("obj3", "cape bouclier", "cape protectrice contre maléfice mineur", 5);
	produitsAVendre[9].InitialiserProduit("obj4", "rêve éveillé", "plonge la personne dans un rêve réaliste pendant 30 min", 7);
	produitsAVendre[10].InitialiserProduit("obj5", "poudre d'obscurité", "poudre noire produisant une obscurité dense", 8);
	produitsAVendre[11].InitialiserProduit("obj6", "échec", "jeu d'échec version sorcier où les pièces sont animées et grandeur nature", 12);
	produitsAVendre[12].InitialiserProduit("obj7", "oreille à rallonge", "permet d'écouter une conversation inaudible", 5);
	produitsAVendre[13].InitialiserProduit("obj8", "plume à papotte", "note des propos en les exagérant", 5);
	produitsAVendre[14].InitialiserProduit("pot1", "potion de babillage", "provoque des propos insensés", 3);
	produitsAVendre[15].InitialiserProduit("pot2", "potion d'enflure", "potion qui fait enfler la personne", 4);
	produitsAVendre[16].InitialiserProduit("pot3", "philtre d'amour", "rend temporairement une personne vraiment amouseuse d'une autre", 9);
	produitsAVendre[17].InitialiserProduit("bon7", "marque des ténèbres comestible", "confiserie qui rend malade à coup sûr", 3);
	produitsAVendre[18].InitialiserProduit("obj9", "marécage portable", "transforme un espace en marécage", 6);
	produitsAVendre[19].InitialiserProduit("obj10", "chapeau sans tête", "une fois sur la tête, le chapeau et la tête de la personne deviennent invisibles", 4);

}



