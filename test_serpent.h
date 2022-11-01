#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <unistd.h>

void avancer(element *serp, parametre* p){
    int ax = serp[0].x, ay = serp[0].y;
    if(p->sens == 0){
        ax += 20;
    }else if(p->sens == 1){
        ay += 20;
    }else if(p->sens == 2){
        ax -= 20;
    }else if(p->sens == 3){
        ay -= 20;
    }
    ChoisirCouleurDessin(CouleurParComposante(141,199,63));
    RemplirRectangle(serp[p->Serpent-1].x,serp[p->Serpent-1].y,20,20);
    for(int i = p->Serpent-1; i >= 0; i--){
        if(i == 0){
            serp[i].x = ax;
            serp[i].y = ay;
        }else{
            serp[i] = serp[i-1];
        }
    }
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(ax,ay,20,20);
    for(int j = 1; j<255;j++){
        if(serp[0].x == serp[j].x && serp[0].y == serp[j].y){
            FermerGraphique();
            main();
        }
    }
    if(ax<0 || ax>p->Lignes || ay<0 || ay>p->Colonnes){
        FermerGraphique();
        main();
    } 
}
//----------------------------------------SNAKE--------------------------------------//
int snake(element *serpentelement, parametre* parametre){
    InitialiserGraphique();
    int zone;
    CreerFenetre(10,10,parametre->Lignes,parametre->Colonnes);
    couleur d;
    couleur c;
    c=CouleurParComposante(141,199,63);
    EffacerEcran(c);
    int end = 0;
    int TailleSerpent = parametre->Serpent;
    parametre->sens = 0;
    pommes(parametre->Pommes,parametre);
    while(end == 0){
        usleep(70000);   
        int t = -1;
        while(ToucheEnAttente()){
             t = Touche();
            if (t==XK_Left){
                if(parametre->sens  != 0)
                    parametre->sens = 2;
            }else if (t==XK_Right){
                if(parametre->sens  != 2)
                    parametre->sens = 0;
            }else if (t==XK_Up){
                if(parametre->sens  != 1)
                    parametre->sens = 3;
            }else if (t==XK_Down){
                if(parametre->sens  != 3)
                    parametre->sens = 1;
            }else if (t==XK_Escape){
                FermerGraphique();
                main();
            }
            else if(t==XK_space){
                t==Touche();
            }
        }
        avancer(serpentelement,parametre);
    }                   
}
//----------------------------------------FUNCTION_SERPENT--------------------------------------//
int function_serpent(parametre* parametre  ){
    
    struct element serpentelement={parametre->Lignes/2,parametre->Colonnes/2};
    snake(&serpentelement,parametre);
}