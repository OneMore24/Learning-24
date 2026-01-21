#include <iostream>
using namespace std;

int globalA=10;
int globalB=24;

void referenciaPuntero(int *&ptr){
    ptr=&globalB;
    cout << "value in function      : " << *ptr << endl; // el valor ahora es el que esta en la nueva direccion de m.
    cout << "address in function    : " << ptr << endl; // la direccion de m. ahora es & global B
}

int main (){
    int *ptr=&globalA;
    cout << "value A before         : " << *ptr << endl; // 10
    cout << "address A before       : " << ptr << endl; 
    referenciaPuntero(ptr);
    cout << "value A after          : " << *ptr << endl; // cambia porque ahora apunta a global B
    cout << "address A after        : " << ptr << endl; // cambia a la direccion de m. de global B
    return 0;
}
