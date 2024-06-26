/*
Problema: Distância Mínima em um Grafo Não Ponderado

Descrição:

Você deve implementar um programa em C que encontre a distância mínima (em número de arestas) entre dois vértices em um grafo não direcionado e não ponderado.

Entrada:

    O número de vértices V no grafo.
    O número de arestas E no grafo.
    As próximas E linhas contêm dois inteiros u e v representando uma aresta entre o vértice u e o vértice v.
    Dois inteiros src e dest representando o vértice de origem e o vértice de destino, respectivamente.

Saída:

    A distância mínima (em número de arestas) entre src e dest.
    Se src e dest não estiverem conectados, imprima -1.

Exemplo de Entrada:

6
7
0 1
0 2
1 2
1 3
2 3
3 4
4 5
0 5

Exemplo de Saída:

4

Detalhes da Implementação:

    Use uma representação de lista de adjacência para armazenar o grafo.
    Use uma função BFS para encontrar a distância mínima entre os dois vértices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// Estrutura de dados para a fila
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para criar um novo nó na fila
QueueNode* newQueueNode(int data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Função para adicionar um elemento à fila
void enqueue(Queue* q, int data) {
    QueueNode* temp = newQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Função para remover um elemento da fila
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;  // Fila vazia
    }
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Implementando um grafo com lista de adjacência
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
    no *novo = malloc(sizeof(no));
    novo->v = u;
    novo->next = list;
    return novo;
}

void cria_aresta(grafo *g, int u, int v) {
    g->adj[u] = cria_lista(g->adj[u], v);
    g->adj[v] = cria_lista(g->adj[v], u);
}

void bfs(grafo *g, int v, int *vis, int *dist){
    vis[v] = 1;
    dist[v] = 0;
    Queue *q = createQueue();
    enqueue(q,v);

    while(not isEmpty(q)) {
        int vertice = dequeue(q);
        no* adj = g->adj[vertice];
        while(adj) {
            if(not vis[adj->v]) {
                vis[adj->v] = 1;
                dist[adj->v] = dist[vertice] + 1;
                enqueue(q,adj->v);
            }
            adj = adj->next;
        }
    }
}


int main(void) {
    
    int v, e; 
    scanf("%d %d", &v, &e);

    grafo *g = cria_grafo(v);
    int *vis = calloc(v, sizeof(int));
    int *dist = calloc(v, sizeof(int));
   
    while(e--) {
        int u, v;
        scanf("%d %d", &u, &v);
        cria_aresta(g,u,v);
    }

    int x,y;
    scanf("%d %d", &x, &y);

    bfs(g,x,vis,dist);

    if (dist[y] == 0 and x != y) {
        printf("-1\n");  // Não conectado
    } else {
        printf("%d\n", dist[y]);
    }

    return 0;
}