#ifndef __ARRAY_H__
#define __ARRAY_H__

// crear clase Carray
class CArray{
    //crear atributos privados y publicos
    private:
        int m_size; //declarar tamaño del array como entero
        int  m_data[100]; //tamaño declarado/estatico
    public:
        CArray(int size); //constructor
        ~CArray(); //destructr
        
    //metodos para devolver direccion de memoria y el tamaño del array
    int& operator[](int index);
    int getSize() const;
};

void DemoArray();

#endif //__ARRAY_H__