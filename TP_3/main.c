/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

#include "Controller.h"
#define ARCHIVOTEXTO "data.csv"
#define ARCHIVOBINARIO "data.bin"
#define ARCHIVOID "id.csv"

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int id;
	int banderaDeLectura;
	int banderaDeCambios;
	banderaDeCambios=-1;
	banderaDeLectura = 0;
	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		printf(
				"Menu:\n"
						"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
						"3. Alta de empleado\n"
						"4. Modificar datos de empleado\n"
						"5. Baja de empleado\n"
						"6. Listar empleados\n"
						"7. Ordenar empleados\n"
						"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
						"10. Salir\n");
		getIntWithParams("ingrese la opcion deseada\n", "opcion invalida\n",
				&option, 1, 10);
		switch (option) {
		case 1:
			if (banderaDeLectura == 0) {
				get_id_Text(&id);
				controller_loadFromText(ARCHIVOTEXTO, listaEmpleados);
				//	set_id_Text(2);
				banderaDeLectura = 1;
			} else {
				printf("Ya fueron cargados los datos\n");
			}

			break;
		case 2:
			if (banderaDeLectura == 0) {
				controller_loadFromBinary(ARCHIVOBINARIO, listaEmpleados);
				banderaDeLectura = 1;
			} else {

				printf("Ya fueron cargados los datos\n");
			}

			break;
		case 3:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				controller_addEmployee(listaEmpleados);
				banderaDeCambios = 0;

			}

			break;
		case 4:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				controller_editEmployee(listaEmpleados);
				banderaDeCambios = 0;
			}
			break;
		case 5:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				controller_removeEmployee(listaEmpleados);
				banderaDeCambios = 0;
			}
			break;

		case 6:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				controller_ListEmployee(listaEmpleados);

			}

			break;
		case 7:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				controller_sortEmployee(listaEmpleados);

			}

			break;

		case 8:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				banderaDeCambios = 1;
				controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
			}

			break;
		case 9:
			if (banderaDeLectura == 0) {

				printf(
						"Es necesario cargar los datos antes de cualquier operacion\n");

			} else {
				banderaDeCambios = 1;
				controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
			}

			break;
		case 10:
			if (banderaDeLectura != 0) {
				if (banderaDeCambios == 0) {
					printf("No guardo los archivos, "
							"si no guarda puede ocurrir GRAVES problemas."
							"especialmente con el ID.\n ");
					printf("1-Guardar en texto\n"
							"2-Guardar en binario\n"
							"3-Salir\n");
					getIntWithParams("ingrese la opcion que desee;",
							"opcion invalida", &option, 1, 3);
					switch (option) {
					case 1:
						controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
						banderaDeCambios = 1;
						break;
					case 2:
						controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
						banderaDeCambios = 1;
						break;
					case 3:
						option = 10;
						banderaDeCambios = 1;
						break;

					}

				}
			}

			break;

		}
	} while (option != 10);
	return 0;
}

