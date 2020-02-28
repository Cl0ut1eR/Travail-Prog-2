#pragma region Include
	#include <fcntl.h>  
	#include <io.h>  
	#include <string>
	#include <conio.h>
	#include <stdio.h>
	#include <iostream>
	#include <iomanip>
	#include <stdbool.h>
	#include<cstdlib>
#pragma endregion

using namespace std;

#pragma region IncludeModules
	#include "..\screen\screen.h"
	#include "donnees.h" 
	#include"Commande.h"
#pragma endregion

#pragma region Globale Var

	Donnees gestionCommande;

#pragma endregion

#pragma region InitialisationFunc
	char AfficherMenu();
	void CreerCommande();
	//void AjouterCommande(Commande);
	void AfficherLesCommandes();
	void TraiterLesCommandes();
	string DemanderNom();
	void AfficherProduitsDisponible();
	void AfficherUnProduit(int Pos);
	string DemanderCodeProduit();
	void ajouterLigneCommande(Commande* inCommande);
	int DemanderQtyProduit(string nomProduit);
	void AjouterCommande(Commande inCommande);
	void AfficherUneCommande(Commande* inCommande);
	void FinaliserCommande(Commande* inCommande);
#pragma endregion


void main()
{
	#pragma region UTF8
		#if defined WIN32
		system("chcp 1252");
		#endif
	#pragma endregion

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

#pragma region Functions

	void CreerCommande()
	{
		Commande UneCommande = Commande();

		//set nom commande
		UneCommande.SetNom(DemanderNom());

		//ajout lignes commandes
		string ajouterNew = "N";
		do 
		{
			ClrScr();
			ajouterLigneCommande(&UneCommande);

			if (UneCommande.getQuantiteActuel() < UneCommande.getMaxProduitCommande())
			{
				cout << "En ajouter un autre? o/n?\n";
				cin >> ajouterNew;
				cin.clear();
			}
			else
			{
				cout << "Limite du nombre article accepte par commande atteint.";
				ajouterNew = "n";
			}
		} while (ajouterNew =="o"||ajouterNew=="O");


		AjouterCommande(UneCommande);
	}

	void ajouterLigneCommande(Commande* inCommande)
	{
		
		if (inCommande->getQuantiteActuel() < QuantiteeProduitsMax)
		{
			string Code = DemanderCodeProduit();

			int quantite = DemanderQtyProduit(gestionCommande.getProduitByCode(Code)->getNom());

			inCommande->AjouterLigneDeCommande(gestionCommande.getProduitByCode(Code), quantite);
			cout << quantite<<" "<<gestionCommande.getProduitByCode(Code)->getNom()<<"à ajouter avec succès.\n\n";
		}

	}

#pragma endregion


#pragma region Ask

	string DemanderCodeProduit()
	{
		string codeProduit="";
		AfficherProduitsDisponible();
		while (codeProduit == "" || !gestionCommande.VerifierCodeProduit(codeProduit))
		{
			cout << "\nEntrer le code du produit souhaiter: \n";
			cin>>codeProduit;
			std::cin.clear();
			if (codeProduit == "" || !gestionCommande.VerifierCodeProduit(codeProduit))
			{
				ClrScr();
				AfficherProduitsDisponible();
				cout << "\nUne erreure est survenue,\n";
			}
		}
		return codeProduit;
	}

	int DemanderQtyProduit(string inNomProduit)
	{
		int QtyProduit = 0;
		cout << "Combien de "<<inNomProduit<<" voulez vous?\n";

		while (!(std::cin >> QtyProduit) || QtyProduit < 1)
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(2000, '\n');
			}
			ClrScr();
			cout << "Une erreure est survenue,\nCombien de "<<inNomProduit<<" voulez vous?\n";
		}

		return QtyProduit;
	}

	string DemanderNom()
	{
		ClrScr();
		string nomClient = "";
		cout << "Veuillez écrire le nom à indiquer sur la commande.\n";
		do 
		{
			getline(cin, nomClient);
			std::cin.clear();
			ClrScr();
			cout << "Le nom dois contenir entre 3 et 250 charactères,\nveuillez écrire le nom à indiquer sur la commande.\n";

		} while (nomClient.length() < 3 || nomClient.length()>250);

		return nomClient;
	}

