#include "Commande.h"

Commande::Commande()
{
	for (int i = 0; i < QuantiteeProduitsMax; i++)
	{
		TabLignesCommandes[i] = LigneDeCommande();
	}
	NomClient = "";
	CommandeFini = false;
	QuantitéeProduitsActuel = 0;
	
}

Commande::Commande(const Commande& inCommande)
{
	for (int i = 0; i < QuantiteeProduitsMax; i++)
	{
		TabLignesCommandes[i] = inCommande.TabLignesCommandes[i];
	}

	NomClient = inCommande.
}

void Commande::SetNom(string inNom)
{
	NomClient = inNom;
}

void Commande::SetFin(bool inFini)
{
	CommandeFini = inFini;
}

Produit* Commande::getProduitLigneCommande(int inNoCommande) const
{
	Produit* unProduit = NULL;
	if (inNoCommande <= QuantitéeProduitsActuel)
	{
		unProduit = TabLignesCommandes[inNoCommande].getProduit();
	}
	return unProduit;
}

int Commande::getQuantiteLigneCommande(int inNoCommande) const
{
	int Quantite = 0;
	if (inNoCommande <= QuantitéeProduitsActuel)
	{
		Quantite = TabLignesCommandes[inNoCommande].getQuantite();
	}
	return Quantite;
}

string Commande::getName() const
{
	return NomClient;
}

bool Commande::getCommandeFini() const
{
	return CommandeFini;
}

int Commande::getQuantiteActuel() const
{
	return QuantitéeProduitsActuel;
}

void Commande::AjouterLigneDeCommande(Produit* inProduit, int inQuantitée)
{
	if (QuantitéeProduitsActuel < QuantiteeProduitsMax)
	{
		QuantitéeProduitsActuel++;
		TabLignesCommandes[QuantitéeProduitsActuel].setProduit(inProduit);
		TabLignesCommandes[QuantitéeProduitsActuel].setQuantite(inQuantitée);

	}
}
