// nexo-

#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

// aca se toca dsp de empleados.

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief carga los datos de texto en la memoria
/// @param path archivo a leer y cargar
/// @param pArrayListEmployee lista donde cargar
/// @return retorna 0 si salio bien -1 si salio mal.
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee);
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief carga los datos de binario en la memoria
/// @param path archivo a leer y cargar
/// @param pArrayListEmployee lista donde cargar
/// @return retorna 0 si salio bien -1 si salio mal.
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee);
/// @fn int controller_addEmployee(LinkedList*)
/// @brief añade un nuevo empleado
/// @param pArrayListEmployee lsita
/// @return retorna 0 si salio bien -1 si salio mal
int controller_addEmployee(LinkedList *pArrayListEmployee);
int controller_editEmployee(LinkedList *pArrayListEmployee);

/// @fn int controller_removeEmployee(LinkedList*)
/// @brief elimina un empleado de la lista.
/// @param pArrayListEmployee
/// @return
int controller_removeEmployee(LinkedList *pArrayListEmployee);
/// @fn int controller_ListEmployee(LinkedList*)
/// @brief lista los empleados.
/// @param pArrayListEmployee
/// @return retorna 0 si salio bien -1 si salio mal
int controller_ListEmployee(LinkedList *pArrayListEmployee);
/// @fn int controller_sortEmployee(LinkedList*)
/// @brief ordena la lista segun lo que se reciba dentro
/// @param pArrayListEmployee
/// @return retorna 0 si salio bien -1 si salio mal
int controller_sortEmployee(LinkedList *pArrayListEmployee);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief guarda en en texto el nuevo archivo.
/// @param path
/// @param pArrayListEmployee
/// @return  retorna 0 si salio bien -1 si salio mal
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee);
/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief guarda en binario el archivo.
/// @param path
/// @param pArrayListEmployee
/// @return retorna 0 si salio bien -1 si salio mal
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee);

/// @fn int generadorDeId(LinkedList*, int*)
/// @param pArrayListEmployee lista
/// @param id
/// @return retorna 0 si salio bien -1 si salio mal
int generadorDeId(LinkedList *pArrayListEmployee, int *id);

/// @fn int findEmployee_by_Id(LinkedList*, int)
/// @brief  recibe una lista y un id y busca que elemento tiene ese id
/// @param pArrayListEmployee
/// @param id id a buscar
/// @return -1 si no encontro o salio algo mal y si no la posicion del elemento
int findEmployee_by_Id(LinkedList *pArrayListEmployee, int id);

