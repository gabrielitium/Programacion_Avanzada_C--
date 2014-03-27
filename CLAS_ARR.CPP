/*Ultima actualizaci¢n 03 - de marzo - de 2003
		   ** PROGRAMACION AVANZADA **
Este programa realizado en c++ puede manejar una clase arreglo y
realizar sobre este las diferentes operaciones que se presentan en el
menu*/
#include "iostream.h"
#include "conio.h"
#define max 15

class arreglo      //Declaracion de la clase arreglo
{
    int A[max],n;
    public:                      //______
	char menu(void);               //|
	void lee(void);                //|
	void muestra(int pos);         //|
	int asigna(int C[]);
	int ordena(void);
	void retorna(int C[]);           //|
	int suma(int pos);             //|>> Metodos de la clase
	int cuenta_par(int pos);       //|
	int suma_impar(int pos);       //|
	int cuenta_primo(int pos);     //|
	int sust_primo(int pos);      //|
};                               //-------
char arreglo::menu(void)     //Metodo menu
{
   char op;
	do{
	cout<<"\n\tOPCIONES (TRABAJANDO CON VECTORES Y RECURSIVIDAD)\n"
	    <<"\ta) -- MOSTRAR ARREGLO\n"
	    <<"\tb) -- ORDENAR ELEMENTOS DEL ARREGLO\n"
	    <<"\tc) -- SUMAR ELEMENTOS DE ARREGLO\n"
	    <<"\td) -- CUENTA LOS PARES EXISTENTES EN EL ARREGLO\n"
	    <<"\te) -- SUMA IMPARES EXISTENTES EN EL ARREGLO\n"
	    <<"\tf) -- CUENTA NUMEROS PRIMOS EL EL ARREGLO \n"
	    <<"\tg) -- SUSTITUYE NUMEROS PRIMOS DEL ARREGLO\n"
	    <<"\ts) -- << SALIR >>\n"
	    <<"\t\tOpcion ==> ";cin>>op;
	    if(op!='a'&&op!='b'&&op!='c'&&op!='d'&&op!='e'&&op!='f'&&op!='g'&&op!='s')
	       cout<<"\n		*** Error  !!  *** "<<endl;
	 }while(op!='a'&&op!='b'&&op!='c'&&op!='d'&&op!='e'&&op!='f'&&op!='g'&&op!='s');
    return op;
}
void arreglo::lee(void)         //Metodo leer arreglo
{  int i;
       do{
	  cout<<"\nDe cuantos elementos desea su arreglo: "; cin>>n;
	  if((n<=0)||(n>max))
	  cout<<"\n  ** ESO NO SERA POSIBLE ** \n";
       }while((n<=0)||(n>max));
	cout<<"\n\tAHORA DEBERA LLENAR EL ARREGLO\n";
	for(i=0;i<n;i++)
	{
	cout<<"\tN£mero "<<i+1<<":";
	cin>>A[i];
	}

}
void arreglo::muestra(int pos) //Metodo mostrar contenido del arreglo
{
       if(pos>=n)
	  cout<<"\n    \tSe ha mostrado el contenido del arreglo\n";
       else
       {
	cout<<"\tNumero "<<pos+1<<":  "<<A[pos]<<endl;
	muestra(pos+1);
       }
}


int arreglo::ordena(void)   //Metodo ordenar el contenido del arreglo
{    char opc;
	cout<<"\tDe que manera descea ordenar su arreglo\n"
	    <<"1.- Ordenar de manera ascendente (M. Burbuja)\n"
	    <<"2.- Ordenar de manera descentente (M. Burbuja)\n"
	    <<"3.- Ordenar de manera ascendente (M. burbuja c/ se¤al)\n"
	    <<"4.- Ordenar de manera descendente (M. burbuja c/ se¤al)\n"
	    <<"-----> "; cin>>opc;


     return opc;
}
int arreglo::asigna(int C[])
{    int i,aux;
     for(i=0;i<n;i++)
     {aux=A[i];
     C[i]=aux;}
     return n;
}
void arreglo::retorna(int C[])
{   int i,aux;
    for(i=0;i<n;i++)
    {aux=C[i];
    A[i]=aux;}
}






