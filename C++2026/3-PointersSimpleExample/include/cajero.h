#ifndef __CAJERO_H__
#define __CAJERO_H__

#include "tipos.h"

// paso por valor -> imprime boleta y guarda el monto (por copia)
void imprimirBoleta(Dinero montoCopia);

// paso por ref. cte. -> lee un pin que no debe de modificarse
bool revisarPin(const Texto& pin2, const Texto& pin);

// paso por ref. -> al depositar se necesita cambiar el dinero original
void depositar(Dinero& saldoOriginal, Dinero cantidad);

// paso por ptr -> muestra datos de una cuenta, no se necesita copia, solo mostrar datos de una direccion de memoria
void mostrarDatos(PunteroCuenta cuenta);

// paso por ref. a un ptr. -> cuando termina de usar el cajero, el ptr del main debe apuntar a otra cuenta
void cambiarSesion(PunteroCuenta& ptrSesion, PunteroCuenta newCuenta);

#endif // __CAJERO_H__