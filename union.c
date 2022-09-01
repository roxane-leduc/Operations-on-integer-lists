#include <stdio.h>
#define T1 5
#define T2 7

int main(){
	int i=1, j=1, k=1, l, m, n, t1[T1], t2[T2], t3[T1+T2] ;

	for (m=0;m<T1;m++){
                printf("Quelle valeur pour la case %d du tableau: \n ",m);
                scanf("%d",&t1[m]);
        }
	for (n=0;n<T2;n++){
                printf("Quelle valeur pour la case %d du tableau: \n ",n);
                scanf("%d",&t2[n]);
        }

	while ((i<=T1) && (j<=T2)){
		if (t1[i]<=t2[j]){
			t3[k]=t1[i];
			i++;
			k++;
			}
		else {
			t3[k]=t2[j]; 
			j++;
			k++;
			}
	}

	if (i>T1){
		for(i=j;i<T2;i++){
			t3[k]=t2[i];
			k++;}
	}
	else {
		for(j=i;j<T1;j++){
		t3[k]=t1[j];
		k++;
		}
	}

	for (l=0;l<T1+T2;l++){
                printf("%d ",t3[l]);
        }
}

