
/*                   PROGRAMACION AVANZADA

PROGRAMADO POR: REYES SEVERIANO GABRIEL



		     **DIRECTORIO UTILIZANDO LISTAS**

 ESTE PROGRAMA INSERTA, ELIMINA O MUESTRA INFORMACION EN UNA
LISTA DE NOMBRE, DIRECCION Y TELEFONO
*/

#include "iostream.h"
#include "string.h"
//#include "conio.h"
struct info
{
      char nom[50];
      char dir[30];
      char tel[10];
      struct info *sig;
};
class listas
{
      struct info *cabeza;
      public:
	      void insertar(char nom[],char dir[],char tel[]);
	      void mostrar(void);
	      void elimina(char nom[]);
	      listas(){cabeza=NULL;}
};
void listas::insertar(char nom[],char dir[],char tel[])
{
   struct info *recorre;
   struct info *anterior;
   struct info *p;

      p=new(struct info);

      strcpy((*p).nom,nom);
      strcpy((*p).dir,dir);
      strcpy((*p).tel,tel);
      (*p).sig=NULL;
      if(cabeza==NULL)
	  cabeza=p;
      else {        //{   1ø llave

	    recorre=cabeza;   anterior=recorre;
	    while(((*recorre).sig!=NULL)&&(strcmp((*recorre).nom,nom)<0))
	    {  // { 2ø llave
		anterior=recorre;
		recorre=(*recorre).sig;
	    }   //} 2ø llave
	    if(strcmp((*recorre).nom,nom)<0)
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
void listas::elimina(char nom[])
{
    struct info *recorre;
    struct info *anterior;
    struct info *p;

	if(cabeza!=NULL)
	 {  recorre=cabeza;   //{ 1ø llave
	    anterior=recorre;
	    while(((*recorre).sig!=NULL)&&(strcmp((*recorre).nom,nom)!=0))
	     {      // { 2ø llave
		 anterior=recorre;
		 recorre=(*recorre).sig;
	     }      // } 2ø llave
	     if(strcmp((*recorre).nom,nom)==0)  // ­ lo encontro !
	     {     //{ 3ø llave
		if(recorre==cabeza)  //es la cabeza
		   cabeza=(*recorre).sig;
		else  //esta al final o entre 2
		    (*anterior).sig=(*recorre).sig;
	      }     //} 3ø llave
	      else
		 cout<<"  ­ No se encontro ! \n";
	 }                    //} 1ø llave
	else
	    cout<<"  ­ Lista vacia! \n";

}

void listas::mostrar()
{  int cont=0;
    struct info *recorre;
    if(cabeza!=NULL)
      {	 recorre=cabeza;
	 while((*recorre).sig!=NULL){
	 cout<<"  "<<(*recorre).nom;
	 cout<<"  "<<(*recorre).dir;
	 cout<<"  "<<(*recorre).tel<<endl;
	 recorre=(*recorre).sig;
	 if(cont==3)
	 { cont=0;
	  // getch();
         }
	 cont++;
	 }
	 cout<<"  "<<(*recorre).nom;
	 cout<<"  "<<(*recorre).dir;
	 cout<<"  "<<(*recorre).tel<<endl;
      }
      else
         cout<<"\n LISTA VACIA \n";
}

int main()
{  int opc,dato;
   char nom[50],dir[30],tel[10];
   listas obj1;
    // clrscr();
   do{
     do{
	cout<<" \n   BIENVENIDO AL DIRECTORIO \n"
	    <<"\t 1. Insertar registro en lista \n"
	    <<"\t 2. Eliminar registro de lista \n"
	    <<"\t 3. Mostrar registros \n"
	    <<"\t 4. Salir \n"
	    <<"\t opcion:  "; cin>>opc;
     }while(opc<=0||opc>4);
	 switch(opc)
	 {
	 case 1:     cout<<"\n Nombre: ";  cin.getline(nom,50,'.');
		     cout<<"Direccion: ";  cin.getline(dir,30,'.');
		     cout<<"Telefono: ";  cin.getline(tel,10,'.');
		     obj1.insertar(nom,dir,tel);
	 break;
	 case 2:     cout<<"\t  Proporcione el nombre que sera borrado \n ";
		     cin.getline(nom,50,'.');
		     obj1.elimina(nom);
	 break;
	 case 3:     obj1.mostrar();

	 break;

	 }


   }while(opc!=4);

}

