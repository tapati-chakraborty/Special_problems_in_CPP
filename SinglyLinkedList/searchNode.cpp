/*C++ program to search an element in the link list */

#include <iostream>
#include <stdlib.h>

using namespace std;

/*Link list node*/
class Node
{
	public:
		int data;
		Node * next;
};

/*Given a reference(pointer to pointer) to the head of the list
	push an element to the link list */
void push(Node **head, int val)
{
	//Allocate a Node
	Node *ptr = new Node();

	//Put the data to the new node
	ptr->data = val;

	//Link the list to the new node
	ptr->next = (*head);
	//Move the head to point the new node
	(*head) = ptr;
}

//Method to search an element in the link list
bool searchValue(Node *head)
{
	int x;
	Node *current = head;

	cout << "enter an element: " << endl;
	cin >> x;

	while(current != NULL)
	{
		if(current->data == x)
			return true;
		current = current->next;
	}
	return false;
}

int main()
{
	//Start a new list
	Node *head = NULL;
	cout << "Link list has been created successfully" << endl;

	//Use push to insert an element to the link list
	push(&head, 5);
	push(&head, 32);
	push(&head, 56);
	push(&head, 6);
	push(&head, 38);

	if(searchValue(head))
		cout << "Yes! The elemnt is present here." << endl;
	else
		cout << "Sorry! The element is not here." << endl;


	return 0;
}

/*############################################################

Output:

Link list has been created successfully
enter an element:
32
Yes! The elemnt is present here.

Link list has been created successfully
enter an element:
70
Sorry! The element is not here.

#############################################################*/