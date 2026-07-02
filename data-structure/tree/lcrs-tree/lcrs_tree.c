/**
 * \file lcrs_tree.c
 * \author Filipe Augusto
 */

#include "lcrs_tree.h"

lcrs_tree lcrs_new (void)
{
    return NULL;
}

lcrs_tree lcrs_node_new (int data, lcrs_tree lc, lcrs_tree rs)
{
    lcrs_tree t = (lcrs_tree)malloc(sizeof(lcrs_node_t));

    if (t == NULL)
        return NULL;

    t->data = data;
    t->lc = lc;
    t->rs = rs;

    return t;
}

void lcrs_free (lcrs_tree *t)
{
    if (t == NULL || *t == NULL)
        return;

    lcrs_free(&(*t)->lc);
    lcrs_free(&(*t)->rs);

    free(*t);
    *t = NULL;
}

lcrs_tree lcrs_lc (lcrs_tree t)
{
    if (t == NULL)
        return NULL;

    return t->lc;
}

lcrs_tree lcrs_rs (lcrs_tree t)
{
    if (t == NULL)
        return NULL;

    return t->rs;
}

int lcrs_node_value (lcrs_tree t)
{
    assert(t != NULL);
    return t->data;
}

bool lcrs_is_empty (lcrs_tree t)
{
    return t == NULL;
}

bool lcrs_is_leaf (lcrs_tree t)
{
    return t != NULL && t->lc == NULL;
}

bool lcrs_search (lcrs_tree t, int data)
{
    if (t == NULL)
        return false;
    if (t->data == data)
        return true;

    return lcrs_search(t->lc, data) || lcrs_search(t->rs, data);
}

int lcrs_node_count (lcrs_tree t)
{
    if (t == NULL)
        return 0;

    return 1 + lcrs_node_count(t->lc) + lcrs_node_count(t->rs);
}

int lcrs_leaf_count (lcrs_tree t)
{
    if (t == NULL)
        return 0;
    if (t->lc == NULL)
        return 1 + lcrs_leaf_count(t->rs);

    return lcrs_leaf_count(t->lc) + lcrs_leaf_count(t->rs);
}

int lcrs_height (lcrs_tree t)
{
    if (t == NULL)
        return 0;

    int hc = 1 + lcrs_height(t->lc);
    int hs = lcrs_height(t->rs);

    return hc > hs ? hc : hs;
}
