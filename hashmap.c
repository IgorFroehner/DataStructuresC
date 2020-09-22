#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "avltree.h"
#include <stdio.h>

typedef struct bucket{
    avltree *tree;
}bucket;

struct hashmap{
    bucket **buffer;
    int capacity;
    int size;
};

// Uma funcao para criar uma tabela vazia na memória. Essa função irá receber um inteiro como argumento, 
// que será a quantidade de buckets desejados dentro da tabela hash. 
// A função deve retornar NULL caso o número seja menor que um.
hashmap *hashmap_create(int capacity){
    if (capacity<1) return NULL;
    
    hashmap *res = malloc(sizeof(hashmap));
    res->buffer = malloc(sizeof(bucket*)*capacity);
    res->capacity = capacity;
    res->size = 0;

    for (int i=0; i<capacity; i++){
        res->buffer[i] = malloc(sizeof(bucket));
    }
    
    return res;
}

// Uma função para inserir valores dentro da tabela. Essa função irá receber como argumentos a tabela desejada, a chave desejada, e o valor a ser salvo.
// A função deverá encontrar o bucket correto para a chave, e inserir o valor (ou atualizá-lo, caso o valor já exista no bucket). 
void hashmap_set(hashmap *map, const char *key, int value){
    int index = elf_hash(key)%map->capacity;

    if (map->buffer[index]->tree==NULL){
        map->buffer[index]->tree = avltree_create();
    }
    avltree_insert(map->buffer[index]->tree, key, value);
    map->size++;
}

// Uma função para procurar o valor de uma chave dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a chave não exista dentro da tabela, a função deve retornar zero.
int hashmap_get(hashmap *map, const char *key){
    int index = elf_hash(key)%map->capacity;

    if (map->buffer[index]->tree!=NULL){
        return avltree_get(map->buffer[index]->tree, key);
    }
}

// Uma função para verificar se uma chave existe dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a tabela contenha um valor para a chave informada, a função deve retornar 1 (verdadeiro). 
// Caso a tabela não contenha um valor para a chave, a função deve retornar 0 (falso).
bool hashmap_has(hashmap *map, const char *key){
    int index = elf_hash(key)%map->capacity;

    if (map->buffer[index]->tree!=NULL){
        return avltree_has(map->buffer[index]->tree, key);
    }
}

// Uma função que remove uma chave e seu valor da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a tabela contenha um valor para aquela chave, o valor deve ser removido. 
// Caso a tabela não contenha um valor para aquela chave, nada precisa ser feito.
void hashmap_remove(hashmap *map, const char *key){
    int index = elf_hash(key)%map->capacity;
    
    if (map->buffer[index]->tree!=NULL){
        map->size--;
        return avltree_remove(map->buffer[index]->tree, key);
    }
}

// Uma função que retorna a quantidade de itens (pares de chave e valor) existentes em uma tabela. Seu único argumento é a tabela desejada.
int hashmap_size(hashmap *map){
    return map->size;
}

// Finalmente, uma função para limpar a memória de uma tabela. Seu único argumento é a tabela a ser deletada. 
// Todos os buckets dentro da tabela precisam ser liberados também.
void hashmap_delete(hashmap *map){
  for (int i=0; i<map->capacity; i++){
        if (map->buffer[i]->tree!=NULL){
            avltree_delete(map->buffer[i]->tree);
        }
    }
    free(map->buffer);
    free(map);
}

// Printa o hashmap.
void hashmap_print(hashmap *map){
    for (int i=0; i<map->capacity; i++){
        if (map->buffer[i]->tree!=NULL){
            printf("hash: %i", i);
            avltree_print(map->buffer[i]->tree);
        }
    }
}

/**
 * Função padronizada para calcular o hash de uma string.
 */
unsigned long elf_hash(const char *s) {
    unsigned long h = 0;
    for(int i = 0; i < strlen(s); i++) {
        h = (h << 4) + s[i];
        unsigned long x = h & 0xF0000000;
        if(x != 0) {
            h ^= x >> 24;
            h &= ~x;
        }
    }

    return h;
}
