#include <iostream>
using namespace std;

void pasoPorPuntero(int* ptr){
    *ptr=24; // para acceder al valor se escribe *ptr -> ir a la direccion ptr y cambiar por 24
    cout << "local change   : " << *ptr << endl;
    cout << "memory address : " << ptr << endl; // la direccion m. es la misma
}

int main(){
    int x=10;
    cout << "before         : " << x << endl;
    cout << "memory address : " << &x << endl; // la direccion m. es la misma
    pasoPorPuntero(&x);
    cout << "after          : " << x << endl; // el puntero modifica el valor original
    return 0;
}