int arreglo::suma(int pos)  //Metodo sumar el contenido del arreglo
{ int sum=0;
     if(pos>=n)
       sum=0;
     else
	sum=A[pos]+suma(pos+1);
   return sum;
}
int arreglo::cuenta_par(int pos) //Metodo contar pares existentes en el arreglo
{ int cont=0;
      if(pos>=n)
	 cont=0;
      else
	{
	  if((A[pos]%2)==0)
	  cont=1+cuenta_par(pos+1);
	  else
	  cont=cuenta_par(pos+1);
	}
   return cont;
}
int arreglo::suma_impar(int pos) //Metodo buscar y sumar impares
{  int sum=0;
	 if(pos>=n)
	 sum=0;
	 else{
	    if((A[pos]%2)!=0)
	     sum=A[pos]+suma_impar(pos+1);
	    else
	     sum=suma_impar(pos+1);
	 }
    return sum;
}
int arreglo::cuenta_primo(int pos)//Metodo contar numeros primos existentes
{ int primo=0,i,cont=0;

      if(pos>=n)
      primo=0;
      else{
	   for(i=1;i<=A[pos];i++)
	     {
	      if((A[pos]%i)==0)
	       cont++;
	     }
	   if(cont==2)
	   primo=1+cuenta_primo(pos+1);
	   else
	   primo=cuenta_primo(pos+1);
      }
  return primo;
}
int arreglo::sust_primo(int pos)//Metodo sustituir primos
{  int i,cont=0;                //por el siguiente numero no primo
     if(pos>=n)
	cont=0;
     else{
	 for(i=1;i<=A[pos];i++)
	   if((A[pos]%i)==0)
	    cont++;
	  if(cont==2)
	  A[pos]++;
	  sust_primo(pos+1);

     }
}
class ordenar: public arreglo  //Clase heredada de la clase arreglo
{
     int B[max],num;
     public:
	    void muestra(void);
	    void recibe(void);
	    void burbuja_asc(void);
	    void burbuja_des(void);
	    void bur_sen_asc(void);
	    void bur_sen_des(void);
	    void recupera(void);
};
void ordenar::recibe(void)
{  int C[max],i;
    num=asigna(C);
    for(i=0;i<num;i++)
    B[i]=C[i];
}
void ordenar::muestra(void)
{  int opc;
	opc=ordena();
	switch(opc)
	    {
	    case '1':  burbuja_asc(); break;
	    case '2':  burbuja_des(); break;
	    case '3':  bur_sen_asc(); break;
	    case '4':  bur_sen_des(); break;
	    }
}
void ordenar::recupera(void)
{   int C[max],i;
     for(i=0;i<num;i++)
     C[i]=B[i];
     retorna(C);
}


void ordenar::burbuja_asc(void)
{   int I,revi,aux=0;
       for(revi=1;revi<num;revi++)
       {
	   for(I=0;I<num-revi;I++)
	   {
	      if (B[I]>B[I+1])
	      {
	      aux=B[I];
	      B[I]=B[I+1];
	      B[I+1]=aux;
	      }
	      aux=0;
	   }
       }
}
void ordenar::burbuja_des(void)
{   int I,revi,aux=0;
       for(revi=1;revi<num;revi++)
       {
	   for(I=0;I<num-revi;I++)
	   {
	      if (B[I]>B[I+1])
	      {
	      aux=B[I];
	      B[I]=B[I+1];
	      B[I+1]=aux;
	      }
	      aux=0;
	   }
       }

}
void ordenar::bur_sen_asc(void)
{
     int I,revi=1,conta=0,aux=0;

     do{
       conta=0;
	 for(I=0;I<num-revi;I++)
	   {
	      if (B[I]<B[I+1])
	      {
	      aux=B[I];
	      B[I]=B[I+1];
	      B[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=num));

}
void ordenar::bur_sen_des(void)
{
     int I,revi=1,conta=0,aux=0;

     do{
       conta=0;
	 for(I=0;I<num-revi;I++)
	   {
	      if (B[I]<B[I+1])
	      {
	      aux=B[I];
	      B[I]=B[I+1];
	      B[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=num));
}
int main()        //Funcion principal
{
  int pos=0,sum=0;
  int cont=0;
  char op;
  arreglo obj1;
       obj1.lee();
  do{  clrscr();
       op=obj1.menu();
       clrscr();
       switch(op){
       case 'a': cout<<"\n\tELEMENTOS CONTENIDOS EN EL ARREGLO\n"<<endl;
		obj1.muestra(pos); 		break;
       case 'b': cout<<"\n\tLOS ELEMENTOS SE ORDENARON DE MANERA ASCENDENTE\n"<<endl;
		obj1.ordena();
		//obj1.muestra(pos);
				break;
       case 'c': cout<<"\n\tSE HAN SUMADO LOS ELEMENTOS DEL ARREGLO\n"<<endl;
		 sum=obj1.suma(pos);
		 obj1.muestra(pos);
		 cout<<"\nLa Suma es: "<<sum<<endl; 	break;
       case 'd': cout<<"\n\tSE CONTO EL NUMERO DE PARES EXISTENTES EN EL ARREGLO\n"<<endl;
		 obj1.muestra(pos);
		 cont=obj1.cuenta_par(pos);
		 cout<<"El numero de pares es:"<<cont<<endl;    break;
       case 'e': cout<<"\n\tSE HAN SUMADO LOS NUMEROS IMPARES\n"<<endl;
		 obj1.muestra(pos);sum=0;
		 sum=obj1.suma_impar(pos);
		 cout<<"La suma de impares es: "<<sum<<endl;break;
       case 'f': cout<<"\n\tSE CONTARON LOS NUMEROS PRIMOS EXISTENTES EN EL ARREGLO\n"<<endl;
		 obj1.muestra(pos);
		 cont=0;
		 cont=obj1.cuenta_primo(pos);
		 cout<<"Numeros Primos encontrados:  "<<cont<<endl;  break;
       case 'g': cout<<"\n\tSE SUSTITUYERON LOS NUMEROS PRIMOS POR LOS SIGUIENTES NO PRIMOS\n"<<endl;
		 obj1.sust_primo(pos);
		 obj1.muestra(pos);	 	 break;
		 }
	//cout<<"\nPresiona alguna tecla"<<endl;
      getch();
  }while(op!='s');
}