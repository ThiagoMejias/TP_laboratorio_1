#include "menu.h"

int menu(int banderaNumeroUno, int banderaNumeroDos, float numeroUno,
		float numeroDos) {
	int opcion;

	printf("***menu***\n");

	if (numeroUno == 0 && numeroDos == 0) {

		printf("1. Ingresar 1er operando (A=x)\n");
		printf("2. Ingresar 2do operando (B=y)\n");
		printf("3. Calcular todas las operaciones\n");
		printf("4.mostrar resultados\n");
		printf("5.Salir\n\n");

	} else {
		if (banderaNumeroUno != 0 && banderaNumeroDos != 0) {
			system("cls");
			printf("1. Ingresar 1er operando (A=%.2f)\n", numeroUno);
			printf("2. Ingresar 2do operando (B=%.2f)\n", numeroDos);

		} else {
			if (banderaNumeroUno != 0) {
				system("cls");
				printf("1. Ingresar 1er operando (A=%.2f)\n", numeroUno);
				printf("2. Ingresar 2do operando (B=y)\n");

			} else {
				system("cls");
				printf("1. Ingresar 1er operando (A=x)\n");
				printf("2. Ingresar 2do operando (B=%.2f)\n", numeroDos);

			}
		}
		printf("3. Calcular todas las operaciones\n");
		printf("4.mostrar resultados\n");
		printf("5.Salir\n\n");

	}

	 getValidInt("ingrese la opcion deseada", &opcion);
	return opcion;

}

/*
 * menu.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Thiago
 */

