#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct circular_buffer circular_buffer;

circular_buffer *circular_buffer_create(void);

void circular_buffer_delete(circular_buffer *);

void circular_buffer_grow(circular_buffer *);

void circular_buffer_pushback(circular_buffer *, int);

void circular_buffer_pushfront(circular_buffer *, int);

int circular_buffer_pop_back(circular_buffer *);

int circular_buffer_pop_front(circular_buffer *);

int circular_buffer_get(circular_buffer *, int);

int circular_buffer_size(circular_buffer *);

bool circular_buffer_is_empty(circular_buffer *);

#endif