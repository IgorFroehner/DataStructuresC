#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "circular_buffer.h"
#include "heap.h"
#include "tree.h"
#include "avltree.h"
#include "hashmap.h"

static void printa(int k, int v){
    printf(" %d : %d", k, v);
}

static void printas(const char *k, int v){
    printf(" %s : %d", k, v);
}

void list_test();
void stack_test();
void vector_test();
void queue_test();
void circular_buffer_test();
void heap_test();
void tree_test();
void avltree_test();
void hashmap_test();

int main(){
    
    // list_test();
    // stack_test();
    // queue_test();
    // vector_test();
    // circular_buffer_test();
    // heap_test();
    // tree_test();
    // avltree_test();
    hashmap_test();

}

void hashmap_test(){

    hashmap *map = hashmap_create(512);

    hashmap_set(map, "lorem", 1);
    hashmap_set(map, "ipsum", 2);
    hashmap_set(map, "dolor", 3);
    hashmap_set(map, "sit", 4);
    hashmap_set(map, "amet", 5);

    printf("map['%s'] = %i\n", "lorem", hashmap_get(map, "lorem"));
    printf("map['%s'] = %i\n", "ipsum", hashmap_get(map, "ipsum"));
    printf("map['%s'] = %i\n", "amet", hashmap_get(map, "amet"));

    printf("has('%s') = %i\n", "amet", hashmap_has(map, "amet"));
    printf("has('%s') = %i\n", "pedro", hashmap_has(map, "pedro"));

    printf("size: %i\n", hashmap_size(map));

    printf("hashmap print:\n");
    hashmap_print(map);

    hashmap_remove(map, "lorem");
    printf("size: %i\n", hashmap_size(map));
    hashmap_print(map);

    hashmap_delete(map);

}


void avltree_test(){

    avltree *arvore = avltree_create();

    avltree_insert(arvore, "A", 259);
    avltree_insert(arvore, "B", 799);
    avltree_insert(arvore, "C", 400);
    avltree_insert(arvore, "D", 12);
    avltree_insert(arvore, "E", 0);

    printf("size = %i\n", avltree_size(arvore));
    printf("height = %i\n", avltree_height(arvore));
    printf("has('A') = %i\n", avltree_has(arvore, "A"));
    printf("has('J') = %i\n", avltree_has(arvore, "J"));
    printf("preorder: ");
    avltree_preorder(arvore, printas);
    printf("\n");
    printf("inorder: ");
    avltree_inorder(arvore, printas);
    printf("\n");
    printf("postorder: ");
    avltree_postorder(arvore, printas);
    printf("\n");

    printf("Balanceada\n");

    avltree_remove(arvore, "D");
    // avltree_remove(arvore, "D");

    avltree_print(arvore);

    avltree_delete(arvore);

}

void tree_test(){
    
    tree *arvore = tree_create();

    tree_insert(arvore, 1, 120);
    tree_insert(arvore, 2, 24);
    tree_insert(arvore, 3, 42);
    tree_insert(arvore, 4, 76);
    tree_insert(arvore, 5, 300);

    tree_print(arvore);

    printf("size = %i\n", tree_size(arvore));
    printf("height = %i\n", tree_height(arvore));
    printf("has(4) = %i\n", tree_has(arvore, 4));
    printf("has(22) = %i\n", tree_has(arvore, 22));
    printf("preorder: ");
    tree_preorder(arvore, printa);
    printf("\n");
    printf("inorder: ");
    tree_inorder(arvore, printa);
    printf("\n");
    printf("postorder: ");
    tree_postorder(arvore, printa);
    printf("\n");

    printf("Balanceada\n");
    tree_balance(arvore);
    tree_print(arvore);

    tree_delete(arvore);

}

void heap_test(){

    heap *h = heap_create();

    int const n = 12;

    // Inicia o vetor com valores aleatórios
    
    for (int i=0; i<n; i++){
        heap_insert(h, rand() % 1000);
    }
    heap_print(h);

    int *v = heap_sort(h);
    printf("vetor sortado:\n");
    for (int i=0; i<n; i++){
        printf("%i ", v[i]);
    }
    printf("\n");

    heap_print(h);

    heap_delete(h);

}

