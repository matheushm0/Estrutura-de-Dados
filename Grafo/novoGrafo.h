#define TAM 40

struct no{
    int vertice;
    struct no* prox;
};

typedef struct no no;

struct Grafo{
    int numVertices;
    int* visitado;
    struct no** listaAdj;//precisa de ponteiro de ponteiro pra salvar em um vetor bidimensional, com isso a gente cria um vetor de lista ligada.
};

typedef struct Grafo Grafo;

/*FUNÇÃO PARA CRIAR OS NÓS*/

struct no* criaNo(int v){
    struct no* novoNo = malloc(sizeof(struct no));
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

/*FUNÇÃO PARA CRIAR O GRAFO*/

struct Grafo* criaGrafo(int v){
   struct Grafo* g = malloc(sizeof(struct Grafo));
    g->numVertices = v;

    g->listaAdj = malloc(v * sizeof(struct no*));

    g->visitado = malloc(v * sizeof(int));

    int i;
    for(i = 0; i < v; i++){
        g->listaAdj[i] = NULL;
        g->visitado[i] = 0;
    }
    return g;
}

/*FUNÇÃO PARA ADICIONAR ARESTAS*/

void addAresta(struct Grafo* g, int vi, int vf){

    // adiciona aresta do vi para o vf
    struct no* novoNo = criaNo(vf);
    novoNo->prox = g->listaAdj[vi];
    g->listaAdj[vi] = novoNo;

    //adiciona aresta do vf para o vi
    novoNo = criaNo(vi);
    novoNo->prox = g->listaAdj[vf];
    g->listaAdj[vf] = novoNo;
}

/*FUNÇÃO PARA IMPRIMIR O GRAFO*/

void imprime(struct Grafo* g){

    int v;
    for(v = 0; v < g->numVertices; v++){
        struct no* aux = g->listaAdj[v];
        printf("\n Lista de Adjacencia do vertice %d\n ", v);
        while(aux){
            printf("%d -> ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
    }
}

/*BUSCA EM PROFUNDIDADE (DFS)*/

void DFS(Grafo* g, int v){
    struct no* listaAdj = g->listaAdj[v];
    struct no* aux = listaAdj;

    g->visitado[v] = 1;
    printf("  Visitado %d \n", v);

    while(aux!=NULL){

        int vConectado = aux->vertice;

        if(g->visitado[vConectado] == 0){
            DFS(g, vConectado);
        }
        aux = aux->prox;
    }
}

/*BUSCA EM LARGURA (BFS)*/

struct fila{
    int itens[TAM];
    int frente;
    int atras;
};

struct fila* criaFila() {
    struct fila* f = malloc(sizeof(struct fila));
    f->frente = -1;
    f->atras = -1;
    return f;
}


int estaVazia(struct fila* f) {
    if(f->atras == -1)
        return 1;
    else
        return 0;
}

void enfila(struct fila* f, int v){
    if(f->atras == TAM-1)
        printf("\nFila esta cheia!!");
    else {
        if(f->frente == -1)
            f->frente = 0;
        f->atras++;
        f->itens[f->atras] = v;
    }
}

int defila(struct fila* f){
    int item;
    if(estaVazia(f)){
        printf("  Fila esta vazia");
        item = -1;
    }
    else{
        item = f->itens[f->frente];
        f->frente++;
        if(f->frente > f->atras){
            printf("Redefinindo fila ");
            f->frente = f->atras = -1;
        }
    }
    return item;
}

void imprimeFila(struct fila* f) {
    int i = f->frente;

    if(estaVazia(f)) {
        printf("  Fila esta vazia");
    } else {
        printf("\n  Fila contem \n");
        for(i = f->frente; i < f->atras + 1; i++) {
                printf("  %d ", f->itens[i]);
        }
    }
}

void BFS(Grafo* g, int vInicial) {

    struct fila* f = criaFila();

    g->visitado[vInicial] = 1;
    enfila(f, vInicial);

    while(!estaVazia(f)){
        imprimeFila(f);
        int vAtual = defila(f);
        printf("Visitado %d\n", vAtual);

       struct no* aux = g->listaAdj[vAtual];

       while(aux) {
            int verticeAdj = aux->vertice;

            if(g->visitado[verticeAdj] == 0){
                g->visitado[verticeAdj] = 1;
                enfila(f, verticeAdj);
            }
            aux = aux->prox;
       }
    }
}

/*MENU*/

char menu_principal()
{
    printf("  1 - Criar grafo\n");
    printf("  2 - Inserir no grafo\n");
    printf("  3 - Listar grafo\n");
    printf("  4 - Excluir itens do grafo\n");
    printf("  5 - Pesquisar no grafo\n");
    printf("  6 - Contar vertices\n");
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}
