#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    char op, op2, op3;
    int num;
    GRAFO *gr;

    while(1){
        printf("\n********************************\n");
        printf("*             GRAFO            *\n");
        printf("********************************\n");

    	op = menu_principal();
    	printf("\n\n");

        if(op == '0') {
            break;
        }

        switch(op)
        {
            case '1':
            	system("cls");
            	printf("\n  Grafo criado com sucesso!\n",181);
            	gr = criaGrafo(5);
            	break;

            case '2':
                criaAresta(gr,0,1,2);
                criaAresta(gr,1,2,4);
                criaAresta(gr,2,0,12);
                criaAresta(gr,2,4,40);
                criaAresta(gr,3,1,3);
                criaAresta(gr,4,3,8);
                break;

            case '3':
                imprime(gr);
				break;

            case '4':
				break;

            case '5':
                break;

            case '6':
                break;

            case '7':
                break;

            case '8':
                break;

			case '9':
                break;

            default:
                system("cls");
                printf("\n  Opcao Invalida\n");
        }
    }

    free(gr);

    return 0;
}
