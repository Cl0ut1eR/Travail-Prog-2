#include "Commande.h"

Commande::Commande()
{
	for (int i = 0; i < QuantiteeProduitsMax; i++)
	{
		TabLignesCommandes[i] = LigneDeCommande();
	}
	NomClient = "";
	CommandeFini = false;
	QuantiteProduitsActuel = 0;
	
}

Commande::Commande(const Commande& inCommande)
{
	for (int i = 0; i < QuantiteeProduitsMax; i++)
	{
		TabLignesCommandes[i] = inCommande.TabLignesCommandes[i];
	}
	QuantiteProduitsActuel = inCommande.getQuantiteActuel();
	NomClient = inCommande.getName();
	CommandeFini = inCommande.getCommandeFini();
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
	if (inNoCommande <= QuantiteProduitsActuel)
	{
		unProduit = TabLignesCommandes[inNoCommande].getProduit();
	}
	return unProduit;
}





int Commande::getQuantiteLigneCommande(int inNoCommande) const
{
	int Quantite = 0;
	if (inNoCommande <= QuantiteProduitsActuel)
	{
		Quantite = TabLignesCommandes[inNoCommande].getQuantite();
	}
	return Quantite;
}

int Commande::getMaxProduitCommande() const
{
	return QuantiteeProduitsMax;
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
	return QuantiteProduitsActuel;
}

void Commande::AjouterLigneDeCommande(Produit* inProduit, int inQuantitée)
{
	if (QuantiteProduitsActuel < QuantiteeProduitsMax)
	{
		TabLignesCommandes[QuantiteProduitsActuel].setProduit(inProduit);
		TabLignesCommandes[QuantiteProduitsActuel].setQuantite(inQuantitée);
		QuantiteProduitsActuel++;
	}
}
