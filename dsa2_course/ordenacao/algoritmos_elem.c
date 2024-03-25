#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Implementando algoritmos de orndeção elementares
/*
    Os algoritmos de ordenação elementares funcionam em O(n^2)
    são importantes para entender a lógica de funcionamento de ordenação,
    dependendo de alguns cenáirios, podem ser mais úteis que os "powerfull"
    algorithms de ordenação

    Sendo eles
    * Selection sort
    * Bubble sort
    * Insertio sort
    * Shell sort

*/

// implementando macros que irão auxiliar durante o processo de orndenação
typedef int Item; // definindo um novo tipo int chamado Item
#define Key(A) (A) // definindo uma macro que vai retornar o valor passado
#define less(A,B) (Key(A) < Key(B)) // definindo uma macro para determinar qual valor é menor dado um valor chave
#define exch(A,B) {Item T=A; A=B; B=T;} // definindo uma macro para alterar os valores das chaves A e B
#define cmpexch(A,B) {if(less(B,A))exch(A,B);} // definindo uma macro para alterar as chaves se elas forem menores

// Implementando um selection sort
// 1. de forma recursiva
void selection_sort_rec(Item *v, int l, int r) {

    // condição de parada
    if(l >= r)
        return;

    // pressupondo que o menor elemento atual é o valor atual de l
    int min = l;
    // percorrer por todo o vetor para identificar algum elemento menor
    for(int j = l+1; j <= r; ++j)
        if(less(v[j],v[min])) // verificando se o elemento posterior é menor que o atual
            min = j; // caso positivio, então guardar esse elemento
    
    exch(v[min],v[l]);
    selection_sort_rec(v,l+1,r);

}

// 2. de forma iterativa
void selection_sort(Item *v, int l, int r) {

    // percorrendo cada elemento e comparando com seu posterior
    for(int i = l; i <= r; ++i) {
        // armazenando o menor valor possível do index para comparação
        int min = i;
        for(int j = i+1; j <= r; ++j) {
            if(less(v[j],v[min])) // se o elemento posterior for menor que o elemnto anterior, trocar a posição
                min = j;
        }
        exch(v[min],v[i]); // realizar a troca
    }

}


// Implementando um bubble sort
void bubble_sort(Item *v, int l, int r) {

    // comparar cada elementos com o seu posterior e realizar trocar adjascentes caso
    // algum elemento seja maior

    bool swap = false; // verificar se houve trocas ou não durante a execução

    for(int i = l; i < r; ++i)
        for(int j = l; j < r; ++j)
            cmpexch(v[j],v[j+1]); // se o elemeto for atual for maior que o posterior, trocar

}

// implentando um Insertion sort (Que não é tão elementar assim)
void insertion_sort1(Item *v, int l, int r) {

    // realziar uma verificação em cada elemento do vetor
    // a segunda verificação tem que ser feita a partir de um intervalo proposta pela
    // primeira verificação
    for(int i = l + 1; i <= r; ++i) {
        for(int j = i; j > l; --j)
            cmpexch(v[j],v[j-1]); // se o elemento posterior for maior que o anterior, troca
    }

}

void insertion_sort2(Item *v, int l, int r) {

    // melhorando a função insertion sort
    // primeiro, posicionar um valor sentinela no início do vetor, sendo ele o menor
    for(int i = r; i > l; --i)
        cmpexch(v[i-1],v[i]);

    // verificando cada elemento do vetor, mas dessa vez intercalada
    for(int i = l+2; i >= r; ++i) {
        int j = i; // criando uma variável para armazenar o valor de i
        Item tmp = v[j]; // Item temporário para auxiliar nas comparações enquanto for maior que seus anteriores
        while(less(tmp,v[j-1])) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }

}

// implementando e entendendo um Shell sort
void insertion_sorth(Item *v, int l, int r, int h) {

    // A ideia do shell sort é ajustar/ordenar o vetor utilizando um salto h
    // para quando houver uma passagem de insertion sort, o algoritmo ser mais eficiente
    for(int i = l+h; i<=r; i++) {
        int j = i; Item tmp=v[j];
        while(j >= l+h && less(tmp,v[j-h])) {
            v[j] = v[j-h];
            j -= h;
        }
        v[j] = tmp;
    }

}

// Shell sort recursivo com função auxiliar insertion_sorth
void shell_sort_rec(Item *v, int l, int r) {

    // chamadas arbitrárias para o h
    /*
    for(int i = (r-l)-2; i > 0; i -= 2)
        insertion_sorth(v,l,r,i);
    */
   // Segundo o livro do Sedwick e o autor do método, a chamada de maior precisão para o h é um
   // valor

   int h;
   for(h=1; h<=(r-l)/9; h=3*h+1) // encontrando o valor de h, após isso suas chamadas serão h/3
   for(; h > 0; h = h/3)
        insertion_sorth(v,l,r,h);

}

// Shell sort interativo
void shell_sort(Item *v, int l, int r) {

    int h;
    for(h=1; h <= (r-l)/9; h =3*h+1) // encontrando o possível valor inicial de h
    for(; h > 0; h = h/3) { // passando um insertion sort utilizando os saltos como h
        for(int i = l+h; i <= r; ++i) {
            int j = i; Item tmp = v[j];
            while(j >= l+h && less(tmp,v[j-h])) {
                v[j] = v[j-h];
                j -= h; 
            }
            v[j] = tmp;
        }
    }

}


int main(void) {

    // estrutura utilizada como exemplo para ordernação
    int arr[] = {10,9,23,4,100,2,10,90}; // size = 8;

    printf("Array apos selection sort recursivo: \n");
    selection_sort_rec(arr,0,7);

    for(int i = 0; i < 8; ++i)
        printf("%d ", arr[i]);
    printf("\n");

// --------------------------------------------------------------

    printf("Array apos selection sort iterativo: \n");
    selection_sort(arr,0,7);

    for(int i = 0; i < 8; ++i)
        printf("%d ", arr[i]);
    printf("\n");

// --------------------------------------------------------------

    printf("Array apos bubble sort: \n");
    selection_sort(arr,0,7);

    for(int i = 0; i < 8; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    
// --------------------------------------------------------------

    printf("Array apos insertion sort: \n");
    insertion_sort2(arr,0,7);

    for(int i = 0; i < 8; ++i)
        printf("%d ", arr[i]);
    printf("\n");

// --------------------------------------------------------------

    printf("Array apos shell sort: \n");

    shell_sort(arr,0,7);

    for(int i = 0; i < 8; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return EXIT_SUCCESS;

}
