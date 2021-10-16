/*
 * empleados.h
 *
 *  Created on: 27 sep. 2021
 *      Author: Thiago
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
// isEmpty
#define CARGADO 0
#define VACIO 1

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;
/**
 * @fn int initEmployees(Employee*, int)
 * @brief recibe un vector y pone el is empty en true
 * @param list  vector de empleados
 * @param len tamaño de vector
 * @return -1 si no se logro  si se logro
 */
int initEmployees(Employee *list, int len);
/**
 * @fn int requestEmployee(Employee*, int, int)
 * @brief pide y registra un nuevo empleado
 * @param list
 * @param len
 * @param id
 * @return -1 si no se logro  si se logro
 */
int requestEmployee(Employee *list, int len, int id);
/// @fn int addEmployee(Employee*, int, char[], char[], float, int, int)
/// @brief agrega un emplado nuevo al vector
/// @param list
/// @param len
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @param id
/// @return -1 si no se logro  si se logro
int addEmployee(Employee *list, int len, char name[], char lastName[],
		float salary, int sector, int id);
/// @fn int findFreePosition(Employee*, int)
/// @brief encuentra una posicion libre
/// @param list
/// @param len
/// @return devuelve la posicion libre
int findFreePosition(Employee *list, int len);
/// @fn int findEmployeeById(Employee*, int, int)
/// @brief encuentra a un empleado segun la id
/// @param list
/// @param len
/// @param id
/// @return retorna la posicion
int findEmployeeById(Employee *list, int len, int id);
/// @fn int removeEmployee(Employee*, int, int)
/// @brief remueve un empleado con la id ingresada
/// @param list
/// @param len
/// @param id
/// @return
int removeEmployee(Employee *list, int len, int id);
/// @fn int printEmploy(Employee)
/// @brief  muestra un empleado
/// @param nombre
/// @return-1 si no se logro 0  si se logro
int printEmploy(Employee nombre);
/// @fn int printEmployees(Employee*, int)
/// @brief muestra en pantalla todo el vector
/// @param list
/// @param len
/// @return -1 si no se logro  0si se logro
int printEmployees(Employee *list, int len);

/// @fn int modifyName(Employee*, int)
/// @brief recibe el vector de empleados y su posicion y  modifica el nombre segun lo que el ususario decida
/// @param empleado
/// @param pos
/// @return -1 si no se logro 0 si se logro

int modifyName(Employee *empleado, int pos);
/// @fn int modifyLastName(Employee*, int)
/// @brief recibe el vector de empleados y su posicion y modifica el apellido segun lo que el ususario decida
/// @param empleado
/// @param pos
/// @return-1 si no se logro  0 si se logro
int modifyLastName(Employee *empleado, int pos);
/// @fn int modifySector(Employee*, int)
/// @brief recibe el vector de empleados y su posicion y  modifica el sector segun lo que el ususario decida
/// @param empleado
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifySector(Employee *empleado, int pos);
/// @fn int modifySalary(Employee*, int)
/// @brief recibe el vector de empleados y su posicion y modifica el salario segun lo que el usuario decida
/// @param empleado
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifySalary(Employee *empleado, int pos);
/// @fn int modifyEmployees(Employee*, int, int)
/// @brief  recibe el vector el tamaño y la id para luego mostrar un menu para selecccionar que se desea moficiar
/// @param list
/// @param len
/// @param id
/// @return-1 si no se logro  0 si se logro

int modifyEmployees(Employee *list, int len, int id);

/// @fn int getAvarageOfSalary(Employee*, int, float*, int*)
/// @brief esta funcion calcula el promedio de los salarios y devuelve por referencia el promedio y el acumulado de los salarios
/// @param list
/// @param len
/// @param promedio
/// @param acumuladorDeSalarios
/// @return
int getAvarageOfSalary(Employee *list, int len, float *promedio,
		int *acumuladorDeSalarios);

/// @fn int employeesAboveSalary(Employee*, int)
/// @brief muestra cual es el promedio de los salarios y cuantos empleados superan el mismo
/// @param list
/// @param len
/// @return

int employeesAboveSalary(Employee *list, int len);

/// @fn int sortForSector(Employee*, int)
/// @brief ordena el vector por sector
/// @param list
/// @param len
/// @return

int sortForSector(Employee *list, int len);
/// @fn int sortForLastName(Employee*, int)
/// @brief ordena el vector por apellido
/// @param list
/// @param len
/// @return
int sortForLastName(Employee *list, int len);
/// @fn int sortEmployees(Employee*, int)
/// @brief ordena el vector por doble referencia
/// @param list
/// @param len
/// @return
int sortEmployees(Employee *list, int len, int option);

int sortUpEmployees(Employee *list, int len);
int sortDownEmployees(Employee *list, int len);
int callSortEmployees(Employee *list, int len);
#endif /* ARRAYEMPLOYEES_H_ */
