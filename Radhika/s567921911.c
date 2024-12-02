#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag {
    unsigned int key;
    struct nodetag *next;
    struct nodetag *prev;
} Node;

Node *createNode(int key)
{
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = node->prev = NULL;

    return node;
}

void insert(Node *node, Node **tail)
{
    if(*tail == NULL) {
        node->next = node->prev = NULL;
    } else {
        (*tail)->next = node;
        node->prev = *tail;
        node->next = NULL;
    }
    *tail = node; 
}

void delete(int key, Node **tail)
{
    Node *node = *tail;

    while(node != NULL && node->key != key) {
        node = node->prev;
    }
    if(node == NULL)
        return;
    if(node->prev == NULL) {
        (node->next)->prev = NULL;
    } else if(node->next == NULL) {
        (node->prev)->next = NULL;
        *tail = node->prev;
    } else {
        (node->prev)->next = node->next;
        (node->next)->prev = node->prev;
    }
    free(node);
}

void deleteFirst(Node **tail)
{
    Node *node = *tail;

    if(tail == NULL)
        return;

    *tail = (*tail)->prev;
    if(*tail == NULL) {
        free(node);
        return;
    }
    (*tail)->next = NULL;
    free(node);
}

void deleteLast(Node **tail)
{
    Node *node = *tail;

    while(node->prev != NULL) 
        node = node->prev;
    if(node->next == NULL) {
        *tail = NULL;
        free(node);
        return;
    }
    (node->next)->prev = NULL; 
    free(node);
}

int main(void)
{
    int i, n, key;
    char command[11];
    Node *tail = NULL, *node;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", command); 
        if(strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            node = createNode(key);
            insert(node, &tail); 
        } else if(strcmp(command, "delete") == 0) {
            scanf("%d", &key);
            delete(key, &tail);
        } else if(strcmp(command, "deleteFirst") == 0) {
            deleteFirst(&tail);
        } else if(strcmp(command, "deleteLast") == 0){
            deleteLast(&tail);
        } else {
            printf("command not found: %s\n", command);
        }
    }
    printf("%d", tail->key);
    tail = tail->prev;
    while(tail != NULL) {
        printf(" %d", tail->key);
        tail = tail->prev;
    }
    printf("\n");

    return 0;
}