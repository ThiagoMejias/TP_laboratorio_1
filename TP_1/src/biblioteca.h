/*
 * biblioteca.h
 *
 *  Created on: 14 sep. 2021
 *      Author: Thiago
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief se piden dos numeros para sumarlos
 * @param numero1
 * @param numero2
 * @return retorna la suma de los numeros
 */

float suma(float numero1, float numero2);

/**
 * @brief se piden dos numeros para restarlos
 * @param numero1
 * @param numero2
 * @return retorna la resta de los numeros
 */

float resta(float numero1, float numero2);

/**
 * @brief se piden dos numeros y se dividen
 * @param numero1
 * @param numero2
 * @return retorna la division de los numeros
 */

float division(float numero1, float numero2);

/**
 * @brief se piden dos numeros y se multiplca
 * @param numero1
 * @param numero
 * @return retorna la multiplicacion de los numeros
 */
float multiplicacion(float numero1, float numero);

/**
 * @brief se pide un numero y se factoriza
 * @param numero1
 * @return retorna la factorizacion de el numero
 */
float factorizacion(float numero1);

#endif /* BIBLIOTECA_H_ */
