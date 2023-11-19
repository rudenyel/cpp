#include "list.h"


List::List() : first(new Element()), last(new Element()), counter(0) { initList(); }

List::~List(){
    clear();
    delete first;
    delete last;
}

//copy elements from source list into this list
void List::copyDataFrom(List &source){
    Element *iter = source.first->next;
    while(iter!=source.last){
        this->pushBack(iter->getData());
        iter = iter->next;
    }
}

List::List(List &other) : first(new Element), last(new Element), counter(0) {
    initList();
    copyDataFrom(other);
}

void List::clear(){
    while(!isEmpty()){
        popFront();
    }
}

void List::initList(){
    first->next = last;
    last->prev = first;
}

void List::pushBack(Data d){
    last->next = new Element;
    last->setData(d);
    last->next->prev = last;
    last = last->next;
    counter++;
}

/*
 * last <-> first
 * next <-> prev
*/
void List::pushFront(Data d){
    first->prev = new Element;
    first->setData(d);
    first->prev->next = first;
    first = first->prev;
    counter++;
}

void List::popFront(){
    if(!isEmpty()){
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        counter--;
    }
}

void List::popBack(){
    if(!isEmpty()){
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        counter--;
    }
}

void List::print() const{
    /*Element* current;
    current = first->next;
    while (current != last) {
        current->printLn();
        current = current->next;
    }*/

    for (Element *iter = first->next; iter != last; iter = iter->next) {
        iter->printLn();
    }
}


Element* List::find(Data data){
    last->setData(data);
    Element *iter = first->next;
    while (iter->getData() != data) {
        iter = iter->next;
    }
    return iter == last ? nullptr : iter;
}

bool List::remove(Data data){
    Element *del = find(data);
    if (!del) {
        return del;
    }
    del->prev->next = del->next;
    del->next->prev = del->prev;
    delete del;
    counter--;
    return true;
}

void List::swap(Element* a, Element* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Element* List::findMin(Element* node){
    Element *min = node;
    Element* current = node->next;
    Data minData = node->getData();
    while (current != last) {
        if (current->getData() < minData) {
            min = current;
            minData = current->getData();
        }
        current = current->next;
    }
    return min;
}

void List::sort()
{
    Element* current = first->next;
    while (current != last) {
        swap(current, findMin(current));
        current = current->next;
    }
} 
