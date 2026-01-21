#include <iostream>

using namespace std;

void pasoPorReferencia (int& ref){
    ref=24;
    cout << "local change   : " << ref << endl; // valor ORIGINAL puede cambiarse
    cout << "memory address : " << &ref << endl; // direccion de memoria es la misma
}

int main(){
    int x=10; 
    cout << "before         : " << x << endl;
    cout << "memory address : " << &x << endl; // direccion de memoria es la misma
    pasoPorReferencia(x);
    cout << "after          : " << x << endl; // valor original CAMBIA
    return 0;
}