/*                *** programacion avanzada ***


PROGRAMADO POR: REYES SEVERIANO GABRIEL


Este programa realiza diferentes operaciones sobre un mismo arreglo
proporcionado por el usuario como sumarlo,encontrar pares, sumar impares,
encontrar primos, sustituir primos ordenar por 4 diferentes metodos.

Ultima modificaci¢n:  09/03/03               secci¢n: 109           */


#include "iostream.h"
#include "conio.h"     
#define max 15         
//********************************************************************
class arreglo            //clase principal arreglo
{
    int A[max],n;
    public:                        //------|
	char menu(void);                 //|
	void lee(void);                  //|
	void muestra(int pos);           //|
	void ordena(void);               //|
	int suma(int pos);               //|
	int cuenta_par(int pos);         //|
	int suma_impar(int pos);         //|>> M‚todos publicos de la
	int cuenta_primo(int pos);       //|   clase arreglo.
	int sust_primo(int pos);         //|
	void burbuja_asc(void);          //|
	void burbuja_des(void);          //|
	void bur_sen_asc(void);          //|
	void bur_sen_des(void);          //|
	void inser_dir_asc(void);        //|
	void operaciones(void);          //|
};                                 //------|

//*********************************************************************
char arreglo::menu(void)    //m‚todo menu de la clase arreglo
{
   char op;
	do{
	cout<<"\n\tMENU (TRABAJANDO CON VECTORES Y RECURSIVIDAD)\n"
	    <<"\ta -- MOSTRAR ARREGLO\n"
	    <<"\tb -- ORDENAR ELEMENTOS DEL ARREGLO\n"
	    <<"\tc -- SUMAR ELEMENTOS DE ARREGLO\n"
	    <<"\td -- CUENTA LOS PARES EXISTENTES EN EL ARREGLO\n"
	    <<"\te -- SUMA IMPARES EXISTENTES EN EL ARREGLO\n"
	    <<"\tf -- CUENTA NUMEROS PRIMOS EL EL ARREGLO \n"
	    <<"\tg -- SUSTITUYE NUMEROS PRIMOS DEL ARREGLO\n"
	    <<"\th -- VOLVER A LLENAR EL ARREGLO\n"
	    <<"\ts -- << SALIR >>\n"
	    <<"\t\tOpcion ==> ";cin>>op;
	    if(op!='a'&&op!='b'&&op!='c'&&op!='d'&&op!='e'&&op!='f'&&op!='g'&&op!='s'&&op!='h')
	       cout<<"\n		*** Error  !!  *** "<<endl;
	 }while(op!='a'&&op!='b'&&op!='c'&&op!='d'&&op!='e'&&op!='f'&&op!='g'&&op!='s'&&op!='h');
    return op;
}
//*******************************************************************
void arreglo::lee(void)   // M‚todo encargado de leer y almacenar
{  int i;                 //los elementos proporcionados por el usuario
       do{                //hacia el arreglo.
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
//*******************************************************************
void arreglo::muestra(int pos)  //Este m‚todo despliega en pantalla
{                               //los elementos contenidos en el arreglo.
       if(pos>=n)
	  cout<<"\n    \tSe ha mostrado el contenido del arreglo\n";
       else
       {
	cout<<"\tNumero "<<pos+1<<":  "<<A[pos]<<endl;
	muestra(pos+1);
       }
}
//********************************************************************
void arreglo::ordena(void)  //Este m‚todo establece un menu que ofrecera
{   int met;                //las diferentes maneras de ordenar el arreglo.
   cout<<"\tORDENAR ARREGLO\n"
       <<"1.-M‚todo de la burbuja (ordenar de manera ascendente)\n"
       <<"2.-M‚todo de la burbuja (ordenar de manera descendente)\n"
       <<"3.-M‚todo de la burbuja con se¤al (ascendente)\n"
       <<"4.-M‚todo de la burbuja con se¤al (descendente)\n"
       <<"5.-M‚todo de insercion directa (ascendente)\n"
       <<"¨Que m‚todo desea? --> "; cin>>met;
	switch(met)
     {
      case 1:burbuja_asc(); break;    //--|
      case 2:burbuja_des(); break;      //|
      case 3:bur_sen_asc(); break;      //|>>llamando a otros m‚todos
      case 4:bur_sen_des(); break;      //|  de la clase arreglo.
      case 5:inser_dir_asc();break;     //|
     }  			      //--|
}
//*******************************************************************
void arreglo::burbuja_asc() //m‚todo de ordenamiento de la burbuja
{   int I,revi,aux=0;       //de manera ascendente.
       cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA ASCENDENTE\n";
       for(revi=1;revi<n;revi++)
       {
	   for(I=0;I<n-revi;I++)
	   {
	      if (A[I]>A[I+1])
	      {
	      aux=A[I];
	      A[I]=A[I+1];
	      A[I+1]=aux;
	      }
	      aux=0;
	   }
      }
}

// M‚todo de ordenamiento de la burbuja de manera descendente

void arreglo::burbuja_des()
{   int I,revi,aux=0;
       cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA DESCENDENTE\n";
       for(revi=1;revi<n;revi++)
       {
	   for(I=0;I<n-revi;I++)
	   {
	      if (A[I]<A[I+1])
	      {
	      aux=A[I];
	      A[I]=A[I+1];
	      A[I+1]=aux;
	      }
	      aux=0;
	   }
       }
}

//M‚todo de ordenamiento de la burbuja con se¤al de manera ascendente

void arreglo::bur_sen_asc()
{
     int I,revi=1,conta=0,aux=0;
     cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA C/ SE¥AL ASCENDENTE\n";
     do{
       conta=0;
	 for(I=0;I<n-revi;I++)
	   {
	      if (A[I]>A[I+1])
	      {
	      aux=A[I];
	      A[I]=A[I+1];
	      A[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=n));
}

//M‚todo de ordenamiento de la burbuja con se¤al de manera descendente.

void arreglo::bur_sen_des()
{
     int I,revi=1,conta=0,aux=0;
     cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA C/ SE¥AL DESCENDENTE\n";
     do{
       conta=0;
	 for(I=0;I<n-revi;I++)
	   {
	      if (A[I]<A[I+1])
	      {
	      aux=A[I];
	      A[I]=A[I+1];
	      A[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=n));
}
void arreglo::inser_dir_asc()      //M‚todo de ordenamiento de inserci¢n directa
{                                  //(M‚todo de la baraja)
   int i,j=0,aux=0;
       cout <<"\nSE HA UTILIZADO EL METODO DE INSERCION DIRECTA ASCENDENTE\n";
       for(i=0;i<n;i++)
       {
	  j=i;

	   do{
	     if(A[j+1]<A[j])
	     {	aux=A[j];
		A[j]=A[j+1];
		A[j+1]=aux;
		aux=0;
	      j--;
	     }

	      //else
		//j=0;
	  }while/*(*/(A[j+1]>A[j])/*&&(j!=0))*/;
	  j=0;
	}
}

int arreglo::suma(int pos)    //Este m‚todo suma los elementos contenidos
{ int sum=0;                  //en el arreglo.
     if(pos>=n)
       sum=0;
     else
	sum=A[pos]+suma(pos+1);
   return sum;
}
int arreglo::cuenta_par(int pos)  //Este m‚todo cuenta el n£mero de pares
{ int cont=0;                     //existentes en el arreglo.
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
int arreglo::suma_impar(int pos) //Este m‚todo busca y suma los
{  int sum=0;                    //impares encontrados en el arreglo.
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
int arreglo::cuenta_primo(int pos) // Este m‚todo busca n£meros primos en el
{ int primo=0,i,cont=0;    // arreglo y un contado se encargara de contarlos.

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
int arreglo::sust_primo(int pos)  //Este m‚todo sustituye los n£meros primos
{  int i,cont=0;                  //encontrados en el arreglo por el
     if(pos>=n)                   //siguiente n£mero no primo.
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
int main()    //Funci¢n principal del programa.
{
  int pos=0,sum=0;
  int cont=0;
  char op;
  arreglo obj1;//    <----  Declaracion de objetos.
       obj1.lee();
  do{  clrscr();
       op=obj1.menu();
       clrscr();
       switch(op){
       case 'a': cout<<"\n\tELEMENTOS CONTENIDOS EN EL ARREGLO\n"<<endl;
		obj1.muestra(pos); 		break;
       case 'b': cout<<"\n\tLOS ELEMENTOS SE ORDENARON DE MANERA ASCENDENTE\n"<<endl;
		obj1.ordena();
		obj1.muestra(pos);    		break;
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
       case 'h': cout<<"\tLLENANDO EL ARREGLO\n";
		 obj1.lee();                     break;
		 }
	cout<<"\nPresiona alguna tecla"<<endl;
      getch();
  }while(op!='s');
}