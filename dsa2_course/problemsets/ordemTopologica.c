/*
    Imprimir a ordem topologia de um DAG
*/
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

typedef struct no {
    int v;
    struct no *next;
} no;

typedef struct grafo {
    no **adj;
    int n;
} grafo;

grafo *cria_grafo(int v) {
    grafo *g = malloc(sizeof(grafo));
    g->n = v;
    g->adj = malloc(sizeof(no) * v);

    for(int i = 0; i < v; ++i)
        g->adj[i] = NULL;

    return g;
}

no *cria_lista(no *list, int u) {
    no* novo = malloc(sizeof(no));
    novo->v = u;
    novo->next = list;
    return novo;
}

void cria_aresta(grafo *g, int u ,int v) {
    g->adj[u] = cria_lista(g->adj[u],v);
}

void dfs(grafo *g, int *vis, int v) {

    vis[v] = 1;
    for(no *adj = g->adj[v]; adj != NULL; adj = adj->next)
        if(not vis[adj->v])
            dfs(g, vis, adj->v);
    
    printf("%d ", v);
}

void ordenacao_topologica(grafo *g) {
    int *vis = calloc(g->n, sizeof(int));
    for(int v = 0; v < g->n; ++v)
        if(not vis[v])
            dfs(g,vis,v);

    free(vis);
    printf("\n");
}

int main(void) {
    int v,e; 
    scanf("%d %d", &v, &e);
    grafo *g = cria_grafo(v);

    while(e--) {
        int u, w;
        scanf("%d %d", &u, &w);
        cria_aresta(g,u,w);
    }

    ordenacao_topologica(g);
    return 0;
}