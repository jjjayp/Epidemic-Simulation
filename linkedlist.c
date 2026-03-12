#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

node *create_node(THost host) {
    node *newnode = malloc(sizeof(node));
    if (!newnode) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newnode->host = host;
    newnode->next = NULL;
    return newnode;
}

void add_first(node **head, node *newnode) {
    newnode->next = *head;
    *head = newnode;
}

node *remove_first(node **head) {
    if (*head == NULL) return NULL;
    node *first = *head;
    *head = first->next;
    first->next = NULL;
    return first;
}

void remove_all(node **head) {
    while (*head != NULL) {
        node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

int location_match(node *head, THost host) {
    while (head != NULL) {
        if (head->host.x == host.x && head->host.y == host.y)
            return 1;
        head = head->next;
    }
    return 0;
}
