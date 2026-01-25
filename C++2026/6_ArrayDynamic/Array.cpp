#include <iostream>
using namespace std;

#include "Array.h"

/*
quitar el uso de variable nativas -int- y "remplazar" por -value_type-
usar size_t cuando se devuelve un valor o se indica un index que este en memoria, ya que no puede ser negativo
en el FOR en lugar de int i (nativo) se usa AUTO i ...
*/

CArray::CArray(size_t size){
    m_size = size;
}

CArray::~CArray(){
    //delete[] m_data;
}

value_type& CArray::operator[](size_t index){
    return m_data[index];
}

size_t CArray::getSize() const{
    return m_size;
}

void DemoArray(){
    CArray arr1(7);
    for(auto i=0; i < arr1.getSize(); ++i)
        arr1[i] = i * 11;

    for(auto i=0; i < arr1.getSize(); ++i)
        cout << arr1[i] << endl;
}
