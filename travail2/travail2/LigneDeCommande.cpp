#include "LigneDeCommande.h"

LigneDeCommande::LigneDeCommande()
{
	LeProduit = NULL;
	Quantite = 0;
}

LigneDeCommande::LigneDeCommande(Produit* inProduit, int inQuantite)
{
	LeProduit = inProduit;
	Quantite = inQuantite;
}

LigneDeCommande::LigneDeCommande(const LigneDeCommande& inLigneCommande)
{
	LeProduit = inLigneCommande.getProduit();
	Quantite = inLigneCommande.getQuantite();
}

void LigneDeCommande::setProduit(Produit* inProduit)
{
	LeProduit = inProduit;
}

void LigneDeCommande::setQuantite(int inQuantite)
{
	Quantite = inQuantite;
}

Produit* LigneDeCommande::getProduit() const
{
	return LeProduit;
}

int LigneDeCommande::getQuantite() const
{
	return Quantite;
}
