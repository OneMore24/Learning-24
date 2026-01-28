#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>
#include <stddef.h>
#include <assert.h>
#include "../algorithms/sorting.h"
using namespace std;

template<typename T>
class CArray{
    using value_type = T;
    using CompareFunc = bool (*)(const T &, const T &);
    private:
        size_t m_capacity=0, m_last=0;
        value_type *m_data=nullptr;
    public:
        CArray(size_t size); 
        ~CArray(); 

    void push_back(value_type value); 

    value_type& operator[](size_t index);
    size_t getSize() const { return m_last + 1; };

    void resize(size_t delta=10);
    void sort(CompareFunc pComp);
      
// declaracion del metodo foreach, que parametros recibe
// void (*pf)(...) -> es el puntero a funcion
// (T &, ... ) -> la funcion recibe una referencia del array para modificarlo
// ( ... , T ) -> el valor que se usa para operar, suma o mult.
// ... T p1 -> es el 2do parametro del metodo, el valor constante p1 que se le pasa a la funcion
    void Foreach(void (*pf)(T &, T), T p1);
};

template <typename T>
CArray<T>::CArray(size_t size){
    m_capacity = size;
    m_data = new value_type[size]{};
}

template <typename T>
CArray<T>::~CArray(){ delete[] m_data; }

template <typename T>
typename CArray<T>::value_type& CArray<T>::operator[](size_t index){   
    if (index >= m_capacity){
        cout << "Cambiar el tamaño de " << m_capacity << " a " << index + 5 << endl;
        resize(index-m_last+5); 
    }
    assert(index < m_capacity);
    if(index > m_last)
        m_last = index;
    return m_data[index];
}

template <typename T>
void CArray<T>::push_back(value_type value){
    if(m_last >= m_capacity)
        resize();
    m_data[m_last++]=value;
}

template <typename T>
void CArray<T>::resize(size_t delta){
    size_t new_capacity = m_capacity + delta;
    value_type *new_data = new value_type[new_capacity]{};   
    for (size_t i = 0; i < m_capacity; ++i)
        new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;    
}

template <typename T>
void CArray<T>::sort(CompareFunc pComp){
    BurbujaRecursivo(m_data, getSize(), pComp);
}

// funciones normales que suman o mult. deben concidir con (T &, T), en este caso int = T
// elem -> es un elemento del array el cual se paso por referencia para modificarlo, p1 es con el que se opera
// en los archivos .h , suma y mult van como templates sino el linker al intentar enlazar main.o y array.o, explota
template <typename Q>
void Suma(Q &elem, Q p1){ elem += p1; }

template <typename Q>
void Mult(Q &elem, Q p1){ elem *= p1; }

// template del foreach
template <typename T>
void CArray<T>::Foreach(void (*pf)(T &, T), T p1){
    for (size_t i=0; i<getSize(); ++i) // recorre 1 por 1
        pf(m_data[i], p1); // ejecuta la funcion
    // llama a la funcion, sea suma o mult
    // entrega el elem actual m_data[i] para que lo modifique
    // entrega p1 como el valor con el que hará alguna operacion
}

template <typename T> 
ostream &operator<<(ostream &os, CArray<T> &arr) {
    os << "CArray: size = " << arr.getSize() << endl; 
    os << "[";
        for(size_t i=0; i<arr.getSize(); ++i)
            os << arr[i] << ", ";
    os << "]";
    return os;
}

void DemoArray();

#endif //__ARRAY_H__