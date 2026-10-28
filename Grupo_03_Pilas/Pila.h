/* Universidad de las Fuerzas Armadas
     Ciencias de la Computacion
        Estructura de Datos

Grupo: 3            Integrantes: Kevin Cabezas, Martin Paz
Fecha: 00/10/2026                Erick Sabando, Adrian Toapanta
        Tema: Pilas
*/

// Clase Pila.h

#pragma once
#include "IPila.h"
#include "Nodo.h"

/// class Pila

class Pila : public IPila {
private:
    Nodo *tope;

public:
    // constructor
    Pila();

    // destructor
    virtual ~Pila();

    // setter y getter
    void setTope(Nodo *tope);
    Nodo *getTope() const;

    // funcion implementada del reto
    int sizePila() const override;

    // metodos de la interface
    void apilar(const Persona &p) override;
    void desapilar() override;
    bool buscar(const std::string &cedula) override;
    void imprimir() override;
};