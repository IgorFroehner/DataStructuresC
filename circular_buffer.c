#include "circular_buffer.h"

struct circular_buffer{
    int *buffer;

    int head;
    int tail;
    int capacity;
};

circular_buffer *circular_buffer_create(void){
    circular_buffer *res = malloc(sizeof(circular_buffer));

    const int cap = 8;
    res->buffer = malloc(sizeof(int)*cap);
    res->head = 0;
    res->tail = 0;
    res->capacity = cap;

    return res;
}

void circular_buffer_grow(circular_buffer *cb){
    // Os primeiros itens da lista começam em head e vão até capacity...
    int old_capacity = cb->capacity;
    int first_half = old_capacity - cb->head;

    // Primeiro, aumentamos a capacidade e alocamos um novo vetor
    cb->capacity *= 2;
    int *new_buffer = malloc(sizeof(int) * cb->capacity);

    // Agora, copiamos os dados, porém na ordem correta
    memcpy(new_buffer, cb->buffer + cb->head, sizeof(int) * first_half);
    memcpy(new_buffer + first_half, cb->buffer, sizeof(int) * cb->head);

    // Como agora os dados estão em ordem, devemos lembrar isso
    cb->head = 0;
    cb->tail = old_capacity;

    // Finalmente, limpamos o buffer antigo e usamos o novo
    free(cb->buffer);
    cb->buffer = new_buffer;
}


void circular_buffer_delete(circular_buffer *cb){
    free(cb->buffer);
    free(cb);
}

void circular_buffer_pushback(circular_buffer *cb, int value){
    cb->buffer[cb->tail] = value;
    cb->tail++;

    if (cb->tail>=cb->capacity){
        cb->tail = 0;
    }

    if (cb->tail == cb->head){
        circular_buffer_grow(cb);
    }
}

void circular_buffer_pushfront(circular_buffer *cb, int value){
    cb->head--;
    if (cb->head < 0){
        cb->head = cb->capacity-1;
    }
    
    cb->buffer[cb->head] = value;

    if (cb->tail == cb->head){
        circular_buffer_grow(cb);
    }
}

int circular_buffer_pop_back(circular_buffer *cb){
    if (!circular_buffer_is_empty(cb)){
        cb->tail--;
        if (cb->tail<0)
            cb->tail = cb->capacity-1;
        
        return cb->buffer[cb->tail];
    }
    return 0;
}

int circular_buffer_pop_front(circular_buffer *cb){
    if (!circular_buffer_is_empty(cb)){
        int res = cb->buffer[cb->head];
        cb->head++;
        if (cb->head>=cb->capacity){
            cb->head = 0;
        }

        return res;
    }
    return 0;
}

int circular_buffer_get(circular_buffer *cb, int ind){
    int i = (ind+cb->head) % cb->capacity;
    return cb->buffer[i];
}

int circular_buffer_size(circular_buffer *cb){
    int size = cb->tail - cb->head;
    if (size<0){
        size += cb->capacity;
    }
    return size;
}

bool circular_buffer_is_empty(circular_buffer *cb){
    if (cb->head == cb->tail) return true;
    return false;
}
