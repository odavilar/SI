#include <iostream>
#include <vector>
#include "Nodo.h"

using namespace std;

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
	int tm = 328;
	int um = 80;
	int vm = 199;
	int zm = 374;

	/*
	 * Nodos y relaciones
	 */

	Nodo A('A', am);
	Nodo AZ;
	Nodo AT;
	Nodo AS;
	Nodo B('B', bm);
	Nodo BG;
	Nodo BU;
	Nodo BP;
	Nodo BF;
	Nodo C('C', cm);
	Nodo CD;
	Nodo CP;
	Nodo CR;
	Nodo D('D', dm);
	Nodo DM;
	Nodo DC;
	Nodo E('E', em);
	Nodo EH;
	Nodo F('F', fm);
	Nodo FS;
	Nodo FB;
	Nodo G('G', gm);
	Nodo GB;
	Nodo H('H', hm);
	Nodo HE;
	Nodo HU;
	Nodo I('I', im);
	Nodo IN;
	Nodo IV;
	Nodo L('L', lm);
	Nodo LT;
	Nodo LM;
	Nodo M('M', mm);
	Nodo ML;
	Nodo MD;
	Nodo N('N', nm);
	Nodo NI;
	Nodo O('O', om);
	Nodo OZ;
	Nodo OS;
	Nodo P('P', pm);
	Nodo PR;
	Nodo PC;
	Nodo PB;
	Nodo R('R', rm);
	Nodo RP;
	Nodo RS;
	Nodo RC;
	Nodo S('S', sm);
	Nodo SF;
	Nodo SR;
	Nodo SA;
	Nodo SO;
	Nodo T('T', tm);
	Nodo TL;
	Nodo TA;
	Nodo U('U', um);
	Nodo UH;
	Nodo UB;
	Nodo UV;
	Nodo V('V', vm);
	Nodo VI;
	Nodo VU;
	Nodo Z('Z', zm);
	Nodo ZO;
	Nodo ZA;

	AZ.set(&AT, &A, Z.h, 75);
	AT.set(&AS, &A, T.h, 118);
	AS.set(NULL, &A, S.h, 140);
	BG.set(&BU, &B, G.h, 90);
	BU.set(&BP, &B, U.h, 85);
	BP.set(&BF, &B, P.h, 211);
	BF.set(NULL, &B, F.h, 101);
	CD.set(&CP, &C, D.h, 120);
	CP.set(&CR, &C, P.h, 146);
	CR.set(NULL, &C, R.h, 138);
	DM.set(&DC, &D, M.h, 75);
	DC.set(NULL, &D, C.h, 120);
	EH.set(NULL, &E, H.h, 86);
	FS.set(&FB, &F, S.h, 99);
	FB.set(NULL, &F, B.h, 211);
	GB.set(NULL, &G, B.h, 90);
	HE.set(&HU, &H, E.h, 86);
	HU.set(NULL, &H, U.h, 98);
	IN.set(&IV, &I, N.h, 87);
	IV.set(NULL, &I, V.h, 92);
	LT.set(&LM, &L, T.h, 111);
	LM.set(NULL, &L, M.h, 70);
	ML.set(&MD, &M, L.h, 70);
	MD.set(NULL, &M, D.h, 75);
	NI.set(NULL, &N, I.h, 87);
	OZ.set(&OS, &O, Z.h, 71);
	OS.set(NULL, &O, S.h, 151);
	PR.set(&PC, &P, R.h, 97);
	PC.set(&PB, &P, C.h, 138);
	PB.set(NULL, &P, B.h, 101);
	RP.set(&RS, &R, P.h, 97);
	RS.set(&RC, &R, S.h, 80);
	RC.set(NULL, &R, C.h, 146);
	SF.set(&SR, &S, F.h, 99);
	SR.set(&SA, &S, R.h, 80);
	SA.set(&SO, &S, A.h, 140);
	SO.set(NULL, &S, O.h, 151);
	TL.set(&TA, &T, L.h, 111);
	TA.set(NULL, &T, A.h, 118);
	UH.set(&UB, &U, H.h, 98);
	UB.set(&UV, &U, B.h, 85);
	UV.set(NULL, &U, V.h, 142);
	VI.set(&VU, &V, I.h, 92);
	VU.set(NULL, &V, U.h, 142);
	ZO.set(&ZA, &Z, O.h, 71);
	ZA.set(NULL, &Z, A.h, 75);

	vector<Nodo> A;
	vector<Nodo> C;

	return 0;
}
