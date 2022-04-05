#include "Vector.hpp"
#include <iostream>
#include <string>

const int INITIAL_CAPACITY = 2;

// when vector is full increase size EXPAND_COEFFICIENT times
const int EXPAND_COEFFICIENT = 2; 

// when condition for shrink is true decrease size SHRINK_COEFFICIENT times
const int SHRINK_COEFFICIENT = 2; 

// const std::string EMPTY_VECTOR_MESSAGE = "Vector is empty! Returning 0.";

Vector::Vector() : capacity(INITIAL_CAPACITY), size(0) {
	data = new int[capacity];
}

Vector::Vector(unsigned int _capacity) : size(0)
{
	if (_capacity == 0)
	{
		std::cerr << "Size must be positive integer value! Setting size to: " << INITIAL_CAPACITY << '\n';
		capacity = INITIAL_CAPACITY;
	}
	else
	{
		capacity = _capacity;
	}

	data = new int[capacity];
}

Vector::Vector(const Vector& other) : capacity(other.capacity), size(other.size)
{
	data = new int[capacity];

	copyData(other.data, data, size);
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete[] data;
		capacity = rhs.capacity;
		size = rhs.size;
		data = new int[capacity];
		copyData(rhs.data, data, size);
	}
	return *this;
}

Vector::~Vector()
{
	delete[] data;
}

int Vector::getAt(int index) const
{
	if(indexIsInRange(index))
	{
    return data[index];
	}
  
	std::cerr << "Vector is empty! Returning -1." << '\n';
  return -1; 
}

int Vector::getLast() const
{
	if (isEmpty())
	{
		std::cerr << "Vector is empty! Returning -1." << '\n';
		return -1;
	}
	return data[size - 1];
}

int Vector::getCapacity() const
{
	return capacity;
}

bool Vector::isEmpty() const
{
	return size == 0;
}

unsigned int Vector::getNumberOfElements() const
{
	return size;
}

bool Vector::isFull() const
{
	return size == capacity;
}

bool Vector::setAt(int index, int value)
{
	if (indexIsInRange(index))
	{
		data[index] = value;
		return true;
	}

	return false;
}

void Vector::push_back(int value)
{
	if (isFull()) // if there is no space left to add, increase vector size
	{
		expand();
	}

	data[size++] = value;
}

int Vector::pop_back()
{
	if (isEmpty())
	{
		std::cerr << "Vector is empty! Returning -1." << '\n';
		return -1;
	}
	
	// if vector size decreased to 1/4 of the capacity (size <= capacity/4)
	// then shrink it to half size 	
	
	if(size <= capacity / (SHRINK_COEFFICIENT * SHRINK_COEFFICIENT))
	{
		shrink();
	}

	return data[--size]; //return value stored at size - 1, and then decrement size (prefix)
}

bool Vector::indexIsInRange(int index) const
{
	return index >= 0 && index < size;
}

void Vector::shrink()
{
	int newCapacity = capacity / SHRINK_COEFFICIENT;

	int *newDataArray = new int[newCapacity]; //create new array to store values
	
	// copy values in new array
	copyData(data, newDataArray, size);

	// free memory allocated for old (larger) data array
	delete[] data;
	capacity = newCapacity;

	// set data pointer to point to new array with values
	data = newDataArray;
}

void Vector::expand()
{
	int newCapacity = capacity * EXPAND_COEFFICIENT;

	int *newDataArray = new int[newCapacity];

	// copy values in new array
	copyData(data, newDataArray, size);

	// free memory allocated for old (smaller) data array
	delete[] data;

	capacity = newCapacity;

	// set data pointer to point to new array with values
	data = newDataArray;
}

void Vector::copyData(int* from, int* to, int nr_of_elements) {
  for (int i = 0; i < nr_of_elements; ++i)
	{
		to[i] = from[i];
	}
}

void Vector::print(std::ostream& o) const
{
	if (isEmpty())
	{
		o << "Vector is empty!";
	}
  else 
  {
    for (int i = 0; i < size; ++i)
	  { 
		  o << i << ": " << data[i] << '\n';
	  }
  }
}