#pragma once
#include <iostream>

const int INITIAL_SIZE = 2;

// when vector is full increase size EXPAND_COEFFICIENT times
const int EXPAND_COEFFICIENT = 2; 

// when condition for shrink is true decrease size SHRINK_COEFFICIENT times
const int SHRINK_COEFFICIENT = 2; 

const std::string EMPTY_VECTOR_MESSAGE = "Vector is empty! Returning 0.";

template <typename T>
class Vector;

template <typename T>
std::ostream& operator<<(std::ostream& o, const Vector<T>& vector);

template <typename T = int>
class Vector
{
private:
	T* data;
	unsigned int size;
	int lastIndex;

public:
	
	Vector();
	Vector(unsigned int);
	Vector(const Vector& other);
	Vector& operator=(const Vector& rhs);
	~Vector();

	T getAt(int) const;
	T getLast() const;

	
	int getSize() const
	{
		return size;
	}

	void compileTest(T i)
	{
		std::cout << "Has iterator" << '\n';
		auto it = i.begin();
	}

	unsigned int getNumberOfElements() const
	{
		return lastIndex + 1;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	bool isFull() const
	{
		return lastIndex == size - 1;
	}

	bool setAt(int index, const T& value);
	void push_back(const T&);
	void pop_back();
	
	// by returning int& you can write directly to the data array like: vec[i] = 5;
	T& operator[](int) const;

	friend std::ostream& operator<< <> (std::ostream& o, const Vector<T>& vector);

private:
	bool indexIsInRange(int index) const 
	{
		return index >= 0 && index <= lastIndex;
	}

	void shrink();
	void expand();
};

template <typename T>
Vector<T>::Vector() : size(INITIAL_SIZE), lastIndex(-1) {
	data = new T[size];
}

template <typename T>
Vector<T>::Vector(unsigned int _size) : lastIndex(-1)
{
	if (_size == 0)
	{
		std::cerr << "Size must be positive integer value! Setting size to: " << INITIAL_SIZE << '\n';
		size = INITIAL_SIZE;
	}
	else
	{
		size = _size;
	}

	data = new T[size];
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), lastIndex(other.lastIndex)
{
	data = new T[size];

	for (int i = 0; i <= lastIndex; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete[] data;
		size = rhs.size;
		lastIndex = rhs.lastIndex;
		data = new T[size];
		for (int i = 0; i <= lastIndex; ++i)
		{
			data[i] = rhs.data[i];
		}
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
}

template <typename T>
T Vector<T>::getAt(int index) const
{
	if (0 < index || index > lastIndex)
	{
		std::cerr << "Index: " << index << " is out of range! Possible range: [" << 0 << "-" << lastIndex << "]\n";
		return -1;
	}

	return data[index];
}

template <typename T>
T Vector<T>::getLast() const
{
	if (isEmpty())
	{
		std::cerr << EMPTY_VECTOR_MESSAGE << '\n';
		return 0;
	}
	return data[lastIndex];
}

template <typename T>
bool Vector<T>::setAt(int index, const T& value)
{
	if (indexIsInRange(index))
	{
		data[index] = value;
		return true;
	}

	return false;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
	if (isFull()) // if there is no space left to add, increase vector size
	{
		expand();
	}

	data[++lastIndex] = value;
}


template <typename T>
void Vector<T>::pop_back()
{
	if (isEmpty())
	{
		std::cerr << EMPTY_VECTOR_MESSAGE << '\n';
		return;
	}

	
	// if vector size decreased to 1/4 of the maximum size (lastIndex <= size/4)
	// then shrink it to half size 	
	
	if(lastIndex < size / (SHRINK_COEFFICIENT * SHRINK_COEFFICIENT))
	{
		shrink();
	}

	--lastIndex; // decrement lastIndex
}

template <typename T>
void Vector<T>::shrink()
{
	int newSize = size / SHRINK_COEFFICIENT;

	T *newDataArray = new T[newSize]; //create new array to store values
	
	// copy values in new array
	for (int i = 0; i <= lastIndex; ++i)
	{
		newDataArray[i] = data[i];
	}

	// free memory allocated for old (larger) data array
	delete[] data;
	size = newSize;

	// set data pointer to point to new array with values
	data = newDataArray;
}

template <typename T>
void Vector<T>::expand()
{
	int newSize = size * EXPAND_COEFFICIENT;

	T *newDataArray = new T[newSize];

	// copy values in new array
	for (int i = 0; i <= lastIndex; ++i)
	{
		newDataArray[i] = data[i];
	}

	// free memory allocated for old (smaller) data array
	delete[] data;

	size = newSize;

	// set data pointer to point to new array with values
	data = newDataArray;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Vector<T>& vector)
{
	if (vector.isEmpty())
	{
		return o << "Vector is empty!";
	}

	for (int i = 0; i <= vector.lastIndex; ++i)
	{
		o << i << ": " << vector.data[i] << '\n';
	}

	return o;
}