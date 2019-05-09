/* Árvore Binária - Binary Tree
 *
 * São estruturas de dados caracterizadas por:
 * ou, não tem elemento algum (árvore vazia).
 *
 * ou tem um elemento distinto, denominado raiz,
 * com dois apontamentos para duas estruturas diferentes,
 * denominadas sub-árove esquerda e sub-árvore direita.
 *
 * existe uma regra para adifree(t);cionar valores na árvore,
 * se o valor novo for menor do que já existe na árvore é
 * criado um apontamento a esquerda caso contrário é criado
 * a direita.
 */

struct st_arvore{
    int valor;
    struct st_arvore *direita; //sub-árvore direita
    struct st_arvore *esquerda; //sub-árvore esquerda
};

typedef struct st_arvore arvore;

/*Na criação da árvore retorna um ponteiro nulo*/
arvore* criaArvore(){
    return NULL;
}

/*Verifica se a árvore está vazia retornando nulo*/
int arvoreEstaVazia(arvore* t){
    return t == NULL;
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){// sendo nula ela não existe ainda
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->esquerda = NULL;// acessa o valor e aponta esquerda pra NULL
        (*t)->direita = NULL;
        (*t)->valor = num;// árvore recebe um valor
    }else{// se a árvore já tiver valores, seus galhos estarão vazios e adicionaremos os valores nos galhos
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->esquerda, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->direita, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){ // busca em árvore binária
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->esquerda, num) || estaNaArvore(t->direita, num);
    //esse return verifica pros dois ramos da árvore se existe o valor.
}

/*--- O em ordem, busca o último à esquerda, depois volta até o nó onde ele terá
que ir à direita. Após isso ele busca o último à esquerda e volta....---*/
void exibirEmOrdem(arvore *pRaiz){//recebe o nó raiz, de novo aquela confusão com o nome da variável
	if(pRaiz != NULL){//verifica se o nó atual existe, pois ao ser chamado pRaiz->direita ou pRaiz->esquerda, sabemos que poderão ser nulos
            exibirEmOrdem(pRaiz->esquerda);//chamada recursiva para o próximo à esquerda, e será chamado até o último à esquerda.
            printf("\n%i", pRaiz->valor);//Ao chegar no último à esquerda, ou seja, for pRaiz->esquerda for NULL, ele começa a printar, e vai printando todos os nós por onde ele passou, "voltando"
            exibirEmOrdem(pRaiz->direita);//é chamado o nó a direita, seguindo o fluxo
	}
}

void exibirPreOrdem(arvore *pRaiz){//Pré-Ordem é mais simples, no nó que ele tá, ele já printa. Começa pela raiz e vai printando até o último a esquerda, depois volta pro nó onde ele terá que ir até a esquerda e volta denovo a buscar o último a esquerda e segue o fluxo.
    if(pRaiz != NULL){//mesmo teste anterior
        printf("\n%i", pRaiz->valor);//assim que está no nó, já faz o print
        exibirPreOrdem(pRaiz->esquerda);//faz a chamada recursiva pro nó a esquerda, perceba que o pRaiz->direita só é chamado quando passa por todos os nós a esquerda
        exibirPreOrdem(pRaiz->direita);//chamada recursiva para nó à direita
    }
}

void exibirPosOrdem(arvore *pRaiz){//Pós-ordem é o que eu acho mais complicado, mas não impossível de entender. A ideia basicamente é passar por toda a árvore, e só depois vir fazendo os prints. Ele busca o último a esquerda, depois volta pro nó que tiver que voltar e vai pra direita, sem printar nada, e busca de novo o último a esquerda, ate varrer toda a árvore, depois ele vai printando tudo.
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->valor);
    }
}