#pragma endregion


#pragma region Affichage

	void AfficherProduitsDisponible()
	{
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
		cout << "\n" << gestionCommande.produitsAVendre[Pos].getNom();
		cout << "\n\t" << gestionCommande.produitsAVendre[Pos].getDescription();
		cout << "\n\t" << gestionCommande.produitsAVendre[Pos].getPrix() + "$";
		cout << "\n\tCode:" << gestionCommande.produitsAVendre[Pos].getCode();
		cout << "\n";
	}

	char AfficherMenu()
	{
		char choix;
		TextBackground(Blue);
		TextColor(White);
		ClrScr();
		Gotoxy(40, 1);
		cout << "Choisir une option";
		Gotoxy(40, 4);
		cout << ("1- Créer une commande");
		Gotoxy(40, 6);
		cout << "2- Afficher les commandes";
		Gotoxy(40, 8);
		cout << "3- Traiter les commandes";
		Gotoxy(40, 10);
		cout << "0- Arrêter";
		Gotoxy(40, 12);
		cout << "Choix: ";
		cin >> choix;
		std::cin.clear();
		std::cin.ignore(2000, '\n');
		TextBackground(Black);
		TextColor(Lightgray);
		return choix;
	}

#pragma endregion



void AjouterCommande(Commande inCommande) 
{

	if (inCommande.getQuantiteActuel() < gestionCommande.getMaxProduitsAVendre())
	{
		gestionCommande.AddCommande(inCommande);
	}
}

void AfficherLesCommandes()
{
	ClrScr();
	for (int i = 0; i < gestionCommande.getQtyCommandeActuel(); i++)
	{
		AfficherUneCommande(gestionCommande.getUneCommande(i));
		cout << "-------------------------\n";
	}
	system("Pause");
}

void AfficherUneCommande(Commande* inCommande)
{
	if (inCommande != NULL && inCommande->getQuantiteActuel() > 0)
	{
		int grandTotalCommande = 0;
		cout << inCommande->getName()<<"\n\n";
		Produit* produitTempo = NULL;
		for (int i = 0; i < inCommande->getQuantiteActuel(); i++)
		{
			produitTempo = inCommande->getProduitLigneCommande(i);
			grandTotalCommande += produitTempo->getPrix() * inCommande->getQuantiteLigneCommande(i);
			cout << produitTempo->getCode()
				<< "\n" << produitTempo->getNom()
				<< "\n" << inCommande->getQuantiteLigneCommande(i) << " au prix de " << produitTempo->getPrix()<<"$ chacun " << "pour un total de : " << produitTempo->getPrix() * inCommande->getQuantiteLigneCommande(i)<<"$"
				<< "\n\n";
		}
		cout << "Total de : " << grandTotalCommande << "$\n\n";
	}
}

void TraiterLesCommandes()
{
	vector<int> tabCommandesNonFini = gestionCommande.getTabCommandeNonFinal();
	int index = 0;
	string Continuer = "o";
	while (index < tabCommandesNonFini.size()&&(Continuer=="o" || Continuer=="n"))
	{
		if (Continuer == "o")
		{
			string Action = "";
			ClrScr();
			while (Action != "F" && Action != "f" && Action != "m" && Action != "M")
			{
				AfficherUneCommande(gestionCommande.getUneCommande(index));
				cout << "\n\tfinaliser  --- f-F\n\tModifier les quantitées  --- m-M\n";
				cin >> Action;
				cin.clear();
				ClrScr();
				if (Action != "F" && Action != "f" && Action != "m" && Action != "M")
				{
					cout << "Une erreur est survenue.\n";
				}
			}
			if (Action == "F" || Action == "f")
			{
				FinaliserCommande(gestionCommande.getUneCommande(index));
				ClrScr();
				cout << "La commande à été finalisée\n";
				system("pause");
			}
		}
		index++;
	}
}

void FinaliserCommande(Commande* inCommande)
{
	if (inCommande != NULL)
	{
		inCommande->SetFin(true);
	}
}

