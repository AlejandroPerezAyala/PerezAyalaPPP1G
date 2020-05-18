/*
 ============================================================================
 Name        : Ejercicios.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM 4

typedef struct{
	int id;
	char procesador[50];
	char marca[20];
	float precio;

}Notebook;


float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarNotebooks(Notebook list[], int tam);
int printNotebooks(Notebook list[], int tam);

int main(void) {

	float precio;// = 20000;
	float descuento;

	char cadena[20];// = "alejandro ayala";
	char caracter;// = 'a';
	int contCaracteres;

	Notebook notebook[TAM] = {	{1000, "I5 8600", "Intel", 20500},
								{1002, "Ryzen 2600", "AMD", 18600},
								{1003, "i5 9400f", "Intel", 15000},
								{1004, "ryzen 3600x", "AMD", 22400}	};

	printf("ingrese le precio del producto: ");
	scanf("%f", &precio);

	printf("ingresa una cadena de caracteres: ");
	__fpurge(stdin);
	fgets(cadena, 20, stdin);
	for(int i = 0; cadena[i] != '\0'; i++){
		if(cadena[i] == '\n'){
			cadena[i] = '\0';
		}
	}

	printf("ingrese el caracter: ");
	__fpurge(stdin);
	scanf("%c", &caracter);




	descuento = aplicarDescuento(precio);

	contCaracteres = contarCaracteres(cadena, caracter);


	printf("[1]-El precio del producto es: $%.2f y con el descuento quedaria en: $%.2f\n\n", precio, descuento);

	printf("[2]-En la cadena %s la letra A se repite %d veces\n\n", cadena, contCaracteres);

	printNotebooks(notebook, TAM);



	return EXIT_SUCCESS;
}


float aplicarDescuento(float precio){

	float descuento;
	float D5 = 0.95;

	descuento = precio * D5;

	return descuento;
}

int contarCaracteres(char cadena[], char caracter){
	int contCaracteres = 0;

	for (int i = 0; cadena[i] != '\0'; i ++){
		if (cadena[i] == caracter){
			contCaracteres++;
		}
	}


	return contCaracteres;
}


int printNotebooks(Notebook list[], int tam){
	ordenarNotebooks(list, tam);
	printf("[3]-ID     PROCESADOR    MARCA    PRECIO\n\n");
	for(int i = 0; i < tam; i++){
		printf("%d    %11s    %11s     %5.2f\n\n", list[i].id, list[i].procesador, list[i].marca, list[i].precio);
	}
	return 0;
}

int ordenarNotebooks(Notebook list[], int tam){
	Notebook auxMarca;
	Notebook auxPrecio;

	for(int i = 0; i < tam - 1; i ++){
		for(int j = i + 1; j < tam; j ++){
			if (strcmp(list[i].marca, list[j].marca) > 0 ){
				auxMarca = list[i];
				list[i] = list[j];
				list[j] = auxMarca;

				} else if(strcmp(list[i].marca, list[j].marca) == 0 && list[i].precio < list[j].precio){
						auxPrecio = list[i];
						list[i] = list[j];
						list[j] = auxPrecio;
				}
			}
		}

	return 0;
	}


