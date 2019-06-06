struct st_no{
    int vertice;
    struct no* prox;
};

typedef struct st_no no;

struct st_Grafo{
    int numVertices;
    struct no** listaAdj;
};

typedef struct st_Grafo Grafo;

/*FUNÇÃO PARA CRIAR OS NÓS*/

no* criaNo(int v){
    no* novoNo = malloc(sizeof(no));
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

/*FUNÇÃO PARA CRIAR O GRAFO*/

Grafo* criaGrafo(int v){
    Grafo* g = malloc(sizeof(Grafo));
    g->numVertices = v;

    g->listaAdj = malloc(v * sizeof(no*));

    int i;
    for(i = 0; i < v; i++){
        g->listaAdj[i] = NULL;
    }
    return g;
}

/*FUNÇÃO PARA ADICIONAR ARESTAS*/

void addAresta(Grafo* g, int vi, int vf){

    // adiciona aresta do vi para o vf
    no* novoNo = criaNo(vf);
    novoNo->prox = g->listaAdj[vi];
    g->listaAdj[vi] = novoNo;

    //adiciona aresta do vf para o vi
    novoNo = criaNo(vi);
    novoNo->prox = g->listaAdj[vf];
    g->listaAdj[vf] = novoNo;
}

/*FUNÇÃO PARA IMPRIMIR O GRAFO*/

void imprime(Grafo* g){

    int v;
    for(v = 0; v < g->numVertices; v++){
        no* aux = g->listaAdj[v];
        printf("\n Lista de Adjacencia do vertice %d\n ", v);
        while(aux){
            printf("%d -> ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
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
