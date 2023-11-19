#ifndef ELEMENT_H
#define ELEMENT_H

typedef int Data;

#include <iostream>

class Element{
    Element *prev;
    Element *next;
    Data data;

public:
    Element(Data data) : prev(nullptr), next(nullptr), data(data) {}
    Element() : prev(nullptr), next(nullptr), data(0) {}
    
    void setData(Data data) { this->data = data; }
    Data getData() const { return data; }
    void print() const { std::cout << getData(); }
    
    void printLn() const { print(); std::cout << std::endl; }
    
    friend class List;
};

#endif // ELEMENT_H
