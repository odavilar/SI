/*
 *
 * Algoritmo de búsqueda A estrella por Oscar Dávila (793523) para la materia de sistemas inteligentes.
 *
 */

#include <iostream>
#include <vector>
#include "Nodo.h"

using namespace std;

int remove(Nodo* N, vector<Nodo*> *list);
bool is_there(Nodo* N, vector<Nodo*> list);
Nodo* less_A(vector<Nodo*> A);
int Buscar_A_Estrella(Nodo* inicio, Nodo* meta);

int main()
{	
	/*
	 * Heurística del nodo a la meta
	 */

	int am = 366;
	int bm = 0;
	int cm = 160;
	int dm = 242;
	int em = 161;
	int fm = 176;
	int gm = 77;
	int hm = 151;
	int im = 226;
	int lm = 244;
	int mm = 241;
	int nm = 234;
	int om = 380;
	int pm = 100;
	int rm = 193;
	int sm = 253;
	int tm = 329; //En un lado estaba 328 en el otro 329 de la presentación
	int um = 80;
	int vm = 199;
	int zm = 374;

	/*
	 * Nodos y relaciones
	 */

	Nodo *A = new Nodo('A', am);
	Nodo *AZ = new Nodo;
	Nodo *AT = new Nodo;
	Nodo *AS = new Nodo;
	Nodo *B = new Nodo('B', bm);
	Nodo *BG = new Nodo;
	Nodo *BU = new Nodo;
	Nodo *BP = new Nodo;
	Nodo *BF = new Nodo;
	Nodo *C = new Nodo('C', cm);
	Nodo *CD = new Nodo;
	Nodo *CP = new Nodo;
	Nodo *CR = new Nodo;
	Nodo *D = new Nodo('D', dm);
	Nodo *DM = new Nodo;
	Nodo *DC = new Nodo;
	Nodo *E = new Nodo('E', em);
	Nodo *EH = new Nodo;
	Nodo *F = new Nodo('F', fm);
	Nodo *FS = new Nodo;
	Nodo *FB = new Nodo;
	Nodo *G = new Nodo('G', gm);
	Nodo *GB = new Nodo;
	Nodo *H = new Nodo('H', hm);
	Nodo *HE = new Nodo;
	Nodo *HU = new Nodo;
	Nodo *I = new Nodo('I', im);
	Nodo *IN = new Nodo;
	Nodo *IV = new Nodo;
	Nodo *L = new Nodo('L', lm);
	Nodo *LT = new Nodo;
	Nodo *LM = new Nodo;
	Nodo *M = new Nodo('M', mm);
	Nodo *ML = new Nodo;
	Nodo *MD = new Nodo;
	Nodo *N = new Nodo('N', nm);
	Nodo *NI = new Nodo;
	Nodo *O = new Nodo('O', om);
	Nodo *OZ = new Nodo;
	Nodo *OS = new Nodo;
	Nodo *P = new Nodo('P', pm);
	Nodo *PR = new Nodo;
	Nodo *PC = new Nodo;
	Nodo *PB = new Nodo;
	Nodo *R = new Nodo('R', rm);
	Nodo *RP = new Nodo;
	Nodo *RS = new Nodo;
	Nodo *RC = new Nodo;
	Nodo *S = new Nodo('S', sm);
	Nodo *SF = new Nodo;
	Nodo *SR = new Nodo;
	Nodo *SA = new Nodo;
	Nodo *SO = new Nodo;
	Nodo *T = new Nodo('T', tm);
	Nodo *TL = new Nodo;
	Nodo *TA = new Nodo;
	Nodo *U = new Nodo('U', um);
	Nodo *UH = new Nodo;
	Nodo *UB = new Nodo;
	Nodo *UV = new Nodo;
	Nodo *V = new Nodo('V', vm);
	Nodo *VI = new Nodo;
	Nodo *VU = new Nodo;
	Nodo *Z = new Nodo('Z', zm);
	Nodo *ZO = new Nodo;
	Nodo *ZA = new Nodo;


	A->set(AZ, NULL, NULL);
	B->set(BG, NULL, NULL);
	C->set(CD, NULL, NULL);
	D->set(DM, NULL, NULL);
	E->set(EH, NULL, NULL);
	F->set(FS, NULL, NULL);
	G->set(GB, NULL, NULL);
	H->set(HE, NULL, NULL);
	I->set(IN, NULL, NULL);
	L->set(LT, NULL, NULL);
	M->set(ML, NULL, NULL);
	N->set(NI, NULL, NULL);
	O->set(OZ, NULL, NULL);
	P->set(PR, NULL, NULL);
	R->set(RP, NULL, NULL);
	S->set(SF, NULL, NULL);
	T->set(TL, NULL, NULL);
	U->set(UH, NULL, NULL);
	V->set(VI, NULL, NULL);
	Z->set(ZO, NULL, NULL);
	
	AZ->set(AT, A, Z, 75);
	AT->set(AS, A, T, 118);
	AS->set(NULL, A, S, 140);
	BG->set(BU, B, G, 90);
	BU->set(BP, B, U, 85);
	BP->set(BF, B, P, 211);
	BF->set(NULL, B, F, 101);
	CD->set(CP, C, D, 120);
	CP->set(CR, C, P, 138);
	CR->set(NULL, C, R, 146);
	DM->set(DC, D, M, 75);
	DC->set(NULL, D, C, 120);
	EH->set(NULL, E, H, 86);
	FS->set(FB, F, S, 99);
	FB->set(NULL, F, B, 211);
	GB->set(NULL, G, B, 90);
	HE->set(HU, H, E, 86);
	HU->set(NULL, H, U, 98);
	IN->set(IV, I, N, 87);
	IV->set(NULL, I, V, 92);
	LT->set(LM, L, T, 111);
	LM->set(NULL, L, M, 70);
	ML->set(MD, M, L, 70);
	MD->set(NULL, M, D, 75);
	NI->set(NULL, N, I, 87);
	OZ->set(OS, O, Z, 71);
	OS->set(NULL, O, S, 151);
	PR->set(PC, P, R, 97);
	PC->set(PB, P, C, 138);
	PB->set(NULL, P, B, 101);
	RP->set(RS, R, P, 97);
	RS->set(RC, R, S, 80);
	RC->set(NULL, R, C, 146);
	SF->set(SR, S, F, 99);
	SR->set(SA, S, R, 80);
	SA->set(SO, S, A, 140);
	SO->set(NULL, S, O, 151);
	TL->set(TA, T, L, 111);
	TA->set(NULL, T, A, 118);
	UH->set(UB, U, H, 98);
	UB->set(UV, U, B, 85);
	UV->set(NULL, U, V, 142);
	VI->set(VU, V, I, 92);
	VU->set(NULL, V, U, 142);
	ZO->set(ZA, Z, O, 71);
	ZA->set(NULL, Z, A, 75);

	Buscar_A_Estrella(A,B);

	return 0;
}

