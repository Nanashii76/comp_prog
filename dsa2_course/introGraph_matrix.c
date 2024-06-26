// Introdução à grafos, principais funções e implementação com matrix de adjacência
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// Definindo algumas estruturas importantes para auxiliar na criação do Grafo
typedef struct {int v; int w;} Edge;

// Função para criar um par de arestas
Edge *edge(int x, int y) {

    Edge *ed = malloc(sizeof(Edge));
    ed->v = x;
    ed->w = y;
    
    return ed;
}

typedef struct Graph{
    int v, e;
    int **adj;

} graph;

// Criando um grafo e alocando uma matrix de forma dinâmica
graph *GraphInit(int v) {

    graph *g = malloc(sizeof(graph));
    g->v = v;
    g->e = 0;
    g->adj = malloc(sizeof(int*) *v);
    for(int i = 0; i < v; ++i) {
        g->adj[i] = malloc(sizeof(int)*v);
        g->adj[i] = 0;
    }

    return g;
}


// Implementando uma função para adicioanr arestas em um grafo já inicializado
void GraphInsertEd(graph *g, Edge e, int dir) {
    
    // Se não for um digrafo, então é bidirecional
    if((not dir) and (not g->adj[e.v][e.w])) {    
        g->adj[e.v][e.w] = 1;
        g->adj[e.w][e.v] = 1;
        g->e++;
    } else if(dir and (not g->adj[e.v][e.w])) {
        g->adj[e.v][e.w] = 1;
        g->e++;
    }
        
}

// Implementando uma função para remover uma aresta do grafo
void GraphRemoveEd(graph *g, Edge e, int dir) {

    // Se não for um digrafo, então é bidirecional
    if((not dir) and (g->adj[e.v][e.w])) {
        g->adj[e.v][e.w] = 0;
        g->adj[e.v][e.w] = 0;
        g->e--;
    } else if(dir and (g->adj[e.v][e.w])) {
        g->adj[e.v][e.w] = 0;
        g->e--;
    }

}

// Implemetando uma função para retornar um vetor de arestas presentes no grafo
int *GraphEdges(Edge e[], graph *g) {

    int idx = 0;
    for(int v = 0; v < g->v; ++v)
        for(int w = v+1; w < g->v; ++w)
            if(g->adj[v][w]) {
                e[idx++] = *edge(v,w);
            }

    return idx;
}