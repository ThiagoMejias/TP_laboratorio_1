/*
 * empleados.c¿
 *
 *  Created on: 27 sep. 2021
 *      Author: Thiago Mejias
 *
 */

#include "ArrayEmployees.h"

int initEmployees(Employee *list, int len) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int requestEmployee(Employee *list, int len, int id) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {

		system("cls");
		printf("*ingreso de empleados*\n");
		Employee newEmployee;
		newEmployee.id = id;

		getValidInt("ingrese el sector", &newEmployee.sector);

		getStringVerificado("ingrese el nombre",
				"error ingrese el nombre correctamente", newEmployee.name);

		getStringVerificado("ingrese el apellido\n",
				"ingrese correctamente el apellido\n", newEmployee.lastName);

		getFloatWithParams("ingrese el salario(maximo $500.000)\n", "ERROR	\n",
				&newEmployee.salary, 1, 500000);
		addEmployee(list, len, newEmployee.name, newEmployee.lastName,
				newEmployee.salary, newEmployee.sector, newEmployee.id);
		retorno = 0;

	}

	return retorno;

}

int findFreePosition(Employee *list, int len) {
	int pos = -1;
	if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == VACIO) {
				pos = i;
				break;
			}
		}

	}

	return pos;
}

int addEmployee(Employee *list, int len, char name[], char lastName[],
		float salary, int sector, int id) {

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		int posFree;
		posFree = findFreePosition(list, len);
		list[posFree].id = id;
		list[posFree].salary = salary;
		list[posFree].sector = sector;
		strcpy(list[posFree].name, name);
		strcpy(list[posFree].lastName, lastName);
		list[posFree].isEmpty = CARGADO;

		retorno = 0;
	}

	return retorno;
}

int findEmployeeById(Employee *list, int len, int id) {
	int pos;
	pos = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == CARGADO && list[i].id == id) {
				pos = i;
				break;
			}
		}
	}

	if (pos == -1) {
		printf("no existe empleado con ese ID\n");
		system("pause");
	}

	return pos;
}
int removeEmployee(Employee *list, int len, int id) {
	int retorno, pos;
	retorno = -1;
	pos = findEmployeeById(list, len, id);
	if (pos > -1) {

		list[pos].isEmpty = VACIO;
		printf("el empleado fue dado de baja correctamente\n");
		system("pause");
		retorno = 0;
	}

	return retorno;

}

int callSortEmployees(Employee *list, int len) {
	int retorno, option;
	retorno = -1;

	getIntWithParams("ingrese 1 para ordenar de arriba hacia abajo\n"
			"ingrese 0 para ordenar de abajo hacia arriba\n",
			"ERROR ingrese la opcion correctamente\n", &option, 0, 1);

	sortEmployees(list, len, option);

	return retorno;
}

int sortDownEmployees(Employee *list, int tam) {
	Employee temp;
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(list[i].lastName, list[j].lastName)
					< 0&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			} else {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {

					if (list[i].sector
							> list[j].sector&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
					}
				}
			}
		}
	}

	return retorno;
}

int sortUpEmployees(Employee *list, int tam) {

	Employee temp;
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(list[i].lastName, list[j].lastName)
					> 0&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			} else {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {

					if (list[i].sector
							< list[j].sector&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
					}
				}
			}
		}
	}

	return retorno;
}

int sortEmployees(Employee *list, int len, int option) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		if (option == 1) {
			sortUpEmployees(list, len);

		} else {
			sortDownEmployees(list, len);

		}
		retorno = 0;
	}

	return retorno;
}

int modifyName(Employee *empleado, int pos) {
	int retorno;
	retorno = 0;
	system("cls");
	getStringVerificado("ingrese el nuevo nombre\n",
			"ingrese correctamente el nuevo nombre", empleado[pos].name);

	return retorno;
}

int modifyLastName(Employee *empleado, int pos) {
	int retorno;
	retorno = 0;
	system("cls");
	getStringVerificado("ingrese el nuevo apellido\n",
			"ingrese correctamente el nuevo apellid\n", empleado[pos].lastName);

	return retorno;

}

int modifySector(Employee *empleado, int pos) {
	system("cls");
	getValidInt("ingrese el nuevo sector\n", &empleado[pos].sector);

	return 0;
}
int modifySalary(Employee *empleado, int pos) {
	system("cls");
	getValidFloat("ingrese el nuevo salario\n", &empleado[pos].salary);

	return 0;
}

int modifyEmployees(Employee *list, int len, int id) {
	int pos, option;
	pos = findEmployeeById(list, len, id);
	system("cls");
	if (pos != -1) {

		do {
			system("cls");
			printf("1 para modificar el nombre\n");
			printf("2 para modificar el apellido\n");
			printf("3 para modifica el salario\n");
			printf("4 para modificar el sector\n");
			printf("5 para regresar atras\n");
			getIntWithParams("ingrese una opcion\n",
					"ingrese correctamente la opcion\n", &option, 1, 5);
			switch (option) {
			case 1:

				modifyName(list, pos);

				break;
			case 2:
				modifyLastName(list, pos);
				break;
			case 3:

				modifySalary(list, pos);
				break;
			case 4:
				modifySector(list, pos);
				break;

			}

		} while (option != 5);

	}

	return 0;
}

int getAvarageOfSalary(Employee *list, int len, float *promedio,
		int *acumuladorDeSalarios) {
	int contadorDeEmpleados, auxDeAcumuladorDeSalarios;

	contadorDeEmpleados = 0;
	auxDeAcumuladorDeSalarios = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == CARGADO) {
				auxDeAcumuladorDeSalarios = auxDeAcumuladorDeSalarios
						+ list[i].salary;
				++contadorDeEmpleados;

			}
		}

	}

	*promedio = auxDeAcumuladorDeSalarios / (float) contadorDeEmpleados;
	*acumuladorDeSalarios = auxDeAcumuladorDeSalarios;
	return 0;
}

int employeesAboveSalary(Employee *list, int len) {
	int contadorDeEmpleadosSuperadoresDePromedio, acumuladorDeSalarios;
	float promedio;
	contadorDeEmpleadosSuperadoresDePromedio = 0;
	getAvarageOfSalary(list, len, &promedio, &acumuladorDeSalarios);

	for (int i = 0; i < len; i++) {

		if (list[i].salary > promedio && list[i].isEmpty == CARGADO) {
			contadorDeEmpleadosSuperadoresDePromedio++;
		}

	}

	printf("el promedio de los salarios es:%.2f \n"
			"la cantidad de empleados que superan el promedio son %d\n",
			promedio, contadorDeEmpleadosSuperadoresDePromedio);
	return 1;
}

int printEmploy(Employee nombre) {

	printf("\t\t\t\t\t|%9s|%10s|", nombre.name, nombre.lastName);
	printf("%5d|%5d |%10.2f |\n", nombre.id, nombre.sector, nombre.salary);

	return 0;
}

int printEmployees(Employee *list, int len) {
	int retorno;
	retorno = -1;
	system("cls");
	printf("\t\t\t\t\t_______________________________________________\n");
	printf("\t\t\t\t\t|Name     |LastName  |Id   |Sector|salary     |\n");
	printf("\t\t\t\t\t|_________|__________|_____|______|___________|\n");
	for (int i = 0; i < len; i++) {

		if (list != NULL && len > 0) {

			if (list[i].isEmpty == CARGADO) {
				printEmploy(list[i]);
			}
			retorno = 0;
		}

	}

	return retorno;
}

