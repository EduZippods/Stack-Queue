/* Ejemplo de una Lista implementada como cola.
A partir de un archivo del tipo texto llamado nombres.txt
cargar en una lista implementada como cola para lo cual se debera crear
una estructura que soporte una cadena de caracteres de 25.
Una vez cargada la Lista, el programa debera desplegar un menu en pantalla
con las opciones de insertar nodos,Borrar Nodos y Visualizar los datos de la Lista.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
{ char nom[25];};

typedef struct elemento T_Elemento;

struct cola
{
  T_Elemento Dato;
  struct cola *sig;
};

typedef struct cola T_Cola;

typedef T_Cola *Ptr_Cola;

void insertar(Ptr_Cola *, Ptr_Cola *, T_Elemento);
void extraer(Ptr_Cola *);
void visualizar(T_Cola *);

main() /* Rellenar, extraer y visualizar */
{
	T_Cola *L=NULL, *F=NULL;
	T_Elemento N;
	char opc;
	FILE *Ar;
    if ((Ar=fopen("nombre.dat","r"))==NULL)
       {printf("\nError en apertura......\n");
        getch();
        exit(0);}
	fscanf(Ar,"%s",&N.nom);
    while (!feof(Ar))
	  {	insertar(&L,&F,N);
        fscanf(Ar,"%s",&N.nom); }
        
	
	do
	{
		system("cls"); /* borramos la pantalla */
		printf("\nLista Implementada como COLA\n");
       	printf("1.- Borrar\n");
    	printf("2.- Mostrar\n");
        printf("3.- Salir\n");
		opc=getch( );
		switch(opc)
		{
			case '1':
				extraer(&L);
				break;
			case '2':
				visualizar(L);
		}
	}while (opc!='3');
}

void insertar(Ptr_Cola *Q, Ptr_Cola *QF,T_Elemento X)
{
   T_Cola *AUX;
   AUX = (T_Cola *)malloc(sizeof(struct cola));
   AUX->Dato= X;
   AUX->sig =NULL;
   if ((*Q)==NULL)
     { (*Q)=(*QF) = AUX;     }
   else
     {
       (*QF)->sig = AUX;
       (*QF)=AUX;
     }
}

void extraer(Ptr_Cola *Q)
{
   T_Cola *AUX;
  
   if (Q!=NULL)
     { AUX=(*Q);
       (*Q)=(*Q)->sig;
       free(AUX);
       printf("\n\nExtraccion realizada...., pulse una tecla\n");}
   
   system("pause");
}

void visualizar(T_Cola *Q)
{
    if (Q==NULL) return;
    system("cls");
    printf("\n\nNombres de la lista\n\n");
    while (Q!=NULL)
    {
	printf("%s\n",Q->Dato.nom);
	Q=Q->sig;
    }
    getch( );
}
