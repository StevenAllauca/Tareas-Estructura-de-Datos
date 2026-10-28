#include <iostream>
#include "Operaciones.h"
using namespace std;

int main() {
    Nodo* frente = nullptr;
    Nodo* fin = nullptr;

    // 1. Probar cola vacia
    cout << "--- 1. Probar cola vacia con contarElementos ---\n";
    cout << "Cantidad inicial: " << contarElementos(frente) << "\n";
    imprimir(frente);

    // 2. Insertar elementos y contar
    cout << "\nInsertar 10, 20 y 30:\n";
    insertar(frente, fin, 10);
    insertar(frente, fin, 20);
    insertar(frente, fin, 30);
    imprimir(frente);
    cout << "Cantidad tras insertar 3 nodos: " << contarElementos(frente) << "\n";

    // 3. Buscar
    cout << "\nBuscar 20: ";
    if (buscar(frente, 20)) {
        cout << "encontrado\n";
    } else {
        cout << "no encontrado\n";
    }

    // 4. Eliminar y volver a contar
    cout << "\nEliminar el primero (10):\n";
    eliminar(frente, fin);
    imprimir(frente);
    cout << "Cantidad tras eliminar 1 nodo: " << contarElementos(frente) << "\n";

    cout << "\nBuscar 10: ";
    if (buscar(frente, 10)) {
        cout << "encontrado\n";
    } else {
        cout << "no encontrado\n";
    }

    // 5. Vaciar la cola y comprobar conteo final
    cout << "\nLiberar todos los nodos antes de finalizar:\n";
    while (frente != nullptr) {
        eliminar(frente, fin);
    }
    imprimir(frente);
    cout << "Cantidad final (debe ser 0): " << contarElementos(frente) << "\n";

    return 0;
}