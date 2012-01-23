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
		char name;
		int h;
		int g;
		void set(Nodo* sig, Nodo* padre, int g);
		void set(Nodo* sig, Nodo* padre, int h, int g);
};

#endif

