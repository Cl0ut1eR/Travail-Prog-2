#ifndef commandeH
#define commandeH
#include <string>
#include <stdio.h>
#include <vector>

#include"LigneDeCommande.h"
const int QuantiteeProduitsMax = 5;

class Commande
{
private:
	LigneDeCommande TabLignesCommandes[QuantiteeProduitsMax];
	string NomClient;
	bool CommandeFini;
	int QuantitéeProduitsActuel;
public:
	/*---constructeur---*/
	Commande();
	Commande(const Commande&);

	/*---------set----------*/
	void SetNom(string Nom);
	void SetFin(bool Fini);

	/*---------get---------*/
	Produit* getProduitLigneCommande(int noCommande) const;
	int getQuantiteLigneCommande(int inNoCommande) const;

	string getName() const;
	bool getCommandeFini() const;
	int getQuantiteActuel() const;

	/*---------fonction----------*/
	void AjouterLigneDeCommande(Produit* produit, int Quantitée);
};

#endif