/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Thiago Mejias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 #include "utn.h"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Biblioteca.h"
#include "menu.h"
int main(void) {
	setbuf(stdout, NULL);
	int banderaNumeroUno = 0;
	int banderaNumeroDos = 0;
	float numeroUno = 0;
	float numeroDos = 0;
	float resultadoSuma = 0;
	float resultadoResta = 0;
	float resultadoMultiplicacion = 0;
	float resultadoDivision = 0;
	float resultadoFactorizacionUno;
	float resultadoFactorizacionDos;
	int opcion;
	do {
		opcion = menu(banderaNumeroUno, banderaNumeroDos, numeroUno, numeroDos);
		switch (opcion) {
		case 1:
			numeroUno = getFloat("ingrese el primer operando: ");
			banderaNumeroUno = 1;
			break;
		case 2:
			numeroDos = getFloat("ingrese el segundo operando: ");
			banderaNumeroDos = 1;
			break;
		case 3:
			system("cls");
			printf("Calculando operaciones\n\n ");
			printf("Las operaciones fueron calculadas correctamente\n");

			resultadoSuma = suma(numeroUno, numeroDos);
			resultadoResta = resta(numeroUno, numeroDos);
			resultadoMultiplicacion = multiplicacion(numeroUno, numeroDos);
			resultadoDivision = division(numeroUno, numeroDos);
			resultadoFactorizacionUno = factorizacion(numeroUno);
			resultadoFactorizacionDos = factorizacion(numeroDos);
			break;
		case 4:
			system("cls");
			printf("\nEl resultado de %.2f+%.2f es: %.2f\n", numeroUno,
					numeroDos, resultadoSuma);
			printf("El resultado de %.2f-%.2f es: %.2f\n", numeroUno, numeroDos,
					resultadoResta);
			printf("el resultado de la multiplicacion de %.2f*%.2f es: %.2f\n",
					numeroUno, numeroDos, resultadoMultiplicacion);
			if (resultadoDivision == 0) {
				printf("no se puede dividir un numero por 0\n");
			} else {
				printf("El resultado de  %.2f/ %.2f es: %.2f\n", numeroUno,
						numeroDos, resultadoDivision);
			}
			if (resultadoFactorizacionUno == -1) {
				printf(
						" el factorial de %.2f no pudo sacarse debido a que solo se puede sacar el factorial de un numero entero entre el 0 y el 35.\n",
						numeroUno);
			} else {
				printf("el factorial de %.2f es: %.2f\n", numeroUno,
						resultadoFactorizacionUno);
			}
			if (resultadoFactorizacionDos == -1) {
				printf(
						"el factorial de %.2f no pudo sacarse debido a que solo se puede sacar el factorial de un numero entero entre el 0 y el 35.\n\n\n",
						numeroDos);
			} else {
				printf("el factorial de %.2f es: %.2f \n\n\n", numeroDos,
						resultadoFactorizacionDos);
			}

			system("pause");

			break;

		}
	} while (opcion != 5);

<<<<<<< HEAD
	printf("gracias por utilizar la calucladora!!!");
=======
	printf("gracias por utilizar la calucladora!!");
>>>>>>> 28b9b032914a79bc174203530f39c0ed79d65fe9
	return EXIT_SUCCESS;
}

