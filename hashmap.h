#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

typedef struct hashmap hashmap;

// Uma funcao para criar uma tabela vazia na memória. Essa função irá receber um inteiro como argumento, 
// que será a quantidade de buckets desejados dentro da tabela hash. 
// A função deve retornar NULL caso o número seja menor que um.
hashmap *hashmap_create(int capacity);

// Uma função para inserir valores dentro da tabela. Essa função irá receber como argumentos a tabela desejada, a chave desejada, e o valor a ser salvo.
// A função deverá encontrar o bucket correto para a chave, e inserir o valor (ou atualizá-lo, caso o valor já exista no bucket). 
void hashmap_set(hashmap *map, const char *key, int value);

// Uma função para procurar o valor de uma chave dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a chave não exista dentro da tabela, a função deve retornar zero.
int hashmap_get(hashmap *map, const char *key);

// Uma função para verificar se uma chave existe dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a tabela contenha um valor para a chave informada, a função deve retornar 1 (verdadeiro). 
// Caso a tabela não contenha um valor para a chave, a função deve retornar 0 (falso).
bool hashmap_has(hashmap *map, const char *key);

// Uma função que remove uma chave e seu valor da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. 
// Caso a tabela contenha um valor para aquela chave, o valor deve ser removido. 
// Caso a tabela não contenha um valor para aquela chave, nada precisa ser feito.
void hashmap_remove(hashmap *map, const char *key);

// Uma função que retorna a quantidade de itens (pares de chave e valor) existentes em uma tabela. Seu único argumento é a tabela desejada.
int hashmap_size(hashmap *map);

// Finalmente, uma função para limpar a memória de uma tabela. Seu único argumento é a tabela a ser deletada. 
// Todos os buckets dentro da tabela precisam ser liberados também.
void hashmap_delete(hashmap *map);

// print o hashmap
void hashmap_print(hashmap *map);

// Função hash
unsigned long elf_hash(const char *);

#endif