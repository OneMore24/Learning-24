#include <iostream>
#include "containers/lists.h"

using namespace std;

using T1 = int;

void DemoLists(){
    CLinkedList< AscendingTrait<T1> > l1;
    l1.Insert(30, 5);
    l1.Insert(7, 3);
    l1.push_back(12, 3);
    cout << l1 << endl;
}