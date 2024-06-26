/*
Problema: Componentes Conectados em um Grafo

Descrição:

Você deve implementar um programa em C que encontre e liste todos os componentes conectados de um grafo não direcionado.

Entrada:

    O número de vértices V no grafo.
    O número de arestas E no grafo.
    As próximas E linhas contêm dois inteiros u e v representando uma aresta entre o vértice u e o vértice v.

Saída:

    O número de componentes conectados no grafo.
    Para cada componente conectado, liste os vértices pertencentes a esse componente.

Exemplo de Entrada:

6
5
0 1
0 2
1 2
3 4
4 5

Exemplo de Saída:

Número de componentes conectados: 2
Componente 1: 0 1 2
Componente 2: 3 4 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// Definição das estruturas de dados para o grafo
typedef struct no {
    int v;
    struct no* next;
} no;

typedef struct grafo {
    no **adj;
    int n;
} grafo;

// Função para criar um novo grafo
grafo *cria_grafo(int v) {
    grafo *g = malloc(sizeof(grafo));
    g->n = v;
    g->adj = malloc(v * sizeof(no*));

    for(int i = 0; i < v; ++i)
        g->adj[i] = NULL;

    return g;
}

// Função para inserir um novo nó na lista de adjacência
no *insere_list(no *list, int u) {
    no *novo = malloc(sizeof(no));
    novo->v = u;
    novo->next = list;
    return novo;
}

// Função para inserir uma aresta no grafo
void insere_aresta(grafo *g, int u, int v) {
    g->adj[u] = insere_list(g->adj[u], v);
    g->adj[v] = insere_list(g->adj[v], u);
}

// Função de busca em profundidade (DFS) para encontrar componentes conectados
void dfs(grafo *g, int v, int *vis, int *comp, int count) {
    vis[v] = 1;
    comp[v] = count;
    no *adj = g->adj[v];
    while(adj) {
        if (not vis[adj->v]) {
            dfs(g, adj->v, vis, comp, count);
        }
        adj = adj->next;
    }
}

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    grafo *G = cria_grafo(v);
    int *vis = calloc(v, sizeof(int));
    int *components = calloc(v, sizeof(int));
    int count = 0;

    // Lendo as arestas
    for (int i = 0; i < e; ++i) {
        int u, w;
        scanf("%d %d", &u, &w);
        insere_aresta(G, u, w);
    }

    // Encontrando componentes conectados
    for (int i = 0; i < v; ++i) {
        if (not vis[i]) {
            dfs(G, i, vis, components, count);
            ++count;
        }
    }

    // Imprimindo os resultados
    printf("Numero de componentes conectados: %d\n", count);
    for (int a = 0; a < count; ++a) {
        printf("Componente %d: ", a + 1);
        for (int i = 0; i < v; ++i) {
            if (components[i] == a) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
