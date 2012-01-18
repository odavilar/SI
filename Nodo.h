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
		Nodo(int h);
		~Nodo();
		Nodo* sig;
		Nodo* sub;
		int h;
		int g;
		void set(Nodo* sig, Nodo* sub, int g);
		void set(Nodo* sig, Nodo* sub, int h, int g);
};

#endif

