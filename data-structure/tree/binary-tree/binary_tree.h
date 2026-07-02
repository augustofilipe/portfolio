/**
 * \file binary_tree.h
 * \author Filipe Augusto
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h> 

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t, *tree;

tree bt_new (void);
tree bt_node_new (int data, tree left, tree right);
void bt_free (tree *t);

tree bt_left (tree t);
tree bt_right (tree t);
int bt_node_value (tree t);

bool bt_is_empty (tree t);
bool bt_is_leaf (tree t);
bool bt_search (tree t, int data);

int bt_node_count (tree t);
int bt_leaf_count (tree t);
int bt_height (tree t);

#endif /* BINARY_TREE_H */
