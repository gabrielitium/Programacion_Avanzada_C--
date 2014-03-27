/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACI„N AVANZADA
Realizado por el compa§ero: Gabriel Reyes Severiano


                     ** OPERACIONES BASICAS DE MATRICES **

* SUMA
* RESTA
* MULTIPLICACION
* MULTIPLOS DE 2,3 Y 5
* MULTIPLOS DE Y NUMERO DADO
* PARES E IMPARES EXISTENTES EN LAS MATRICES

*/ 


#include <stdio.h>
#define max 100



//*********************************************************************************************

                  //  FUNCIONES CON LAS CUALES LA FUNCION PRINCIPAL MAIN
                  // EJECUTARA LAS OPCIONES DEL MENU

void llenar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max]);
void sumar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max]);
void restar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max]);
void multiplicar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max]);
void pares_nones(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max]);
void multiplos_2_3_5(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max]);
void multiplos_y(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max]);
//**********************************************************************************************

main()
{

   int ma_1[max][max],ma_2[max][max],res[max][max];
   int m1,n1,m2,n2,opc;

	printf("\t  OPERACIONES BASICAS DE MATRICES \n");
	printf("Antes de iniciar debe de llenar las dos matrices\n");
	llenar_matrices(&m1,&n1,&m2,&n2,ma_1,ma_2,res);

   do{
   printf("\n  …ÕÕÕÕÕÕÕÕ**- ELIJA UNA OPCION Y PRESIONE ENTER -**ÕÕÕÕÕÕª \n");
   printf("    æ       1.-Sumar  matrices                              æ \n");
   printf("    æ       2.-Restar matrices                              æ \n");
   printf("    æ       3.-Multiplicar  matrices                        æ \n");
   printf("    æ       4.-Pares y nones de las matrices                æ \n");
   printf("    æ       5.-Determinar  matriz  identidad                æ \n");
   printf("    æ       6.-Multiplos  de 2 , 3 y  5  de  las  matrices  æ\n");
   printf("    æ       7.-Multiplos de 'y' existentes en las matrices  æ\n");
   printf("    æ       8.-Volver  a  llenar  matrices                  æ\n");
   printf("    æ       9.-Salir                                        æ\n");
   printf("     ÕÕÕÕÕÕÕÕÕÕ  Opci¢n:- - - - -> ");
   scanf("%d",&opc);

   /* EN EL SIGUIENTE SWITCH SE LLAMARA A TODAS LAS FUNCIONES DE ACUERDO
   A LOS REQUERIMIENTOS SOLICITADOS POR EL USUARIO */


      switch(opc)
      {
	case 1:
	  sumar_matrices(&m1,&n1,&m2,&n2,ma_1,ma_2,res);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 2:
	  restar_matrices(&m1,&n1,&m2,&n2,ma_1,ma_2,res);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 3:
	  multiplicar_matrices(&m1,&n1,&m2,&n2,ma_1,ma_2,res);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 4:
	  pares_nones(&m1,&n1,&m2,&n2,ma_1,ma_2);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 6:
	  multiplos_2_3_5(&m1,&n1,&m2,&n2,ma_1,ma_2);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 7:
	  multiplos_y(&m1,&n1,&m2,&n2,ma_1,ma_2);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
	case 8:
	  llenar_matrices(&m1,&n1,&m2,&n2,ma_1,ma_2,res);
	  printf("\nPresione cualquier tecla para continuar\t");
	  getchar();
	break;
       }
  }while(opc!=9);
  return 0;

}

//************************************************************************************

