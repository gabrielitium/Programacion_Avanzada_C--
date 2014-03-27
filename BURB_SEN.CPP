/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACI„N AVANZADA
Realizado por el compa§ero: Gabriel Reyes Severiano

*/

#include <iostream.h>
#define max 10
//***********************************************************************

class senal
{      int Arr[max],n;
	     public:
	     char menu(void);
	     void read(void);
	     void muestra(int pos);
	     void asc_sen_bur(void);
	     void des_sen_bur(void);
};
//************************************************************************
char senal::menu(void)
{
     char opc;
	 do{
	    cout<<"\n \t METODO DE ORDENAMIENTO BURBUJA \n\n"
		<<"   \t       MENU                       \n "
		<<"   \t 1 ) -- llenar areglo                \n "
		<<"   \t 2 ) -- ordenar de manera ascendente \n "
		<<"   \t 3 ) -- ordenar de manera descendente\n "
		<<"   \t 4 ) -- mostrar arreglo              \n"
		<<"   \t s ) -- ***  salir  ***              \n "
		<<"\n \t OPC ÕÕ  ";
		cin>>opc;
	     if((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='4')&&(opc!='s'))
		cout<<"\n \n  \t  ERROR !! ...........................\n\n\n";


	  }while((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='4')&&(opc!='s'));
     return opc;
}
//***************************************************************************
void senal::muestra(int pos)
{   int i;
       if(pos>=n)
	  pos=0;
	else
	{cout<<"\n Numero:    "<<Arr[pos];
	muestra(pos+1);
	}



}

//***************************************************************************
void senal::read()  // MÇtodo encargado de leer y almacenar
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
	cin>>Arr[i];
	}

}
//***************************************************************************
//MÇtodo de ordenamiento de la burbuja con se§al de manera ascendente

void senal::asc_sen_bur()
{
     int I,revi=1,conta=0,aux=0;
     cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA C/ SE•AL ASCENDENTE\n";
     do{
       conta=0;
	 for(I=0;I<n-revi;I++)
	   {
	      if (Arr[I]>Arr[I+1])
	      {
	      aux=Arr[I];
	      Arr[I]=Arr[I+1];
	      Arr[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=n));
}

//***************************************************************************
//MÇtodo de ordenamiento de la burbuja con se§al de manera descendente.

void senal::des_sen_bur()
{
     int I,revi=1,conta=0,aux=0;
     cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA C/ SE•AL DESCENDENTE\n";
     do{
       conta=0;
	 for(I=0;I<n-revi;I++)
	   {
	      if (Arr[I]<Arr[I+1])
	      {
	      aux=Arr[I];
	      Arr[I]=Arr[I+1];
	      Arr[I+1]=aux;
	      }
	      aux=0;
	      conta++;
	   }
	 revi++;
     }while((conta!=0)||(revi<=n));
}

//**************************************************************************
int main()
{
int pos=0;
char op;
senal objet;

    objet.read();
		do{
		op=objet.menu();
		 switch(op)
		 {
		 case '1':
		       objet.read();

		 break;
		 case '2':
		       objet.asc_sen_bur();

		 break;
		 case '3':
		      objet.des_sen_bur();

		 break;
		 case '4':
		      cout<<"\n \t EL CONTENIDO DEL ARREGLO ES: \n";
		      objet.muestra(pos);
		 break;

		 }

		}while(op!='s');

}

//************************ FIN DEL CODIGO *********************************