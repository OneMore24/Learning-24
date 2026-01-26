#include <iostream>
using namespace std;

#include "Array.h"

void DemoArray(){
    const int N = 5;
    CArray<int> arr1(N); // crea una version de la clase array donde T es INT

    for (size_t i=0; i<N; ++i)
        arr1.push_back(i*10);
    cout << "--- First part finished ---" << endl;

    arr1[3] = 43;
    arr1.push_back(80);
    arr1.push_back(75);
    cout << "--- Second part finished ---" << endl; 

    arr1[9] = 10;
    arr1[12] = 15;
    cout << "--- Third part finished ---" << endl; 

    cout << "--- Ready to print ---" << endl;

    for (size_t i = 0; i < arr1.getSize(); ++i)
        cout << "[" << i << "] " << arr1[i] << endl;
    cout << "--- DemoArray finished --- " << endl;
}
