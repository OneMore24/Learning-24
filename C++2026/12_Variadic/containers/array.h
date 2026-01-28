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

/* VARIADIC TEMPLATES - Plantillas variadicas, tienen la capacidad de aceptar 
cualquier cantidad de argumentos de cualquier tipo, es como una funcion sumar infinita 
Se crea un funcion que acepta infinitos argumentos
para esto se necesitan 2 partes obligatoriamente
1 - la que detiene el bucle cuando queda un elemento
2 - la funcion que procesa los datos y pasar a la siguiente llamada */

// el test solo acepta un unico parametro, se activa cuando solo qued aun elemento, ya no llama a Test de nuevo
template <typename Q>
auto Test(Q elem) { return elem;} // solo retorna el elemento que queda

// el test que suma el primero y vuelve a llamar a la funcion y suma el primero que queda y asi ... 
// auto hace que devuelva el tipo de dato que detecte el compilador
template <typename Q, typename ...Args>
auto Test( Q elem, Args ...args){ 
    // recibe elem (el primero) y "args..." el resto de elementos
    //suma el primero + el resultado de procesar el resto
    return elem + Test(args...);
}

template <typename Q>
void Suma(Q &elem, Q p1){ elem += p1; }

template <typename Q>
void Mult(Q &elem, Q p1){ elem *= p1; }

template <typename T>
void CArray<T>::Foreach(void (*pf)(T &, T), T p1){
    for (size_t i=0; i<getSize(); ++i)
        pf(m_data[i], p1);
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