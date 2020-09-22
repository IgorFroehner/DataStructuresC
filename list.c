#include "list.h"

typedef struct node{
    int value;

    struct node *next;
    struct node *prev;
} node;

struct list{
    node *head;

    node *tail;
};

list *list_create(void){
    list *res = malloc(sizeof(list));

    res->head = NULL;
    res->tail = NULL;

    return res;
}

void node_delete(node *node){
    if (!(node->next==NULL)){
        node_delete(node->next);
    }
    free(node);
}

void list_delete(list *list){
    if (!list_is_empty(list)){
        node_delete(list->head);
    }
    free(list);
}

/*
* 
* head                           tail
*   0     1       2       3       4      
*   + --- + ----- + ----- + ----- + ------ null
*                       prev               next
*
* head                                     tail  
*   0     1       2       3       4         5 
*   + --- + ----- + ----- + ----- + ------- + ---- null
*                                prev               next
*
*/

void list_push_back(list *list, int value){
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    
    if (list_is_empty(list)){
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }else{
        new_node->next = NULL;
        new_node->prev = list->tail;

        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void list_push_front(list *list, int value){
    node *new_node = malloc(sizeof(node));
    new_node->value = value;

    if (list_is_empty(list)){
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }else{
        new_node->prev = NULL;
        new_node->next = list->head;
        
        list->head->prev = new_node;
        list->head = new_node;
    }
}

/*
*          tail
*          head
*            0    
*  null ---- + --- null
*  prev             next
*
*/

int list_pop_back(list *list){
    if (list_is_empty(list)){
        return -1;
    }
    int value = list->tail->value;
    node *old_tail = list->tail;

    if (list->head->next==NULL){
        list->head = NULL;
        list->tail = NULL;
    }else{
        list->tail = old_tail->prev;
        list->tail->next = NULL;
    
    }
    free(old_tail);
    return value;
}

int list_pop_front(list *list){
    if (list_is_empty(list)){
        return -1;
    }
    int value = list->head->value;
    node *old_head = list->head;

    if (list->head->next==NULL){
        list->head = NULL;
        list->tail = NULL;
    }else{
        list->head = old_head->next;
        list->head->prev = NULL;
    }
    free(old_head);
    return value;
}

int list_get(list *l, int index){
    node *i = l->head;
    int j=0;
    while(i!=NULL){
        if (j==index)
            return i->value;
        i = i->next;
        j++;
    }
    return -1;
}

int list_peek_first(list *l){
    if (l->head!=NULL)
        return l->head->value;
    return -1;
}

int list_peek_last(list *l){
    if (l->tail!=NULL)
        return l->tail->value;
    return -1;
}

int list_size(list *list){
    int count = 0;
    if (list_is_empty(list)) return 0;
    for (node *i = list->head; i != NULL; i = i->next){
        count++;
    }
    return count;
}

int list_is_empty(list *list){
    if ((list->head == NULL) && (list->tail == NULL)) return 1;
    return 0;
}
