/* C++ program to count the lenght of a link list Or count the number of nodes
	available in the link list*/

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

/*Given a reference(pointer to pointer) to the head of the list
	push an element to the link list */
void push(Node **head, int val)
{
	//Allocate Node
	Node *ptr = new Node();

	//Put the data to the new node
	ptr->data = val;

	//Link the list to the new node
	ptr->next = (*head);
	//Move the head to point the new node
	(*head) = ptr;
}

//Count no of nodes in the link list
int getCount (Node *head)
{
	int count = 0;	//Initialize count
	Node *current  = head;	//Initialize current

	while(current != NULL)
	{
		count ++;
		current = current->next;//Move current to the next node
	}
	return count;
}

int main()
{
	//Start a new list
	Node *head  = NULL;
	cout << "Link list has been created successfully" << endl;

	//Use push to insert element to the list
	push(&head, 5);
	push(&head, 2);
	push(&head, 9);
	push(&head, 4);
	push(&head, 7);

	cout << "Number of nodes are: " << getCount(head) << endl;
	push(&head, 12);
	push(&head, 17);

	cout << "Number of nodes are: " << getCount(head) << endl;

	return 0;

}


/*###############################################

Output:
Link list has been created successfully
Number of nodes are: 5
Number of nodes are: 7

################################################*/