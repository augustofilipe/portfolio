/**
 * \file lcrs_tree.h
 * \author Filipe Augusto
 */

#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct lcrs_node {
    int data;
    struct lcrs_node *lc;
    struct lcrs_node *rs;
} lcrs_node_t, *lcrs_tree;

lcrs_tree lcrs_new (void);
lcrs_tree lcrs_node_new (int data, lcrs_tree lc, lcrs_tree rs);
void lcrs_free (lcrs_tree *t);

lcrs_tree lcrs_lc (lcrs_tree t);
lcrs_tree lcrs_rs (lcrs_tree t);
int lcrs_node_value (lcrs_tree t);

bool lcrs_is_empty (lcrs_tree t);
bool lcrs_is_leaf (lcrs_tree t);
bool lcrs_search (lcrs_tree t, int data);

int lcrs_node_count (lcrs_tree t);
int lcrs_leaf_count (lcrs_tree t);
int lcrs_height (lcrs_tree t);

#endif /* LCRS_TREE_H */
