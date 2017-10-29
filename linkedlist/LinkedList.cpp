#include <iostream>

usign namespace std;

typedef struct Node
{
    int data;
    Node *next;
}node;

void insert_front(node **head , int val)
{
    node *new_node = new node;
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}
void insert_back(node **head, int val)
{
    node *new_node = new node;
    new_node->data = val;
    new_node->next = NULL;
    if(NULL == *head)
    {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (NULL != temp-next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
