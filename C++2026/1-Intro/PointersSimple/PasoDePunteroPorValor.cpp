#include <iostream>
using namespace std;

int globalA=10;
int globalB=24;

void pasoDePunteroPorValor(int *p){
    p = &globalB; // ahora apunta a global B -> 24
    cout << "value in function      : " << *p << endl; // 24
    cout << "address in function    : " << p << endl; // direccion m. -> global B
    *p = 26; // modificar el valor de esta direccion -> globalB = 26
    cout << "value in function      : " << *p << endl; // ahora B es 26
    cout << "address in function    : " << p << endl; // la direccion m. de B sigue siendo la misma
}

int main (){
    int *ptr=&globalA; // apunta a global A -> 10
    cout << "value A before         : " << *ptr << endl; // 10 
    cout << "address A before       : " << ptr << endl; // direccion m. -> global A
    pasoDePunteroPorValor(ptr);
    cout << "value A after          : " << *ptr << endl; // NO cambia -> 10
    cout << "address A after        : " << ptr << endl; // No cambia -> direccion m. -> global A
    int *ptr2=&globalB;
    cout << "value B after          : " << *ptr2 << endl; // el valor de B fue cambiado a 26
    cout << "address B after        : " << ptr2 << endl; // la direccion de m. de B sigue siendo la misma
    return 0;
}