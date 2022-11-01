#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <unistd.h>

typedef struct element
{
	int x;
	int y;
}element; 

struct element serpentelement[256];

typedef struct parametre
{
	int Lignes;
	int Colonnes;
	int Pommes;
	int Serpent;
	int  sens;// 0=doite  1=bas  2=gauche 3=haut  
}parametre;

struct element Pommes[10];


int main();
int option();
int pommes();
