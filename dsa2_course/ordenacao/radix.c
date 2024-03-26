#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Implementando um radix sort e entendendo seu funcionamento
/*
    É uma solução para alocação de memória do count sort, visto que
    o problema do count é que ele aloca um novo vetor de contagem
    com o tamanho do maior elemento do vetor original.

    verificar base por base (dado algum sistema númerico), quais
    são os menores valores e ir ordenando conforma essa ordem
*/

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lessequal(A,B) (Key(A) <= Key(B))
#define exch(A,B) {Item T=A;A=B;B=T;}

#define digit(A,m) ((A/m) % 10) // criando uma macro para pegar cada mascara numérica decimal

// o Radix é uma forma de acelerar o count sort, porém com umas alterações
void countsort(Item *v, int l, int r, int mask) {
    
    int maior = 0;
    for (int i = l; i <= r; ++i)
        if (less(maior, digit(v[i], mask)))
            maior = digit(v[i], mask); // fazemos a comparação com cada máscara de elemento e não o elemento em si
    
    // criando um vetor para realizar as contagens    
    Item *count = calloc(maior + 1, sizeof(Item));

    // armazenando cada valor contado em uma posição posterior
    for (int i = l; i <= r; ++i)
        count[digit(v[i], mask)]++;

    // somando cada elemento com seu anteriror para definir sua posição atual na ordenação
    for (int i = 1; i <= maior; ++i)
        count[i] += count[i - 1];
    
    // criando um vetor auxiliar para ajudar na ordenação
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    for (int i = r; i >= l; --i) {
        aux[count[digit(v[i], mask)] - 1] = v[i];
        count[digit(v[i], mask)]--;
    }

    // copiando o vetor ordenado para o vetor original
    for (int i = l; i <= r; ++i)
        v[i] = aux[i - l]; // realizando ajuste de index do vetor auxiliar

    // liberando espaço na memória
    free(aux);
    free(count);
}

// a implementação do radix chama de forma recursiva o vetor, passando então a quantidade de vezes referenta ao valor da base da máscara
void radixsort(Item *v, int l, int r) {

    // pegando o maior elemento para servir de base para a máscara

    int maior = 0;
    for (int i = l; i <= r; ++i)
        if (less(maior, v[i]))
            maior = v[i];

    // teremos certeza que o vetor estará ordenado assim que ele ordenar todos os elementos do maior elemento do vetor
    int mask = 1;
    while (maior / mask) {
        countsort(v, l, r, mask);
        mask *= 10;
    }
}

int main(void) {
    Item arr[] = {1, 6, 2, 1, 6, 2, 1, 1, 2};
    int size = 9;
    
    radixsort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

