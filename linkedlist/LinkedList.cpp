#include <iostream>

using namespace std;

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
    while (NULL != temp->next)
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
    node *temp = *head,*prev = NULL;
    while(NULL != temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    temp = NULL;
}
void delete_after(node *prev_node)
{
    if((NULL == prev_node) || (NULL == prev_node->next))
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
int getcount(node *head)
{
    if (NULL == head)
        return 0;
    else
    {
        return (1 + getcount(head->next));
    }
}
bool search(node *head,int key)
{
    if(NULL == head)
    return false;
    if(head->data  == key)
    return true;
    return search(head->next,key);
}
void swap(node **head,int x,int y)
{
    if(x == y)
    return;
    node *currX= NULL, *prevX=NULL,*currY=NULL,*prevY=NULL;
    currX = *head, currY = *head;
    while((currX != NULL) && (currX->data!=x))
    {
        prevX = currX;
        currX = currX->next;
    }
    while((currY != NULL) && (currY->data!=x))
    {
        prevY = currY;
        currY = currY->next;
    }
    if(prevX!=NULL)
        prevX->next = currY;
    else
        *head = currY;
    if(prevY!=NULL)
        prevY->next = currX;
    else
        *head = currX;
    node *temp = currX->next;
    currX->next = currY->next;;
    currY->next = temp;
    
}
int main()
{
    node *head = NULL;
    int ch , data;
    cout<<"1.Insert front\n2.Insert back\n3.Insert After\n4.Delete Front\n5.DeleteBack\n6.DeleteAfter\n7.Delete Key\n";
    cout<<"8.Display\n9.Exit\n";
    do
    {
        cout<<"Enter choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter data\n";
            cin>>data;
            insert_front(&head,data);
            break;
            case 2:
            cout<<"Enter data\n";
            cin>>data;
            insert_back(&head,data);
            break;
            case 3:
            cout<<"Enter data\n";
            cin>>data;
            insert_after(head->next,data);
            break;
            case 4:
            delete_first(&head);
            break;
            case 5:
            delete_last(&head);
            break;
            case 6:
            delete_after(head->next);
            break;
            case 7:
            cout<<"Enter key\n";
            cin>>data;
            delete_key(&head,data);
            break;
            case 8:
            display(head);
            break;
            case 9:
            return 0;
            default:
            cout<<"Invalid choice\n";
        }
        
    }
    while(1);
    getchar();
    return 0;
}