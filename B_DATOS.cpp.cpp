/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACI„N AVANZADA
Realizado por el compa§ero: Gabriel Reyes
        03/02/2003             


   Este programa utiliza una estructura para almacenar datos de 53 
estudiantes, ademas de que se obtiene el promedio de cada uno de ellos,
el promedio general, y numero de aprovados y reprovados



  */


//********************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

main()
{
	struct Arreglo_re
	{                                 //estructura para los 53 alumnos
	char matricula[10];
	char nombre[60];
	float calif[3];
	float promedio;
	}Arreglo_re[MAX];

	int i,j,c,re=0,ap=0,n;
	float prom,prom_tot=0,l;
	char dat;
        system("clear");
	printf("\nCuantos alumnos desea registrar:\t");
	scanf("%d",&n);
	   if(n>50)
	   {
		printf("ERROR! se excedio el n£mero de alumnos (50)");
		getchar();
	   }
	   else
	   {
		for(i=0;i<n;i++)
		{ /*Inicio del para*/
		    prom=0;
		    printf("   *-- Esta capturando los datos del alumno n£mero %d :\n",i+1);
		    printf("\n *-- Matricula:\t");
		    scanf("%s",Arreglo_re[i].matricula);
		    printf("   *-- Nombre:\t");
		    scanf("\n%[^\n]",Arreglo_re[i].nombre);
		    printf("\n\tProporcione las calificaciones correspondientes:\n");

			for(c=0;c<=2;c++)
			{
			printf("\t*-- Calificaci¢n %d:\t",c+1);
			scanf("%f",&l);
			Arreglo_re[i].calif[c]=l;
			prom=prom+Arreglo_re[i].calif[c];

			}
		    prom=prom/3;
		    Arreglo_re[i].promedio=prom;
		    prom_tot=prom_tot+prom;
		    if(Arreglo_re[i].promedio>=6)
			ap++;
			else
			re++;




		}/*fin del para*/
		printf("\n");
	   prom_tot=prom_tot/n;
	   do{
	   printf("Presione '+' para verificar los datos\n");
	   dat=getchar();
	   }while(dat!='+');
	   j=0;
	   i=0;

		system("clear");
		for(i=0;i<n;i++)
		{
		c=0;
		printf("\n");
		printf("                 --  Alumno n£mero %d  --\n",i+1);
		printf("	Matricula: \t%s\n",Arreglo_re[i].matricula);
		printf("	Nombre: \t%s\n",Arreglo_re[i].nombre);
		printf("	\t** Calificaciones: **\n");
			for(c=0;c<=2;c++)
			printf("	\tCalificaci¢n %d:\t%f\n",c+1,Arreglo_re[i].calif[c]);
			printf("	Promedio:\t%f\n",Arreglo_re[i].promedio);
			if(j==2)
			{
			j=0;
			printf("Presione cualquier tecla para continuar");
			getchar();
			system("clear");
			}
			j++;
		}/*fin del para*/
		printf("\n-----------------------------------------------------\n");
		printf("\n	Promedio del grupo:\t%2f\n",prom_tot);
		printf("	No. de aprovados:\t%d\n",ap);
		printf("	No. de reprovados:\t%d\n",re);
		printf("    Presione cualquier tecla para salir");
		getchar();

	     }/*fin si_no*/
	     return 0;
}
