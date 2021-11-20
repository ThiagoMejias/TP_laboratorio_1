/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Thiago
 */
#include "input.h"
#include "LinkedList.h"
#include "Employee.h"
#ifndef PARSER_H_
#define PARSER_H_
#endif /* PARSER_H_ */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_textFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_binaryFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_idFromText(FILE *pFile, LinkedList *pArrayListEmployee);
int parser_textFromId(FILE *pFile, LinkedList *pArrayListEmployee);

int get_id_Text(int *id);
int set_id_Text( int id);
