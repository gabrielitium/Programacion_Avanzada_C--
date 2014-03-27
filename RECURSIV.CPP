/*  
	
 Este programa obtiene el factorial de un n—mero n dado por el usuario
mediante una funci•n recursiva    */

#include <iostream.h>
#include <conio.h>
int long factorial(int n);
main()
{
  int n;
  int long fac;
  do{
  cout<<"\nProporcione numero para determinarsu factorial:  ";
  cin>>n;
       if(n<0)
       cout<<"\nError debe ser mayor\n";
     }while(n<0);
     fac=factorial(n);
     cout<<"El factorial es:  "<<fac<<endl;
    getch();
}
int long factorial(int n)
{
  long fac;

	  if(n==0)
	  fac=1;
	  else
	     fac=n*factorial(n-1);
  return fac;
}

