#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int dia, mes, ano;

} data;

// Tamanho das variáveis
int main(void) {

    printf("sizeof (data) = %d\n", sizeof(data));
    return EXIT_SUCCESS;

}