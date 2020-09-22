#include "list.h"
#include "queue.h"

typedef struct queue {
    list *list;
} queue;

queue *queue_create(void){
    queue *result = malloc(sizeof(queue));

    result->list = list_create();

    return result;
}

void queue_delete(queue *queue){
    list_delete(queue->list);
    free(queue);
}

void queue_enqueue(queue *queue, int value){
    list_push_front(queue->list, value);
}

int queue_dequeue(queue *queue){
    if (queue_size(queue)==0){
        return 0;
    }
    return list_pop_back(queue->list);
}

int queue_peek(queue *queue){
    return list_peek_last(queue->list);
}

int queue_size(queue *queue){
    list_size(queue->list);
}

int queue_empty(queue *queue){
    if (queue_size(queue)==0){
        return 1;
    }
    return 0;
}
