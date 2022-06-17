#pragma once
#include <iostream>
#include <exception>

template <typename T>
struct Node
{
    T value;
    Node* next;
};

template <typename T>
class LinkedList
{
    Node<T>* first;
    size_t size;

public:

    LinkedList();

    void push_front(const T& v);
    void push_back(const T& v);
    void insert_at(size_t index, const T& value);
    void pop_front();
    void pop_back();
    void remove_at(size_t index);

    const T& peek_front() const;
    const T& peek_back() const;
    const T& peek_at(size_t index) const;
    
    // recursive versions
    void push_back_rec(const T& value)
    {   
        // calling recursive helper function
        first = _push_back_recursive(first, value);
    }

    void remove_at_rec(size_t index) // doesn't return removed value
    {
        if (index >= size)
        {
            std::cerr << "Invalid index!\n";
            return;
        }
        // calling recursive helper function
        first = _remove_at_recursive(first, index);
    }

    void print() const;
    size_t getSize() const
    {
        return size;
    }

    ~LinkedList();

private:
    Node<T>* _push_back_recursive(Node<T>*, const T&);
    Node<T>* _remove_at_recursive(Node<T>*, size_t);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    first = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::push_front(const T& v)
{
    Node<T>* toAdd = new Node<T>();
    toAdd->value = v;
    toAdd->next = first;
    first = toAdd;
    ++size;
}

template <typename T>
Node<T>* LinkedList<T>::_push_back_recursive(Node<T>* current, const T& value)
{
    if (current == nullptr)
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->next = nullptr;
        ++size;
        return newNode;
        std::cout << "reached nullptr\n";
    }

    current->next = _push_back_recursive(current->next, value);
    return current;
}

template <typename T>
Node<T>* LinkedList<T>::_remove_at_recursive(Node<T>* current, size_t index)
{
    if(index == 0)
    {
        Node<T>* tmp = current->next;
        delete current;
        --size;
        return tmp;
    }

    current->next = _remove_at_recursive(current->next, --index);
    return current;
}

template <typename T>
void LinkedList<T>::push_back(const T& v)
{
    Node<T>* tmp = first;

    if(tmp == nullptr)
    {
        tmp = new Node<T>();
        tmp->value = v;
        tmp->next = nullptr;
        first = tmp;
        ++size;
        return;
    }

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = new Node<T>();
    tmp->next->value = v;
    tmp->next->next = nullptr;
    ++size;
}

template <typename T>
void LinkedList<T>::insert_at(size_t index, const T& value)
{
    if (index > size) // не е >= защото можем да добавяме и в края
    {
        std::cerr << "Invalid index\n";
        return;
    }

    if(index == 0)
    {
        push_front(value);
        return;
    }

    Node<T>* tmp = first;
    int counter = 1;

    while(counter < index)
    {
        tmp = tmp->next;
        ++counter;
    }

    Node<T>* newNode = new Node<T>();
    newNode->value = value; 
    newNode->next = tmp->next;
    tmp->next = newNode;
    ++size;
}

template <typename T>
void LinkedList<T>::pop_front() 
{
    if (first == nullptr)
    {
        std::cerr << "List is empty\n";
    }

    Node<T>* tmpPtr = first->next; // <=> (*first).next;
    delete first;
    first = tmpPtr;
    --size;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if(first == nullptr)
    {
        std::cerr << "List is empty\n";
    }

    Node<T>* tmp = first;
    Node<T>* tmpNext = first->next;

    if(tmpNext == nullptr)
    {
        pop_front();
        return;
    }

    while(tmpNext->next != nullptr)
    {
        tmp = tmpNext;
        tmpNext = tmpNext->next;
    }
    

    delete tmpNext;
    tmp->next = nullptr;
    --size;
}

template <typename T>
void LinkedList<T>::remove_at(size_t index)
{
    if (index >= size)
    {
        std::cerr << "Invalid index\n";
    }

    if(index == 0)
    {
        pop_front();
        return;
    }
    
    Node<T>* tmp = first;
    Node<T>* tmpNext = first->next;
    int counter = 0;

    while(counter < index - 1)
    {
        tmp = tmp->next;
        tmpNext = tmpNext->next; 
        ++counter;
    }
    
    tmp->next = tmpNext->next;
    delete tmpNext;
    --size;    
}

template <typename T>
const T& LinkedList<T>::peek_front() const
{
    if (first == nullptr)
    {
        throw std::logic_error("List is empty!");
    }

    return first->value;
}

template <typename T>
const T& LinkedList<T>::peek_back() const
{
    if (first == nullptr)
    {
        throw std::logic_error("List is empty!");
    }

    Node<T>* tmp = first;

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    return tmp->value;
}

template <typename T>
const T& LinkedList<T>::peek_at(size_t index) const
{
    if (index >= size)
    {
        throw std::logic_error("Invalid index!");
    }

    if(index == 0)
    {
        return peek_front();
    }

    Node<T>* tmp = first;
    int counter = 0;

    while(counter < index)
    {
        tmp = tmp->next; 
        ++counter;
    }

    return tmp->value;
}

template <typename T>
void LinkedList<T>::print() const
{
    Node<T>* tmp = first;

    if(first == nullptr)
    {
        std::cout << "Empty!\n";
        return;
    }

    while(tmp != nullptr)
    {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* tmp;
    Node<T>* tmpNext;

    if(first!=nullptr)
    {
        tmp = first;
        tmpNext = first->next;
        while(tmpNext != nullptr)
        {
            delete tmp;
            tmp = tmpNext;
            tmpNext = tmpNext->next;
        }
        delete tmp;
    }
}