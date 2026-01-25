#include <iostream>
#include "../include/tipos.h"
#include "../include/cajero.h"

using namespace std;

int main() {
    cout << "--/ cajero /--" << endl;

    // cuentas prestablecidas
    Cuenta ctaA = { "aaaaa", "1111", 2400 }; 
    Cuenta ctaB = { "bbbbb", "2222", 1000 };

    // ptr que representa la sesión actual, apunta a null
    PunteroCuenta sesionActual = nullptr;

    // paso por ptr ->  intentamos ver datos sin iniciar sesion, no sale nada *creo
    mostrarDatos(sesionActual); 

    // ref. a un ptr. -> inicia sesion ctaA
    cout << "\n-- nueva sesion: A --" << endl;
    cambiarSesion(sesionActual, &ctaA);
    
    // verifica que ahora el puntero sí apunta a algo -> ctaA
    mostrarDatos(sesionActual);

    // ref. cte. -> validamos pin (solo lectura) // sesionActual->pin = (*sesionActual).pin
    if (revisarPin("1111", sesionActual->pin)) {
        cout << "sesion iniciada" << endl;
    }

    // ref. -> A deposita dinero. pasamos su saldo real.
    cout << "\n-- realizando deposito de 500 --" << endl;
    depositar(sesionActual->saldo, 500.0);
    // verificar que se actualize el struct original
    cout << "saldo en struct original de A: " << ctaA.saldo << " (debe ser 2900)" << endl;

    // valor -> imprimimos boleta (copia del dato)
    imprimirBoleta(ctaA.saldo);
    
    // ref. a ptr -> para cambiar de sesion
    cout << "\n-- cambio de sesion a B --" << endl;
    cambiarSesion(sesionActual, &ctaB);
    mostrarDatos(sesionActual); // ahora va a imprimir los datos de B

    return 0;
}