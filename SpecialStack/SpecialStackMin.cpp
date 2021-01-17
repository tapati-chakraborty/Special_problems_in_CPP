/*Cpp program to design and implement a special stack*/

/*The stack here implemented has all the stack functions such as push(),pop()
	isFull(),isEmpty() and another  extra function gitMin() which return the
	min value present in the stack*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/*stack class with basic stack functionalitis*/
class Stack
{
	private:
		static const int max = 100;
		int arr[max];
		int top;
	public:
		Stack()//constructor
		{
			top = -1;//At first the top is set as -1
		}
		bool isFull();
		bool isEmpty();
		void push(int x);
		int pop();
};

/*Stack's member method to check if the stack is full*/
bool Stack::isFull()
{
	if(top == max-1)
		return true;
	else
		return false;

}

/*Stack's member method to check if the stack is empty*/
bool Stack::isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;

}

/*Stack's member method to push an element to the stack*/
void Stack::push(int x)
{
	if(isFull())
		cout << "Stack Overflow!" << endl;
	else
	{
		top++;
		arr[top] = x;
	}

}

/*Stack's member method to remove an element from the stack*/
int Stack::pop()
{
	int x;
	if(isEmpty())
		cout << "Stack Underflow!" << endl;
	else
	{
		x = arr[top];
		top--;

	}
	return x;

}

/*A class that support all the functionalitis of Stack and holds an additional
	function getMin() which return the minimum value from the stack at any time.
	This class inherits from Stack class and uses an auxiliary stack that
	holds the min value.*/
class SpecialStack:public Stack
{
	Stack auxiliarystack;	//------>Stack object

	public:
		int pop();
		void push(int x);
		int getMin();
};

/*SpecialStack's member method to insert an element to the stack.
	This method make sure that the auxiliary stack also updated with the
	minimum value.*/
void SpecialStack::push(int x)
{
	if(isEmpty() == true)
	{
		Stack::push(x);
		auxiliarystack.push(x);
	}
	else
	{
		Stack::push(x);
		int y = auxiliarystack.pop();
		auxiliarystack.push(x);
		if(x < y)//Check if the inserted element is lesser than remaining elements
			auxiliarystack.push(x);//if true then push the new element to the auxiliary stack
		else
			auxiliarystack.push(y);//else push the same element to the stack again

	}

}

/*SpecialStack's member method to remove top most element from the stack.
	This method also remove top most element from the auxiliary stack.*/
int SpecialStack::pop()
{
	int x = Stack::pop();
	auxiliarystack.pop();
	return x;
}

/*SpecialStack's method to get the minimum value of it*/
int SpecialStack::getMin()
{
	int x = auxiliarystack.pop();
	auxiliarystack.push(x);
	return x;
}

/*Driver program to test the Special Stack*/
int main()
{
	SpecialStack sp;	//------->SpecialStack object
	cout << "Special Stack has been created successfully" << endl;
	sp.push(52);
	sp.push(34);
	sp.push(67);

	cout << "The min value is: ";
	cout << sp.getMin() << endl;
	sp.push(3);

	cout << "The min value is: ";
	cout << sp.getMin() << endl;

	return 0;
}

/*##################################################

Output:

Special Stack has been created successfully
The min value is: 34
The min value is: 3

###################################################*/