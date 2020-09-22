#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list list;

list *list_create(void);

void list_delete(list *);

void list_push_back(list *, int );

void list_push_front(list *, int );

int list_pop_back(list *);

int list_pop_front(list *);

int list_peek_first(list *);
int list_peek_last(list *);
int list_get(list *, int );

int list_size(list *);

int list_is_empty(list *);

#endif