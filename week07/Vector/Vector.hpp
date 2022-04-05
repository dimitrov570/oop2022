#pragma once
#include <ostream>

class Vector
{
private:
	int* data;
	unsigned int capacity;
	int size;

public:
	
	Vector();
	Vector(unsigned int);
	Vector(const Vector& other);
	Vector& operator=(const Vector& rhs);
	~Vector();

	int getAt(int) const;
	int getLast() const;
	int getCapacity() const;
	unsigned int getNumberOfElements() const;
	bool isEmpty() const;
	bool isFull() const;

	bool setAt(int index, int value);
	void push_back(int);
	int pop_back();
	
  void print(std::ostream&) const;

private:
	bool indexIsInRange(int) const;
	void shrink();
	void expand();

  static void copyData(int* from, int* to, int nr_of_elements);
};