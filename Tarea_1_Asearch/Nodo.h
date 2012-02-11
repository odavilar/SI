/*
 *
 * Algoritmo de búsqueda A estrella por Oscar Dávila (793523) para la materia de sistemas inteligentes.
 *
 */

#ifndef NODO_H
#define NODO_H

class Nodo
{
	/*
	 * h heurística
	 * g costo a nodo padre
	 * padre Nodo padre
	 * enlae Nodo siguiente
	 */

	public:
		Nodo();
		Nodo(char name, int h);
		~Nodo();
		Nodo* sig;
		Nodo* padre;
		Nodo* dest;
		char name;
		int h;
		int g;
		int f;
		void set(Nodo* sig, Nodo* padre, int g);
		void set(Nodo* sig, Nodo* padre, Nodo* dest, int g);
};

#endif

