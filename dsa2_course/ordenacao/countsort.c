#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// implementando um count sort e entendendo como funciona
/*
	É feito uma primeira passagem no vetor para identificar o maior
	valor, após isso, um novo vetor é criado recebendo como tamanho
	o maior elemento encontrado no vetor passado.

	apartir disso, contamos quantas vezes cada elemento aparece no vetor,
	adicionando então a quantidade de vezes no index posterior.

	após isso, realizar uma soma com os index passados e mais uma
	vez, passar pelo vetor para sim, criar um novo vetor ordenado

*/

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lessequal(A,B) (Key(A) <= Key(B))
#define exch(A,B) {Item T=A;A=B;B=T;}

void countsort(Item *v, int l, int r) {

	// descobrir qual o maior elemento do vetor
	int maior = v[l];
	for(int i = l+1; i<= r; ++i)
		if(less(maior,v[i]))
			maior = v[i];

	// apos encontrar o maior elemento, adicionar mais 2 a sua posição
	maior += 2;

	// alocar o vetor de contagem
	Item *count = calloc(maior,sizeof(Item));

	// percorrer o vetor original e preecher os valores do vetor
	// de contagem, somando ao seu index posterior
	for(int i = l; i <= r; ++i) {
		count[v[i]+1]++;
	}

	// adicionar a cada elemento do vetor de contagem, seu valor
	// posterior, para sabermos exatamente qual sua posição ordenada
	for(int i = l+1; i <= r; ++i)
		count[i] += count[i-1];

	// criar um vetor auxiliar para ordenar dados os valores de count
	Item *aux = malloc(sizeof(Item)*(r-l+1)); // possui o tamanho do vetor original
	
	// percorrer novamente o vetor original e comparar com o vetor de cotnagem
 	for(int i = l; i <= maior; ++i) {
		aux[count[v[i]]] = v[i];
		count[v[i]]++;
	}
	
	// copiar os elementos do vetor auxiliar para o original
	for(int i = l; i <= r; ++i)
		v[i] = aux[i-l];

	// liberar o espaço extra utilizado da memória
	free(aux);
	free(count);
}




int main (void) {

	Item arr[] = {1,6,2,1,6,2,1,1,2};
	int size = 9;
	
	countsort(arr,0,size-1);

	for(int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
