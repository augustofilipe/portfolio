/**
 * \file avl_tree.h
 * \author Filipe Augusto
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct avl_node {
    int data;
    int height;
    struct avl_node *left;
    struct avl_node *right;
} avl_node_t, *avl_tree;

avl_tree avl_new (void);
void avl_free (avl_tree *t);

avl_tree avl_insert (avl_tree t, int data);
avl_tree avl_delete (avl_tree t, int data);

avl_tree avl_left (avl_tree t);
avl_tree avl_right (avl_tree t);
int avl_node_value (avl_tree t);
int avl_min (avl_tree t);
int avl_max (avl_tree t);

bool avl_is_empty (avl_tree t);
bool avl_is_leaf (avl_tree t);
bool avl_search (avl_tree t, int data);

int avl_node_count (avl_tree t);
int avl_leaf_count (avl_tree t);
int avl_height (avl_tree t);
int avl_balance (avl_tree t);

#endif /* AVL_TREE_H */
