#include <iostream>
#include <vector>
#include "Nodo.h"

using namespace std;

int main()
{	
	vector<Nodo*> list_A;
	vector<Nodo*> list_C;
	
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
	int tm = 328;
	int um = 80;
	int vm = 199;
	int zm = 374;

	/*
	 * Nodos y relaciones
	 */

	list_A.push_back(Nodo *A = new Nodo('A', am));
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

	AZ->set(AT, A, Z->h, 75);
	AT->set(AS, A, T->h, 118);
	AS->set(NULL, A, S->h, 140);
	BG->set(BU, B, G->h, 90);
	BU->set(BP, B, U->h, 85);
	BP->set(BF, B, P->h, 211);
	BF->set(NULL, B, F->h, 101);
	CD->set(CP, C, D->h, 120);
	CP->set(CR, C, P->h, 146);
	CR->set(NULL, C, R->h, 138);
	DM->set(DC, D, M->h, 75);
	DC->set(NULL, D, C->h, 120);
	EH->set(NULL, E, H->h, 86);
	FS->set(FB, F, S->h, 99);
	FB->set(NULL, F, B->h, 211);
	GB->set(NULL, G, B->h, 90);
	HE->set(HU, H, E->h, 86);
	HU->set(NULL, H, U->h, 98);
	IN->set(IV, I, N->h, 87);
	IV->set(NULL, I, V->h, 92);
	LT->set(LM, L, T->h, 111);
	LM->set(NULL, L, M->h, 70);
	ML->set(MD, M, L->h, 70);
	MD->set(NULL, M, D->h, 75);
	NI->set(NULL, N, I->h, 87);
	OZ->set(OS, O, Z->h, 71);
	OS->set(NULL, O, S->h, 151);
	PR->set(PC, P, R->h, 97);
	PC->set(PB, P, C->h, 138);
	PB->set(NULL, P, B->h, 101);
	RP->set(RS, R, P->h, 97);
	RS->set(RC, R, S->h, 80);
	RC->set(NULL, R, C->h, 146);
	SF->set(SR, S, F->h, 99);
	SR->set(SA, S, R->h, 80);
	SA->set(SO, S, A->h, 140);
	SO->set(NULL, S, O->h, 151);
	TL->set(TA, T, L->h, 111);
	TA->set(NULL, T, A->h, 118);
	UH->set(UB, U, H->h, 98);
	UB->set(UV, U, B->h, 85);
	UV->set(NULL, U, V->h, 142);
	VI->set(VU, V, I->h, 92);
	VU->set(NULL, V, U->h, 142);
	ZO->set(ZA, Z, O->h, 71);
	ZA->set(NULL, Z, A->h, 75);


	return 0;
}
