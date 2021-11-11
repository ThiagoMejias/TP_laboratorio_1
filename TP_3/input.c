#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char *mensaje) {
	float auxiliar;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &auxiliar);
	return auxiliar;
}

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char *mensaje) {
	int auxiliar;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &auxiliar);
	return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
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
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
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
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[]) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]s", input);
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] != ' ') && (isalpha(str[i]) == 0))
			return 0;
		i++;
	}
	return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[]) {
	char aux[256];

	getString(mensaje, aux);
	if (esSoloLetras(aux)) {
		strcpy(input, aux);

		return 1;
	}
	return 0;
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargar� el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getValidString(char requestMessage[], char errorMessage[],
		char errorMessageLenght[], char input[], int maxLenght, int attemps) {
	int i;
	int retorno = -1;
	char buffer[1024];

	for (i = 0; i < attemps; i++) {
		fflush( stdin);
		if (!getStringLetras(requestMessage, buffer)) {
			printf("%s", errorMessage);
			continue;
		}
		if (strlen(buffer) >= maxLenght) {
			printf("%s", errorMessageLenght);
			continue;

		}
		retorno = 0;
		strcpy(input, buffer);
		break;
	}
	return retorno;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[], char input[]) {
	char aux[256];
	char parche[2] = "xd";
	strcpy(aux, parche);
	getString(mensaje, aux);
	if (esNumerico(aux) && input != NULL) {
		strcpy(input, aux);

		return 1;
	}
	return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[], char input[]) {
	char aux[256];
	char parche[2] = "xd";
	strcpy(aux, parche);
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
 *
 * \param input puntero al lugar donde se cargar� el numero ingresado *
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char mensaje[], int *input) {
	char auxStr[256];
	int auxInt, retorno;
	retorno = -1;

	while (!getStringNumeros(mensaje, auxStr)) {
		printf("ERROR ingrese el numero correctamente\n");
	}
	auxInt = atoi(auxStr);
	*input = auxInt;
	retorno = 0;

	return retorno;

}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \return 0 si consiguio el Numero -1 si no
 *
 */

int getFloatWithParams(char requestMessage[], char errorMessage[], float *input,
		float lowLimit, float hiLimit) {
	char auxStr[256];
	int retorno = -1;
	char parche[2] = "xd";
	float auxInt;
	strcpy(auxStr, parche);
	while (retorno == -1) {

		if (!getStringNumerosFlotantes(requestMessage, auxStr)) {
			printf("%s", errorMessage);
		}
		auxInt = atof(auxStr);
		if (auxInt < lowLimit || auxInt > hiLimit) {
			printf("%s", errorMessage);

		} else {
			*input = auxInt;
			retorno = 0;
			return retorno;
		}

	}

	return retorno;

}

int getIntWithParams(char requestMessage[], char errorMessage[], int *input,
		int lowLimit, int hiLimit) {
	char auxStr[256];
	char parche[2] = "xd";
	int auxInt, retorno = -1;
	while (retorno == -1) {

		if (!getStringNumeros(requestMessage, auxStr)) {
			printf("%s", errorMessage);

		}
		auxInt = atoi(auxStr);
		if (auxInt < lowLimit || auxInt > hiLimit) {
			printf("%s", errorMessage);

		} else {
			*input = auxInt;
			auxInt = atof(auxStr);
			strcpy(auxStr, parche);
			retorno = 0;

			return retorno;
		}

	}
	return retorno;

}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char mensaje[], float *input) {
	char auxStr[256];
	char parche[2] = "xd";
	int retorno = -1;
	float auxInt;

	while (!getStringNumerosFlotantes(mensaje, auxStr)) {
		printf(" ERROR ingrese el numero correctamente\n\n");

	}
	auxInt = atof(auxStr);
	strcpy(auxStr, parche);
	*input = auxInt;

	retorno = 0;

	return retorno;

}

int esAlpha(char str[]) {
	int retorno;
	int i = 0;
	while (str[i] != '\0') {

		if ((str[i] != ' ') && isalpha(str[i]) == 0) {
			retorno = 0;
			break;
		} else {
			retorno = 1;
		}
		i++;
	}

	return retorno;

}

int getStringVerificado(char mensaje[], char mensajeError[], char *input) {
	int retorno = -1;
	char aux[256];
	char parche[2] = "10";
	getString(mensaje, aux);
	while (retorno == -1) {
		if (esAlpha(aux) == 0) {
			getString(mensajeError, aux);
		} else {
			retorno = 0;
			strcpy(input, aux);
			strcpy(aux, parche);
		}
	}
	return retorno;
}

// Punteros

int eliminarCaracterDeArray(int *numeros, int tam, int caracter,
		int *controlDeCambios) {
	int retorno;
	int posicion;
	retorno = -1;
	if (numeros != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			if (*(numeros + i) == caracter) {
				posicion = i;
			}
		}
		moverCaracterAlFinal(numeros, tam, posicion);

		numeros = realloc(numeros, sizeof(int) * (tam - 1));
		*controlDeCambios = *controlDeCambios - 1;
		retorno = 0;
	}

	return retorno;
}

int moverCaracterAlFinal(int *puntero, int tam, int posicion) {
	int retorno;
	retorno = -1;

	if (puntero != NULL && tam > 0) {

		for (int i = posicion; i < tam - 1; i++) {

			swap((puntero + i), (puntero + (i + 1)));

		}

		retorno = 0;
	}

	return retorno;
}

int pedirPunteroEntero(int *puntero, int tam) {
	int retorno;
	retorno = -1;
	if (puntero != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			getValidInt("ingrese el numero\n", (puntero + i));

		}

		retorno = 0;
	}

	return retorno;
}

int mostrarPunteroEntero(int *puntero, int tam) {
	int retorno;
	retorno = -1;
	if (puntero != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			printf("%d\n", *(puntero + i));

		}

		retorno = 0;
	}

	return retorno;

}

int swap(int *x, int *y) {

	int z;

	z = *x;

	*x = *y;

	*y = z;

	return 0;

}

int* constructor(int tam, int *puntero, int *controlDeCambios) {
	int *auxiliar;
	auxiliar = (int*) realloc(puntero, sizeof(int) * (tam + 1));
	*controlDeCambios = *controlDeCambios + 1;
	return auxiliar;
}

int agregarCaracterEnPuntero(int *puntero, int tam, int *controlDeCambios,
		int caracter, int indice) {
	int retorno;
	retorno = -1;

	if (puntero != NULL && tam > 0) {

		puntero = constructor(tam, puntero, controlDeCambios);
		*(puntero + (tam + *controlDeCambios) - 1) = caracter;
		moverCaracterAposicionDeseada(puntero, tam, *controlDeCambios, indice);
		retorno = 0;

	}

	return retorno;
}

int moverCaracterAposicionDeseada(int *puntero, int tam, int controlDeCambios,
		int indice) {
	int retorno;
	retorno = -1;

	if (puntero != NULL && tam > 0) {
		for (int i = (tam + controlDeCambios) - 1; i > (indice - 1); i--) {
			swap((puntero + i), (puntero + i - 1));

		}

		retorno = 0;
	}
	return retorno;
}

int confirmacionDeAccion(char *mensaje) {
	char respuesta[128];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]s", respuesta);
	return strcmp(respuesta, "si");

}

