#ifndef __TIPOS_H__
#define __TIPOS_H__

#include <string>

// typedef para double y string
typedef double Dinero;
typedef std::string Texto;

// estructura de una cuenta -> como una plantilla para luego crear lo mismo varias veces
struct Cuenta {
    Texto titular;
    Texto pin;
    Dinero saldo;

};

// typedef para el puntero *
typedef Cuenta* PunteroCuenta;

#endif // __TIPOS_H