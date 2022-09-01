#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define T1 6
#define T2 4
#define T3 (T1+T2)
#define T 30

void main(){
        int choix, i, tab1[T1], tab2[T2], tab3[T3], tab[T]; 

	printf("Si vous voulez lire un tableau depuis un fichier entrez 0 sinon entrez n'importe quel chiffre. \n");
	scanf("%d", &choix);
	
	if (choix!=0){
		printf("Pour acceder a la suite commencez par remplir le tableau 1. \n");
		for (i=0;i<T1;i++){
		        printf("Quelle valeur pour la case %d du tableau 1: \n ",i);
		        scanf("%d",&tab1[i]);
			}	

		printf("Que voulez-vous faire? 1. Afficher, 2. Cardinal, 3. Tri a bulles, 4. Union, 5. Intersection, 6. Difference symetrique, 7. Ajouter 8. Supprimer (indice) 9. Supprimer (valeur) 10. Extraire une sous-liste 11. Tri par insertion \n");
		scanf("%d", &choix);
	}

	switch(choix){
	
	case 1:
		{int i;

		printf("Affichage du tableau: \n");
		for (i=0;i<T1;i++) printf("tab1[%2d] = %d \n",i, tab1[i]);

		break;}

	case 2:
		{int i, c=0;

		for (i=0;i<T1;i++) c++;
		printf("Le cardinal de la liste est de : %d \n", c);

		break;}

	case 3:
		{int n, e=T1, i;
		bool bouge;

		while (bouge){
			n=e;
			bouge=false;
			for (i=0;i<T1;i++){
				if (tab1[i]>tab1[i+1]) {
					e=tab1[i];
					tab1[i]=tab1[i+1];
					tab1[i+1]=e;
					e=i;
					bouge=true;
				}
			}
		}

		printf("Le tableau trie est: \n");
		for (i=0;i<T1;i++){
		        printf("tab1[%2d] = %d \n",i, tab1[i]);
		}

		break;}
	
	case 4:
		{int k, l, m;	
	
		for (k=0;k<T2;k++){
                	printf("Quelle valeur pour la case %d du tableau 2: \n ",k);
                	scanf("%d",&tab2[k]);
		}

		for (k=0;k<T1;k++){
			tab3[k]=tab1[k];
			}

		for (l=T1, m=0;l<T3, m<T2;l++, m++){
			tab3[l]=tab2[m];
			}

		printf("L union des deux tableaux est: \n");
		for (k=0;k<T3;k++){
		        printf("tab3[%2d] = %d \n",k, tab3[k]);
		}

		break;}

	case 5:
		{int j, k, c=0;

		for (j=0;j<T2;j++){
                	printf("Quelle valeur pour la case %d du tableau 2: \n ",j);
                	scanf("%d",&tab2[j]);
		}

		for (j=0;j<T1;j++){
			for (k=0;k<T2;k++){
				if (tab1[j]==tab2[k]){
					tab3[c]=tab2[k];
					c++;
					}
				}
			}
		
		printf("L intersection des deux tableaux est: \n");
		for (j=0;j<c;j++){
		        printf("tab3[%2d] = %d \n",j, tab3[j]);
		}

		break;}		

	case 6: 
		{int i, j, c=0;
		bool element_a_inserer;

		for (j=0;j<T2;j++){
                        printf("Quelle valeur pour la case %d du tableau 2: \n ",j);
                        scanf("%d",&tab2[j]);
                }

                for (i=0;i<T1;i++){
			element_a_inserer = true;
			for (j=0 ; j<T2 ; j++) {
				if (tab1[i] == tab2[j]) {
					element_a_inserer = false;
					break;
				}
			}
			if (element_a_inserer) {
				tab[c] = tab1[i];
				c++;
			}
		}
                for (i=0;i<T2;i++){
			element_a_inserer = true;
			for (j=0 ; j<T1 ; j++) {
				if (tab2[i] == tab1[j]) {
					element_a_inserer = false;
					break;
				}
			}
			if (element_a_inserer) {
				tab[c] = tab2[i];
				c++;
			}
		}

		printf("La difference des deux tableaux est: \n");
                for (j=0;j<c;j++){
                        printf("tab[%2d] = %d \n",j, tab[j]);
                }

		break;}

	case 7:
		{int n, m, i, j, k, c, l;

		printf("Combien d elements voulez vous rentrer?\n");
		scanf("%d", &n);

		printf("A partir de quel indice voulez vous ajouter des elements? \n");
		scanf("%d", &m);

		if (m>T1) break;
		
		for (i=0;i<m;i++) {
			tab[i]=tab1[i];
			}
		
		for (k=m;k<m+n;k++){
			printf("Quel element?");
			scanf("%d", &l); 
			tab[k]=l;
			}

		for (c=m+n,j=m;c<T1,j<T1;c++,j++){
			tab[c]=tab1[j];
			}
		
		printf("Apres ajout: \n");
		for (i=0;i<T1+n;i++){
                        printf("tab[%2d] = %d \n",i, tab[i]);
                }

		break;}	

	case 8:
		{int m, i, k;
		
		printf("Combien d element(s) voulez vous supprimer? \n");
		scanf("%d", &m);

		printf("A partir de quel indice? \n");
		scanf("%d", &i);
		
		if ((m>T1-i) || (i>T1)) break;
		
		for (k=0;k<i;k++) {
			tab[k]=tab1[k];
			}
		
		for (k=i+m;k<T1;k++){
			tab[i]=tab1[k];
			i++;
			}

		printf("Apres suppression: \n");		
		for (k=0;k<T1-m;k++){
                        printf("tab[%2d] = %d \n",k, tab[k]);
                }

		break;}

	case 9:
		{int m, l, c=0;

		printf("Quel(s) element(s) voulez vous supprimer? \n");
		scanf("%d", &m);

		for (l=0;l<T1;l++){
			if (tab1[l]!=m){
				tab[c]=tab1[l];
				c++;
				}
		}

		printf("Apres suppression: \n");			
		for (l=0;l<c;l++){
                        printf("tab[%2d] = %d \n",l, tab[l]);
                }

                break;}
                
	case 10:
		{int i, j, k, l, m=0;

		printf("De quel indice à quel indice voulez vous extraire la liste?");
		scanf("%d%d", &i, &j);
		
		if ((i>T1-1) || (j>T1-1)) break;
		
		for (k=i;k<=j;k++){
			tab[m]=tab1[k];
			m++;
			}

		printf("La liste extraite est: \n");	
		for (l=0;l<m;l++){
                        printf("tab[%2d] = %d \n",l, tab[l]);
                }
			
		break;}
		
	case 11:
		{int i, j, m;
		
		for(i=1;i<T1;i++){
			j=i;
			while ((j>0) && (tab1[j]<tab1[j-1])){
				m=tab1[j];
				tab1[j]=tab1[j-1];
				tab1[j-1]=m;
				j--;
			}
		} 

		printf("Le tableau trie est: \n");	
		for (i=0;i<T1;i++) printf("tab1[%2d] = %d \n",i, tab1[i]);
		
		break;}

	case 0:    
		{FILE* fichier = NULL;
		char chaine[T]="";
            
		fichier = fopen("tableau.txt", "r");

		if (fichier != NULL){
			while (fgets(chaine, T, fichier) != NULL){
				printf("La liste stockée dans le fichier est : \n");
				printf("%s", chaine);
			}

			fclose(fichier);
		}
		else printf("Impossible d'ouvrir le fichier tableau.txt");

		break;}

	default :
		printf("Recommencez");
		break;
	}
}

