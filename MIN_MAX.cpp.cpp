/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACI„N AVANZADA
Realizado por el compa§ero: Gabriel Reyes Severiano

Este programa utiliza funciones con las cuales rellenara un arreglo y
en el buscara al mayor y al menor de los elementos del arreglos

*/

#include <stdio.h>
#include <stdlib.h>
#define max 10
//**************************************************************************
int obten_mayor(int N,int A[]);    //declaracion de protocolo de funciones
int obten_menor(int N,int A[]);
//***************************************************************************
main()
{
int N,A[max],MAYOR,MENOR,i;
    system("clear");
    do{
	printf("\n   **  BUSCANDO MAYOR Y MENOR **");
	printf("\n\n   ** Numero de elementos que contendra su arreglo :**\t");
	scanf("%d",&N);
	if(N>max)
		printf("ERROR!................... (debe ser menor que 10)");
	else if(N<=0)
		printf("No permitido!, debe ser mayor que cero");

    }while((N>max)||(N<=0));
    N=N-1;

    for(i=0;i<=N;i++)
	{
	printf("Proporcione elemento %d\t",i+1);
	scanf("%d",&A [i]);
	}
     printf("\n");

	MAYOR=obten_mayor(N,A);
		printf("El mayor es: %d\n",MAYOR);

	MENOR=obten_menor(N,A);
		printf("El menor es: %d",MENOR);
	getchar();
	getchar();

     return 0;
}
//*********************************************************************
int obten_mayor(int N,int A[])        //esta funcion busca en el arreglo
{                                     //el mayor de los elementos
	int mayor,i;
	mayor=A[0];
	for(i=1;i<=N;i++)
	   if(mayor<A[i])
	   mayor=A[i];
	 return mayor;
}
//**********************************************************************

int obten_menor(int N,int A[])  // esta funcion busca en el arreglo el menor
				// de los elementos
{
	int menor,i;
	menor=A[0];
	for(i=1;i<=N;i++)
	   if(menor>A[i])
	   menor=A[i];
	return menor;
}
//**********************   FIN DEL CODIGO   ****************************