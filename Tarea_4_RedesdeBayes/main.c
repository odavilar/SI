#include <stdio.h>

#define FILAS 20
#define COLUMNAS 4

/*
 * Evidencias
 */
#define CLIMA 0
#define TEMP 1
#define TRAB 2
#define HUMOR 3

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
 * CANTIDAD DE TRABAJO EN EL DÍA
 */
#define MUCHO 0
#define NORMAL 1
#define POCO 2

/*
 * HUMOR AL TERMINAR EL DÍA
 */
#define BUENO 0
#define MALO 1

static int info[FILAS][COLUMNAS] = 
{
	{ SOL, ALTA, MUCHO, MALO },
//	{ SOL, ALTA, NORMAL, MALO },
	{ SOL, ALTA, POCO, BUENO },
	{ SOL, MEDIA, MUCHO, MALO },
	{ SOL, MEDIA, NORMAL, BUENO },
	{ SOL, MEDIA, POCO, BUENO },
	{ SOL, BAJA, MUCHO, BUENO },
//	{ SOL, BAJA, NORMAL, BUENO },
//	{ SOL, BAJA, POCO, BUENO },
	{ NUB, ALTA, MUCHO, MALO },
	{ NUB, ALTA, NORMAL, MALO },
	{ NUB, ALTA, POCO, BUENO },
	{ NUB, MEDIA, MUCHO, BUENO },
	{ NUB, MEDIA, NORMAL, BUENO },
//	{ NUB, MEDIA, POCO, BUENO },
	{ NUB, BAJA, MUCHO, BUENO },
	{ NUB, BAJA, NORMAL, BUENO },
	{ NUB, BAJA, POCO, BUENO },
//	{ LLU, ALTA, MUCHO, MALO },
	{ LLU, ALTA, NORMAL, MALO },
	{ LLU, ALTA, POCO, BUENO },
	{ LLU, MEDIA, MUCHO, MALO },
	{ LLU, MEDIA, NORMAL, BUENO },
//	{ LLU, MEDIA, POCO, BUENO },
	{ LLU, BAJA, MUCHO, MALO },
//	{ LLU, BAJA, NORMAL, MALO },
	{ LLU, BAJA, POCO, MALO }
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
	int cantBueno;
	int cantMalo;
	float PBueno;
	float PMalo;
	int clima;
	int temp;
	int trab;
	float P1;
	float P2;

	for(i = 0; i < FILAS; i++)
	{
		if(info[i][HUMOR] == BUENO)
			cont++;
	}

	cantBueno = cont;
	cantMalo = FILAS - cantBueno;

//	printf("%d %d \n", cantBueno, cantMalo);

	PBueno = (float)cantBueno / (float)FILAS;
	PMalo = (float)cantMalo / (float)FILAS;

//	printf("%f %f \n", PBueno, PMalo);

	printf("Este programa predice el humor de una persona al terminar su jornada laboral dependiendo del Clima, la Temperatura y la Cantidad de Trabajo durante el día\n");
	printf("Clima:\n1) Sol\t\t2) Nublado\t 3)Lluvioso\n");
	scanf("%d", &clima);
	printf("Temperatura:\n1) Alta\t\t2) Media\t3) Baja\n");
	scanf("%d", &temp);
	printf("Cantidad de trabajo:\n1) Mucho\t2) Normal\t3) Poco\n");
	scanf("%d", &trab);



	P1 = PBueno * calc_prob_ind(clima - 1, BUENO, CLIMA) * calc_prob_ind(temp - 1, BUENO, TEMP) * calc_prob_ind(trab - 1, BUENO, TRAB);
	P2 = PMalo * calc_prob_ind(clima - 1, MALO, CLIMA) * calc_prob_ind(temp - 1, MALO, TEMP) * calc_prob_ind(trab - 1, MALO, TRAB);

	if(P1>P2)
		printf("El Humor es Bueno con una probabilidad del %f\n", P1);
	else
		printf("El Humor es Malo con una probabilidad del %f\n", P2);
	
	return 0;
}

float calc_prob_ind(int A, int B, int evidencia)
{
	int cont = 0;
	int contH = 0;
	int i;

	for(i = 0; i < FILAS; i++)
	{
		if(info[i][HUMOR] == B){
			contH++;
			if(info[i][evidencia] == A)
				cont++;
		}
	}

	return (float)cont/(float)contH;
}
