#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Defnindo macros para o auxílio das ordenações
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < key(B))
#define lessequal(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item T=A;A=B;B=T;}
#define cmpexch(A,B) {if(lessequal(B,A))exch(A,B);}


// Entendendo a lógica do merge sort
/*
    De forma semelhante ao quick, o merge sort divide seu vetor em pedaços menores para 
    auxiliar na ordenação

    porém, ao invés de buscar por um pivô, ordenamos de forma intervalar

*/
void merge(Item *v, int l, int r1, int r2) {

    // criando um novo vetor para auxiliar na ordenação
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    // variáveis auxiliares
    int k = 0; // posição inicial do novo vetor
    int i = l; // posição inicial do vetor v1
    int j = r1+1; // posição inicial do vetor v2

    // comparando cada elemento de ambos os vetores
    while(i <= r1 && j <= r2) {
        if(lessequal(v[i],v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }

    // pode ser que as cópias ainda não tenham terminado, então
    // copiar os elementos restantes para v2;
    while(i <= r1)
        v2[k++] = v[i++];
    
    while(j <= r2)
        v2[k++] = v[j++];
    
    // agora, copiar os elementos ordenados de v2 para v1;
    k = 0;
    for(int i = l; i <= r2; ++i)
        v[i] = v2[k++];

    free(v2); // liberando o espaço na memória
}

// implementando um merge sort
void merge_sort(Item *v, int l, int r){

    // Condição de parada (quando o vetor já estiver ordenado)
    if(l >= r)
        return;

    int mid = (r+l)/2; // intervalo para ordenação

    merge_sort(v,l,mid); // ordena os elementos do início ao meio
    merge_sort(v,mid+1,r); // ordena os elementos do meio ao fim
    merge(v,l,mid,r); // ordena o vetor por completo

}