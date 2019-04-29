#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

    arvore* t = criaArvore();

    insereDadoArvore(&t, 12);
    insereDadoArvore(&t, 15);
    insereDadoArvore(&t, 10);
    insereDadoArvore(&t, 13);

    mostraArvore(t);

    if(arvoreEstaVazia(t)){
        printf("\n\nArvore vazia!!\n");
    }else{
        printf("\n\nArvore nao vazia!!\n");
    }

    if(estaNaArvore(t, 15)){
        printf("\nO elemento 15 pertence a arvore!\n");
    }else{
        printf("\nO elemento 15 nao pertence a arvore!\n");
    }

    if(estaNaArvore(t, 22)){
        printf("\nO elemento 22 pertence a arvore!\n");
    }else{
        printf("\nO elemento 22 nao pertence a arvore!\n");
    }

    free(t);

    return 0;
}
