#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// implementando uma lista encadeada em C (encaabeçada)
typedef struct Node {

    int data;
    struct Node *next;

} Node;

// Função para criar um novo node
Node *new_node(int data) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    return new;
}

// inserir elementos no final da lista
void insere_fim(Node **head, int data){

    // checando se a lista está vazia, caso contrário
    if(*(head) == NULL) {
        *head = new_node(data);
        return;
    }

    // encontrando o último elemento da lista atual
    Node *aux = *head;
    while(aux->next != NULL)
        aux = aux->next;
    
    // criando novo Node e adicionando ao final da lista
    Node *new = new_node(data);
    aux->next = new; 

}

// imprimir elementos da lista
// 1. interativa
void imprime(Node *head) {

    // Checando se a lista está vazia
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    // caso não esteja vazia, armazenando o valor da cabeça em uma 
    // variável auxiliar para impimir cada elemento
    Node *aux = head;
    while(aux != NULL) {
        printf("%d-->",aux->data);
        aux = aux->next;
    }
    printf("NULL\n"); // chegando ao final da lista

}

// 2. recursiva
void imprime_rec(Node *head) {

    // condição de parada
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    // impimindo cada elemento e chamando recusivamente o próximo
    printf("%d-->",head->data);
    imprime_rec(head->next);

}



int main(void) {

    // criando uma nova lista vazia
    Node *head = NULL;

    // adicionando elementos de 1-5 na lista
    for(int i = 1; i <= 5; ++i)
        insere_fim(&head,i);
    
    // impimindo lista atual
    imprime(head);
    imprime_rec(head);

}