#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node Node;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *create_node(int num);
Node *insert_node(Node *root, int data);
void print_list(Node *root);

int main()
{
    printf("Trees...\n");
    Node *root = create_node(10);
    insert_node(root, 9);
    insert_node(root, 30);
    insert_node(root, -1);
    insert_node(root, 0);
    print_list(root);
    printf("\n");

    return 0;
}
Node *create_node(int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *insert_node(Node *root, int data)
{
    if (root->data > data)
    {
        if (!root->left)
        {
            Node *node = create_node(data);
            root->left = node;
            return node;
        }
        return insert_node(root->left, data);
    }
    if (!root->right)
    {
        Node *node = create_node(data);
        root->right = node;
        return node;
    }
    return insert_node(root->right, data);
}
void print_list(Node *root)
{
    if (!root)
        return;

    print_list(root->left);
    printf("%d ", root->data);
    print_list(root->right);
}