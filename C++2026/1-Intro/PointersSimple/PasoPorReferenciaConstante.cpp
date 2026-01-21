#include <iostream>
#include <vector>
using namespace std;

void pasoPorReferenciaConstante(const vector<int> &refC){
    cout << "size           : " << refC.size() << endl;
    cout << "first num      : " << refC.at(0) << endl;
    cout << "last num       : " << refC.at(refC.size()-1) << endl;
    // refC[0] = 999;   // ERROR -> no se puede modificar
    cout << "memory address : " << &refC << endl; // direccion de memoria es la misma
}

int main (){
    vector<int> listaNum={10,20,30,40,50};
    cout << "memory address : " << &listaNum << endl; // direccion de memoria es la misma
    pasoPorReferenciaConstante(listaNum);
    return 0;
}
