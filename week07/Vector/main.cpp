#include <iostream>
#include "Vector.hpp"

int main()
{
	Vector myVector;
	
	std::cout << "Adding 3" << '\n';
	myVector.push_back(3);
	std::cout << "Adding 10" << '\n';
	myVector.push_back(10);

	myVector.print(std::cout);
	std::cout << "Capacity: " << myVector.getCapacity() << '\n';
	std::cout << "Last element: " << myVector.getLast() << '\n';

	std::cout << "Adding -20" << '\n';
	myVector.push_back(-20); // capacity should increase to 4
	std::cout << "Capacity: " << myVector.getCapacity() << '\n';
	std::cout << "Last element: " << myVector.getLast() << '\n';

	std::cout << "Adding -30" << '\n';
	myVector.push_back(-30);
	
	std::cout << "Adding -45" << '\n';
	myVector.push_back(-45); // capacity should increase to 8
	std::cout << "Capacity: " << myVector.getCapacity() << '\n';
	std::cout << "Last element: " << myVector.getLast() << '\n';
	
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Popping element: " << myVector.pop_back() << '\n';
		std::cout << "Number of elements is: " << myVector.getNumberOfElements() << '\n';
		std::cout << "Capacity is: " << myVector.getCapacity() << '\n';
	}

	Vector secondVector = myVector; //copy constructor
	Vector thirdVector;
	thirdVector = secondVector; //operator=

	return 0;
}