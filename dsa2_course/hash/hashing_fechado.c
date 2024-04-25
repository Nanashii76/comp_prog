// Implementando uma tabela hash com hashi fechado (Endereçamento Aberto)
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

// Definindo a struct que armazenará os valores de um determinado universo positivo
typedef struct Item {
    int key;
    int value;
} Item; Item NULLITEM = {0,0};

// definindo algumas macros e variáveis importantes para o código
#define Key(A) (A.key)
#define null(A) (Key(ht[A])==Key(NULLITEM))

static int N,M = 11213;
static Item *ht;

// Implementando as principais funções da tabela hash
// definindo a lei de formação da tabela hash
int hash(int key) {return key%M;}

// Inicilizando a tabela hash
void HTinit() {

    // a quantidade atuais de itens
    N = 0;
    ht = malloc(sizeof(Item)*M);
    for(int i = 0; i < M; ++i)
        ht[i] = NULLITEM;

}

// Implementnado uma função para retornar a quantidade de elementos atuais da tabela hash
int HTcount() {return N;}

// Implementando uma função para inserir novos elementos na tabela hash
void HTinsere(Item item) {

    int hash_key = hash(Key(item));
    while(!null(hash_key))
        hash_key = (hash_key+1)%M;

    ht[hash_key] = item;
    N++;

}

// Implemetando uma função para buscar um determinado elemento
Item HTbusca(int key){

    int hash_key = hash(key);
    while(!null(hash_key)) {
        if(key == Key(ht[hash_key]))
            return ht[hash_key];
        hash_key = (hash_key+1)%M;
    }

    return NULLITEM;

}

// Implementando uma função para deletar um elemento da tabela hash
void HTdelete(int key) {

    int hash_key = hash(key);
    while(!null(hash_key)) {
        if(key == Key(ht[hash_key])) {
            ht[hash_key] = NULLITEM;
            int next = hash_key;
            while(!null(next)) {
                ht[next] = ht[(next+1)%M];
                next = (next+1)%M;
            }
            hash_key = (hash_key+1)%M;
        }
    }

    N--;
}

int main() {
    // Exemplo de uso da tabela hash
    HTinit();

    // Criando alguns itens para inserir na tabela hash
    Item item1 = {10, 100};
    Item item2 = {20, 200};
    Item item3 = {30, 300};
    Item item4 = {22, 220}; // Colide com item2

    // Inserindo os itens na tabela hash
    HTinsere(item1);
    HTinsere(item2);
    HTinsere(item3);
    HTinsere(item4);

    // Imprimindo a quantidade de elementos atuais da tabela hash
    printf("Quantidade atuais de elementos: %d\n", HTcount());

    // Buscando um elemento na tabela hash
    int key_to_search = 20;
    Item result = HTbusca(key_to_search);
    if (result.key != 0) {
        printf("Elemento encontrado: key=%d, value=%d\n", result.key, result.value);
    } else {
        printf("Elemento com a chave %d nao encontrado na tabela hash.\n", key_to_search);
    }

    // Removendo um elemento da tabela hash
    int key_to_remove = 20;
    HTdelete(key_to_remove);
    result = HTbusca(key_to_remove);
    if (result.key != 0) {
        printf("Elemento com a chave %d encontrado apos a remocao.\n", key_to_remove);
    } else {
        printf("Elemento com a chave %d nao encontrado apos a remocao.\n", key_to_remove);
    }
    
    // Imprimindo a quantidade de elementos atuais da tabela hash
    printf("Quantidade atuais de elementos: %d", HTcount());

    return 0;
}
