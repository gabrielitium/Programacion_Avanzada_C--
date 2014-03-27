/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACIãN AVANZADA
Realizado por el compa¤ero: Gabriel Reyes Severiano


*/


#include <iostream.h>
#define max 10
//***********************************************************************

class burbuja
{      int Arr[max],n;
	     public:
	     char menu(void);
	     void read(void);
	     void muestra(int pos);
	     void asc_burbuja(void);
	     void des_burbuja(void);
};
//************************************************************************
char burbuja::menu(void)
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
		<<"\n \t OPC ÍÍ  ";
		cin>>opc;
	     if((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='4')&&(opc!='s'))
		cout<<"\n \n  \t  ERROR !! ...........................\n\n\n";


	  }while((opc!='1')&&(opc!='2')&&(opc!='3')&&(opc!='4')&&(opc!='s'));
     return opc;
}
//***************************************************************************
void burbuja::muestra(int pos)
{   int i;
       if(pos>=n)
	  cout<<"\n \t El contenido del arreglo es:";
	else
	{cout<<"\n Numero:    "<<Arr[pos];
	muestra(pos+1);
	}



}

//***************************************************************************
void burbuja::read()  // M‚todo encargado de leer y almacenar
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
void burbuja::asc_burbuja() //m‚todo de ordenamiento de la burbuja
{   int I,revi,aux=0;       //de manera ascendente.
       cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA ASCENDENTE\n";
       for(revi=1;revi<n;revi++)
       {
	   for(I=0;I<n-revi;I++)
	   {
	      if (Arr[I]>Arr[I+1])
	      {
	      aux=Arr[I];
	      Arr[I]=Arr[I+1];
	      Arr[I+1]=aux;
	      }
	      aux=0;
	   }
      }
}
//**************************************************************************
// M‚todo de ordenamiento de la burbuja de manera descendente

void burbuja::des_burbuja()
{   int I,revi,aux=0;
       cout <<"\nSE HA UTILIZADO EL METODO DE LA BURBUJA DESCENDENTE\n";
       for(revi=1;revi<n;revi++)
       {
	   for(I=0;I<n-revi;I++)
	   {
	      if (Arr[I]<Arr[I+1])
	      {
	      aux=Arr[I];
	      Arr[I]=Arr[I+1];
	      Arr[I+1]=aux;
	      }
	      aux=0;
	   }
       }
}
//**************************************************************************
int main()
{
int pos=0;
char op;
burbuja objet;

    objet.read();
		do{
		op=objet.menu();
		 switch(op)
		 {
		 case '1':
		       objet.read();

		 break;
		 case '2':
		       objet.asc_burbuja();

		 break;
		 case '3':
		      objet.des_burbuja();

		 break;
		 case '4':
		      objet.muestra(pos);
		 break;

		 }

		}while(op!='s');

}

//************************ FIN DEL CODIGO *********************************