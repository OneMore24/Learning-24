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

    arr1[3] = 43;
    arr1.push_back(80);
    arr1.push_back(75);
    cout << "--- Second part finished ---" << endl; 

    arr1[9] = 10;
    arr1[12] = 15;
    cout << "--- Third part finished ---" << endl; 

    cout << "--- Ready to print ---" << endl;
    cout << arr1 << endl; // imprime el array

    ofstream of("array.txt"); // crea un archivo array.txt
    of << arr1; // pega el contenido del array en el archivo
    of.close(); // guarda los cambios y cierra el archivo 

    cout << "--- DemoArray finished --- " << endl;
}
