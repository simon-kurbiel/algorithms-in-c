#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Node *insertBeginning(Node *head, int data)
{
    Node *node = createNode(data);
    node->next = head;
    return node;
}
void freeEverything(Node *head)
{
    Node *curr = head;
    Node *next;

    while (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
void printList(Node *head)
{
    if (!head)
    {
        printf("Done\n");
        return;
    }
    printf("%d ", head->data);
    printList(head->next);
}
int main()
{
    printf("Main file...\n");
    Node *head = createNode(10);
    head = insertBeginning(head, 9);
    head = insertBeginning(head, 8);
    printList(head);
    freeEverything(head);
    return 0;
}