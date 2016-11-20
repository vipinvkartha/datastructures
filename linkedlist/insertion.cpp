#include <iostream>
using namespace std;

class LinkedList
{
	int data;
	LinkedList *next;
	public:
	LinkedList()
	{
		data = 0;
		next = NULL;
	}

	void insert(LinkedList **,int);
	void display(LinkedList *);
};
void LinkedList::insert(LinkedList **head,int data1)
{
	LinkedList *node = NULL,*temp = NULL;
	node = new LinkedList;
	node->next = NULL;
	node->data = data1;
	if (NULL == *head)
	{
		*head = node;
	}
	else
	{
		temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}
void LinkedList::display(LinkedList *head)
{
	LinkedList *temp = NULL;
	temp = head;
	while (temp->next != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

int main()
{
	LinkedList *head = NULL;
	LinkedList list1;
	list1.insert(&head,5);
	list1.insert(&head,4);
	list1.insert(&head,6);
	list1.insert(&head,7);
	list1.insert(&head,1);
	list1.display(head);
	getchar();
}