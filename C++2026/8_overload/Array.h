#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream> // agregar la libreria iostream para usar el flujo COUT
#include <stddef.h>
#include <assert.h>
using namespace std;

template<typename T>
class CArray{
    using value_type = T; 
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
// ostream es el tipo de dato COUT y de OFSTREAM
// & -> es para trabajar con el COUT original, ya que al ser un flujo no se puede copiar
// operator << -> es el nombre de la func. C++ entiende que debe ejecutarse cuando vea <<
// ostream &os -> representa el flujo de salida, puede ser la consola cout o un archivo (ofstream) y damos un alias -> os
// CArray<T> &arr -> recibe el array por referencia
ostream &operator<<(ostream &os, CArray<T> &arr) {
// en lugar se COUT usamos OS, tal como declaramos en los parametros
    os << "CArray: size = " << arr.getSize() << endl; 
    os << "[";
        for(size_t i=0; i<arr.getSize(); ++i)
            os << arr[i] << ", ";
    os << "]";
// para terminar se devuelve el mismo flujo q se recibio al principio, cout
    return os;
}

void DemoArray();

#endif //__ARRAY_H__