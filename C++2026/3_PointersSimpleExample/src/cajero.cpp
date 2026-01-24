#include "../include/cajero.h"
#include <iostream>

using namespace std;

void imprimirBoleta(Dinero montoCopia) {
    // modifica montoCopia aquí, no afecta al exterior
    montoCopia = 0; 
    cout << "imprimiendo boleta de la operacion...(cambio de monto a 0)" << endl;
    cout << "monto: " << montoCopia << endl;
}

bool revisarPin(const Texto& pin2, const Texto& pin) {
    // pin = "1111" o "2222"
    // 2.error -> el compilador no te deja modificarlo
    cout << "verificando PIN..." << endl;
    return pin2 == pin;
}

void depositar(Dinero& saldoOriginal, Dinero cantidad) {
    saldoOriginal += cantidad; // modifica directamente la memoria original
    cout << "Deposito exitoso. Nuevo saldo interno: " << saldoOriginal << endl;
}

void mostrarDatos(PunteroCuenta cuenta) {
    if (cuenta == nullptr) {
        cout << "Error           : No hay ninguna sesion." << endl;
    } else {
        // usamos flecha -> porque es un puntero
        cout << "Bienvenido sr/a :  " << cuenta->titular << endl;
        cout << "Saldo actual    :  " << cuenta->saldo << endl;
    }
}

void cambiarSesion(PunteroCuenta& ptrSesion, PunteroCuenta newCuenta) {
    // redirigimos el puntero que vive en el main.
    ptrSesion = newCuenta;
    cout << "Cambio de sesion realizado" << endl;
}



