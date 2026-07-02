/**
 * \file binary_tree.c
 * \author Filipe Augusto
 */

#include "binary_tree.h"

tree bt_new (void)
{
    return NULL; 
}

tree bt_node_new (int data, tree left, tree right)
{
    tree t = (tree)malloc(sizeof(node_t));

    if (t == NULL)
        return NULL;

    t->data = data;
    t->left = left;
    t->right = right;

    return t;
}

void bt_free (tree *t)
{
    if (t == NULL || *t == NULL)
        return;

    bt_free(&(*t)->left);
    bt_free(&(*t)->right);

    free(*t);
    *t = NULL;
}

tree bt_left (tree t)
{
    if (t == NULL)
        return NULL;

    return t->left;
}

tree bt_right (tree t)
{
    if (t == NULL)
        return NULL;

    return t->right;
}

int bt_node_value (tree t)
{
    assert(t != NULL);
    return t->data; 
}

bool bt_is_empty (tree t)
{
    return t == NULL;
}

bool bt_is_leaf (tree t)
{
    return t != NULL && t->left == NULL && t->right == NULL;
}

bool bt_search (tree t, int data)
{
    if (t == NULL)
        return false;
    if (t->data == data)
        return true;

    return bt_search(t->left, data) || bt_search(t->right, data); 
}

int bt_node_count (tree t)
{
    if (t == NULL)
        return 0;

    return 1 + bt_node_count(t->left)
        + bt_node_count(t->right);
}

int bt_leaf_count (tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;

    return bt_leaf_count(t->left)
        + bt_leaf_count(t->right);
}

int bt_height (tree t)
{
    if (t == NULL)
        return 0;

    int hl = bt_height(t->left);
    int hr = bt_height(t->right);

    return 1 + (hl > hr ? hl : hr);
}