int Buscar_A_Estrella(Nodo* inicio, Nodo* meta)
{
	vector<Nodo*> A;
	vector<Nodo*> C;

	inicio->padre = NULL;
	inicio->g = 0;
	inicio->f = inicio->h + inicio->g;
	A.push_back(inicio);

	while(!A.empty())
	{
		Nodo* N = less_A(A);
		C.push_back(N);
		remove(N, &A); //borrar N de los abiertos
		if(N == meta)
		{
			cout<<"Llegué a la meta, la ruta está escrita al revés, osea del final al inicio."<<endl;
			do{
				cout<<N->name;
				N = N->padre;
			}while(N->padre != NULL);
			cout<<inicio->name<<endl;
			return 1;
		}
		Nodo *temp = N;
		do{
			if(!is_there(temp->sig->dest, C)){
				A.push_back(temp->sig->dest);
				temp->sig->dest->f = N->g + temp->sig->g + temp->sig->dest->h;
				temp->sig->dest->g = N->g + temp->sig->g;
				cout<<temp->sig->dest->name<<" "<<temp->sig->dest->f<<" "<<N->g<<endl;
				temp->sig->dest->padre = temp;
			}
			temp = temp->sig;
		}while(temp->sig != NULL);
	}

	return 0;
}

Nodo* less_A(vector<Nodo*> A)
{	
	Nodo* N;
	vector<Nodo*>::iterator it;
	int menor = (A.front())->f;

	for(it = A.begin(); it < A.end(); it++)
	{
		if( (*it)->f <= menor )
		{
			menor = (*it)->f;
			N = (*it);
		}
	}
	return N;
}

bool is_there(Nodo* N, vector<Nodo*> list)
{
	vector<Nodo*>::iterator it;
	for(it = list.begin(); it < list.end(); it++){
		if(*it == N)
			return true;
	}

	return false;
}

int remove(Nodo* N, vector<Nodo*> *list)
{
	vector<Nodo*>::iterator it;
	for(it = list->begin(); it < list->end(); it++){
		if(*it == N)
		{
			list->erase(it);
			return 0;
		}
	}
	return -1;
}
