#include <iostream>
#include "Vector.hpp"

int main()
{
	Vector<int> intVector;
	//Vector<> intVector; // default type

	Vector<std::string> stringVector;
	
	intVector.push_back(3);
	intVector.push_back(-2);
	intVector.push_back(44);

	stringVector.push_back("Hello");
	stringVector.push_back("world");
	stringVector.push_back("!");

	std::cout << intVector << '\n';

	std::cout << stringVector << '\n';

	intVector.pop_back();
	stringVector.pop_back();

	std::cout << intVector << '\n';

	std::cout << stringVector << '\n';
	
	return 0;
}