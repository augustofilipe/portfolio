/**
 * \file binary_search_tree.h
 * \author Filipe Augusto
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node_t, *bst;

bst bst_new (void);
void bst_free (bst *t);

bst bst_insert (bst t, int data);
bst bst_delete (bst t, int data);

bst bst_left (bst t);
bst bst_right (bst t);
int bst_node_value (bst t);
int bst_min (bst t);
int bst_max (bst t);

bool bst_is_empty (bst t);
bool bst_is_leaf (bst t);
bool bst_search (bst t, int data);

int bst_node_count (bst t);
int bst_leaf_count (bst t);
int bst_height (bst t);

#endif /* BINARY_SEARCH_TREE_H */
