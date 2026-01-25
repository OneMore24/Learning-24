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
        size_t m_size; 
        value_type m_data[100]; 
    public:
        CArray(size_t size); 
        ~CArray(); 

    value_type& operator[](size_t index);
    size_t getSize() const;
};

void DemoArray();

#endif //__ARRAY_H__