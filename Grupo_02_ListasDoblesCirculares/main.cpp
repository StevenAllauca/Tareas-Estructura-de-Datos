#include <iostream>
#include "ListaDobleCircular.h"

using namespace std;

int main() {
    ListaDobleCircular<int> lista;

    // Pruebas de insercion
    lista.insertarAlFinal(20);
    lista.insertarAlFinal(30);
    lista.insertarAlFinal(40);
    lista.insertarAlInicio(10);

    cout << "ESTADO INICIAL" << endl;
    lista.imprimir();
    cout << "Tamanio: " << lista.getTamanio() << endl;

    // === PRUEBA DE LA FUNCION obtenerEnPosicion ===
    cout << "\n=== PRUEBA DE obtenerEnPosicion ===" << endl;
    for (int i = 0; i < lista.getTamanio(); i++) {
        cout << "Dato en posicion " << i << ": " << lista.obtenerEnPosicion(i) << endl;
    }

    // Validacion de posicion invalida controlada con try-catch
    try {
        cout << "\nIntentando acceder a posicion invalida (99):" << endl;
        lista.obtenerEnPosicion(99);
    } catch (const out_of_range& e) {
        cout << "Capturada excepcion: " << e.what() << endl;
    }

    cout << "\nPRUEBA CON OTRO TIPO (string)" << endl;
    ListaDobleCircular<string> nombres;
    nombres.insertarAlFinal("Ana");
    nombres.insertarAlInicio("Luis");
    nombres.insertarAlFinal("Carlos");
    nombres.imprimir();
    cout << "Elemento en posicion 1: " << nombres.obtenerEnPosicion(1) << endl;

    return 0;
}