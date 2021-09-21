#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char *mensaje) {
	float auxiliar;
	printf("%s", mensaje);
	scanf("%f", &auxiliar);
	return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char *mensaje) {
	int auxiliar;
	printf("%s", mensaje);
	scanf("%d", &auxiliar);
	return auxiliar;
}

