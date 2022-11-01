#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>

int pommes(int NombrePommes, parametre* parametre,element* Pommes){
 int i = 0;
 int j = 0;
 int count = 0;

 srand(time(NULL));

 while(count != NombrePommes){
 	i = rand() % (parametre->Lignes)%20;
 	j = rand() % (parametre->Colonnes)%20;
 	count++;
 	ChoisirCouleurDessin(CouleurParComposante(255,0,0));
 	RemplirRectangle(i*20,j*20,20,20);
 	//Pommes[count].x = i;
 	//Pommes[count].y = j;
 }
}

void pomme_mangee(parametre* parametre){

}