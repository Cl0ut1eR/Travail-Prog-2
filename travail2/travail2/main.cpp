#include <fcntl.h>  
#include <io.h>  
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
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
void test2();

void main()
{

	//SetConsoleCP(CP_UTF8);
//SetConsoleOutputCP(CP_UTF8);

	while (true)
	{
		test2();
	}

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

void test2()
{
	ClrScr();
	std::string testt = "";
	cin >> testt;
	cout << "1 :"<<testt<<" 2: é  3: à  4: É";
	cin >> testt;
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
	cout << "1- Creer une commande";
	Gotoxy(40, 6);
	cout << "2- Afficher les commandes";
	Gotoxy(40, 8);
	cout << "3- Traiter les commandes";
	Gotoxy(40, 10);
	cout << "0- Arreter";
	Gotoxy(40, 12);
	cout << "Choix: ";
	cin >> choix;
	TextBackground(Black);
	TextColor(Lightgray);
	return choix;
}
void CreerCommande()
{
	Commande UneCommande = Commande();
	UneCommande.SetNom(DemanderNom());

	AfficherProduitsDisponible();
	string test = "";
	cin >> test;
//	Commande laCommande;



//	AjouterCommande(laCommande);
}

string ConvertToUTF8(string inText)
{
	bool ACorrige = true;
	while (ACorrige)
	{
		inText.find("à")
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
	cout << "\n"<<gestionCommande.produitsAVendre[Pos].getNom();
	cout << "\n\t" << gestionCommande.produitsAVendre[Pos].getDescription();
	cout << "\n\t" << gestionCommande.produitsAVendre[Pos].getPrix()<<"$";
	cout << "\n\tCode:" << gestionCommande.produitsAVendre[Pos].getCode();
	cout << "\n";
}



string DemanderNom()
{
	ClrScr();
	string nomClient = "";
	cout << "Veuillez écrire le nom à indiquer sur la commande.\n";

		while (!(std::cin >> nomClient) || nomClient =="")
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(2000, '\n');
			}
			ClrScr();
			cout << "Une erreure est survenue,\nveuillez écrire le nom à indiquer sur la commande.\n";
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

