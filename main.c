#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    char op;
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

            criaArvore(&t);

            case '2':
                exibirEmOrdem(t);
                printf("\n");
                exibirPosOrdem(t);
                printf("\n");
                exibirPreOrdem(t);
                printf("\n");
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

                free(t);
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
