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

void Nodo::set(Nodo* sig, Nodo* padre, int h, int g)
{
	this->sig = sig;
	this->padre = padre;
	this->h = h;
	this->g = g;
}
