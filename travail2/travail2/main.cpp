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
			string Code = "";
			do{
				ClrScr();
				AfficherProduitsDisponible();
				if (Code == "-1")
				{
					cout << "\n---Code invalide---\n";
				}
				Code = DemanderCodeProduit();
			} while (Code=="-1");
			ClrScr();
			int Qty = 0;
			if (-1 == inCommande->VerifCode(Code))
			{
				Qty = DemanderQtyProduit(gestionCommande.getProduitByCode(Code)->getNom());
				inCommande->AjouterLigneDeCommande(gestionCommande.getProduitByCode(Code), Qty);
				ClrScr();
				cout << Qty << " " << gestionCommande.getProduitByCode(Code)->getNom() << "à ajouter avec succès.\n\n";
			}
			else
			{
				char Ajout = '%';
				do 
				{
					ClrScr();
					if (Ajout !='%'&&Ajout!='O'&&Ajout!='N' )
					{
						cout << "une erreur est survenue\n";
					}
					cout <<inCommande->getQuantiteLigneCommande( inCommande->VerifCode(Code)) << " " << gestionCommande.getProduitByCode(Code)->getNom() << " existe déjà dans votre commande, voulez vous modifier la quantité ? o-n\n";

					cin >> Ajout;
					cin.clear();
					cin.ignore(2000, '\n');
					Ajout = toupper(Ajout);
				} while (Ajout!='O'&&Ajout!='N');
				if (Ajout == 'O')
				{
					Qty = DemanderQtyProduit(gestionCommande.getProduitByCode(Code)->getNom());
					inCommande->ModifierQtyProduit(inCommande->VerifCode(Code), Qty);
					ClrScr();
					cout << Qty << " " << gestionCommande.getProduitByCode(Code)->getNom() << " a été modifier avec succès.\n\n";
				}
				else
				{
					cout << "Aucune modification éffectuée\n";
					system("pause");
					ClrScr();
				}
			}


		}

	}

#pragma endregion


#pragma region Ask

	string DemanderCodeProduit()
	{
		string codeProduit="";
			cout << "\nEntrer le code du produit souhaiter: \n";
			cin>>codeProduit;
			std::cin.clear();
			if (codeProduit == "" || !gestionCommande.VerifierCodeProduit(codeProduit))
			{
				codeProduit = "-1";
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
	char Continuer = 'O';
#pragma region affiche chaque commandes non fini
	while (index < tabCommandesNonFini.size()&&(Continuer=='O'))
	{


		#pragma region Action pour cette commande
			char Action = ' ';
			ClrScr();
			while (Action != 'F' && Action != 'M' && Action != 'Q' && Action != 'P')
			{
				AfficherUneCommande(gestionCommande.getUneCommande(tabCommandesNonFini[index]));
				cout << "-------------------\n";
				if (Action != 'F' && Action != 'M'&& Action != ' ')
				{
					cout << "\tUne erreur est survenue.\n";
				}
				cout << "\n\tfinaliser  --- f-F\n"
					<<"\tModifier les quantitées  --- m-M\n"
					<<"\tProchainne commande --- p-P\n"
					<<"\tQuiter --- q-Q\n";
				cin >> Action;
				cin.clear();
				cin.ignore(2000, '\n');
				ClrScr();
				Action = toupper(Action);
			}
			string Code = "";
			int Pos = 0;
			
			switch (Action)
			{
			case 'F'://------------F------------------

				FinaliserCommande(gestionCommande.getUneCommande(tabCommandesNonFini[index]));
				ClrScr();
				cout << "La commande à été finalisée\n";
				system("pause");
				break;

			case'M'://-------------M-----------------
				do {
					ClrScr();
					AfficherUneCommande(gestionCommande.getUneCommande(tabCommandesNonFini[index]));
					cout << "-------------------\n";
						
					if (Pos == -1)
					{
						cout << "Le code n'existe pas\n";
					}
						cout<< "Modification de quantitées\n"
						<< "Entrez le numero du produit que vous voulez modifier\n";

					Code = DemanderCodeProduit();

					if (Code != "-1")
					{
						Pos = gestionCommande.getUneCommande(tabCommandesNonFini[index])->VerifCode(Code);
						if (Pos != -1)
						{
							/*code pour modification*/
							gestionCommande.getUneCommande(tabCommandesNonFini[index])->ModifierQtyProduit(Pos, DemanderQtyProduit(gestionCommande.getProduitByCode(Code)->getNom()));
							cout << "Modification éffectuée avec succès\n";
							system("pause");
						}
					}
					else
					{
						Pos = -1;
					}

				} while (Pos==-1);
				index--;
				break;

			case 'Q':
				Continuer = 'N';
				break;
			case 'P':
				break;
			default:
				index--;
				break;
			}
#pragma endregion

		
		index++;
	}
#pragma endregion

}





void FinaliserCommande(Commande* inCommande)
{
	if (inCommande != NULL)
	{
		inCommande->SetFin(true);
	}
}

