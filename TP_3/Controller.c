#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "r");
	if (pFile != NULL) {

		parser_EmployeeFromText(pFile, pArrayListEmployee);

		retorno = 0;
	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "rb");
	if (pFile != NULL) {
		//printf("entro aca al != null\n");

		parser_EmployeeFromBinary(pFile, pArrayListEmployee);

		retorno = 0;
	}
	fclose(pFile);
	return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	Employee *newEmployee;
	int id;
	int confirmacion;
	int retorno;

	retorno = -1;
	confirmacion =
			confirmacionDeAccion(
					"si desea confirmar la dada de alta de un empleado 'si', de lo contrario escribe otra cosa"
							"\n");

	if (confirmacion == 0) {
		if (pArrayListEmployee != NULL) {

			//generadorDeId(pArrayListEmployee, &id);

			get_id_Text(&id);
			id++;
			newEmployee = employee_add(id);
			set_id_Text(id);

			ll_add(pArrayListEmployee, newEmployee);
			printf("el empleado fue dada de alta correctamente\n");
			retorno = 0;

		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int idABuscar;
	int pos;
	int indice;
	int confirmacion;

	controller_ListEmployee(pArrayListEmployee);
	getValidInt("ingrese el id del empleado que desea eliminar\n", &idABuscar);
	pos = findEmployee_by_Id(pArrayListEmployee, idABuscar);
	if (pos != -1) {
		aux = ll_get(pArrayListEmployee, pos);
		employee_print(aux);
		confirmacion =
				confirmacionDeAccion(
						"si desea confirmar la baja de ese empleado ingrese 'si' de lo contrario ingrese otra cosa\n");

		if (confirmacion == 0) {
			indice = ll_indexOf(pArrayListEmployee, aux);
			ll_remove(pArrayListEmployee, indice);
			employee_delete(aux);
			printf("el empleado fue removido correctamente\n");
			employee_print(aux);
			printf(" removido\n");
		}

	} else {
		printf("no se encontro el empleado\n");

	}

	return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int tam;
	int retorno;

	retorno = -1;
	if (pArrayListEmployee != NULL) {
		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++) {
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_print(aux);
			retorno = 0;
		}

	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	Employee *aux;
//Employee *auxDos;
	int idABuscar;
	int pos;
//int indice;
	retorno = -1;

	if (pArrayListEmployee != NULL) {

		controller_ListEmployee(pArrayListEmployee);
		getValidInt("ingrese el id del empleado que desea modificar\n",
				&idABuscar);
		pos = findEmployee_by_Id(pArrayListEmployee, idABuscar);
		if (pos != -1) {
			aux = ll_get(pArrayListEmployee, pos);
			//	indice = ll_indexOf(pArrayListEmployee, aux);
			aux = employee_modification(aux);
		} else {
			printf("no se encontro el empleado\n");

		}

		retorno = 0;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//int controller_sortEmployee(LinkedList *pArrayListEmployee) {
//	ll_sort(pArrayListEmployee, employee_compare_salary, 1);
//	controller_ListEmployee(pArrayListEmployee);
//	return 0;
//}
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	int option;
	int subOption;
	retorno = -1;

	if (pArrayListEmployee != NULL) {

		do {

			printf("*order lista\n*"
					"1-Ordenar Por Nombre\n"
					"2-Ordenar Por Salario\n"
					"3-Ordenar Por Horas de trabajo\n"
					"4-salir\n");
			getIntWithParams("ingrese la opcion\n", "opcion invalida\n",
					&option, 1, 4);
			switch (option) {

			case 1:
				printf("*ordenar por Nombre\n*"
						"0-Ordenar de mayor a menor\n"
						"1-Ordenar de menor a mayor\n"
						"2-salir\n");
				getIntWithParams("ingrese la opcion\n", "opcion invalida\n",
						&subOption, 0, 2);

				if (subOption != 2) {

					ll_sort(pArrayListEmployee, employee_compare_name,
							subOption);

				}
				break;
			case 2:
				printf("*ordenar por Salario*\n"
						"0-Ordenar de mayor a menor\n"
						"1-Ordenar de menor a mayor\n"
						"2-salir\n");
				getIntWithParams("ingrese la opcion\n", "opcion invalida\n",
						&subOption, 0, 2);
				ll_sort(pArrayListEmployee, employee_compare_salary, subOption);

				break;
			case 3:
				printf("*ordenar por Horas De trabajo\n*"
						"0-Ordenar de mayor a menor\n"
						"1-Ordenar de menor a mayor\n"
						"2-salir\n");
				getIntWithParams("ingrese la opcion\n", "opcion invalida\n",
						&subOption, 0, 2);
				ll_sort(pArrayListEmployee, employee_compare_hours, subOption);

				break;
			}

		} while (option != 4);

		retorno = 0;
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {

	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "w");
	if (pFile != NULL) {

		parser_textFromEmployee(pFile, pArrayListEmployee);

		retorno = 0;
	}
	fclose(pFile);
	return retorno;

	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "wb");
	if (pFile != NULL) {
		parser_binaryFromEmployee(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);
	return retorno;
}

int generadorDeId(LinkedList *pArrayListEmployee, int *id) {
	int retorno;
	int tam;
	int banderaDeEntrada;
	int idAux;
	int auxMayor;
	banderaDeEntrada = 0;
	Employee *aux;
	retorno = -1;

	if (pArrayListEmployee != NULL) {

		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++) {

			aux = (Employee*) ll_get(pArrayListEmployee, (i));

			employee_getId(aux, &idAux);

			if (banderaDeEntrada == 0) {
				banderaDeEntrada = 1;

				auxMayor = idAux;
				if (auxMayor < idAux) {
					auxMayor = idAux;

				}
			}

			*id = idAux + 1;

			retorno = 0;
		}

	}

	return retorno;
}

int findEmployee_by_Id(LinkedList *pArrayListEmployee, int id) {
	Employee *aux;
	int retorno;
	int tam;
	int idABuscar;
	retorno = -1;
	if (pArrayListEmployee != NULL) {
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; i++) {
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &idABuscar);

			if (id == idABuscar) {

				retorno = i;
			}

		}

	}

	return retorno;
}

