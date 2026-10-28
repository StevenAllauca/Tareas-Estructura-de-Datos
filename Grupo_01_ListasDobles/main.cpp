#include "Lista.h"
#include <iostream>

using namespace std;

int main() {
    ListaDoble miLista;

    cout << "=== INSERTANDO DATOS QUEMADOS ===\n";
    miLista.insertar("Carlos");
    miLista.insertar("Ana");
    miLista.insertar("Mateo");
    miLista.insertar("Sofia");

    cout << "\n=== MOSTRAR LISTA ORIGINAL ===\n";
    miLista.imprimirAdelante();
    miLista.imprimirAtras();

    cout << "\n=== INVERTIR LISTA (CAMBIANDO PUNTEROS) ===\n";
    miLista.invertir();

    cout << "\n=== MOSTRAR LISTA TRAS INVERTIR ===\n";
    miLista.imprimirAdelante();
    miLista.imprimirAtras();

    cout << "\n=== PRUEBA DE BUSQUEDA Y ELIMINACION TRAS INVERTIR ===\n";
    miLista.buscar("Ana");
    miLista.eliminar("Ana");

    cout << "\n=== LISTA FINAL ===\n";
    miLista.imprimirAdelante();
    miLista.imprimirAtras();

    return 0;
}