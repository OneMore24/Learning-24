#include <iostream>

using namespace std;

void pasoPorValor (int valor) {
    valor=24;
    cout << "local change   :  " << valor << endl;
    cout << "memory address :  " << &valor << endl; // direccion de memoria de la COPIA
}

int main(){
    int x=10;
    cout << "before         :  " << x << endl; // no cambia x=10
    cout << "memory address :  " << &x << endl; // direccion de memoria del valor ORIGINAL
    pasoPorValor(x); // si cambia es dentro de la funcion
    cout << "after          :  " << x << endl; // no cambia x=10
    return 0;
}
