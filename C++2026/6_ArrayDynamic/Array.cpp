#include <iostream>
#include <assert.h>
using namespace std;

#include "Array.h"

/*
quitar el uso de variable nativas -int- y "remplazar" por -value_type-
usar size_t cuando se devuelve un valor o se indica un index que este en memoria, ya que no puede ser negativo
en el FOR en lugar de int i (nativo) se usa AUTO i ...
*/

CArray::CArray(size_t size){ 
    m_capacity = size; // la capacidad inicial sera el tamaño que se indique al contructor
    m_data = new value_type[size]{};  // pedir un espacio de memoria con new, crea un array nuevo de tamaño size
}

CArray::~CArray(){
    delete[] m_data; // ahora es obligatorio, devolver la memoria prestada
}

value_type& CArray::operator[](size_t index){ 
// verifica si el valor pedido es mas grande q el tamaño del array    
    if (index >= m_capacity){
        cout << "Cambiar el tamaño de " << m_capacity << " a " << index + 5 << endl;
        resize(index-m_last+5); // calcula cuanto debe añadir, seria delta, pero le aumenta 5 por si acaso, asegura que el array sea mas que suficiente
    }
// si el indice pedido es menor a la capacidad, continua, y si no ASSERT hace que todo se detenga si no comple la condicion
    assert(index < m_capacity);
// actualizar el tamaño del array, m_last
    if(index > m_last)
        m_last = index;
// retorna la direccion de lo que se pidio al inicio, despues de aumentar mas memoria si era necesario
    return m_data[index];
}

size_t CArray::getSize() const { return m_last + 1; } // devuelve el tamaño del array, si el ultimo valor esta en 9, el tamaño es 10

void CArray::push_back(value_type value){
    if(m_last >= m_capacity) // verifica si la ultima posicion ocupada es mayor o igual al tamaño pedido del inicio
        resize(); // si es asi llama a esta funcion, aumenta en 10 ...
    m_data[m_last++]=value; // se le dice que guarde value en m_data[m_last] y que luego le aumente 1 a la ultima posicion para actualizar
}

void CArray::resize(size_t delta){
    size_t new_capacity = m_capacity + delta; // calcular nuevo tamaño, aumenta +10
    value_type *new_data = new value_type[new_capacity]{}; // reservar una memoria de mas tamaño, crea un direccion nueva y alamcena el nuevo tamaño
// copiar los datos antiguos m_data a new_data    
    for (size_t i = 0; i < m_capacity; ++i)
        new_data[i] = m_data[i];
// elimnar m_data, ya no sirve
    delete[] m_data;
// ahora hacer que los punteros apunten a las nuevas direcciones
    m_data = new_data;
    m_capacity = new_capacity;    
}

void DemoArray(){
    const int N = 5;
    CArray arr1(N);
    for (size_t i=0; i<N; ++i)
        arr1.push_back(i*10);
    cout << "--- First part finished ---" << endl; // cada valor del arreglo multiplicado x10
    arr1[3] = 43;
    arr1.push_back(80);
    arr1.push_back(75);
    cout << "--- Second part finished ---" << endl; // cambiar el q esta en posicion 3 (30) por 43 y agregar al final 80 y 70
    arr1[11] = 24; 
    cout << "--- Third part finished ---" << endl; // aumentar el tamño de 7 a (9-7)+5, y en la posicion 9 poner el 24, aqui m_last sera 10
    cout << "--- Ready to print ---" << endl;
    for (size_t i = 0; i < arr1.getSize(); ++i)
        cout << "[" << i << "] " << arr1[i] << endl;
        // cout << arr1[50] << endl; // This will trigger an assertion failure
    cout << "--- DemoArray finished --- " << endl;
}

/*
USAR {} AL CONSTRUIR DESPUES DE m_data = new value_type[size]{}; 
PARA QUE LOS VALORES DEL ARRAY NUEVO SE INICIEN EN 0 Y AL EJECUTAR NO MUESTRE DATOS BASURA (-123546789) 
USAR {} DESPUES DE new value_type[new_capacity]{}; EN EL CODIGO PARA CORREGIR EL "ERROR", 
no es un error como tal, es la misma RAM q arroja datos basura porque no se inicializan
pedimos memoria a la RAM con new ... por eso muestra a veces valores que no reconocemos
*/