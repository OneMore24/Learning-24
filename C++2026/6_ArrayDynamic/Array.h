#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <stddef.h>

/*
usa size_t -> esta en la libreria <stddef.h> -> es un tipo de variable que mide cosas en memoria, nunca puede ser negativo
value_type "remplaza" int -> cuando se necesite modificar el tipo de variable solo se cambia en una linea
*/

using value_type = int;

class CArray{
    private:
    //capacidad real y ultima posicion ocupada, empiezan en 0
        size_t m_capacity=0, m_last=0;
    //direccion de memoria donde empieza el array, empieza apuntando a ningun lado
        value_type *m_data=nullptr;
    public:
        CArray(size_t size); 
        ~CArray(); 
    // metodo para agregar al final, y crece el tamaño del array si es necesario
    void push_back(value_type value);

    value_type& operator[](size_t index);
    size_t getSize() const;

    // la funcion que hace la mudanza de memoria, deberia ser privada, pero estará en publico
    void resize(size_t delta=10);
};

void DemoArray();

#endif //__ARRAY_H__