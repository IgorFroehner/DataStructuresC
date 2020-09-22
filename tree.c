#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    int value;
} node;

struct tree {
    node *root;
};

tree *tree_create(void){
    tree *res = malloc(sizeof(tree));
    res->root = NULL;
    return res;
}

// -------------- DELETE -----------------

static void node_delete(node *n){
    if (n->left!=NULL) node_delete(n->left);
    if (n->right!=NULL) node_delete(n->right);
    free(n);
}

void tree_delete(tree *t){
    if (t->root!=NULL) node_delete(t->root);
    free(t);
}

// -------------- INSERT ---------------

static node *node_insert(node *n, int k, int v){
    if (n!=NULL){
        // vê se o cara que a gente tá já não é a chave que estamos procurando
        if (n->key==k){
            return n;
        }

        // se for menor vamos pra esquerda se não vamos pra direita
        if (k<n->key){
            n->left = node_insert(n->left, k, v);
            return n;
        } else {
            n->right = node_insert(n->right, k, v);
            return n;
        }

    } else{
        // se chegamos em uma parte em que não existe nodo é aqui que ele vai
        n = malloc(sizeof(node));
        n->key = k;
        n->left = NULL;
        n->right = NULL;
        n->value = v;
        return n;
    }
}

void tree_insert(tree *t, int k, int v){
    t->root = node_insert(t->root, k, v);
}

// ------------- HEIGHT

static int node_height(node *n){
    if (n==NULL) return 0;
    int left_height = node_height(n->left);
    int right_height = node_height(n->right);
    if (left_height>right_height){
        return left_height+1;
    }else{
        return right_height+1;
    }
}

int tree_height(tree *t){
    return node_height(t->root);
}

// ------------- SIZE ---------

static int node_size(node *n){
    if (n==NULL) return 0;
    return node_size(n->left)+node_size(n->right)+1;
}

int tree_size(tree *t){
    if (t->root!=NULL)
        return node_size(t->root);
    return 0;
}

// ------------ HAS -------------

bool tree_has(tree *t, int k){
    node *it = t->root;
    while (it!=NULL){
        if (it->key == k) return true;
        if (it->key > k) it = it->left;
        else it = it->right;
    }
    return false;
}


// ----------- INORDER ---------------

static void node_inorder(node *n, void (*f)(int, int)){
    if (n!=NULL){
        node_inorder(n->left, f);
        f(n->key, n->value);
        node_inorder(n->right, f);
    }
}

void tree_inorder(tree *t, void (*f)(int, int)){
    node_inorder(t->root, f);
}

// ------------ POSTORDER ---------------

static void node_postorder(node *n, void (*f)(int, int)){
    if (n!=NULL){
        node_postorder(n->left, f);
        node_postorder(n->right, f);
        f(n->key, n->value);
    }
}

void tree_postorder(tree *t, void (*f)(int, int)){
    node_postorder(t->root, f);
}

// ------------ PREORDER ----------------

static void node_preorder(node *n, void (*f)(int, int)){
    if (n!=NULL){
        f(n->key, n->value);
        node_preorder(n->left, f);
        node_postorder(n->right, f);
    }
}

void tree_preorder(tree *t, void (*f)(int, int)){
    node_preorder(t->root, f);
}

// -------------- BALANCE --------------------

// coloca os cara em inorder no v
static int node_place_inorder(node *n, node *v[]){
    if (n!=NULL){
        int i = node_place_inorder(n->left, v);

        v[i++] = n;

        return 1 + node_place_inorder(n->right, v+1);
    }
    return 0;
}

static void tree_place_inorder(tree *t, node *v[]){
    node_place_inorder(t->root, v);
}

static node *node_balance(node *v[], int i, int j){
    if (i>j) return NULL;
    
    int m = (i+j)/2;

    node *root = v[m];
    root->left = node_balance(v, i, m-1);
    root->right = node_balance(v, m+1, j);
    return root;
}

void tree_balance(tree *t){
    int size = tree_size(t);

    node **v = malloc(sizeof(node *) * size);
    tree_place_inorder(t, v);

    t->root = node_balance(v, 0, size - 1);

    free(v);
}

// -------------- PRINT -----------

static void node_print(node *n){
    printf("( ");
    if (n!=NULL){
        if (n->left!=NULL){
            node_print(n->left);
            printf(" ");
        }
        printf("%d : %d ", n->key, n->value);
        if (n->right!=NULL){
            node_print(n->right);
            printf(" ");
        }
    }
    printf(")");
}

void tree_print(tree *t){
    node_print(t->root);
    printf("\n");
}