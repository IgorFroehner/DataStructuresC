#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree tree;

tree *tree_create(void);
void tree_delete(tree *t);

void tree_insert(tree *t, int k, int v);

int tree_height(tree *t);
int tree_size(tree *t);

bool tree_has(tree *t, int k);

void tree_inorder(tree *t, void (*f)(int, int));
void tree_postorder(tree *t, void (*f)(int, int));
void tree_preorder(tree *t, void (*f)(int, int));

void tree_balance(tree *t);

void tree_print(tree *t);

#endif