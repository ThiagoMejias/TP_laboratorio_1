/*
 ============================================================================
 Name        : trabajo.c
 Author      : Thiago Mejias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style


 if (removeEmployee(empleados, TAM, id) < 0) {
 printf("el id del empleado no fue encontrado\n");
 } else {
 printf("el empleado fue dado de baja correctamente\n");
 }
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"
#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);
	int option, banderaPrimeraIinicializacion, contador, id, optionOfMainFour,
			confirmacion;
	contador = 0;
	banderaPrimeraIinicializacion =0;
	Employee empleados[TAM];

	do {

		printf("1.Alta de un empleado\n");
		printf("2.Modificar la informacion de un empleado\n");
		printf("3.Dar de baja a un empleado\n");
		printf("4.informar\n");
		printf("5.Salir\n\n\n");
		getIntWithParams("ingrese una opcion\n",
				"ingrese correctamente la opcion\n", &option, 1, 5);
		switch (option) {
		case 1:
			if (banderaPrimeraIinicializacion == 0) {
				banderaPrimeraIinicializacion = 1;
				initEmployees(empleados, TAM);
			}

			getValidInt("ingrese 1 para confirmar el alta de un nuevo empleado",
					&confirmacion);
			if (confirmacion == 1) {
				contador++;
				requestEmployee(empleados, TAM, contador);

			}

			break;
		case 2:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				getIntWithParams("ingrese la id\n", "la ID es invalida\n", &id,
						1, 1000);
				modifyEmployees(empleados, TAM, id);

			} else {
				printf("no hay ningun empleado cargado\n");
			}

			break;
		case 3:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				getValidInt("ingrese el ID\n", &id);
				removeEmployee(empleados, TAM, id);
			} else {
				printf("no hay ningun empleado cargado\n");
			}

			break;
		case 4:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				printf(
						"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n 2. Total y promedio de los salarios y cuántos empleados superan el salario promedio.\n");
				getIntWithParams("ingrese que desea ver\n ",
						"ingrese una opcion valida\n", &optionOfMainFour, 1, 2);
				switch (optionOfMainFour) {

				case 1:
					system("cls");
					callSortEmployees(empleados, option);
					printEmployees(empleados, TAM);
					break;
				case 2:
					system("cls");
					employeesAboveSalary(empleados, TAM);

					break;

				}

			} else {
				printf("no hay ningun empleado cargado\n");
			}

			break;

		}
	} while (option != 5);

}
