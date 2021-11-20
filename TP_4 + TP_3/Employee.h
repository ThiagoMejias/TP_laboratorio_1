#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include  "input.h"
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

// leer y cargar los archivos.
//
// despues de modificar y demas otra carga de archivos.

/// @fn Employee employee_new*()
/// @return el empleado creado y vacio
Employee* employee_new(); // construcs
/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief crea un empleado y le carga dentro de los campos correspondientes los parametros recibidos.
/// @param idStr id a cargar
/// @param nombreStr nombre a cargar
/// @param horasTrabajadasStr horas a cargar
/// @param sueldo sueldo a cargar
/// @return retorna el empleado con los campos cargados
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldo);
/// @fn int employee_delete(Employee*)
/// @brief recibe un empleado y lo elimina de la memoria interna del programa.
/// @param this
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int employee_delete(Employee *this);
// agregar por cada set funciones que pidan por consola los datos que sean necesarios.
// funcion de comparacion x cada campo de empleado.

//set
/// @fn int employee_setId(Employee*, int)
/// @brief  recibe un id y lo ingresa en el campo correspondinete de la estructura
/// @param this puntero a empleado
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_setId(Employee *this, int id); // aca flechita
/// @fn int employee_getId(Employee*, int*)
/// @brief recibe el empleado y una variablde donde cargar el id del empleado
/// @param this puntero a empleado
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_getId(Employee *this, int *id); //aca flechita

// nombre
/// @fn int employee_setNombre(Employee*, char*)
/// @brief recibe nombre, un puntero e ingresa el nombre en el campo correspondiente de la estrucura.
/// @param this puntero a empleado
/// @param nombre nombre a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_setNombre(Employee *this, char *nombre); //aca flechita
/// @fn int employee_getNombre(Employee*, char*)
/// @brief recibe el empleado y una variablde donde cargar el nombre del empleado
/// @param this puntero a empleado
/// @param nombre
/// @return retorna 0 si se pudo o -1 si el puntero null
int employee_getNombre(Employee *this, char *nombre); //aca flechita

//horas

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief recibe horas, un puntero e ingresa las horas en el campo correspondiente de la estrucura.
/// @param this untero a empleado
/// @param horasTrabajadas horas a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas); //aca flechita
/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief  recibe el empleado y una variablde donde cargar las horas trabajadas del empleado
/// @param this puntero a empleado
/// @param horasTrabajadas
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas); //aca flechita

// sueldos

/// @fn int employee_setSueldo(Employee*, int)
/// @brief recibe un sueldo, un puntero e ingresa el sueldo en el campo correspondiente de la estrucura.
/// @param this puntero a empleado
/// @param sueldo el sueldo a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_setSueldo(Employee *this, int sueldo); //aca flechita
/// @fn int employee_getSueldo(Employee*, int*)
/// @brief recibe el empleado y una variablde donde cargar el sueldo del empleado
/// @param this puntero a empleado
/// @param sueldo  variable donde se va recibir el sueldo del
/// @return retorna 0 si se pudo o -1 si el puntero es null
int employee_getSueldo(Employee *this, int *sueldo); //aca flechita

int employee_print(Employee *this);

//Modificacion
/// @fn Employee employee_modification*(Employee*)
/// @brief recibe una empleado y modifica el empleado donde se pida
/// @param this empleado.
/// @return retorna el empleado modificado.
Employee* employee_modification(Employee *this);
/// @fn Employee employee_name_Modification*(Employee*)
/// @brief  recibe un empleado y modifica el nombre con los datos que el usuario ponga.
/// @param this
/// @return retorna el empleado modificado.
Employee* employee_name_Modification(Employee *this);
/// @fn Employee employee_salary_Modification*(Employee*)
/// @brief recibe un empleado y modifica el salario con los datos que el usuario ponga.
/// @param this
/// @return retorna el empleado modificado.
Employee* employee_salary_Modification(Employee *this);
/// @fn Employee employee_hours_Modification*(Employee*)
/// @brief recibe un empleado y modifica las horas con los datos que el usuario ponga.
/// @param this
/// @return retorna el empleado modificado.
Employee* employee_hours_Modification(Employee *this);
/// @fn Employee employee_add*()
/// @brief añade un empleado por teclado
/// @return retorna el empleado ingresado.
Employee* employee_add();

//sort
/// @fn int employee_compare_name(void*, void*)
/// @brief compara dos nombre que se reciben por parametro
/// @param uno primer nombre
/// @param dos segundo nombre
/// @return retorna el resultado de la comparacion.
int employee_compare_name(void *uno, void *dos);
/// @fn int employee_compare_hours(void*, void*)
/// @brief compara las horas
/// @param uno primer empleado
/// @param dos segundo empleado
/// @return retorna 0 si las horas son iguales, uno si el primero es menor que el segundo
/// y -1 si las horas del primero es mayor que el segundo
int employee_compare_hours(void *uno, void *dos);
/// @fn int employee_compare_salary(void*, void*)
/// @brieg compara los salarios.
/// @param uno  primer empleado
/// @param dos segundo empleado
/// @return retorna 0 si las horas son iguales, uno si el sueldo del primero  es menor que el segundo
/// y -1 si el sueldo del primero es mayor  que el segundo
int employee_compare_salary(void *uno, void *dos);

#endif // employee_H_INCLUDED
