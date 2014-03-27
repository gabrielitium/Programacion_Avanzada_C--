
/*                   PROGRAMACION AVANZADA

PROGRAMADO POR: REYES SEVERIANO GABRIEL 


		  **COLA CIRCULAR**

ESTE PROGRAMA UTILIZA UNA COLA SIMULANDOLA DE MANERA CIRCULAR, Y EN ESTA
SE ALMACENAN DATOS Y SE ELIMINAN SEGUN EL USUARIO*/

				  /*FUCIONANDO*/
#include "iostream.h"
#define max 5
class colas
{
    char cola_circular[max];
    int frente,fondo,min,cont;
       public:
	  void inicial();
	  void inserta(char dato);
	  char elimina();
	  void estado();
	  void ejecucion();
};
void colas::inicial()
{min=0; frente=min-1; fondo=min-1; cont=0;}

void colas::inserta(char dato)               //METODO EL CUAL INSERTARA DATOS
{   if(((frente==min)&&(fondo==max-1))||((fondo+1)==frente))
	cout<<"\n Cola llena \n";            //COLA CIRCULAR
    else{
       if(fondo==(max-1))
	   fondo=min;
	else
	   fondo++;
	   cont++;  //estado de la cola
	   cola_circular[fondo]=dato;
	   if(frente<min)
	      frente=min;
	 }

}
char colas::elimina()              //ELIMINA DATOS DE LA COLA CIRCULAR
{  int i;
   char dato;
     if(frente<min)
       cout<<"\n Cola Vacia \n";
     else{
       dato=cola_circular[frente];
	  cont--;      //estado de la cola
	  if(frente==fondo)
	   inicial();

	  else
	  {  if(frente==(max-1))
		frente=min;
	     else
		frente=frente+1;
	  }
     }
     return dato;
}
void colas::ejecucion()
{ char opc,dato,x;            //AQUI SE REALIZAN TODAS LAS OPERACIONES
    inicial();               //Y SE PRESENTA EL MENU AL USUARIO
    //clrscr();
  do{
	 do{ cout<<"\n  COLA CIRCULAR  \n"
	   <<"1.-Insertar \n"
	   <<"2.-Eliminar \n"
	   <<"3.-Estado actual de la cola \n"
	   <<"4.-Salir \n"
	   <<"Opcion==>  ";  cin>>opc;
	 }while(opc!='1'&&opc!='2'&&opc!='3'&&opc!='4');
	 switch(opc)
	    {
	     case '1': cout<<"\n Proporcione el dato: ";  cin>>dato;
		       inserta(dato);
	     break;
	     case '2': x=elimina();
		       cout<<" \n Dato eliminado :"<<x;
	     break;
	     case '3':
		     cout<<"  Espacios ocupados:  "<<cont<<" de "<<max<<endl;
	     break;


	    }


    }while(opc!='4');




}
int main()
{  colas obj1;


   obj1.ejecucion();
				   //FUNCION PRINCIPAL DE ESTE PROGRAMA
				   //LA CUAL SERA LLAMADA POR EL SISTEMA
				   //OPERATIVO
}
