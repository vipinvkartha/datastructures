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
void insert_after(node *prev_node,int val)
{
    if(NULL == prev_node)
    {
        cout<<"previous node cannot be NULL\n";
        return;
    }
    node *new_node = new node;
    new_node->data = val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void delete_first(node **head)
{
    if(*head == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    delete temp;
    temp = NULL;
}
void delete_last(node **head)
{
    if(*head == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    node *temp = *head;
    while(NULL != temp->next)
    {
        temp = temp->next;
    }
    delete temp;
    temp = NULL;
}
void delete_after(node *prev_node)
{
    if((NULL == prev_node) || (NULL != prev_node-next))
    {
        cout<<"previous node cannot be NULL\n";
        return;
    }
    node *temp = prev_node->next;
    prev_node->next = temp->next;
    delete temp;
    temp = NULL;
}
void delete_key(node **head,int key)
{
    if (NULL == *head)
    {
        cout<<"List empty\n";
        return;
    }
    node *temp  = *head,*prev = NULL;
    if(temp->data == key)
    {
        *head = (*head)->next;
        delete temp;
        temp = NULL;
    }
    while((temp != NULL)&& (temp->data != key))
    {
        prev = temp;
        temp = temp->next;
    }
    if(NULL == temp)
    {
        cout<<"Key not found\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    temp = NULL;
}
void display(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;
    int ch , data;
    cout<<"1.Insert front\n2.Insert back\n3.Insert After\n4.Delete Front\n5.DeleteBack\n6.DeleteAfter\n7.Delete Key\n";
    cout<<"8.Display\n9.Exit\n"
    do
    {
        cout<<"Enter choice\n";
        cin>>choice;
        
    }
}