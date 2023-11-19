#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List list;

    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0)
        list.pushBack(i);
      else
        list.pushFront(i);
    }
    list.print();
    std::cout << std::endl;
    
    list.sort();
    list.print();
    
    return 0;
}
