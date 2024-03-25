#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Revisão de ponteiros
// Memória
/*
    Stack - 7 mb; -> alocação estática
    Heap - limite da sua máquina; -> alocação dinâmica
    Segmento de dados - armazena variáveis globais


    int *a; -> recebe um endereço de memória, utilizamos o sinal *
    a = &x -> para referenciar uma outra variável, basta usar o sinal de &
    *a -> significa que estamos manipulando o endereço apontado por essa variável,
    podendo então alterar seus valores e etc.


    posso armazenar valores de variáveis maiores em variáveis menores
    já que as variáveis menores pegam determinado bits de valor

    int -> 4bytes
    short int  -> 2bytes

*/

int main(void) {

    // Somando valores de tamanhos menores a partir de tamanhos maiores
    int a,b; // cada variáveis int possui 4 bytes

    short int *c,*d,*e,*f; // cada variáveis do tipo short int possui 2 bytes

    // Alocando memória para os ponteiros
    c = (short int*)malloc(sizeof(short int));
    d = (short int*)malloc(sizeof(short int));
    e = (short int*)malloc(sizeof(short int));
    f = (short int*)malloc(sizeof(short int));

    *c = &a; *d = &c+1; // ou poderia dizer que *d = &c[1];
    *e = &b; *f = &e[1];
    
    *c = 3; *d = 2;
    *e = 5; *f = 4;

    a = a+b; // somando 4 números sucessivamente
    // os valores atuais de c e e são (8,6);

    // atribuindo valores para 'a' e 'b'
    a = *c + *e;
    b = *d + *f;

    // A forma de tratar cada um desses dados não está correta, é apeans para ter uma ideia
    // de como funciona

    return 0;

}

