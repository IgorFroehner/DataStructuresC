#include "heap.h"

struct heap
{
    int *arr;
    int cap;
    int size;
};

heap *heap_create(void){
    heap *res = malloc(sizeof(heap));

    const int initial = 8;
    res->cap = initial;
    res->size = 0;
    res->arr = malloc(sizeof(int)*res->cap);

    return res;
}

void heap_delete(heap *h){
    free(h->arr);
    free(h);
}

void heap_insert(heap *h, int value){
    h->size++;
    if (h->size >= h->cap) {
        h->cap *= 2;
        h->arr = realloc(h->arr, sizeof(int)*h->cap);
    }
    h->arr[h->size-1] = value;
    heapify_up(h);
}

int heap_top(heap *h){
    if (h->size==0) return -1;
    return h->arr[0];
}

int heap_pop(heap *h){
    if (h->size==0) return -1;
    int value = h->arr[0];
    swap(&h->arr[0], &h->arr[h->size-1]);
    h->size--;
    heapify(h->arr, h->size, 0);
    return value;
}

void heapify(int *v, int n, int i){
    int largest = i;
    int l = leftof(i);
    int r = rightof(i);

    if (l < n && v[l] > v[largest]){
        largest = l;
    }

    if (r < n && v[r] > v[largest]){
        largest = r;
    }

    if (largest != i){
        swap(&v[largest], &v[i]);

        heapify(v, n, largest);
    }
}

void heapify_up(heap *h){
    int ind = h->size-1;
    while(heap_has_parent(h, ind) && heap_parent(h, ind) < h->arr[ind]){
        swap(&h->arr[up(ind)], &h->arr[ind]);
        ind = up(ind);
    }
}

void make_heap(int *v, int n){
    for(int i= (n/2)-1; i>=0; i-- ){
        heapify(v, n, i);
    }
}

int leftof(int i) {
    return (i<<1)+1;
}

int rightof(int i) {
    return (i<<1)+2;
}

int up(int i){
    if (i==0) return -1;
    return (i-1)/2;
}

int heap_left_child(heap *h, int ind){
    return h->arr[leftof(ind)];
}

int heap_right_child(heap *h, int ind){
    return h->arr[rightof(ind)];
}

int heap_parent(heap *h, int ind){
    return h->arr[up(ind)];
}

int heap_has_parent(heap *h, int ind){
    if (up(ind)>=0) return 1;
    else return 0;
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heap_print(heap *h){
    int *v = h->arr; int s = h->size; 
    int x = 0;
    int max = 4 * pow(2, (int)floor(log2(s)));
    int itens, used, spacing;

    printf("Vetor:\n");
    for(int i = 0; i < s; i++) {
        if((i & (i + 1)) == 0) {
            if(i) printf("\n");
            itens = (int)pow(2, x);
            used = 4 * itens;
            spacing = ((max - used) / itens) / 2;
            x++;
        }

        // Um código inelegante para imprimir o heap como uma árvore
        for(int j = 0; j < spacing; j++) printf(" ");
        
        printf("%4d", v[i]);
        
        for(int j = 0; j < spacing; j++) printf(" ");

        // Verifica se fizemos tudo direito!
        int l = leftof(i);
        int r = rightof(i);

        if((l < s && v[l] > v[i]) || (r < s && v[r] > v[i])) {
            printf("Tem um bug aqui!\n");
        }
    }
    printf("\n");
}

int *heap_sort(heap *h){
    int size = h->size;
    int *v = malloc(sizeof(int)*size);

    heap *heap_copy = heap_create();
    
    for (int i=0; i<h->size; i++){
        heap_insert(heap_copy, h->arr[i]);
    }

    for (int i=heap_copy->size-1; i>=0; i--){
        v[i] = heap_pop(heap_copy);
    }

    heap_delete(heap_copy);
    return v;
}
