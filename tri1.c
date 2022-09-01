#include <stdio.h>
#include <stdbool.h>
#define T1 3
#define T2 5
#define T3 (T1+T2)
#define T 30

void main(){
        int i, j, k, l, m, choix, cc=0, c=0, n, e=T1, tab1[T1], tab2[T2], tab3[T3], tab[T]; 
	bool bouge=true;

	for (i=0;i<T1;i++){
                printf("Quelle valeur pour la case %d du tableau 1: \n ",i);
                scanf("%d",&tab1[i]);
		}	

	printf("Que voulez-vous faire? 1. Afficher , 2. Cardinal, 3. Tri, 4. Union, 5. Intersection, 6. Difference, 7. Ajouter 8. Supprimer (valeur) \n");
	scanf("%d", &choix);

	switch(choix){
	
	case 1:
		for (i=0;i<T1;i++) printf("tab1[%2d] = %d \n",i, tab1[i]);
		break;

	case 2:
		for (i=0;i<T1;i++) c++;
		printf("Le cardinal de la liste est de : %d \n", c);
		break;

	case 3:
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
		for (i=0;i<T1;i++){
		        printf("tab1[%2d] = %d \n",i, tab1[i]);
		}
		break;
	
	case 4:
		for (j=0;j<T2;j++){
                	printf("Quelle valeur pour la case %d du tableau 2: \n ",j);
                	scanf("%d",&tab2[j]);
		}

		for (k=0;k<T1;k++){
			tab3[k]=tab1[k];
			}

		for (l=T1, m=0;l<T3, m<T2;l++, m++){
			tab3[l]=tab2[m];
			}

		for (i=0;i<T3;i++){
		        printf("tab3[%2d] = %d \n",i, tab3[i]);
		}
		break;

	case 5:
		for (j=0;j<T2;j++){
                	printf("Quelle valeur pour la case %d du tableau 2: \n ",j);
                	scanf("%d",&tab2[j]);
		}

		for (j=0;j<T3;j++){
			tab3[j]=0;
		}

		for (i=0;i<T1;i++){
			for (k=0;k<T2;k++){
				if (tab1[i]==tab2[k]){
					tab3[c]=tab2[k];
					c++;
					}
				}
			}
		
		for (l=0;l<c;l++){
		        printf("tab3[%2d] = %d \n",l, tab3[l]);
		}
		break;		

	case 6:
		for (j=0;j<T2;j++){
                        printf("Quelle valeur pour la case %d du tableau 2: \n ",j);
                        scanf("%d",&tab2[j]);
                }

                for (j=0;j<T3;j++){
                        tab[j]=0; 
                }

                for (i=0;i<T1;i++){
			m=0;
                        for (k=0;k<T2;k++){
                                if (tab1[i]!=tab2[k]) c++;
			}
			if (c == k){
				tab[m]=tab1[i];
				m++;
			} 
		}
		
                for (i=0;i<T2;i++){
                        for (k=0;k<T1;k++){
                                if (tab2[i]!=tab1[k]) cc++;
			}
			if (cc == k){
				tab[m]=tab2[i];
				m++;
			} 
		}		

                for (l=0;l<T3;l++){
                        printf("tab[%2d] = %d \n",l, tab[l]);
                }
		break;

	case 7:

		printf("Combien d elements voulez vous rentrer?\n");
		scanf("%d", &n);

		for (j=0;j<T1+n;j++){
			tab[j]=0;
                }
		
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
		
		 for (l=0;l<T1+n;l++){
                        printf("tab[%2d] = %d \n",l, tab[l]);
                }
		break;	

	case 8:
		printf("Combien d element(s) voulez vous supprimer? \n");
		scanf("%d", &m);

		printf("A partir de quel indice? \n");
		scanf("%d", &i);
		
		if ((m>T1-i+1) || (i>T1)) break;
		for (k=0;k<i;k++) {
			tab[k]=tab1[k];
			}
		
		
		break;

	default :
		printf("Recommence");
		break;
	}
}

