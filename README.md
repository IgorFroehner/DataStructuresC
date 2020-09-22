# MyLib de C

Libzinha de estrutura de dados feita durante a matéria de EDA - Estruturas de Dados com o professor Paulo Torrens.

## Contínuas

### list:

    Lista duplamente linkada, cada novo valor pode ser adicionado ao final da lista ou no começo.

    push_back & push_front: O(1)
    pop_back & pop_front: O(1)
    get: O(n)

### queue:

    Estrutura FIFO(first-in first-out) cada valor novo vai pro final da fila e é o primeiro a ser retirado.

    enqueue & dequeue: O(1)
    peek: O(1)

### stack:

    Estrutura LIFO(last-in first-out) cada valor vai pro começo da lista, e é o primeiro a ser retirado com pop.

    push & pop: O(1)
    top: O(1)

### vector:

    Array dinâmico.

    pushback: O(1)
    get: O(1)

    TODO:
    remove: O(n)

### circular_buffer:

    Array circular dinâmico.

    pushback & pushfront: O(1)
    get: O(1)
    popback e popfront: O(1)

### heap:

    Estrutura com caracteristica de heap, no caso max heap, em que cada filho é menor que o pai.

    insert: O(log(n))
    pop: O(log(n)) retorna e retira o maior numero
    top: O(log(n)) retorna o maior numero
    
    heapsort: retorna um vetor ordenado a partir de uma heap.

## Associativas

    Relacionam uma chave a um valor na estrutura. Ex: 1:60 ou "Igor":10.

### tree:

    Estrutura em formato de arvore em que a chave do nodo a esquerda de cada nodo é menor que ele proprio e a direita é maior. Ela não fica sempre balanceada mas tem uma função para balancear que roda em O(nlog(n)). As chaves nessa implementação são ints.

    insert: O(log(n))

    TODO:
    get: O(log(n))
    remove: O(log(n))

### avltree:

    Árvore que fica sempre balanceada, quando itens são inseridos é calculado o fator de desbalance, se for maior que 1 são necessárias rotações. Implementação em que as chaves são strings e o valor são ints.

    insert, remove e get: O(log(n))

### hashmap:

    Hashmap com buckets sendo avltrees, implementada com um array de avltree, cada chave a ser inserida é hasheada pelo elf_hash e colocada na posição hash%capacidade.

    set, get, remove ~= O(1)
