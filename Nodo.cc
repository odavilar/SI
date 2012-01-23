/*
 *
 * Algoritmo de búsqueda A estrella por Oscar Dávila (793523) para la materia de sistemas inteligentes.
 *
 */

#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(char name, int h)
{
	this->name = name;
	this->h = h;
}

Nodo::~Nodo()
{

}

void Nodo::set(Nodo* sig, Nodo* padre, int g)
{
	this->sig = sig;
	this->padre = padre;
	this->g = g;
}

void Nodo::set(Nodo* sig, Nodo* padre, Nodo* dest, int g)
{
	this->sig = sig;
	this->padre = padre;
	this->dest = dest;
	this->g = g;
}
