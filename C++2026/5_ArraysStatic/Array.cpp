#include <iostream>
using namespace std;

#include "Array.h"

//llamar al contructor para que construya un objeto
CArray::CArray(int size){
    m_size = size;
}

CArray::~CArray(){
    //delete[] m_data;
}

int& CArray::operator[](int index){
    return m_data[index];
}

int CArray::getSize() const{
    return m_size;
}

void DemoArray(){
    CArray arr1(7);
    for(int i=0; i < arr1.getSize(); ++i)
        arr1[i] = i * 11;

    for(int i=0; i < arr1.getSize(); ++i)
        cout << arr1[i] << endl;
}

