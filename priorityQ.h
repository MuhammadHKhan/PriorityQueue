#include <iostream>
#include <algorithm>

using namespace std;
/*This class takes care of the heapArray
and all of its operations, such as insert, delte, bubbleUP
and bubbleDown.*/


template <class Type>
class priorityQ
{
public:
	priorityQ(int = 11);
	priorityQ(const priorityQ <Type>&);
	~priorityQ();
	const priorityQ<Type>& operator=(const priorityQ<Type>&);
	void insert(const Type&);
	void deleteHighestPriority();
	Type getHighestPriority() const;
	bool isEmpty() const;
	void bubbleUp(int);
	void bubbleDown(int);
	int getSize() const;
private:
	int capacity;
	int items;
	Type* heapArray;
};

//constructor that sets capacity and allocates a new heap array
template <class Type>
priorityQ<Type>::priorityQ(int capacity)
{
	this->capacity = capacity;
	heapArray = new Type[capacity];
	items = 1;
}

//copy constructor, copys this to copy
template <class Type>
priorityQ<Type>::priorityQ(const priorityQ<Type>& copy)
{
	*this = copy;
}
//destructor that deallocates the array.
template <class Type>
priorityQ<Type>::~priorityQ()
{
	delete[] heapArray;
}

//operator overload for = operator, sets this to rhs;
template <class Type>
const priorityQ<Type>& priorityQ<Type>::operator=(const priorityQ<Type>& rhs)
{
	if (*this != rhs)
	{
		delete this->heapArray;
	}
	*this = rhs;
}
//insert function, inserts element at 
//the end of the heap array.
template <class Type>
void priorityQ<Type>::insert(const Type& element)
{
	if (items < capacity)
	{
		heapArray[items] = element;
		bubbleUp(items);
		items++;
	}
	else
		return;
}

//deletes the element that has the highest priority
//which is the root, also checks if the array is empty
//or not. Calls bubbledown on root
template <class Type>
void priorityQ<Type>::deleteHighestPriority()
{
	bool a = isEmpty();
	if (a)
	{
		return;
	}
	else
	{
		items--;
		heapArray[1] = heapArray[items];
		bubbleDown(1);
	}
}

//returns the first element in the array
template <class Type>
Type priorityQ<Type>::getHighestPriority() const
{
	return heapArray[1];
}

//checks to see if teh array is empty, if it is
//return true, if not, return false
template <class Type>
bool priorityQ<Type>::isEmpty() const
{
	if (items == 0)
	{
		return true;
	}
	else
		return false;
}

//bubbleUp function helps bubbleUp the element at
//index, and this is going to be a recursive function
//compare the parent to the index, and move on accordingly
template <class Type>
void priorityQ<Type>::bubbleUp(int index)
{
	if (index/2 < 1)
	{
		return;
	}
	if (heapArray[index] < heapArray[index / 2])
	{
		Type tmp = heapArray[index];
		heapArray[index] = heapArray[index / 2];
		heapArray[index / 2] = tmp;
		index = index / 2;
		bubbleUp(index);
	}
	else
		return;
}
//bubbledown function bubbles down the element at index
//compares to the left and right child and calls bubbleDown
//recursively, if not, then just return.
template <class Type>
void priorityQ<Type>::bubbleDown(int index)
{

	int use = index;
	int left = index * 2;
	int right = (index * 2) + 1;
	int a = getSize();
	if (left <= a && heapArray[left] < heapArray[right])
	{
		if (heapArray[index * 2] < heapArray[index])
		{
			swap(heapArray[index * 2], heapArray[index]);
			return bubbleDown(index * 2);
		}
		else
		{
			return;
		}
	}

	else if (right <= a && heapArray[right] < heapArray[left])
	{
		if (heapArray[index * 2 + 1] < heapArray[index])
		{
			swap(heapArray[index * 2 + 1], heapArray[index]);
			return bubbleDown(index * 2 + 1);
		}
		else
		{
			return;
		}
	}
}

//returns the amount of items in the array.
template <class Type>
int priorityQ<Type>::getSize() const
{
	return items;
}