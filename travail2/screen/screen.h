//dans un fichier .h on retrouve les types à utilise dans le programme
//ainsi que le prototypes des fonctions 

#ifndef SCREEN_H	//pour que le fichier soit inclus une seule fois
#define SCREEN_H

#include <windows.h> 
const int Black=0; //on peut définir des constantes en C++
const int Blue=1;
const int Green=2;
const int Cyan=3;
const int Red=4; 
const int Magenta=5;
const int Brown=6;
const int Lightgray=7;
const int Darkgray=8;
const int Lightblue=9;
const int Lightgreen=10;
const int Lightcyan=11;
const int Lightred=12;
const int Lightmagenta=13;
const int Yellow=14;
const int White=15;

void ClrScr(); //prototype des fonctions
void ClrEol();
void ClrEoscr();
void Gotoxy(int x, int y);
void TextColor(int fontcolor);
void TextBackground(int background);

#endif