void circular_buffer_test(){
    circular_buffer *cb = circular_buffer_create();

    circular_buffer_pushback(cb, 3);
    circular_buffer_pushback(cb, 4);
    circular_buffer_pushback(cb, 5);

    circular_buffer_pushfront(cb, 2);
    circular_buffer_pushfront(cb, 1);

    printf("\nfor: \n");
    for (int i=0; i<circular_buffer_size(cb); i++){
        printf("%i\n", circular_buffer_get(cb, i));
    }

    printf("circular size= %i\n", circular_buffer_size(cb));

    printf("\npop_front: %i\n", circular_buffer_pop_front(cb));
    printf("pop_front: %i\n", circular_buffer_pop_front(cb));

    printf("\npop_back: %i\n", circular_buffer_pop_back(cb));
    printf("pop_back: %i\n", circular_buffer_pop_back(cb));
    printf("pop_back: %i\n", circular_buffer_pop_back(cb));

    circular_buffer_pushback(cb, 1);
    circular_buffer_pushback(cb, 2);
    circular_buffer_pushback(cb, 3);

    printf("\nfor2: \n");
    for (int i=0; i<circular_buffer_size(cb); i++){
        printf("%i\n", circular_buffer_get(cb, i));
    }

    printf("\nwhile !empty: \n");
    while (!circular_buffer_is_empty(cb)){
        printf("pop_back: %i\n", circular_buffer_pop_back(cb));
    }

    for (int i=0; i<15; i++){
        circular_buffer_pushback(cb, i);
    }

    printf("\nfor até 15: \n");
    for (int i=0; i<circular_buffer_size(cb); i++){
        printf("%i\n", circular_buffer_get(cb, i));
    }

    circular_buffer_delete(cb);
}

void queue_test(){
    printf("\tqueue test\n\n");

    queue *q = queue_create();

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);

    printf("tamanho: %i\n", queue_size(q));

    printf("peek: %i\n", queue_peek(q));

    printf("dequeue: %i\n", queue_dequeue(q));
    printf("dequeue: %i\n", queue_dequeue(q));
    printf("dequeue: %i\n", queue_dequeue(q));

    queue_delete(q);
}

void vector_test(){
    printf("\tvector test:\n\n");

    vector *v = vector_create();

    vector_pushback(v, 1);
    vector_pushback(v, 2);
    vector_pushback(v, 3);

    printf("tamanho: %i\n", vector_size(v));

    vector_pushback(v, 4);
    vector_pushback(v, 5);
    vector_pushback(v, 6);
    vector_pushback(v, 7);
    vector_pushback(v, 8);
    vector_pushback(v, 9);
    vector_pushback(v, 10);
    vector_pushback(v, 11);
    vector_pushback(v, 12);
    
    for (int i=0; i<vector_size(v); i++) printf("vector[%i] = %i\n", i, vector_get(v, i));

    vector_delete(v);
}

void stack_test(){
    printf("\tstack test:\n\n");

    stack *stk = stack_create();

    stack_push(stk, 1);
    stack_push(stk, 2);
    stack_push(stk, 3);

    printf("tamanho: %i\n", stack_size(stk));
    printf("topo: %i\n\n", stack_peek(stk));

    printf("pop: %i\n", stack_pop(stk));
    printf("pop: %i\n", stack_pop(stk));
    printf("pop: %i\n", stack_pop(stk));

    printf("tamanho: %i\n", stack_size(stk));

    stack_delete(stk);
}

void list_test(){
    printf("\tlist test:\n\n");

    list* lst = list_create();

    list_push_back(lst, 1);
    list_push_back(lst, 2);
    list_push_back(lst, 3);
    
    printf("tamanho: %i\n", list_size(lst));

    printf("%i\n", list_pop_back(lst));
    printf("%i\n", list_pop_back(lst));
    printf("%i\n", list_pop_back(lst));

    printf("tamanho: %i\n", list_size(lst));

    list_push_front(lst, 1);
    list_push_front(lst, 2);
    list_push_front(lst, 3);

    for (int i=0; i<list_size(lst); i++){
        printf("%d\n", list_get(lst, i));
    }

    printf("peek first: %i\n", list_peek_first(lst));
    printf("peek last: %i\n", list_peek_last(lst));

    printf("%i\n", list_pop_front(lst));
    printf("%i\n", list_pop_front(lst));
    printf("%i\n", list_pop_front(lst));

    list_delete(lst);
}
