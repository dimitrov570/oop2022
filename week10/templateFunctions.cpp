#include <iostream>
#include <vector>
#include <string>
#include <set>


//template max
template <typename T> 
T max(T a, T b)
{
    return a > b ? a : b;
}

//template swap
template <typename K>
void mySwap(K& a, K& b)
{
    K tmp = a;
    a = b;
    b = tmp;
}

//special case
void mySwap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

//print vector of ints
void printIntVector(std::vector<int>& vec)
{
    //with index
    std::cout << "Print with index: \n";

    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << '\n';
    }

    //with explicitly declared iterator
    std::cout << "Print with iterator: \n";

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << '\n';
    }

    //with auto for iterator
    std::cout << "Print with iterator (auto): \n";

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << '\n';
    }
 
    //with foreach
    std::cout << "Print with foreach: \n";

    for (auto x : vec)
    {
        std::cout << x <<'\n';
    }
}


//print template vector with T as type of values
template <typename T>
void printVector(std::vector<T>& vec)
{
    //with index
    std::cout << "Print with index: \n";
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << '\n';
    }

    //with explicitly declared iterator
    std::cout << "Print with iterator: \n";

    for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << '\n';
    }

    //with auto for iterator
    std::cout << "Print with iterator (auto): \n";

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << '\n';
    }

    std::cout << "Print with foreach: \n";

    //with foreach
    for (auto x : vec)
    {
        std::cout << x <<'\n';
    }
}

//print container of type T
template <typename K>
void printContainer(K& container)
{
    //with explicitly declared iterator
    std::cout << "Print with iterator: \n";

    for (typename K::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << '\n';
    }
 
    //with auto for iterator
    std::cout << "Print with iterator (auto): \n";

    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << '\n';
    }
    
    //with foreach
    for (auto x : container)
    {
        std::cout << x <<'\n';
    }
}

int main()
{

    // std::vector<int> intVec;
    // intVec.push_back(1);
    // intVec.push_back(123);
    // intVec.push_back(43);
    // intVec.push_back(-2);
   
    // std::set<int> intSet;

    // intSet.insert(1);
    // intSet.insert(4);
    // intSet.insert(-2);

    // printContainer(intSet); 


    std::pair<std::string, std::pair<int, double>> intPair = {"hello", {4, 2.3} };

    std::cout << intPair.first << " " << intPair.second.first << " " << intPair.second.second << '\n';

    return 0;
}