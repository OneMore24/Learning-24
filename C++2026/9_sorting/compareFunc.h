#ifndef __COMPARE_H__
#define __COMPARE_H__
#include "general/types.h"

// C, C++
typedef bool (*CompFunc)(const ContainerElemType &, const ContainerElemType &);
// C++11 en adelante

template <typename T>
bool Mayor(const T &a, const T &b)
{ return a > b;  }

template <typename T>
bool Menor(const T &a, const T &b)
{ return a < b;  }

/*
la funcion mayor devuelve true si a es mayor, la funcion menor devuelve true si a es menor
a ambas funciones se les pasa los valor por referencia const. para solo mirar y no modificar
*/

#endif // __COMPARE_H__