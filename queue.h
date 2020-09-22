#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct queue queue;

queue *queue_create(void);

void queue_delete(queue *);

void queue_enqueue(queue *, int);

int queue_dequeue(queue *);

int queue_peek(queue *);

int queue_size(queue *);

int queue_empty(queue *);

#endif