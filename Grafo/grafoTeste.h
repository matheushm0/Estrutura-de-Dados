typedef struct grafo Grafo;

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

/*FUNÇÃO PARA CRIAR O GRAFO: RECEBE O NÚMERO DE VERTICES QUE VÃO TER, QUANTIDADE MAXIMA DE ARESTAS E SE É PONDERADO OU NÃO*/
Grafo* criaGrafo(int nro_vertices, int grau_max, int eh_ponderado){

     Grafo *gr = (Grafo*)malloc(sizeof(struct grafo));
     if(gr != NULL){

        int i;

        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)? 1:0;
        gr->grau = (int*)calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));

        for(i=0; i<nro_vertices; i++){
            gr->arestas[i] = (int**)malloc(grau_max*sizeof(int));
            if(gr -> eh_ponderado){
                gr->pesos = (float**)malloc(nro_vertices*sizeof(float*));

                for(i=0; i<nro_vertices;i++){
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
                }
            }
        }

     }
     return gr;
}

/*FUNÇÃO PARA INSERIR NO GRAFO*/

//digrafo é um grafo em que a origem é ligada ao destino e o destino é ligado a origem.
int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso){

    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

/*FUNÇÃO PARA REMOVER ARESTA*/

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){

    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;

    while(i <gr->grau[orig] && gr->arestas[orig][i]!=dest)
        i++;
    if(i == gr->grau[orig])//elemento não encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

/*FUNÇÃO PARA IMPRIMIR O GRAFO*/

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}


/*FUNÇÃO PARA EXCLUIR O GRAFO*/

void liberaGrafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i <gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

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
