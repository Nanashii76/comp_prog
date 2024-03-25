#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Realizando cast de int para long int
int main(void) {

    int i = 1234;
    printf("i = %d\n", i); // imprime o valor atual de i
    printf("&i = %ld\n", (long int) &i); // converte o valor do ponteiro de i para decimal
    printf("&i = %p\n", (void *)i); // imprime o valor hex do ponteiro de i

    return EXIT_SUCCESS;

}