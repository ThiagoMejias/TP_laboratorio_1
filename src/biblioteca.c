#include "biblioteca.h"
float suma(float numero1, float numero2) {
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}
float resta(float numero1, float numero2) {
	float resultado;
	resultado = numero1 - numero2;
	return resultado;

}

float division(float numero1, float numero2) {
	float resultado;
	resultado = 0;
	if (numero2 != 0) {
		resultado = numero1 / numero2;
	}
	return resultado;
}

float multiplicacion(float numero1, float numero2) {
	float resultado;
	resultado = numero1 * numero2;
	return resultado;
}

int factorizacion(float numero1) {
	int resultado = 0;

	if (numero1 - (int) numero1 == 0 && numero1 > 0) {
		float multiplicador;

		multiplicador = numero1 - 1;

		while (multiplicador > 1) {
			numero1 = numero1 * multiplicador;
			multiplicador--;

		}
		resultado = numero1;
	}

	return resultado;
}

