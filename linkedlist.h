#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "host.h"

typedef struct node_tag {
    THost host;
    struct node_tag *next;
} node;

node *create_node(THost host);
void add_first(node **head, node *newnode);
node *remove_first(node **head);
void remove_all(node **head);
int location_match(node *head, THost host);

#endif // LINKEDLIST_H