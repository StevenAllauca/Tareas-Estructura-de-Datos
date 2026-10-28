/***********************************************************************
 * Module:  Pila.cpp
 * Author:  STEVEN
 * Modified: martes, 27 de octubre de 2026 12:00:06
 * Purpose: Implementation of the class Pila
 ***********************************************************************/

#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila(int capacidadInicial)
{
   capacidad = capacidadInicial;
   cima = -1;
   datos = new int[capacidad];
}

Pila::~Pila()
{
   delete[] datos;
}

void Pila::redimensionar(void)
{
   int nuevaCapacidad = capacidad * 2;
   int* nuevoArreglo = new int[nuevaCapacidad];

   for (int i = 0; i <= cima; i++) {
       *(nuevoArreglo + i) = *(datos + i);
   }

   delete[] datos;
   datos = nuevoArreglo;
   capacidad = nuevaCapacidad;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::getDatos()
// Purpose:    Implementation of Pila::getDatos()
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Pila::getDatos(void)
{
   return datos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::setDatos(int* newDatos)
// Purpose:    Implementation of Pila::setDatos()
// Parameters:
// - newDatos
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::setDatos(int* newDatos)
{
   datos = newDatos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::getCapacidad()
// Purpose:    Implementation of Pila::getCapacidad()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Pila::getCapacidad(void)
{
   return capacidad;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::setCapacidad(int newCapacidad)
// Purpose:    Implementation of Pila::setCapacidad()
// Parameters:
// - newCapacidad
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::setCapacidad(int newCapacidad)
{
   capacidad = newCapacidad;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::getCima()
// Purpose:    Implementation of Pila::getCima()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Pila::getCima(void)
{
   return cima;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::setCima(int newCima)
// Purpose:    Implementation of Pila::setCima()
// Parameters:
// - newCima
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::setCima(int newCima)
{
   cima = newCima;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::insertar(int valor)
// Purpose:    Implementation of Pila::insertar()
// Parameters:
// - valor
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::insertar(int valor)
{
   if (cima + 1 == capacidad) {
       redimensionar();
   }
   cima++;
   *(datos + cima) = valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::eliminar()
// Purpose:    Implementation of Pila::eliminar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::eliminar(void)
{
   if (cima >= 0) {
       cima--;
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::estaVacia()
// Purpose:    Implementation of Pila::estaVacia()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Pila::estaVacia(void)
{
   return cima < 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::imprimir()
// Purpose:    Implementation of Pila::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::imprimir(void)
{
   if (estaVacia()) return;

   int valorCima = *(datos + cima);
   cima--;
   cout << valorCima << " ";

   imprimir();

   cima++;
}

////////////////////////////////////////////////////////////////////////
// Name:       Pila::buscar(int objetivo)
// Purpose:    Implementation of Pila::buscar()
// Parameters:
// - objetivo
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Pila::buscar(int objetivo)
{
   if (estaVacia()) return false;

   int valorCima = *(datos + cima);
   if (valorCima == objetivo) return true;

   cima--;
   bool encontrado = buscar(objetivo);

   cima++;
   return encontrado;

   
}
////////////////////////////////////////////////////////////////////////
// Name:       Pila::sumarElementos()
// Purpose:    Calcula la suma de los elementos mediante recursividad
// Return:     int
////////////////////////////////////////////////////////////////////////

//NUEVA FUNCIÓN: Suma los elementos de la pila de manera recursiva
int Pila::sumarElementos(void)
{
   // Caso base: si la pila está vacía, la suma es 0
   if (estaVacia()) return 0;

   // 1. Obtener el elemento en la cima usando aritmetica de punteros
   int valorCima = *(datos + cima);

   // 2. Desapilar temporalmente para la llamada recursiva
   cima--;

   // 3. Llamada recursiva con la sub-pila restante
   int sumaRestante = sumarElementos();

   // 4. Restaurar el estado original de la cima (Backtracking)
   cima++;

   // 5. Retornar el acumulado
   return valorCima + sumaRestante;
}