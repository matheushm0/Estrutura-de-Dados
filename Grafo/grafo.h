#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

/* FUNÇÕES PARA CRIAR O GRAFO*/

typedef struct adjacencia{
    int vertice;  //Vetice Final
    TIPOPESO peso; //Peso ou Caminho
    struct adjacencia* prox;  //Proximo item
} ADJACENCIA;

typedef struct vertice{
    ADJACENCIA *cab;  //Cabeça da lista ligada 1 -> "Num"
}VERTICE;

typedef struct grafo {
   int vertices; //São os pontinhos
   int arestas;    //São as arestas ou "caminhos" do grafo
   VERTICE *adj;//Ponteiro para um vetor de listas "Arrajo de vertices"
}GRAFO;


GRAFO *criaGrafo(int v){
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));
    int i;
    for(i=0; i<v;i++)
        g->adj[i].cab = NULL;
    return(g);
}

ADJACENCIA *criaAdj(int v, int peso){
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

bool criaAresta(GRAFO *gr,int vi,int vf, TIPOPESO p){
    if(!gr) return(false);
    if((vf<0)||(vf>= gr->vertices))
        return(false);
    if((vi<0)||(vi>=gr->vertices))
        return(false);
    ADJACENCIA *novo = criaAdj(vf,p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;
    return(true);
}

void imprime(GRAFO *gr){
    printf("  Vertices: %d. Arestas: %d.\n", gr->vertices, gr->arestas);
    int i;
    for(i=0; i<gr->vertices; i++){
        printf("  v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while(ad){
            printf("  v%d(%d) ", ad->vertice,ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}

/*ALGORITMO DE DIJKSTRA*/

//O algoritmo de Dijkstra soluciona o problema
//do caminho mais curto num grafo dirigido
//ou nao dirigido, com arestas de peso não negativo
void inicializaD(GRAFO *g, int *d, int *p, int s){
    int v;
    for(v=0; v<g->vertices;v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

void relaxa(GRAFO *g, int *d, int *p, int u, int v){
    ADJACENCIA *ad = g->adj[u].cab;
    while(ad && ad->vertice != v)
        ad = ad->prox;
    if(ad){
        if(d[v]>d[u] + ad->peso){
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}

int *dijkstra(GRAFO *g, int s){
    int *d = (int *) malloc(g->vertices* sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializaD(g,d,p,s);

    int i;
    for(i=0;i<g->vertices;i++)
        aberto[i] = true;

    while(existeAberto(g,aberto)){
        int u = menorDist(g,aberto,d);
        aberto[u] = false;
        ADJACENCIA *ad = g->adj[u].cab;
        while(ad){
            relaxa(g,d,p,u,ad->vertice);
            ad = ad->prox;
        }
    }
    return(d);
}

//Varre o arranjo de abertos
//Se encontrar um true retorna true
//Ou seja que achou, se não retorna false
bool existeAberto(GRAFO *g, int *aberto){
    int i;
    for(i=0;i<g->vertices;i++)
        if(aberto[i]) return(true);
    return(false);
}

//Dentre todos os abertos necessita
//achar oque possui menor distância
int menorDist(GRAFO *g, int *aberto, int *d){
    int i;
    for(i=0; i<g->vertices; i++)
        if(aberto[i]) break;
    if(i==g->vertices) return(-1);
    int menor = i;
    for(i=menor+1; i<g->vertices;  i++)
        if(aberto[i] && (d[menor]>d[i]))
            menor = i;
        return(menor);
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

/*void contarGrauEntrada(int v){}
void contarGrauSaida(int v){}
void contarGrauTotal(int v){}

void InserirVertice(){}
void RemoveVertice(){}

void InserirAresta(){}
void RemoverAresta(){}

void ImprimeGrafo(){}*/
