/*                   PROGRAMACION AVANZADA

PROGRAMADO POR: REYES SEVERIANO GABRIEL


		*** LISTAS***


Programa que maneja datos en una lista
   ultima modificacion 27/04/02
*/

#include "iostream.h"
//#include "conio.h"
struct info
{
      int dato;
      int cont;
      struct info *sig;
};
class listas
{
      struct info *cabeza;                     // estructura listas
      public:
	      void insertar(int dato);
	      void mostrar(void);
	      void elimina(int dato);
	      listas(){cabeza=NULL;}
};
void listas::insertar(int dato)
{
   struct info *recorre;
   struct info *anterior;     //apuntadores
   struct info *p;

      p=new(struct info);

      (*p).dato=dato; (*p).cont=0; (*p).sig=NULL;
      if(cabeza==NULL)
	  cabeza=p;
      else {        //{   1ø llave

	    recorre=cabeza;   anterior=recorre;
	    while(((*recorre).sig!=NULL)&&((*recorre).dato<dato))
	    {  // { 2ø llave
		anterior=recorre;
		recorre=(*recorre).sig;
	    }   //} 2ø llave
	    if((*recorre).dato<dato)
		 (*recorre).sig=p;  // Inserta al final
	    else if(recorre==cabeza)
		 { cabeza=p;          // Inserta al inicio
		   (*p).sig=recorre;
		 }
	    else {
		(*anterior).sig=p;    // entre 2
		(*p).sig=recorre;
		 }
	   }      //}   1ø llave

}
void listas::elimina(int dato)
{
    struct info *recorre;
    struct info *anterior;
    struct info *p;

	if(cabeza!=NULL)
	 {  recorre=cabeza;   //{ 1ø llave
	    anterior=recorre;
	    while(((*recorre).sig!=NULL)&&((*recorre).dato!=dato))
	     {      // { 2ø llave
		 anterior=recorre;
		 recorre=(*recorre).sig;
	     }      // } 2ø llave
	     if((*recorre).dato==dato)  // ­ lo encontro !
	     {     //{ 3ø llave
		if(recorre==cabeza)  //es la cabeza
		   cabeza=(*recorre).sig;
		else  //esta al final o entre 2
		    (*anterior).sig=(*recorre).sig;
	      delete(recorre); 
              }   //} 3ø llave
	      else
		 cout<<"  ­ No se encontro ! \n";
	 }                    //} 1ø llave
	else
	    cout<<"  ­ Lista vacia! \n";

}

void listas::mostrar()
{  struct info *recorre;
     
   if(cabeza!=NULL) 
      {   recorre=cabeza;
	 
         while((*recorre).sig!=NULL){        //do
	 cout<<"  "<<(*recorre).dato<<endl;
	 recorre=(*recorre).sig;
	 }                                 //while
	 cout<<"  "<<(*recorre).dato<<endl;
      }
    else
         cout<<"\n LISTA VACIA \n";

}

int main()
{  int opc,dato;
   listas obj1;

   do{
     do{
	cout<<" \n  Que desea hacer  \n"
	    <<"\t 1. Insertar dato en lista \n"
	    <<"\t 2. Elimina dato de lista \n"
	    <<"\t 3. Mostrar \n"
	    <<"\t 4. Salir \n"
	    <<"\t opcion:  "; cin>>opc;
     }while(opc<=0||opc>4);
	 switch(opc)
	 {
	 case 1:     cout<<"\t  Dato: ";  cin>>dato;
		     obj1.insertar(dato);
	 break;
	 case 2:     cout<<"\t  Dato a eliminar: "; cin>>dato;
		     obj1.elimina(dato);
	 break;
	 case 3:     obj1.mostrar();

	 break;

	 }


   }while(opc!=4);

}

