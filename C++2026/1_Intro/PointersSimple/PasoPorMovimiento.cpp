#include <iostream>
#include <vector>
#include <utility>
using namespace std;
/*
// opcion 1 (usando &&) -> se crea una nueva direccion de memoria, explicitamente quita los valores
void pasoPorMovimiento(vector<int> &&values){
    vector<int> listNew = std::move(values);
    cout << "size listNew       : " << listNew.size() << endl;
    cout << "size list ...      : " << values.size() << endl;
    cout << "memory 2 address   : " << &listNew << endl;
}
*/

// ++ opcion 2 (sin && - pasa "por valor") -> quita los datos antes de entrar a la funcion, 
// al terminar la funcion values desaparece
void pasoPorMovimiento(vector<int> values){
    cout << "size in function   : " << values.size() << endl;
    cout << "memory address     : " << &values << endl;
}


int main(){
    vector<int> list = {00,11,22,33};
    cout << "size before        : " << list.size() << endl;
    cout << "memory address     : " << &list << endl;
    pasoPorMovimiento(std::move(list));
    cout << "size after         : " << list.size() << endl;
    cout << "memory address     : " << &list << endl;
    return 0;
}