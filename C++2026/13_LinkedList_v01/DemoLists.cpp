#include <iostream>
#include "containers/lists.h"

using namespace std;

using T1 = int;

void DemoLists(){
    CLinkedList< AscendingTrait<T1> > l1;

    l1.Insert(20, 5);
    l1.Insert(30, 3);
    l1.Insert(12, 3);
    l1.Insert(50, 250000);
    cout << l1 << endl;
}