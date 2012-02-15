#include <stdio.h>

#define FILAS 14
#define COLUMNAS 5

/*
 * Evidencias
 */
#define CLIMA 0
#define TEMP 1
#define HUMEDAD 2
#define VIENTO 3 
#define JUGAR 4

/*
 * CLIMA
 */
#define SOL 0
#define NUB 1
#define LLU 2

/*
 * TEMPERATURA
 */
#define ALTA 0
#define MEDIA 1
#define BAJA 2

/*
 * HUMEDAD
 */
#define ALTA 0
#define NORMAL 1

/*
 * VIENTO
 */
#define SI 0
#define NO 1

/*
 * JUGAR AL TERMINAR EL DÍA
 */
#define SI 0
#define NO 1

static int info[FILAS][COLUMNAS] = 
{
	{SOL, ALTA, ALTA, NO, NO},
	{SOL, ALTA, ALTA, SI, NO},
	{NUB, ALTA, ALTA, NO, SI},
	{LLU, MEDIA, ALTA, NO, SI},
	{LLU, BAJA, NORMAL, NO, SI},
	{LLU, BAJA, NORMAL, SI, NO},
	{NUB, BAJA, NORMAL, SI, SI},
	{SOL, MEDIA, ALTA, NO, NO},
	{SOL, BAJA, NORMAL, NO, SI},
	{LLU, MEDIA, NORMAL, NO, SI},
	{SOL, MEDIA, NORMAL, SI, SI},
	{NUB, MEDIA, ALTA, SI, SI},
	{NUB, ALTA, NORMAL, NO, SI},
	{LLU, MEDIA, ALTA, SI, NO}
};

/*
 * Calcula probabilidad individual
 * Probabilidad de A dado B
 */
float calc_prob_ind(int A, int B, int evidencia);

int main()
{	
	int i = 0;
	int cont = 0;
	int cantSi;
	int cantNo;
	float PSi;
	float PNo;
	int clima;
	int temp;
	int hum;
	int viento;
	float P1;
	float P2;

	for(i = 0; i < FILAS; i++)
	{
		if(info[i][JUGAR] == SI)
			cont++;
	}

	cantSi = cont;
	cantNo = FILAS - cantSi;

//	printf("%d %d \n", cantBueno, cantMalo);

	PSi = (float)cantSi / (float)FILAS;
	PNo = (float)cantNo / (float)FILAS;

//	printf("%f %f \n", PBueno, PMalo);

	printf("Este programa predice el humor de una persona al terminar su jornada laboral dependiendo del Clima, la Temperatura y la Cantidad de Trabajo durante el día\n");
	printf("Clima:\n1) Sol\t\t2) Nublado\t 3)Lluvioso\n");
	scanf("%d", &clima);
	printf("Temperatura:\n1) Alta\t\t2) Media\t3) Baja\n");
	scanf("%d", &temp);
	printf("Humedad:\n1) Alta\t\t2) Normal\n");
	scanf("%d", &hum);
	printf("Viento:\n1) Si\t\t2) No\n");
	scanf("%d", &viento);

	P1 = PSi * calc_prob_ind(clima - 1, SI, CLIMA) * calc_prob_ind(temp - 1, SI, TEMP) * calc_prob_ind(hum - 1, SI, HUMEDAD) * calc_prob_ind(viento - 1, SI, VIENTO);
	P2 = PNo * calc_prob_ind(clima - 1, NO, CLIMA) * calc_prob_ind(temp - 1, NO, TEMP) * calc_prob_ind(hum - 1, NO, HUMEDAD) * calc_prob_ind(viento - 1, NO, VIENTO);

	if(P1>P2)
		printf("Si se puede jugar Golf con una probabilidad del %f\n", P1);
	else
		printf("No se puede jugar Golf con una probabilidad del %f\n", P2);
	
	return 0;
}

float calc_prob_ind(int A, int B, int evidencia)
{
	int cont = 0;
	int contG = 0;
	int i;

	for(i = 0; i < FILAS; i++)
	{
		if(info[i][JUGAR] == B){
			contG++;
			if(info[i][evidencia] == A)
				cont++;
		}
	}

	return (float)cont/(float)contG;
}
