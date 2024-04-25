// Implementando um hashing aberto (Encademanto separado)
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


// primeiro, precisamos definir o que iremos armazenar na tabela hash;
// para facilitar o processo, irei armazenar inteiros
typedef struct No {

    int key;
    long long id;
    char *name;
    struct No *prox;

} No; No NULLITEM = {-1,-1,NULL,NULL};

static int N, M = 11213; // utilizaremos os números de Mercêne (2^t-1), podendo ser alterado
static No *ht;

// criando uma função hash para pegar o valor do index referente à chave informada
// realizando o hash da chave
int hash(int key){return key%M;}

// Inicilizando a tabela hash
void HTinit() {

    // inicilizando o tamanho da tabela hash
    N = 0;
    ht = malloc(sizeof(No)*M);
    for(int i = 0; i < M; ++i)
        ht[i] = NULLITEM;

}

// retornar a quantidade de elemetos presentes na tabela hash
int HTcount() {return N;}

// Inserindo novos elementos na tabela hash
// criando uma função para inserir no início de uma lista encadeada
void insere(No *head, No *item) {

    // se a lista estiver vazia
    if(head->prox == NULL) {
        head->prox = item;
        return;
    }

    No *tmp = head->prox;
    head->prox = item;
    item->prox = tmp;

}

// adicionando o novo valor em seu devido index
void HTinsert(No *item) {

    int hash_value = hash(item->key);
    item->prox = ht[hash_value].prox;
    ht[hash_value].prox = item;
    N++;

}
// criando uma função para realizar a busca de uma determinada chave na tabela hash
// realizando uma busca em uma lista encadeada
No *HTbusca(int key) {

    int hash_value = hash(key);
    No *tmp = ht[hash_value].prox;
    
    while (tmp) {
        if (tmp->key == key) {
            return tmp;
        }
        tmp = tmp->prox;
    }
    return NULL;

}

// Criando uma função para remover um determinado valor da tabela hash
// criando uma função para remover um determinado elemento de uma lista encadeada
void HTremove(int key) {

    int hash_value = hash(key);
    No *prev = NULL;
    No *tmp = ht[hash_value].prox;
    while (tmp != &NULLITEM and tmp->key != key) {
        prev = tmp;
        tmp = tmp->prox;
    }
    if (tmp != &NULLITEM) {
        if (prev == NULL) {
            ht[hash_value].prox = tmp->prox;
        } else {
            prev->prox = tmp->prox;
        }
        free(tmp);
    }

    N--;

}


int main(void) {
    // Inicilizando a tabela hash na main
    HTinit();

    // Criando alguns nós para inserir na tabela hash
    No *item1 = malloc(sizeof(No));
    item1->key = 10;
    item1->id = 12345;
    item1->name = "Item 1";
    item1->prox = NULL;

    No *item2 = malloc(sizeof(No));
    item2->key = 20;
    item2->id = 67890;
    item2->name = "Item 2";
    item2->prox = NULL;

    // Inserindo os nós na tabela hash
    HTinsert(item1);
    HTinsert(item2);

    // imprimindo a quantidade de elementos da tabela hash
    printf("Quantidade de elementos atuais: %d\n", HTcount());

    // Buscando um elemento na tabela hash
    int key_to_search = 20;
    No *result = HTbusca(key_to_search);
    if (result != NULL) {
        printf("Elemento encontrado: key=%d, id=%lld, name=%s\n", result->key, result->id, result->name);
    } else {
        printf("Elemento com a chave %d nao encontrado na tabela hash.\n", key_to_search);
    }

    // Removendo um elemento da tabela hash
    int key_to_remove = 20;
    HTremove(key_to_remove);
    result = HTbusca(key_to_remove);
    if (result != NULL) {
        printf("Elemento com a chave %d encontrado apos a remocao.\n", key_to_remove);
    } else {
        printf("Elemento com a chave %d nao encontrado apos a remocao.\n", key_to_remove);
    }

    printf("Quantidade de elementos atuais: %d\n", HTcount());

    // Liberando memória alocada para os nós
    free(item1);
    free(item2);

    return EXIT_SUCCESS;
}
