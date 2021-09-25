#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[]) {
	int i = 0;
	int cantidadPuntos = 0;
	while (str[i] != '\0') {
		if (i == 0 && str[i] == '-') {
			i++;
			continue;

		}
		if (str[i] == '.' && cantidadPuntos == 0) {
			cantidadPuntos++;
			i++;
			continue;

		}
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (i == 0 && str[i] == '-') {
			i++;
			continue;

		}
		if (str[i] < '0' || str[i] > '9')
			return 0;

		i++;
	}
	return 1;
}





/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[]) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]s", input);
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[], char input[]) {
	char aux[256];
	getString(mensaje, aux);
	if (esNumerico(aux)) {
		strcpy(input, aux);
		return 1;
	}
	return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[], char input[]) {
	char aux[256];
	getString(mensaje, aux);
	if (esNumericoFlotante(aux)) {
		strcpy(input, aux);
		return 1;
	}
	return 0;
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char mensaje[], int *input) {
	char auxStr[256];
	int auxInt;
	int retorno = -1;

	while (!getStringNumeros(mensaje, auxStr)) {
		printf("ERROR ingrese el numero correctamente\n\n\n");
	}
	auxInt = atoi(auxStr);
	*input = auxInt;
	retorno = 0;

	return retorno;

}


/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char mensaje[], float *input) {
	char auxStr[256];
	int retorno = -1;
	float auxInt;

	while (!getStringNumerosFlotantes(mensaje, auxStr)) {
		printf(" ERROR ingrese el numero correctamente\n\n");

	}
	auxInt = atof(auxStr);

	*input = auxInt;
	retorno = 0;

	return retorno;

}






