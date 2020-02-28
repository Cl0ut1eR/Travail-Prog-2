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
public:
	Donnees();
	Produit produitsAVendre[maxProduitsAVendre];

	bool VerifierCodeProduit(string inNoProduit) const;
	Produit* getProduitByCode(string CodeProduit) ;

	int getMaxProduitsAVendre() const;
};

