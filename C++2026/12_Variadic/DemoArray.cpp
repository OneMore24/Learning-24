#include <iostream>
#include <fstream>

using namespace std;

// agrega librerias luego de mover el archivo ../
#include "containers/array.h"
#include "variadic-util.h"
#include "compareFunc.h"

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

    // INSTANCIACION IMPLICITA
    /* como foreach acepta ahora un objfunc (cualquier cosa), el compilador se confunde
    si se pasa solo la direccion de memoria de la funcion, porque la funcion es un template
    que puede ser muchas cosas
    al escribir &Suma<int> se le dice al compilador que se quiere especificamente la 
    version de suma que sea de enteros */
    arr1.Foreach(&Suma<T1>, 7);
    cout << arr1 << endl;
    arr1.Foreach(&Mult<T1>, 2);
    cout << arr1 << endl;

    using T2 = string;
    CArray<string> arr2(N);
    arr2[2] = "UNMSM";
    arr2[4] = "FC";
    cout << arr2 << endl;
    arr2.Foreach(&Suma<T2>, ".Enero");
    cout << arr2 << endl;
    cout << endl << "---variadic method---" << endl;

    int x = Test(5,3,2);
    cout << x << endl;
    auto r = Test(1,2,3.4,4,5,6,7);
    cout << r << endl;

    auto str = Test(string("Hola."), string("FC."), string("UNMSM."));
    cout << str << endl;

}
