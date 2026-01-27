#include <iostream>
#include <fstream> // agregar libreria para archivos, file stream, para usar fstream
using namespace std;

#include "Array.h"

void DemoArray(){
    const int N = 5;
    CArray<int> arr1(N);

    for (size_t i=0; i<N; ++i)
        arr1.push_back(i*10);
    cout << "--- First part finished ---" << endl;

    arr1[2] = 43;
    arr1.push_back(80);
    arr1.push_back(75);
    arr1.push_back(12);
    cout << "--- Second part finished ---" << endl; 

    arr1[6] = 2;
    arr1[9] = 10;
    arr1[12] = 15;
    arr1[15] = 105;
    cout << "--- Third part finished ---" << endl; 

    cout << "--- Ready to print ---" << endl;
    cout << arr1 << endl;

    ofstream of("array.txt");
    of << arr1;
    of.close();

    cout << "--- DemoArray finished --- " << endl;

    //llamada a la funcion sort, se le pasa los parametros
    arr1.sort(&Mayor);
    cout << arr1 << endl;

    arr1.sort(&Menor);
    cout << arr1 << endl;
}
