#include <iostream>
#include "sorting.h"
#include "../containers/array.h"
using namespace std;

// FUNCIONES QUE NO SE USAN EN ESTA CARPETA PARA DEMOSTRAR EL ORDENAMIENTO


/*
// Bubble  
void BurbujaClasico(ContainerElemType* arr, ContainerRange n, CompFunc pComp) {
    if (n <= 1)
        return;
    for (auto i = 0; i < n - 1; ++i) {
        for (auto j = i+1; j < n; ++j) {
            if ( (*pComp)(arr[i], arr[j]) ) {
                intercambiar(arr[i], arr[j]);
            }
        }
    }
}

ContainerRange particionar(ContainerElemType* arr, ContainerRange first, ContainerRange last, CompFunc pComp) {
    auto pivote = arr[last];  // Pivote es el elemento de referencia
    auto i = (first - 1);

    for (auto j = first; j <= last - 1; j++) {
        if (arr[j] == pivote) ++i;
        if ( (*pComp)(arr[j], pivote) ){
            ++i; intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[last]);
    return (i + 1);
}
*/


