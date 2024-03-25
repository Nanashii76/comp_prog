#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// definindo macros
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lessequal(A,B) (Key(A) <= Key(B))
#define exch(A,B) {Item T=A;A=B;B=T;}
#define cmpexch(A,B) {if(less(B,A))exch(A,B);}


// Entendendo o funcionamento do quick sort
/*
    Primeiro, definimos um pivor nos nossos elementos do vetor
    após escolher esse pivor, criamos dois novos vetores, um que conterá
    elementos menores que esse pivor e outro que conterá elementos maiores

    o quick sort se baseia no método de dividir e conquistar, então para separar
    esses elementos e retornar o vetor resultando, basta criar uma função de particionanamento
    
*/
// entendendo a lógica do particionamento
int partition_logic(Item *v, int l, int r) {
    int tam = (r-l)+1; // definindo o tamanho do vetor para a criação dos auxiliares
    Item piv = v[r];
    Item *menores = malloc(sizeof(Item)*tam);
    Item *maiores = malloc(sizeof(Item)*tam);

    // indices dos novos vetores
    int a,b;
    a = b = 0;

    // adicionando os seus respectivos elementos
    for(int i = l; i < r; ++i)
        if(lessequal(v[i],piv))
            menores[a++] = v[i];
        else
            maiores[b++] = v[i];

    // rearranjando cada elementos no vetor original
    int i = l;
    // primeiro, adicionando os menores
    for(int j = 0; j < a; ++j)
        v[i++] = menores[j];
    // posicionado o pivor na posição correta
    v[i] = piv;
    // criando uma variável para armazenar a posição do pivor
    int cpos = i;
    i++; // incrementando para não sobrescrever no pivor na próxima chamada
    //adicionando os maiores
    for(int j = 0; j < b; ++j)
        v[i++] = maiores[j];

    free(menores);
    free(maiores);

    // dessa forma, temos a garantia que o pivor está na posição correta
    return cpos; // retorna a posição do pivor

}

// implementando a função partition sem usar memória/recursos de memória adicionais
int partition(Item *v, int l, int r) {

    // meu pivô será o elemento mais a direita do vetor
    Item piv = v[r];
    int j = l; // variável auxiliar para realização das trocas
    for(int k = l; k < r; ++k)
        if(lessequal(v[k],piv)) // comparo se o elemento atual é menor ou igual ao pivô
            exch(v[k],v[j++]); // faço a troca com o primeiro elemento

    // posicionando o pivô
    exch(v[j],v[r]); // lembrando que nesse caso será sempre o último elemento

    // retornando o valor do pivô
    return j;

}

// implementando agora um quick sort de forma ingênua
void quick_sort1(Item *v, int l, int r) {

    // Condição de parada (quando o vetor já estiver ordenado)
    if(l >= r)
        return;

    // criando uma variável auxiliar para coletar o valor do pivor
    int j;
    j = partition(v,l,r);

    // após isso, basta ordenar os elementos à esquerda do pivor
    quick_sort1(v,l,j-1);
    // e ordernar os elementos à direita do vetor
    quick_sort1(v,j+1,r);

}
