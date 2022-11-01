#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <unistd.h>
#include "serpent.h" 
#include "test_serpent.h"
#include "pommes_et_pieges.h"

int options();
int main() {
	int x,y;
	InitialiserGraphique();
	CreerFenetre(100,100,650,650);
	couleur v;
	couleur e;
	couleur c;

	parametre* parametre=malloc(sizeof(parametre));
	parametre->Lignes = 650;
    parametre->Colonnes = 650;
    parametre->Serpent = 10;
    parametre->Pommes = 5;
	parametre->sens = 0;
	v=CouleurParNom("green");
	e=CouleurParNom("grey");
	EffacerEcran(e);
	EcrireTexte(292,160,"Jouer !",2);
	DessinerRectangle(282,123,120,53); // Zone Jouer
	EcrireTexte(287,240,"Options",2);
	DessinerRectangle(282,204,120,53); // Zone Options
	EcrireTexte(291,320,"Quitter",2);
	DessinerRectangle(282,279,120,53); // Zone Quitter
	c=CouleurParNom("black");
	int fermer=0;
	while(!fermer){
		if(SourisCliquee()){
			SourisPosition();
			if((_X>=282 && _X<=402)&&(_Y>=279 && _Y<=332)){
				fermer = 1;
			}
			if((_X>=282 && _X<=402)&&(_Y>=204 && _Y<=257)){
				EffacerEcran(e);
				fermer = 2;
			}
			if((_X>=282 && _X<=402)&&(_Y>=123 && _Y<=176)){
				fermer = 3;
			}			
		}
		if(ToucheEnAttente()){
			if(Touche()==XK_space){
				fermer=1;
			}
		}
	}
	while(fermer==2){
		if(ToucheEnAttente()){
			if(Touche()==XK_space){
				fermer = 1;
			}
		}
		EcrireTexte(202,88,"Nombre de Lignes:",2);
		DessinerRectangle(470,55,60,45); // Zone cliquable
		EcrireTexte(190,196,"Nombre de Colonnes: ",2);
		DessinerRectangle(500,165,60,45); //Zone cliquable
		EcrireTexte(202,304,"Nombre de Pommes:",2);
		DessinerRectangle(495,274,60,45); //Zone cliquable
		EcrireTexte(230,412,"Taille du serpent:",2);
		DessinerRectangle(480,375,60,45); //Zone cliquable
		EcrireTexte(291,515,"Jouer !",2);
		DessinerRectangle(282,475,118,53); //Zone Jouer
		EcrireTexte(285,600,"Quitter !",2);
		DessinerRectangle(282,560,118,53); //Zone Quitter
		if(SourisCliquee()){
			SourisPosition();
			if((_X>=470 && _X<=530)&&(_Y>=55 && _Y<=100)){ //Lignes
				int NombreLigne = options();
				char Lignes[4];
				sprintf(Lignes,"%d",NombreLigne);
				Lignes[4]='\0';
				parametre->Lignes = NombreLigne;
				printf("Nombre Ligne=%s\n",Lignes);
				EcrireTexte(471,87,Lignes,2); 
			}			
			if((_X>=500 && _X<=560)&&(_Y>=165 && _Y<=210)){ //Colonnes
					int NombreColonne = options();
					char Colonnes[4];
					sprintf(Colonnes,"%d",NombreColonne);	
					Colonnes[4]='\0';
					printf("Nombre Colonne=%s\n",Colonnes);
					parametre->Colonnes= NombreColonne;
					EcrireTexte(501,198,Colonnes,2);
			}
			if((_X>=495 && _X<=555)&&(_Y>=274 && _Y<=319)){ //Pommes
					int NombrePommes = options();
					char Pommes[2];
					sprintf(Pommes,"%d",NombrePommes);	
					Pommes[2]='\0';
					printf("Nombre Pommes=%s\n",Pommes);
					EcrireTexte(496,307,Pommes,2);
					parametre->Pommes = NombrePommes;
			}
			if((_X>=480 && _X<=540)&&(_Y>=375 && _Y<=420)){ //Serpent
				int TailleSerpent = options();
				char Serpent[2];
				sprintf(Serpent,"%d",TailleSerpent);
				Serpent[2]='\0';
				parametre->Serpent = TailleSerpent;
				printf("Taille Serpent=%s\n",Serpent);
				EcrireTexte(481,408,Serpent,2);
			}
			if((_X>=282 && _X<=402)&&(_Y>=475 && _Y<=528)){ //Jouer
				fermer = 3;
			}
			if((_X>=282 && _X<=402)&&(_Y>=560 && _Y<=613)){ //Quitter
				fermer = 1;
			}
		} 	
	}
	while(fermer == 3){
		FermerGraphique();
		function_serpent(parametre);
		if(ToucheEnAttente()){
			if(Touche()==XK_space){
				fermer=1;
			}
		}
	}
	while(fermer==1){
		FermerGraphique();
		return EXIT_SUCCESS;
	}
}
//----------------------------------------OPTION--------------------------------------//
int options(){
	int N = 0,tmp,t = -1, i = 0;
	int nombre[4] = {0};	
	while(t != XK_KP_Enter && t != XK_Return){
		t=Touche();		

		if(t == XK_0 || t == XK_KP_0){
			nombre[i]=0;
		}
		else if(t==XK_1 || t == XK_KP_1){
			nombre[i]=1;	
		}
		else if(t==XK_2 || t == XK_KP_2){
			nombre[i]=2;
		}
		else if(t==XK_3 || t == XK_KP_3){
			nombre[i]=3;
		}
		else if(t==XK_4 || t == XK_KP_4){
			nombre[i]=4;
		}
		else if(t==XK_5 || t == XK_KP_5){
			nombre[i]=5;
		}
		else if(t==XK_6 || t == XK_KP_6){
			nombre[i]=6;
		}
		else if(t==XK_7 || t == XK_KP_7){
			nombre[i]=7;
		}
		else if(t==XK_8 || t == XK_KP_8){
			nombre[i]=8;
		}
		else if(t==XK_9 || t == XK_KP_9){
			nombre[i]=9;
		}					
		++i;
	}
	for(tmp = i-2,t=1; tmp !=-1; --tmp,t*=10){
		N+=nombre[tmp]*t;
	}
	return N;
} 	