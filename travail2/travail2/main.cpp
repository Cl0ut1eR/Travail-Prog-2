#include <fcntl.h>  
#include <io.h>  
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdbool.h>
#include "..\screen\screen.h"
using namespace std;

#include "donnees.h" 
#include"Commande.h"

Donnees gestionCommande;

char AfficherMenu();
void CreerCommande();
//void AjouterCommande(Commande);
void AfficherLesCommandes();
void TraiterLesCommandes();
string DemanderNom();
void AfficherProduitsDisponible();
void AfficherUnProduit(int Pos);
string DemanderNoProduit();
void ajouterLigneCommande(Commande* inCommande);
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
string ConvertToUTF8(string inText);

void main()
{

	

	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': CreerCommande();
			break;
		case '2': AfficherLesCommandes();
			break;
		case '3': TraiterLesCommandes();
			break;
		}
	}
}

char AfficherMenu()
{
	char choix;
	TextBackground(Blue);
	TextColor(White);
	ClrScr();
	Gotoxy(40,1);
	cout << "Choisir une option";
	Gotoxy(40, 4);
	cout << ConvertToUTF8("1- Créer une commande");
	Gotoxy(40, 6);
	cout << "2- Afficher les commandes";
	Gotoxy(40, 8);
	cout << "3- Traiter les commandes";
	Gotoxy(40, 10);
	cout << ConvertToUTF8("0- Arrêter");
	Gotoxy(40, 12);
	cout << "Choix: ";
	cin >> choix;
	TextBackground(Black);
	TextColor(Lightgray);
	return choix;
}
void CreerCommande()
{
	string Rep;
	Commande UneCommande = Commande();
	UneCommande.SetNom(DemanderNom());

	AfficherProduitsDisponible();
	ajouterLigneCommande(&UneCommande);


	cout << "Termimner? o/n?\n";
	cin >> Rep;

	while (Rep != "o")
	{
		ajouterLigneCommande(&UneCommande);

		if (UneCommande.getQuantiteActuel() < UneCommande.getMaxProduitCommande())
		{
			cout << "Termimner? o/n?\n";
			cin >> Rep;
		}
		else
		{
			cout << "Limite du nombre article accepte par commande atteint.";
			Rep = "o";
		}


	}

	
	/*string test = "";
	cin >> test;*/
//	Commande laCommande;


	


//	AjouterCommande(laCommande);
}
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}
string ConvertToUTF8(string inText)
{

	inText = ReplaceAll(string(inText), std::string("…"), std::string("..."));
	inText = ReplaceAll(string(inText), std::string("é"), std::string("\202"));
	inText = ReplaceAll(string(inText), std::string("à"), std::string("\205"));
	inText = ReplaceAll(string(inText), std::string("ç"), std::string("\207"));
	inText = ReplaceAll(string(inText), std::string("Ç"), std::string("\200"));
	inText = ReplaceAll(string(inText), std::string("â"), std::string("\203"));
	inText = ReplaceAll(string(inText), std::string("ê"), std::string("\210"));
	inText = ReplaceAll(string(inText), std::string("ë"), std::string("\211"));
	inText = ReplaceAll(string(inText), std::string("è"), std::string("\212"));
	inText = ReplaceAll(string(inText), std::string("é"), std::string("\202"));
	inText = ReplaceAll(string(inText), std::string("É"), std::string("\220"));
	inText = ReplaceAll(string(inText), std::string("ï"), std::string("\213"));
	inText = ReplaceAll(string(inText), std::string("î"), std::string("\214"));
	inText = ReplaceAll(string(inText), std::string("ì"), std::string("\214"));
	inText = ReplaceAll(string(inText), std::string("æ"), std::string("\221"));
	inText = ReplaceAll(string(inText), std::string("Æ"), std::string("\221"));
	inText = ReplaceAll(string(inText), std::string("ô"), std::string("\222"));
	inText = ReplaceAll(string(inText), std::string("û"), std::string("\226"));


	//a trouver
	inText = ReplaceAll(string(inText), std::string("ù"), std::string("u"));

	return inText;
}

string DemanderNoProduit()
{
	string noProduit;
	cout << "\nEntrer le numero de produit souhaiter: ";

	while (!(std::cin >> noProduit) || noProduit == "" || !gestionCommande.VerifierNoProduit(noProduit))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}
		ClrScr();
		cout << "Une erreure est survenue,\nEntrer le numero de produit souhaiter : \n";
	}

	return noProduit;
}

int DemanderQtyProduit()
{
	int QtyProduit =0;
	cout << "Combien?: ";

	while (!(std::cin >> QtyProduit) || QtyProduit < 1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}
		ClrScr();
		cout << "Une erreure est survenue,\nCombien?: \n";
	}

	return QtyProduit;
}



void ajouterLigneCommande(Commande* inCommande)
{


	if (inCommande->getQuantiteActuel()<QuantiteeProduitsMax)
	{
		string Code=DemanderNoProduit();
		int quantite = DemanderQtyProduit();

		inCommande->AjouterLigneDeCommande(gestionCommande.getProduitByCode(Code), quantite);
		cout << ConvertToUTF8("Article ajouter avec succès.\n\n");


	}
	
}

void AfficherProduitsDisponible()
{
	ClrScr();
	for (int i = 0; i < gestionCommande.getMaxProduitsAVendre(); i++)
	{
		if (gestionCommande.produitsAVendre[i].getNom() != "")
		{
			AfficherUnProduit(i);
		}
	}
}

void AfficherUnProduit(int Pos)
{
	cout << "\n"<< ConvertToUTF8(gestionCommande.produitsAVendre[Pos].getNom());
	cout << "\n\t" << ConvertToUTF8(gestionCommande.produitsAVendre[Pos].getDescription());
	cout << "\n\t" << ConvertToUTF8(gestionCommande.produitsAVendre[Pos].getPrix()+"$");
	cout << "\n\tCode:" << ConvertToUTF8(gestionCommande.produitsAVendre[Pos].getCode());
	cout << "\n";
}



string DemanderNom()
{
	ClrScr();
	string nomClient = "";
	cout << ConvertToUTF8("Veuillez écrire le nom à indiquer sur la commande.\n");

		while (!(std::cin >> nomClient) || nomClient =="")
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(2000, '\n');
			}
			ClrScr();
			cout << ConvertToUTF8("Une erreure est survenue,\nveuillez écrire le nom à indiquer sur la commande.\n");
		}
		return nomClient;
}

//pour tester constructeur par recopie
//void AjouterCommande(Commande inCommande) 
//{
//
//}

void AfficherLesCommandes()
{

}

void TraiterLesCommandes()
{

}

