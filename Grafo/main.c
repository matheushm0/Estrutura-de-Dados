#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    char op, op2, op3;
    int num, vi, vf, p;
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
            	printf("\n  Digite o tamanho do grafo: ");

            	scanf("%i", &num);
            	gr = criaGrafo(num);
            	fflush(stdin);

            	printf("\n  Grafo criado com sucesso!\n");
            	break;

            case '2':

                printf("\n  Digite o v%crtice inicial: ", 130);
                scanf("%i",&vi);
                fflush(stdin);

                printf("\n  Digite o v%crtice final: ", 130);
                scanf("%i",&vf);
                fflush(stdin);

                printf("\n  Digite o peso: ");
                scanf("%i",&p);
                fflush(stdin);

                criaAresta(gr, vi, vf, p);

                /*criaAresta(gr,0,1,2);
                criaAresta(gr,1,2,4);
                criaAresta(gr,2,0,12);
                criaAresta(gr,2,4,40);
                criaAresta(gr,3,1,3);
                criaAresta(gr,4,3,8);*/
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
