/**
 * \file binary_search_tree.c
 * \author Filipe Augusto
 */

#include "binary_search_tree.h"

bst bst_new (void)
{
    return NULL;
}

void bst_free (bst *t)
{
    if (t == NULL || *t == NULL)
        return;

    bst_free(&(*t)->left);
    bst_free(&(*t)->right);

    free(*t);
    *t = NULL;
}

bst bst_insert (bst t, int data)
{
    if (t == NULL) {
        bst node = (bst)malloc(sizeof(bst_node_t));

        if (node == NULL)
            return NULL;

        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    if (data < t->data)
        t->left = bst_insert(t->left, data);
    else if (data > t->data)
        t->right = bst_insert(t->right, data);

    return t;
}

bst bst_delete (bst t, int data)
{
    if (t == NULL)
        return NULL;

    if (data < t->data) {
        t->left = bst_delete(t->left, data);
        return t;
    }

    if (data > t->data) {
        t->right = bst_delete(t->right, data);
        return t;
    }

    if (t->left == NULL) {
        bst right = t->right;
        free(t);
        return right;
    }

    if (t->right == NULL) {
        bst left = t->left;
        free(t);
        return left;
    }

    t->data = bst_min(t->right);
    t->right = bst_delete(t->right, t->data);

    return t;
}

bst bst_left (bst t)
{
    if (t == NULL)
        return NULL;

    return t->left;
}

bst bst_right (bst t)
{
    if (t == NULL)
        return NULL;

    return t->right;
}

int bst_node_value (bst t)
{
    assert(t != NULL);
    return t->data;
}

int bst_min (bst t)
{
    assert(t != NULL);

    if (t->left == NULL)
        return t->data;

    return bst_min(t->left);
}

int bst_max (bst t)
{
    assert(t != NULL);

    if (t->right == NULL)
        return t->data;

    return bst_max(t->right);
}

bool bst_is_empty (bst t)
{
    return t == NULL;
}

bool bst_is_leaf (bst t)
{
    return t != NULL && t->left == NULL && t->right == NULL;
}

bool bst_search (bst t, int data)
{
    if (t == NULL)
        return false;
    if (t->data == data)
        return true;
    if (data < t->data)
        return bst_search(t->left, data);

    return bst_search(t->right, data);
}

int bst_node_count (bst t)
{
    if (t == NULL)
        return 0;

    return 1 + bst_node_count(t->left) + bst_node_count(t->right);
}

int bst_leaf_count (bst t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;

    return bst_leaf_count(t->left) + bst_leaf_count(t->right);
}

int bst_height (bst t)
{
    if (t == NULL)
        return 0;

    int hl = bst_height(t->left);
    int hr = bst_height(t->right);

    return 1 + (hl > hr ? hl : hr);
}
