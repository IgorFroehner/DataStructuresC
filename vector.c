#include "vector.h"
#include <stdlib.h>

struct vector
{
    int *buffer;
    int size;
    int capacity;
};

vector* vector_create(void){
    vector* res = malloc(sizeof(vector));
    
    const int cap = 8;
    res->buffer = malloc(sizeof(int)*cap);
    res->size = 0;
    res->capacity = cap;

    return res;
}

void vector_delete(vector* vector){
    free(vector->buffer);
    free(vector);
}

void vector_pushback(vector* vector, int value){
    vector->buffer[vector->size] = value;
    vector->size++;
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->buffer = realloc(vector->buffer, sizeof(int)*vector->capacity);
    }
}

int vector_get(vector* vector, int i){
    if (i>=vector->size) return 0;
    else return vector->buffer[i];
}

int vector_pop(vector* vector){
    return vector->buffer[vector->size--];
}

int vector_size(vector* vector){
    return vector->size;
}

