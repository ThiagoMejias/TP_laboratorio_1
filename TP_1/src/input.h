#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#endif // UTN_H_INCLUDED

int getInt(char* mensaje);
float getFloat(char* mensaje);




int esNumerico(char *str) ;
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char mensaje[], int *input);
int getValidFloat(char mensaje[], float* input);

