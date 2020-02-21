#ifndef lignedecommandeH
#define lignedeommandeH
#include <string>
#include <stdio.h>
#include <vector>
#include "produit/Produit.h"
class LigneDeCommande
{
private:
	Produit* LeProduit;
	int Quantite;

public:
	/*----Constructeur----*/
	LigneDeCommande();
	LigneDeCommande(Produit* Produit,int Quantite);
	LigneDeCommande(const LigneDeCommande&);

	/*------set--------*/
	void setProduit(Produit* Produit);
	void setQuantite(int quantite);

	/*------get-------*/
	Produit* getProduit() const;
	int getQuantite() const;


};




#endif