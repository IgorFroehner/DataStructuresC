#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;

vector* vector_create(void);
void vector_delete(vector*);

void vector_pushback(vector*, int);

int vector_get(vector*, int);

int vector_pop(vector*);

int vector_size(vector*);

#endif