#include <stdio.h>
int main(){

	int vetor[100] = {0};
	int aux = 0;
	int countPar = 0;
	int countImpar = 0;
	int countImparMaior = 0;
	int mediaImpar = 0;

	for(int i = 0; i < 5; i++){
		scanf("%d", &aux);
		if(aux < 256){
			vetor[i] = aux;
		}
		
		if(aux%2 == 1){
			countImpar++;
		}

		if(aux%2 == 0){
			countPar++;
		}
	
		if((aux%2 == 1) && (aux > 50)){
			mediaImpar += aux;
			countImparMaior++;
		}
	}

	printf("Quantidade de PARES: %d\n", countPar);
	printf("Quantidade de IMPARES: %d\n", countImpar);
	printf("Media dos Impares maiores que 50: %d\n", (int)(mediaImpar/countImparMaior));
	return 0;
}