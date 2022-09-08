..#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <string>

struct stack{
	int sueldo;
	char doc[15];
	char nombre[20];
	char apellido[20];
	int hijos;
	stack *sig;
};

void Push (stack *&, stack);
void Pop (stack *&);
void Show (stack *);

int main(){
	stack *pila=NULL;
	stack n;
	char input;
	while(input!='4'){
	system("cls");
	printf ("\n\t\t Test Pilas");
	printf("\n\t Seleccione una opcion");
	printf("\n 1- Adicionar info a la pila 2- Remover ultimo elemento de la pila  3- mostrar pila  4- Cerrar programa");
	printf("\n\t: ");
	input=getch();
	switch(input){
		case '1': system("cls");
		printf("\n\t Insertar nombre a ser adicionado: ");
		scanf("%s", &n.nombre);
		printf("\n\t Insertar apellido a ser adicionado: ");
		scanf ("%s", &n.apellido);
		printf("\n\t Insertar numero de documento: ");
		scanf ("%s", &n.doc);
		printf("\n\t Insertar sueldo: ");
		scanf ("%d", &n.sueldo);
		do{
			printf("\n\t Insertar cantidad de hijos, entre 0 y 4: ");
			scanf("%d", &n.hijos);
		}while(n.hijos<0 || n.hijos>4);
		printf("\n");
		system("cls");
		Push (pila, n);
		break;
		case '2':
			Pop(pila);
		break;
		case '3': 
			Show(pila);
		break;
		case '4':
			printf("Gracias por utilizar el programa\n");
			system("pause");
		break;
		default: printf("ERROR 01: Comando no definido, por favor intente otra vez.\n");
		system("pause");
		
	}
}
}

void Push (stack *&pila, stack n){
	printf("\n\t\tagregado a la pila\n");
	stack *nuevo_nodo=(stack *)malloc(sizeof(struct stack));
	strcpy(nuevo_nodo->nombre, n.nombre);
	strcpy(nuevo_nodo->apellido, n.apellido);
	strcpy(nuevo_nodo->doc, n.doc);
	nuevo_nodo->sueldo=n.sueldo;
	nuevo_nodo->hijos=n.hijos;
	nuevo_nodo->sig=pila;
	pila=nuevo_nodo;
	printf("\n");
	system("pause");
}
void Pop (stack *& pila){
	system ("cls");
	stack *AUX=(*&pila);
	if (pila==NULL){
		printf("\nImposible sacar el valor, pila vacia");
	}else{
	printf("\n\tSacando: %s %s %s", pila->nombre, pila->apellido, pila->doc );
	free(AUX);
	pila=pila->sig;
	}
	printf("\n");
	system("pause");
}
void Show(stack *p){
	system ("cls");
	
	FILE *A;
	if ((A=fopen("Datos.dat", "w"))==NULL){
		printf("\n \n Error en la apertura de archivo...");
	}
	stack *a=p;
	while (a!=NULL){
		printf("\n\tNombre: %s %s\n\tNumero de doc: %s\n\tSueldo: %d, Cantidad de hijos: %d", a->nombre, a->apellido, a->doc, a->sueldo, a->hijos);
		fprintf(A,"\n\tNombre: %s %s\n\tNumero de doc: %s\n\tSueldo: %d, Cantidad de hijos: %d", a->nombre, a->apellido, a->doc, a->sueldo, a->hijos);
		a=a->sig;
	}
	system ("pause");
	fclose(A);
}
