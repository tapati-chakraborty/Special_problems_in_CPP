/*C++ Program to delete a linklist*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/*Link list Node*/
class Node
{
	public:
		int data;
		Node *next;
};

//Traverse the list
void linklistTraversal(Node *ptr)
{
	while(ptr != NULL)
	{
		cout << "The element is: " << ptr->data << endl;
		ptr = ptr->next;
	}

}

//Function to delete the entire link list
void deleteLinkList(Node **head)
{
	Node *current = *head;
	Node *next;
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

//Given a reference(pointer to pointer) to the head of the list
void push(Node **head, int val)
{
	//Allocate Node
	Node *ptr = new Node();

	//Put the data
	ptr->data = val;
	//link the old list to the new Node
	ptr->next = (*head);
	//move the head to point the new node
	(*head) = ptr;
}

int main()
{
	//Start with  the empty list
	Node *head = NULL;

	//Use push to create the below list
	push(&head, 5);
	push(&head, 6);
	push(&head, 8);
	linklistTraversal(head);

	cout << "Deleting link list" << endl;
	deleteLinkList(&head);

	cout << "Link list deleted" << endl;

	free(head);
	return 0;
}

/*###############################################
Output:

The element is: 8
The element is: 6
The element is: 5
Deleting link list
Link list deleted
################################################*/