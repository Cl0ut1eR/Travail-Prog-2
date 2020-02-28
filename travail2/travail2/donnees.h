#pragma once
#include "produit/Produit.h"
#include "Commande.h"
#include <stdbool.h>

const int maxCommandes = 25;
const int maxProduitsAVendre = 40;

class Donnees
{
private:
	void AjouterLesProduitsAVendre();
	Commande tabDesCommandes[maxCommandes];
	int qtyCommandes;
public:
	Donnees();
	Produit produitsAVendre[maxProduitsAVendre];

	bool VerifierCodeProduit(string inNoProduit) const;

#pragma region Get

	Produit* getProduitByCode(string CodeProduit) ;
	Commande* getUneCommande(int Position);
	int getMaxProduitsAVendre() const;
	int getQtyCommandeActuel() const;
	int getQtyCommandeNonFinal() const;
#pragma endregion



#pragma region Set
	void setQtyCommandeActuel(int Quantite) ;
	bool AddCommande(Commande commande);

#pragma endregion

};

