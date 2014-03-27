
/*                   PROGRAMACION AVANZADA

PROGRAMADO POR: REYES SEVERIANO GABRIEL

		**EXPRECION MATEMATICA UTILIZANDO PILAS**

 ESTE PROGRAMA EVALUA UNA EXPRESION PARA VERIFICAR SI TODOS
 LOS PARENTESIS, LLAVES Y CORCHETES SE HAN ABIERTO O CERRADO
CORRECTAMENTE
ULTIMA MODIFICACION 27/04/03
*/

#include "iostream.h"
//#include "conio.h"
#include "string.h"
#define max 30

class stack
{    int tope; 
    char pila[max],cad[max];
	     public:             //   \
		  //void stack();    \   Estos son los metodos de la
		  void push(char X);  //       \ clase stack
		  char pop();        //       /
		  void busqueda();      //     /
		  void compara();    //   /
};
/*void stack()
{ int i;
    tope=max;
     for(i=0;i<max;i++)
     {pila[i]=NULL;  cad[i]=NULL;}
} */
void stack::push(char X)
{
     tope--;
     pila[tope]=X;

     if(tope==0)
     cout<<"pila llena \n";
}
char stack::pop()
{  char Y;

    if(tope>=max)   {
       //cout<<" pila vacia ";
       Y=20; }
    else{
     Y=pila[tope];
     tope++; }

  return Y;
}
void stack::busqueda()
{   int i;    
    char X,Y,op;
    //listas obj2;
      //obj3.inicia();
       tope=max;

      cout<<" \n Proporcione la expresi¢n deseada : \n ";
      cin.getline(cad,max,'.');

	for(i=0;i<max;i++)
	 {    //  1
	      //obj2.insertar(cad[i]);
	      switch(cad[i])
	      {   // 2
		   case '{':   push(cad[i]);


		   break;
		   case '[':   push(cad[i]);


		   break;
		   case '(':   push(cad[i]);


		   break;

		   default :

		     switch(cad[i])
		       {case '}':
				Y=pop();
			     if(Y!=20)
				switch(Y)
				{     case '[':  cout<<"  ** cerraste una llave en lugar de una corchete  \n ";
				      break;
				      case '(':  cout<<"  ** cerraste una llave en lugar de un parentesis \n";
				}
			      else
			      cout<<"  * No se abrio una llave  \n";
			break;
			case ']':   Y=pop();
			     if(Y!=20)
				switch(Y)
				{     case '{':  cout<<"  ** cerraste un corchete en lugar de una llave \n ";
				      break;
				      case '(':  cout<<"  ** cerraste un corchete en lugar de un parentesis \n";
				      break;
				}
			      else
			       cout<<"  * No se abrio un corchete  \n ";
			break;
			case ')':   Y=pop();
			      if(Y!=20)
				switch(Y)
				{     case '{':  cout<<"  ** cerraste un parentesis en lugar de una llave \n ";
				      break;
				      case '[':  cout<<"  ** cerraste un parentesis en lugar de un corchete \n";
				      break;
				}
			       else
				  cout<<"  * No se abrio un parentesis  \n ";
			break;
			}                        //3
		   break;

	      }  //2
	 }  //1


	 do{   //1
	 Y=pop();
	 if(Y!=20)
	  {        //2
	     switch(Y)
	     {     case '{':  cout<<"  *** Falto cerrar una llave \n";  //3
		   break;
		   case '[':  cout<<"  *** Falto cerrar un corchete \n ";
		   break;
		   case '(':  cout<<"  *** Falto cerrar un parentesis \n";
		   break;
	      }                                               //3

	  }  //2

	 }while(Y!=20);       //1

/*      do{
	  cout<<" \n ¨ Desea verificar caracteres y numero de cada caracter ? (S/N) ";
	  cin>>op;
	  }while(op!='s'&&op!='S'&&op!='n'&&op!='N');
	    if(op=='s'||op=='S')
	     obj2.mostrar();  */

}
int main()
{
  stack obj1;
   //clrscr();
   obj1.busqueda();

  //getch();
  return 0;
}
