#include "Employee.h"

// sueldo.
int employee_setSueldo(Employee *this, int sueldo) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

//id
int employee_setId(Employee *this, int id) {

	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->id = id;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

int employee_getId(Employee *this, int *id) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		*id = this->id;
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// nombre
int employee_setNombre(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// horas trabajadas

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// constructores
Employee* employee_new() {

	Employee *retorno;

	retorno = (Employee*) calloc(1, sizeof(Employee));

	return retorno;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {

	Employee *newEmployee;
	newEmployee = employee_new();

	if (newEmployee != NULL) {
		employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
		employee_setNombre(newEmployee, nombreStr);
		employee_setSueldo(newEmployee, atoi(sueldoStr));
		employee_setId(newEmployee, atoi(idStr));
	} else {
		printf("Ocurrio un error\n");
	}

	return newEmployee;
}

int employee_print(Employee *this) {
	int retorno;
	retorno = -1;
	char nombraAux[50];
	int idAux;
	int horasTrabajadasAux;
	int sueldoAux;
	if (this != NULL) {

		employee_getNombre(this, nombraAux);
		employee_getId(this, &idAux);
		employee_getHorasTrabajadas(this, &horasTrabajadasAux);
		employee_getSueldo(this, &sueldoAux);
		printf("%d, %s, %d, %d\n", idAux, nombraAux, horasTrabajadasAux,
				sueldoAux);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;

}

// modificacion

Employee* employee_modification(Employee *this) {
	int option;
	do {
		printf("*modificacion De Empleados*\n"
				"1-Modificar Nombre\n"
				"2-Modificar horas trabajadas\n"
				"3-Modificar el sueldo\n"
				"4-salir\n");
		getIntWithParams("ingrese la opcion deseada\n", "opcion invalida\n",
				&option, 1, 4);
		switch (option) {

		case 1:
			employee_name_Modification(this);
			break;
		case 2:
			employee_hours_Modification(this);
			break;
		case 3:
			employee_salary_Modification(this);
			break;

		}

	} while (option != 4);
	return this;
}
Employee* employee_name_Modification(Employee *this) {
	char nombreAux[50];

	employee_print(this);
	getStringVerificado("ingrese el nuevo nombre\n",
			"ingrese el nombre correctamente\n", nombreAux);
	employee_setNombre(this, nombreAux);
	employee_print(this);
	return this;
}

Employee* employee_salary_Modification(Employee *this) {
	int salaryAux;
	employee_print(this);
	getValidInt("ingrese el nuevo sueldo\n", &salaryAux);
	employee_setSueldo(this, salaryAux);
	employee_print(this);
	return this;
}

Employee* employee_hours_Modification(Employee *this) {
	int horasTrabajadasAux;
	employee_print(this);
	getValidInt("ingrese las nuevas horas trabajadas\n", &horasTrabajadasAux);
	employee_setHorasTrabajadas(this, horasTrabajadasAux);
	employee_print(this);

	return this;
}

//agregar empleados por consola.

Employee* employee_add(int id) {
	Employee *newEmployee;
	char nombraAux[50];
	int horasTrabajadasAux;
	int sueldoAux;

	newEmployee = employee_new();
	if (newEmployee != NULL) {

		printf("*ingreso de empleados\n*");
		getStringVerificado("ingrese el nombre correctamente\n",
				"error ingrese el nombre correctamente\n", nombraAux);
		getValidInt("ingrese el sueldo del nuevo empleado.\n", &sueldoAux);
		getValidInt("ingrese las horas trabajadas\n", &horasTrabajadasAux);

		employee_setHorasTrabajadas(newEmployee, horasTrabajadasAux);
		employee_setNombre(newEmployee, nombraAux);
		employee_setSueldo(newEmployee, sueldoAux);
		employee_setId(newEmployee, id);
	} else {
		printf("Ocurrio un error\n");
	}

	return newEmployee;

}

// ordenamiento

int employee_compare_name(void *uno, void *dos) {
	int retorno;
	char nombreUno[128];
	char nombreDos[128];
	Employee *primero;
	Employee *segundo;

	retorno = -1;
	primero = (Employee*) uno;
	segundo = (Employee*) dos;
	employee_getNombre(primero, nombreUno);
	employee_getNombre(segundo, nombreDos);
	retorno = stricmp(nombreUno, nombreDos);

	return retorno;

}

int employee_compare_salary(void *uno, void *dos) {
	int retorno;
	int sueldoUno;
	int sueldoDos;
	retorno = -1;
	Employee *primero;
	Employee *segundo;
	primero = (Employee*) uno;
	segundo = (Employee*) dos;
	if (employee_getSueldo(primero, &sueldoUno) == 0
			&& employee_getSueldo(segundo, &sueldoDos) == 0) {
		retorno = 0;
		if (sueldoUno < sueldoDos) {

			retorno = 1;
		} else {

			if (sueldoUno > sueldoDos) {
				retorno = -1;

			}

		}

	}

	return retorno;

}

int employee_compare_hours(void *uno, void *dos) {
	int retorno;
	int horasUno;
	int horasDos;
	retorno = -1;
	Employee *primero;
	Employee *segundo;
	primero = (Employee*) uno;
	segundo = (Employee*) dos;

	if (employee_getHorasTrabajadas(primero, &horasUno) == 0
			&& employee_getHorasTrabajadas(segundo, &horasDos) == 0) {
		retorno = 0;
		if (horasUno < horasDos) {

			retorno = 1;
		} else {

			if (horasUno > horasDos) {
				retorno = -1;

			}

		}

	}

	return retorno;

}

int employee_delete(Employee *this) {
	int retorno;

	retorno = -1;

	if (this != NULL) {

		free(this);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

