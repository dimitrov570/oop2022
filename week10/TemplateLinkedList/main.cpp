#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList<int> lst;

    lst.push_back(1);
    lst.push_back_rec(4); // recursive version
    lst.push_front(0);

    lst.insert_at(2, 2);
    lst.insert_at(3, 3);

    lst.print();

    std::cout << "List size: " << lst.getSize() << '\n';
    std::cout << "Front: " << lst.peek_front() << "; Back: " << lst.peek_back() << "; At 2nd index: " << lst.peek_at(2) << '\n';

    // std::cout << "Removing at 3rd index: " << lst.remove_at(3) << '\n';
    std::cout << "Removing at 3rd index recursively!\n";
    lst.remove_at_rec(3);
    
    lst.print();
    std::cout << "Popping back: " << lst.peek_back() << '\n';
    lst.pop_back();
    lst.print();
    std::cout << "Popping front: " << lst.peek_front() << '\n';
    lst.pop_front();
    lst.print();
    std::cout << "Popping front: " << lst.peek_front() << '\n';
    lst.pop_front();
    lst.print();
    std::cout << "Popping front: " << lst.peek_front() << '\n';
    lst.pop_front();
    lst.print();
    
    //empty
    std::cout << "List size: " << lst.getSize() << '\n';
    std::cout << "Popping front: " << lst.peek_front() << '\n'; // should throw exception
    lst.pop_front();
    lst.print();
    std::cout << "Popping back: " << lst.peek_back() << '\n';
    lst.pop_back();
    lst.print();
    return 0;
}