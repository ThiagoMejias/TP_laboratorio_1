/*
 * menu.h
 *
 *  Created on: 18 sep. 2021
 *      Author: Thiago
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "biblioteca.h"
#include "input.h"

/**
 * @brief se muestra una serie de opciones y se selecciona una
 * @param banderaNumeroUno
 * @param banderaNumeroDos
 * @param numeroUno
 * @param numeroDos
 * @return la opcion elegida
 */

int menu( int banderaNumeroUno, int banderaNumeroDos, float numeroUno, float numeroDos);
#endif /* MENU_H_ */
