#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct heap heap;

heap *heap_create(void);

void heap_delete(heap *);

void heap_insert(heap *, int);
int heap_top(heap *);
int heap_pop(heap *);

void heapify_up(heap *h);

int heap_has_parent(heap *, int );

int heap_leftChild(heap *, int);
int heap_rightChild(heap *, int);
int heap_parent(heap *, int);

void make_heap(int *, int);

void heapify(int *v, int n, int i);

int leftof(int);
int rightof(int);
int up(int );
void swap(int *, int *);

int *heap_sort(heap *);

void heap_print(heap *);

#endif