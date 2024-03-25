#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Macros
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lessequal(A,B) (Key(A) <= Key(B))
#define exch(A,B) {Item T=A;A=B;B=A;}
#define cmpexch(A,B) {if(lessequal(B,A))exch(A,B);}

/*
    Quick Select: retorna o respectivo valor que estara em um determinado indice k
    sem precisar ordenar completamente o vetor, pois o quick sort já garante
    que, a cada passagem, os valores dos pivores são sentinelas
*/
int partition(Item *v, int l, int r) {

    int piv = v[r]; int j = l;
    for(int i = l; i < r; ++i)
        if(lessequal(v[i],piv)) {
            exch(v[j],v[i]);
            j++;
        }
    exch(v[j],v[r]);

    return j;

}

void quick_select(Item *v, int l, int r, int k) {

    // condição de parada
    if(l >= r)
        return;

    // retorna o valor do pivor
    int i = partition(v,l,r);

    // como o quick sort garante que todos os elementos anteriores e posteriores
    // do vetor são respectivamente menores e maiores que ele
    // então podemos utilizar a mesma lógica da busca binária
    if(i > k) {
        quick_select(v,l,i-1,k);
    } 
    
    if (i < k) {
        quick_select(v,l,i+1,k);
    }

}