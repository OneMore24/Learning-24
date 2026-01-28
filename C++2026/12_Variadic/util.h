#ifndef __UTIL_H__
#define __UTIL_H__

#include "general/types.h"

template <typename T>
void intercambiar(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

#endif // __UTIL_H__