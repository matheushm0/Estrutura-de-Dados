#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    char op,op2;
    int num;
    arvore* t;

    while(1){
        printf("\n********************************\n");
        printf("*        %cRVORE BIN%cRIA        *\n",181,181);
        printf("********************************\n");

    	op = menu_principal();
    	printf("\n\n");

        if(op == '0') {
            break;
        }

        switch(op)
        {

            case '1':
            t = criaArvore();
            //criaArvore(&t);
            break;

            case '2':
			    while(1){
			        printf("\n********************************\n");
			        printf("*        %cRVORE BIN%cRIA        *\n",181,181);
			        printf("********************************\n");

			    	op2 = sub_menu();
			    	printf("\n\n");

			        if(op2 == '0') {
			        	system("cls");
			            break;
			        }

			        switch(op2){
						case '1':
							system("cls");
							printf("%cRVORE EM ORDEM:\n",181);
							exibirEmOrdem(t);
							printf("\n");
							break;

						case '2':
							exibirPreOrdem(t);
							break;

						case '3':
							exibirPosOrdem(t);
							break;

						default:
                			printf("\n  Opcao Invalida\n\n");
					}
				}
				break;

            case '3':
                printf("  Digite um numero: ");
                scanf("%i",&num);
                fflush(stdin);

                if(estaNaArvore(t, num)){
                    printf("\n  O elemento %i pertence a arvore!\n",num);
                }else{
                    printf("\n  O elemento %i nao pertence a arvore!\n",num);
                }
                break;

            case '4':
                printf("  Digite um numero: ");
                scanf("%i",&num);
                fflush(stdin);

                insereDadoArvore(&t, num);
                break;

            case '5':

            	printf("  Digite um numero: ");
				scanf("%i",&num);
				fflush(stdin);


				remover(&t, num);
				break;

			case '6':

                apagaArvore(t);
                printf("\n %crvore deletada ", 181);
                break;

            case '7':

                printf("Quantidade de N%cs: %d\n",162,contarNos(&t));
                break;

            case '8':
                //Pelo oq eu entendi, quantidade de folhas é a quantidade de elementos na arvóre q apontam pra dois outros elementos
                //digamos que fechando um conjunto de um número apontando pra outros dois
                printf("Quandtidade de folhas: %d\n", contarFolhas(&t));
                break;

            case '9':

                printf("Altura: %d\n", altura(&t));
                break;

            default:
                printf("\n  Opcao Invalida\n\n");

        }
    }

    free(t);

    return 0;
}


// FUNÇÃO PRA REMOVER UM NÚMERO DA ÁRVORE

/*printf("  Digite um numero: ");
scanf("%i",&num);
fflush(stdin);


remover(&t, num);
break;*/

// REMOVER MENOR NÓ DA ESQUERDA
/*MenorEsquerda(&t);*/

// REMOVER MAIOR NÓ DA DIREITA
/*MaiorDireita(&t);*/

//FUNÇÕES PARA MOSTRAR ALTURA DA ÁRVORE, QNTD DE NÓS E FOLHAS
/*
printf("Altura: %d\n", altura(&t));
//Pelo oq eu entendi, quantidade de folhas é a quantidade de elementos na arvóre q apontam pra dois outros elementos
//digamos que fechando um conjunto de um número apontando pra outros dois
printf("Quandtidade de folhas: %d\n", contarFolhas(&t));
printf("Quantidade de N%cs: %d\n",162,contarNos(&t));
*/
