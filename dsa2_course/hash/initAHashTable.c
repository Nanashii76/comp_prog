#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// definindo uma struct do tipo Item que armazena determinados dados
typedef struct Item {

    int chave;
    long e1,e2;
    long elemento;

} Item; Item NULLITEM = {0,0,0,0}; // NULLITEM para comparação na inicialização

// definindo algumas macros importantes para manipulação de hash table
#define key(x) (x.chave)
#define less(a,b) (key(a) < key(b))
#define null(A) (Key(ht[A])==key(NULLITEM))


// inicilizando variáveis e funções
static int N,M;
static Item *ht;

void HTinit(int max){

    int i;
    N = 0, M = 2*max;
    ht = malloc(sizeof(Item)*(M));

    for(i = 0; i < M; ++i)
        ht[i] = NULLITEM;
}

int HTcount(){return N;}

void HTinsert(Item item) {

    int v = key(item);
    int i = hash(v,M);

    while(!null(i)) 
        (i+1)%M;
    
    ht[i] = item;
    N++;
}

Item HTsearch(int v){

    int i = hash(v,M);
    while(!null(i))
        if(v == key(ht[i]))
            return ht[i];
        else
            i = (i+1)%M;

    return NULLITEM;

}

