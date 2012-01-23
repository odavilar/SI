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

	AZ.set(&AT,&A,A.h,75);
	AT.set(&AT,&A,A.h,75);
	AS.set(&AT,&A,A.h,75);
	BG.set(&AT,&B,B.h,75);
	BU.set(&AT,&B,B.h,75);
	BP.set(&AT,&B,B.h,75);
	BF.set(&AT,&B,B.h,75);
	CD.set(&AT,&C,C.h,75);
	CP.set(&AT,&C,C.h,75);
	CR.set(&AT,&C,C.h,75);
	DM.set(&AT,&D,D.h,75);
	DC.set(&AT,&D,D.h,75);
	EH.set(&AT,&E,E.h,75);
	FS.set(&AT,&F,F.h,75);
	FB.set(&AT,&F,F.h,75);
	GB.set(&AT,&G,G.h,75);
	HE.set(&AT,&H,H.h,75);
	HU.set(&AT,&H,H.h,75);
	IN.set(&AT,&I,I.h,75);
	IV.set(&AT,&I,I.h,75);
	LT.set(&AT,&L,L.h,75);
	LM.set(&AT,&L,L.h,75);
	ML.set(&AT,&M,M.h,75);
	MD.set(&AT,&M,M.h,75);
	NI.set(&AT,&N,N.h,75);
	OZ.set(&AT,&O,O.h,75);
	OS.set(&AT,&O,O.h,75);
	PR.set(&AT,&P,P.h,75);
	PC.set(&AT,&P,P.h,75);
	PB.set(&AT,&P,P.h,75);
	RP.set(&AT,&R,R.h,75);
	RS.set(&AT,&R,R.h,75);
	RC.set(&AT,&R,R.h,75);
	SF.set(&AT,&S,S.h,75);
	SR.set(&AT,&S,S.h,75);
	SA.set(&AT,&S,S.h,75);
	SO.set(&AT,&S,S.h,75);
	TL.set(&AT,&T,T.h,75);
	TA.set(&AT,&T,T.h,75);
	UH.set(&AT,&U,U.h,75);
	UB.set(&AT,&U,U.h,75);
	UV.set(&AT,&U,U.h,75);
	VI.set(&AT,&V,V.h,75);
	VU.set(&AT,&V,V.h,75);
	ZO.set(&AT,&Z,Z.h,75);
	ZA.set(&AT,&Z,Z.h,75);

	vector<Nodo> A;
	vector<Nodo> C;

	return 0;
}
