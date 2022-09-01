#include <stdio.h>
#include <stdbool.h>
#define TAILLE 5

int saisie(int tab[], int m){
	int i, c=0;
	for (i=0;i<m;i++){
                printf("Quelle valeur pour la case %d du tableau: \n ",i);
                scanf("%d",&tab[i]);
		c++;		
	}
	printf("Le cardinal de la liste est de : %d \n", c);
	return tab;
}

void affichage(int tab[], int m){
	int i;
	 for (i=0;i<m;i++){
                printf("tab[%2d] = %d \n",i, tab[i]);
        }
}

int tri(int tab[], int m){
	int i, n, e=m;
        bool bouge=true;

        while (bouge){
                n=e;
                bouge=false;
                for (i=0;i<m;i++){
                        if (tab[i]>tab[i+1]) {
                                e=tab[i];
                                tab[i]=tab[i+1];
                                tab[i+1]=e;
                                e=i;
                                bouge=true;
                        }
                }
        }
}

void main(){
        int t[TAILLE];

	saisie(t, TAILLE);
	affichage(t, TAILLE);
	tri(t, TAILLE);
	affichage(t, TAILLE);
}

