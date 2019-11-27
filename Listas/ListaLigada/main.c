#include <stdio.h>
#include "Listas_Ligadas.h"
int
main (void)
{

  int dato, op = 0;
  struct snodo *cabeza;
  cabeza = NULL;

  printf
    (" \n\n Presione 1 para ingresar dato. \n Presione 2 para mostrar datos. \n Presiona 3 para ingresar al final. \n Presione 4 para eliminar \n Presione 5 para salir. ");


  while (op != 5)
    {
      printf
	("\n\n\t\t*********************ELIJE LA OPCION************************ :  ");

      scanf ("%d", &op);
      switch (op)
	{

	case 1:
	  printf ("\nDame el dato: ");
	  scanf ("%d", &dato);
	  ingresar (&cabeza, dato);
	  break;
	case 2:
	  mostrar (cabeza);
	  break;
	case 3:
	  printf ("Dame el dato: ");
	  scanf ("%d", &dato);
	  ingresar_final (&cabeza, dato);
	  break;
	case 4:
	  printf ("Dime el dato que deseas eliminar: ");
	  scanf ("%d", &dato);
	  eliminar (&cabeza, dato);
	  break;
	case 5:
	  printf ("\n\n FIN DEL PROGRAMA");
	  exit (1);
	}

    }


}
