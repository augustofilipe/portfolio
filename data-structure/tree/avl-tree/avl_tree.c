/**
 * \file avl_tree.c
 * \author Filipe Augusto
 */

#include "avl_tree.h"

avl_tree avl_new (void)
{
    return NULL;
}

void avl_free (avl_tree *t)
{
    if (t == NULL || *t == NULL)
        return;

    avl_free(&(*t)->left);
    avl_free(&(*t)->right);

    free(*t);
    *t = NULL;
}

static void avl_update_height (avl_tree t)
{
    if (t == NULL)
        return;

    int hl = avl_height(t->left);
    int hr = avl_height(t->right);

    t->height = 1 + (hl > hr ? hl : hr);
}

static avl_tree avl_rotate_right (avl_tree t)
{
    avl_tree l = t->left;
    avl_tree lr = l->right;

    l->right = t;
    t->left = lr;

    avl_update_height(t);
    avl_update_height(l);

    return l;
}

static avl_tree avl_rotate_left (avl_tree t)
{
    avl_tree r = t->right;
    avl_tree rl = r->left;

    r->left = t;
    t->right = rl;

    avl_update_height(t);
    avl_update_height(r);

    return r;
}

static avl_tree avl_rebalance (avl_tree t)
{
    avl_update_height(t);

    int balance_factor = avl_height(t->left) - avl_height(t->right);

    if (balance_factor > 1) {
        if (avl_height(t->left->left) < avl_height(t->left->right))
            t->left = avl_rotate_left(t->left);

        return avl_rotate_right(t);
    }

    if (balance_factor < -1) {
        if (avl_height(t->right->right) < avl_height(t->right->left))
            t->right = avl_rotate_right(t->right);

        return avl_rotate_left(t);
    }

    return t;
}

avl_tree avl_insert (avl_tree t, int data)
{
    if (t == NULL) {
        avl_tree node = (avl_tree)malloc(sizeof(avl_node_t));

        if (node == NULL)
            return NULL;

        node->data = data;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    if (data < t->data)
        t->left = avl_insert(t->left, data);
    else if (data > t->data)
        t->right = avl_insert(t->right, data);

    return avl_rebalance(t);
}

avl_tree avl_delete (avl_tree t, int data)
{
    if (t == NULL)
        return NULL;

    if (data < t->data) {
        t->left = avl_delete(t->left, data);
        return avl_rebalance(t);
    }

    if (data > t->data) {
        t->right = avl_delete(t->right, data);
        return avl_rebalance(t);
    }

    if (t->left == NULL) {
        avl_tree right = t->right;
        free(t);
        return right;
    }

    if (t->right == NULL) {
        avl_tree left = t->left;
        free(t);
        return left;
    }

    t->data = avl_min(t->right);
    t->right = avl_delete(t->right, t->data);

    return avl_rebalance(t);
}

avl_tree avl_left (avl_tree t)
{
    if (t == NULL)
        return NULL;

    return t->left;
}

avl_tree avl_right (avl_tree t)
{
    if (t == NULL)
        return NULL;

    return t->right;
}

int avl_node_value (avl_tree t)
{
    assert(t != NULL);
    return t->data;
}

int avl_min (avl_tree t)
{
    assert(t != NULL);

    if (t->left == NULL)
        return t->data;

    return avl_min(t->left);
}

int avl_max (avl_tree t)
{
    assert(t != NULL);

    if (t->right == NULL)
        return t->data;

    return avl_max(t->right);
}

bool avl_is_empty (avl_tree t)
{
    return t == NULL;
}

bool avl_is_leaf (avl_tree t)
{
    return t != NULL && t->left == NULL && t->right == NULL;
}

bool avl_search (avl_tree t, int data)
{
    if (t == NULL)
        return false;
    if (t->data == data)
        return true;
    if (data < t->data)
        return avl_search(t->left,  data);

    return avl_search(t->right, data);
}

int avl_node_count (avl_tree t)
{
    if (t == NULL)
        return 0;

    return 1 + avl_node_count(t->left) + avl_node_count(t->right);
}

int avl_leaf_count (avl_tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;

    return avl_leaf_count(t->left) + avl_leaf_count(t->right);
}

int avl_height (avl_tree t)
{
    return t == NULL ? 0 : t->height;
}

int avl_balance (avl_tree t)
{
    if (t == NULL)
        return 0;

    return avl_height(t->left) - avl_height(t->right);
}
