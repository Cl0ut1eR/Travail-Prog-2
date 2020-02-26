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

	#pragma region Constructeurs
		Commande();
		Commande(const Commande&);
	#pragma endregion

	#pragma region Set
		void SetNom(string Nom);
		void SetFin(bool Fini);
	#pragma endregion

	#pragma region Get
		//récupère un produit dans la commandes.
		Produit* getProduitLigneCommande(int noCommande) const;
		//récupère la quantité d'un produit dans la commande.
		int getQuantiteLigneCommande(int inNoCommande) const;

		string getName() const;
		bool getCommandeFini() const;
		int getQuantiteActuel() const;
	#pragma endregion

	#pragma region Functions

		void AjouterLigneDeCommande(Produit* produit, int Quantitée);

	#pragma endregion

};

#endif