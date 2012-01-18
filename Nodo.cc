#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(int h)
{
 this->h = h;
}

Nodo::~Nodo()
{

}
		
void Nodo::set(Nodo* sig, Nodo* sub, int g)
{
	this->sig = sig;
	this->sub = sub;
	this->g = g;
}

void Nodo::set(Nodo* sig, Nodo* sub, int h, int g)
{
	this->sig = sig;
	this->sub = sub;
	this->h = h;
	this->g = g;
}
