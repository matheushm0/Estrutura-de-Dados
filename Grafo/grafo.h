#define true 1
#define false 0
typedef int boll;
typedef int TIPOPESO;

typedef struct adjacencia{
    int vertice;  //Vetice Final
    TIPOPESO peso; //Peso ou Caminho
    struct adjacencia *prox;  //Proximo item
} ADJACENCIA;

typedef struct vertice{
ADJACENCIA *cab;  //Cabeça da lista ligada 1 -> "Num"
}VERTICE;

typedef struct grafo {
   int vertices; //São os pontinhos
   int arestas;    //São as arestas ou "caminhos" do grafo
   VERTICE *adj; //Ponteiro para um vetor de listas "Arrajo de vertices"
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

boll criaAresta(GRAFO *gr,int vi,int vf, TIPOPESO p){
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

/*void contarGrauEntrada(int v){}
void contarGrauSaida(int v){}
void contarGrauTotal(int v){}

void InserirVertice(){}
void RemoveVertice(){}

void InserirAresta(){}
void RemoverAresta(){}

void ImprimeGrafo(){}*/

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
