#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "novoGrafo.h"

int main(){
    char op, op2, op3;
    int num, vi, vf, i, d, p;
    Grafo *gr;
    GRAFO *grp;

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
            	/*system("cls");
            	printf("\n  Digite o tamanho do grafo: ");

            	scanf("%i", &num);
            	gr = criaGrafo(num);
            	fflush(stdin);

            	printf("\n  Grafo criado com sucesso!\n");*/

            	gr = criaGrafo(6);

            	break;

            case '2':

                /*printf("\n  Digite o v%crtice inicial: ", 130);
                scanf("%i",&vi);
                fflush(stdin);

                printf("\n  Digite o v%crtice final: ", 130);
                scanf("%i",&vf);
                fflush(stdin);

                addAresta(gr, vi, vf);*/
                addAresta(gr, 0, 1);
                addAresta(gr, 0, 2);
                addAresta(gr, 1, 2);
                addAresta(gr, 1, 4);
                addAresta(gr, 1, 3);
                addAresta(gr, 2, 4);
                addAresta(gr, 3, 4);

                break;

            case '3':

                imprime(gr);

				break;

            case '4':

                DFS(gr, 0);

				break;

            case '5':

                BFS(gr, 0);

                break;

            case '6':

                excluiGrafo(gr);
                printf("\n  Grafo excluido com sucesso!");

                /*Deseja recriar o grafo 1 pra sim e 2 pra sair do programa*/

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
