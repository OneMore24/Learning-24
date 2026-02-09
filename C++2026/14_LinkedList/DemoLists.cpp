#include <iostream>
#include "containers/lists.h"

using namespace std;

using T1 = int;

void DemoLists(){
    CLinkedList< AscendingTrait<T1> > l1;
    l1.push_back(17,5);
    l1.push_back(9.8,5);
    l1.Insert(20, 5);
    l1.Insert(12, 3);
    l1.Insert(50, 250000);
    cout << l1 << endl;
    l1.push_back(10,5);
    l1.Insert(25, 6);
    cout << l1 << endl;
}