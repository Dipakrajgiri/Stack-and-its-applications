#include <iostream>
using namespace std;
template <class t>
class Stack
{
public:
	int top;
	int maxSize;
	t *array;
	Stack(int max) // Constructor for creating stack
	{
		top = -1;
		maxSize = max;
		array = new t[max];
	}

	bool isFull()
	{
		// cout<<"Should return true if stack is full and false if stack is not full"<<endl;
		return (top == maxSize - 1);
		// Change the return
	}

	bool isEmpty()
	{
		// cout<<"Should return true if stack is empty and false if stack is not empty"<<endl;
		return (top == -1);
		// Change the return
	}

	void push(t item)
	{
		if (!isFull())
		{
			top++;
			array[top] = item;
		}
		else
		{
			cout << "stack is full cannot push\n";
		}
	}

	t pop()
	{
		// cout<<"Should pop from stack"<<endl;
		if (!isEmpty())
		{
			top--;
			return array[top + 1];
		}
		else
		{
			cout << "stack is empty cannot pop\n";
			return array[top]; // it will return undefined value
		}

		// Change the return
	}

	t peek()
	{
		// cout << "Should peek item in stack" << endl;
		if (!isEmpty())
		{
			return array[top];
		}
		else
		{
			cout << "stack is empty cannot pop\n";
			return array[top]; // it will return undefined value
		}

		// Change the return
	}

	void displayStack()
	{
		if (isEmpty())
		{
			cout << "Stack is empty!\n";
		}
		else
		{
			cout << "\nStack: ";
			for (int i = 0; i <= top; i++)
				cout << array[i] << " ";
			cout << "\n";
		}
	}
};
