/* Árvore Binária - Binary Tree

- São estruturas de dados caracterizadas por:

- ou, não tem elemento algum (árvore vazia);
- ou tem um elemento distinto, denominado raiz,
com dois apontamentos para duas estruturas diferentes,
denominadas sub-árove esquerda e sub-árvore direita.
- existe uma regra para adicionar valores na árvore,
se o valor novo for menor do que já existe na árvore é
criado um apontamento a esquerda caso contrário é criado
a direita. */

struct st_arvore{
    int valor;
    struct st_arvore *sad; //sub-árvore direita
    struct st_arvore *sae; //sub-árvore esquerda
};

typedef struct st_arvore arvore;

arvore* criaArvore(){ //na criação da árvore retorna um ponteiro nulo
    return NULL;
}

int arvoreEstaVazia(arvore* t){ //verifica se a árvore está vazia retornando nulo
    return t == NULL;
}

void mostraArvore(arvore* t){
    printf("<");//coloquei pra facilitar a visualização da árvore
    if(!arvoreEstaVazia(t)){
        printf("%d ", t->valor);// se não for vazia mostra o valor
        mostraArvore(t->sae);// mostra os galhos da árvore
        mostraArvore(t->sad);
    }
    printf(">");
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){// sendo nula ela não existe ainda
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->sae = NULL;// acessa o valor e aponta sae pra NULL
        (*t)->sad = NULL;
        (*t)->valor = num;// árvore recebe um valor
    }else{// se a árvore já tiver valores, seus galhos estarão vazios e adicionaremos os valores nos galhos
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->sae, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){ // busca em árvore binária
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->sae, num) || estaNaArvore(t->sad, num);
    //esse return verifica pros dois ramos da árvore se existe o valor.
}
