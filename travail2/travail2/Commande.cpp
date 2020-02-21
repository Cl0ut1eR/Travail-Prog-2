#include "Commande.h"

Commande::Commande()
{
	for (int i = 0; i < QuantiteeProduitsMax; i++)
	{
		TabLignesCommandes[i] = LigneDeCommande();
	}
	NomClient = "";
	CommandeFini = false;
	Quantit�eProduitsActuel = 0;
	
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
	if (inNoCommande <= Quantit�eProduitsActuel)
	{
		unProduit = TabLignesCommandes[inNoCommande].getProduit();
	}
	return unProduit;
}

int Commande::getQuantiteLigneCommande(int inNoCommande) const
{
	int Quantite = 0;
	if (inNoCommande <= Quantit�eProduitsActuel)
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
	return Quantit�eProduitsActuel;
}

void Commande::AjouterLigneDeCommande(Produit* inProduit, int inQuantit�e)
{
	if (Quantit�eProduitsActuel < QuantiteeProduitsMax)
	{
		Quantit�eProduitsActuel++;
		TabLignesCommandes[Quantit�eProduitsActuel].setProduit(inProduit);
		TabLignesCommandes[Quantit�eProduitsActuel].setQuantite(inQuantit�e);

	}
}
