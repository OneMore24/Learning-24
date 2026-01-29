#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>
#include <stddef.h>
#include <assert.h>
#include "../algorithms/sorting.h"
using namespace std;

// definir el trait
// se crea una estructura -> por defecto es publica y cualquiera puede acceder
// template <typename _T> recibe el tipo real y se llamara temporalmente _T
// dentro del struct se guarda el tipo bajo el nombre estandarizado T
template <typename _T>
struct Trait1
{
    using T = _T;
};

template<typename Traits> // ahora recibe traits
class CArray{
    // extraemos el tipo, typename es obligatorio para decirle que es un tipo de dato
    using value_type = typename Traits::T;
    using CompareFunc = bool (*)(const value_type &, const value_type &);
    
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

    template <typename ObjFunc, typename ...Args>
    void Foreach(ObjFunc of, Args ...args){
        for (size_t i=0; i<getSize(); ++i)
            of(m_data[i], args...);
    }
};

template <typename Traits>
CArray<Traits>::CArray(size_t size){
    m_capacity = size;
    m_data = new value_type[size]{};
}

template <typename Traits>
CArray<Traits>::~CArray(){ delete[] m_data; }

template <typename Traits>
typename CArray<Traits>::value_type& CArray<Traits>::operator[](size_t index){   
    if (index >= m_capacity){
        cout << "Cambiar el tamaño de " << m_capacity << " a " << index + 5 << endl;
        resize(index-m_last+5); 
    }
    assert(index < m_capacity);
    if(index > m_last)
        m_last = index;
    return m_data[index];
}

template <typename Traits>
void CArray<Traits>::push_back(value_type value){
    if(m_last >= m_capacity)
        resize();
    m_data[m_last++]=value;
}

template <typename Traits>
void CArray<Traits>::resize(size_t delta){
    size_t new_capacity = m_capacity + delta;
    value_type *new_data = new value_type[new_capacity]{};   
    for (size_t i = 0; i < m_capacity; ++i)
        new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;    
}

template <typename Traits>
void CArray<Traits>::sort(CompareFunc pComp){
    BurbujaRecursivo(m_data, getSize(), pComp);
}

template <typename Traits> 
ostream &operator<<(ostream &os, CArray<Traits> &arr) {
    os << "CArray: size = " << arr.getSize() << endl; 
    os << "[";
        for(size_t i=0; i<arr.getSize(); ++i)
            os << arr[i] << ", ";
    os << "]";
    return os;
}

void DemoArray();

#endif //__ARRAY_H__