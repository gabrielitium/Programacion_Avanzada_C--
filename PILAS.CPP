/*Proyecto de control de alumnos mediante estructuras
		     PROGRAMACI„N AVANZADA


*/


#include <iostream.h>
#include <stdio.h>
#define max 30

class pilas
{
   char texto[max],pila[max];
   int tope,n;
	public:
	     void ini(){tope=max;}
	     void push(char X);
	     char pop();
	     void llena();
	     void buscar();
	     void demuestra();
};
//*********************************************************************
void pilas::push(char X)
{
   tope--;
   pila[tope]=X;
}
//*********************************************************************
char pilas::pop()
{ char Y;
  Y=pila[tope];
  tope++;

  return Y;
}

//*********************************************************************
void pilas::llena()
{  int i;
      cout<<"Escriba su cadena: \n";
      cin.getline(texto,max,'\n');
}
//*********************************************************************
void pilas::buscar()
{
  int i,cont=0;
  char X;

   llena();
   for(i=0;i<max;i++)
     {
      switch(texto[i])
	{
	case '[': push(texto[i]); cont++;  break;
	case ']': push(texto[i]); cont++;  break;
	case '(': push(texto[i]); cont++;  break;
	case ')': push(texto[i]); cont++;  break;
	}
      }
      n=cont;
}
//************************************************************************
void pilas::demuestra()
{
int i,cor_a=0,cor_c=0,par_a=0,par_c=0;

   for(i=0;i<n;i++)
    {	 switch(pop())
	 {
	 case '[': cor_a++;  break;
	 case ']': cor_c++;  break;
	 case '(': par_a++;  break;
	 case ')': par_c++;  break;

	 }
    }
	 cor_a=cor_a/2;
	 cor_c=cor_c/2;
	 par_a=par_c/2;
	 par_c=par_c/2;

	 cout<<"\n \t    DATOS OBTENIDOS    \n";
	 cout<<"\t  [   =   "<<cor_a<<endl;
	 cout<<"\t  ]   =   "<<cor_c<<endl;
	 cout<<"\t  (   =   "<<par_a<<endl;
	 cout<<"\t  )   =   "<<par_c<<endl;

}
//************************************************************************

int main()
{
   pilas obj1;
	 obj1.buscar();
	 obj1.demuestra();


      getchar();
}