void llenar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max])
{
int i,j,num,val;

	 //LLENADO DE LAS MATRICES

	printf("\n\n®Cuantas filas y columnas tiene la primera matriz?\n");
	printf("\tFilas:\t\t");
	scanf("%d",&val);
	*m1=val;
	printf("\tColumnas:\t");
	scanf("%d",&val);
	*n1=val;
	printf("®Cuantas filas y columnas tiene la segunda matriz?\n");
	printf("\tFilas:\t\t");
	scanf("%d",&val);
	*m2=val;
	printf("\tColumnas:\t");
	scanf("%d",&val);
	*n2=val;
	printf("\n\t***Llenando la primera matriz***\n");
		for(i=0;i<*m1;i++)
		    for(j=0;j<*n1;j++)
		    {
		    printf("\tIntroduce un n£mero para la pocision [%d][%d]:\t",i+1,j+1);
		    scanf("\t\t%d",&num);
		    ma_1[i][j]=num;

		    }
	printf("\n\t***Llenando la segunda matriz***\n");
		for(i=0;i<*m2;i++)
		    for(j=0;j<*n2;j++)
		    {
		    printf("\tIntroduce un n£mero para la pocision [%d][%d]:\t",i+1,j+1);
		    scanf("\t\t%d",&num);
		    ma_2[i][j]=num;
		    }
}
//********************************************************************************
void sumar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max])
{
int i,j;

	  /*SUMANDO MATRICES Y EN CASO DE QUE NO SE PUEDA EFECTUAR SE MARCARA
	   UN ERROR    */


	printf("\n\tSUMA DE MATRICES\n");
	if((*m1==*m2)&&(*n1==*n2))
	{
	for(i=0;i<*m1;i++)
		for(j=0;j<*n1;j++)
		{
		res[i][j]=ma_1[i][j]+ma_2[i][j];
		}

	printf("La matriz resultante de la suma es:\n");
	for(i=0;i<*m1;i++)
		for(j=0;j<*n1;j++)
		{
		printf("| %d\t",res[i][j]);
		if(j+1==*n1)
		printf("|\n");
		}

	}
	else{
	printf("! --No  se  puede  realizar  la  suma  de  matrices\n");
	printf("    las dos matrices  deben tener el  mismo  n£mero\n");
	printf("    de  filas  y  el  mismo  numero  de  columnas\n");
	}
}
//*******************************************************************************
void restar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max])
{
int i,j;

    //RESTANDO MATRICES

	printf("\n\t--RESTA DE MATRICES--\n");
	if((*m1==*m2)&&(*n1==*n2))
	{
	for(i=0;i<*m1;i++)
		for(j=0;j<*n1;j++)
		{
		res[i][j]=ma_1[i][j]-ma_2[i][j];
		}

	printf("La matriz resultante de la resta es:\n");
	for(i=0;i<*m1;i++)
		for(j=0;j<*n1;j++)
		{
		printf("| %d\t",res[i][j]);
		if(j+1==*n1)
		printf("|\n");
		}

	}
	else {
	printf("! --No  se  puede  realizar  la  resta de  matrices\n");
	printf("    las dos matrices deben  tener  el  mismo  n£mero\n");
	printf("    de  filas  y  el  mismo  numero  de  columnas\n");
	}
}

//*****************************************************************************
void multiplicar_matrices(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max],int res[][max])
{

int r,i,j,k;

	 //MULTIPLICANDO LAS MATRICES


	printf("\n\t--MULTIPLICACI‡N DE MATRICES--\n");
	if(*n1==*m2)
	{
	for(i=0;i<*m1;i++)     //Cuarto cilo "para"
		    for(k=0;k<*n2;k++) //Quinto ciclo "para"
			{ //inicio de dos ciclos
			for(j=0;j<*n1;j++) //Sexto ciclo
			{
			r=r+(ma_1[i][j]*ma_2[j][k]);
			res[i][k]=r;
			if((j+1)==*n1)
			r=0;

			}
			}
		printf("\n\n&&&&&&&&--La matriz resultante del producto de dos matrices es:--&&&&&&&&\n\n");
		for(i=0;i<*m1;i++)
		    for(j=0;j<*n2;j++)
		    {
		    printf("| %d\t",res[i][j]);
		    if(j+1==*n2)
		    printf("|\n");
		    }

	}
	else {
	printf("! --No se puede realizar la multiplicaci¢n de matrices debido\n");
	printf("    a que a que el n£mero de columnas de la primera matriz no es\n");
	printf("    igual al n£mero de filas de la segunda matriz\n");
	}
}
//**********************************************************************************
void pares_nones(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max])
{
int r,mod,pares=0,impares=0,i,j;

	printf("\n\t--PARES Y NONES--\n");
	do{
	printf("®De que matriz desea saber el n£mero de pares y nones? (1 ¢ 2)?  ");
	scanf("%d",&r);
	}while((r!=1)&&(r!=2));
	if(r==1)
	{
		for(i=0;i<*m1;i++)
			for(j=0;j<*n1;j++)
			{
			mod=ma_1[i][j]%2;
			if(mod==0)
			pares++;
			else
			impares++;
			}
	printf("El  n£mero  de pares encontrados en la matriz %d es de: %d\n",r,pares);
	printf("El n£mero de impares encontrados en la matriz %d es de: %d\n",r,impares);
	}
	else
	{
		for(i=0;i<*m2;i++)
			for(j=0;j<*n2;j++)
			{
			mod=ma_2[i][j]%2;
			if(mod==0)
			pares++;
			else
			impares++;
			}
	printf("El  n£mero  de pares encontrados en la matriz %d es de: %d\n",r,pares);
	printf("El n£mero de impares encontrados en la matriz %d es de: %d\n",r,impares);
	}
}

