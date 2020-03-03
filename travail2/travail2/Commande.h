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
	int QuantiteProduitsActuel;
public:

	#pragma region Constructeurs
		Commande();
		Commande(const Commande&);
	#pragma endregion

	#pragma region Set
		void SetNom(string Nom);
		//true pour quelle soit fini.
		void SetFin(bool Fini);
	#pragma endregion

	#pragma region Get
		//r�cup�re un produit dans la commandes.
		Produit* getProduitLigneCommande(int noCommande) const;
		
		//r�cup�re la quantit� d'un produit dans la commande.
		int getQuantiteLigneCommande(int inNoCommande) const;
		int getMaxProduitCommande() const;

		string getName() const;
		bool getCommandeFini() const;
		int getQuantiteActuel() const;
	#pragma endregion

	#pragma region Functions

		void AjouterLigneDeCommande(Produit* produit, int Quantit�e);

		int VerifCode(string Code);

		void ModifierQtyProduit(int Pos, int Qty);

	#pragma endregion

};

#endif