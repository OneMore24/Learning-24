#include <iostream>
#include <fstream>
using namespace std;

#include "array.h"

// crear un alias para el tipo de variable en los array
using T1 = int;

void DemoArray(){
    const int N = 5;
    CArray<T1> arr1(N);

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

    arr1.sort(&Menor);
    cout << arr1 << endl;

    arr1.sort(&Mayor);
    cout << arr1 << endl;

    // llamar a las funciones para que modifiquen el array
    // con el foreach se envia la direccion de memoria de la funcion suma o mult (&pf) y el (5) lo que adiciona
    arr1.Foreach(&Suma, 7);
    cout << arr1 << endl;
    arr1.Foreach(&Mult, 2);
    cout << arr1 << endl;

    // NUEVO ARRAY DE STRING
    // funciona porque los templates lo permiten, reciben ahora string en lugarde int como en arr1
    CArray<string> arr2(N);
    arr2[2] = "UNMSM";
    arr2[4] = "FC";
    cout << arr2 << endl;

    arr2.Foreach(&Suma, ".Enero");
    cout << arr2 << endl;
}
