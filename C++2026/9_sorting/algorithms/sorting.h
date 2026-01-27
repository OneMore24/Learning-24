#ifndef __SORTING_H__
#define __SORTING_H__
#include "../util.h"
#include "../compareFunc.h"

template <typename T>
// T arr[] -> el puntero al inicio del array que vamos a ordenar
// ContainerRange n -> tamaño del array, se mide con el tipo de variable que se definio en types.h
// bool (*pComp)... -> es la funcion que nos dice si ordenar de mayor a menor o al reves
void BurbujaRecursivo(T arr[], ContainerRange n, 
                      bool (*pComp)(const T &, const T &) ) {

// caso si se va ordenar alguna lista de 1 elemento, ya está ordenado     
    if (n <= 1)
        return;

// bucle para ordenar, al terminar la funcion nos asegura que el tado en la pos[0] se el menor o mayor, segun lo pedido
    for (auto j = 1; j < n; ++j)
        if ( pComp(arr[j], arr[0]) )
            intercambiar(arr[0], arr[j]);
    BurbujaRecursivo(arr+1, n-1, pComp); 
// aqui vuelve a ordenar, ya tiene garantizado en la posicion 0, empieza en la pos. 1 ahora y su tamaño se reduce en uno
}

#endif // __SORTING_H__