//******************************************************************************
void multiplos_2_3_5(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max])
{
int mod2,mod3,mod5;
int mult2=0,mult3=0,mult5=0,r,i,j;

	printf("\n\t--MULTIPLOS 2,3 Y 5--\n");
	do{
	printf("®De que matriz desea saber el n£mero de multiplos de 2,3 y 5? (1 ¢ 2)?  ");
	scanf("%d",&r);
	}while((r!=1)&&(r!=2));
	if(r==1)
	{
		for(i=0;i<*m1;i++)
			for(j=0;j<*n1;j++)
			{
			mod2=ma_1[i][j]%2;
			if(mod2==0)
			mult2++;
			mod3=ma_1[i][j]%3;
			if(mod3==0)
			mult3++;
			mod5=ma_1[i][j]%5;
			if(mod5==0)
			mult5++;
			}
			printf("N£mero de multiplos de 2: %d\n",mult2);
			printf("N£mero de multiplos de 3: %d\n",mult3);
			printf("N£mero de multiplos de 5: %d\n",mult5);
	}
	else
	{
		for(i=0;i<*m2;i++)
			for(j=0;j<*n2;j++)
			{
			mod2=ma_2[i][j]%2;
			if(mod2==0)
			mult2++;
			mod3=ma_2[i][j]%3;
			if(mod3==0)
			mult3++;
			mod5=ma_2[i][j]%5;
			if(mod5==0)
			mult5++;
			}
			printf("N£mero de multiplos de 2: %d\n",mult2);
			printf("N£mero de multiplos de 3: %d\n",mult3);
			printf("N£mero de multiplos de 5: %d\n",mult5);
	}
}
//********************************************************************************
void multiplos_y(int *m1,int *n1,int *m2,int *n2,int ma_1[][max],int ma_2[][max])
{
int  num=0,i,j,r,mody=0,mult;
	printf("\n\t--MULTIPLOS 'y'--\n");
	do{
	printf("®De que matriz desea saber el n£mero de multiplos de 2,3 y 5? (1 ¢ 2)?  ");
	scanf("%d",&r);
	}while((r!=1)&&(r!=2));
	if(r==1)
	{
		if(*m1==*n1)
		{
		printf("\nProporcione el n£mero 'y' para obtener el n£mero de\n");
		printf("multiplos que hay en la diagonal de la matriz.\n");
		scanf("%d",&num);
		for(i=0;i<*m1;i++)
			for(j=0;j<*n1;j++)
			{
			 if(i==j){
			 mody=ma_1[i][j]%num;
			 if(mody==0)
			 mult++; }
			 }
		printf("\nLa cantidad de multiplos de %d en la matriz %d\n",num,r);
		printf("es de: %d\n",mult);
		}
		else
		printf("!--La amtriz debe ser del mismo n£mero de filas y columnas\n");
	}
	else
	{
		if(*m2==*n2)
		{
		printf("\nProporcione el n£mero 'y' para obtener el n£mero de\n");
		printf("multiplos que hay en la diagonal de la matriz.\n");
		scanf("%d",&num);
		for(i=0;i<*m2;i++)
			for(j=0;j<*n2;j++)
			{
			 if(i==j) {
			 mody=ma_2[i][j]%num;
			 if(mody==0)
			 mult++;  }
			 }
		printf("\nLa cantidad de multiplos de %d en la matriz %d\n",num,r);
		printf("es de: %d\n",mult);
		}
		else
		printf("!--La amtriz debe ser del mismo n£mero de filas y columnas\n");
	}
}

//**********************  FIN DEL CODIGO  ************************************