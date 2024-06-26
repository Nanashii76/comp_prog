#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

// // Implementando um grafo com matriz de adjacência
// typedef struct grafo {
//     int **adj;
//     int v;
// } grafo;

// // criando um grafo
// grafo *cria_grafo(int n) {
//     grafo *g = malloc(sizeof(grafo));
//     g->v = n;
//     g->adj = malloc(sizeof(int) * n);

//     for(int i = 0; i < n; ++i) {
//         g->adj[i] = malloc(sizeof(int) * n);
//         for(int j = 0; j < n; ++j)
//             g->adj[i][j] = 0;
//     }

//     return g;
// }

// // destruindo um grafo
// void destroi_grafo(grafo *g) {
//     for(int i = 0; i < g->v; ++i)
//         free(g->adj[i]);
//     free(g->adj);
//     free(g);
// }

// // grau do vértice
// int grau(grafo *g, int v) {
//     int grau = 0;
//     for(int u = 0; u < g->v; ++u)
//         if(g->adj[v][u])
//             ++grau;
//     return grau;
// }

// // imprimindo recomendações
// void imprime_recomendacao(grafo *g, int v) {
//     for(int u = 0; u < g->v; ++u) {
//         if(g->adj[v][u])
//             for(int w = 0; w < g->v; ++w)
//                 if(g->adj[u][w] and w != v and (not g->adj[v][w]))
//                     printf("%d ", w);
//     }

//     printf("\n");
// }

// Implementando grafos com lista de adjâcência
typedef struct no {
    int v;
    struct no *next;
} no;

typedef struct grafo {
    no **adj;
    int v;
} grafo;


// criando um grafo / inicializando um grafo
grafo *cria_grafo(int n) {
    grafo *g = malloc(sizeof(grafo));
    g->v = n;
    g->adj = malloc(sizeof(no) * n);
    
    for(int i = 0; i <n; ++i) 
        g->adj[i] = NULL;

    return g;
}

// inserir no início da lista de um no adjâscente
no *insere_list(no *list, int v) {
    no *novo = malloc(sizeof(no));
    novo->v = v;
    novo->next = list;
    return novo;
}

// inserindo uma aresta em um grafo não direcionado
void insere_aresta(grafo *g, int v, int u) {
    g->adj[v] = insere_list(g->adj[v],u);
    g->adj[u] = insere_list(g->adj[u],v);
} 

// imprimindo um grafo
void imprime_grafo(grafo *g) {
    for(int v = 0; v < g->v; ++v) {
        no *adj = g->adj[v];
        printf("%d -> ", v);
        while(adj) {
            printf("%d ", adj->v);
            adj = adj->next;
        }
        printf("\n");
    }
}


int main(void) {
    return 0;
}
