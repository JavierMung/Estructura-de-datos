#include "ListasDobleLigada.h"
int
main (void)
{
  int dato = 0, op = 0;
  struct Listadoble *cabeza;
  cabeza = NULL;


  printf
    (" 1. Ingresar dato al principio. \n 2. Ingresar dato al final \n 3. Motrar desde el frente \n 4. Mostrar desde el final \n 5. Eliminar dato. \n 6. Salir del programa. \n\n ");
  while (op != 6)
    {
      printf ("\t\t\t\t***********ELIJE LA OPCION****************: ");
      scanf ("%d", &op);
      switch (op)
	{

	case 1:
	  printf ("Dame el dato : ");
	  scanf ("%d", &dato);
	  ingresar (&cabeza, dato);
	  break;
	case 2:
	  printf ("Dame el dato : ");
	  scanf ("%d", &dato);
	  ingresar_final (&cabeza, dato);
	  break;
	case 3:
	  mostrar (cabeza);
	  break;
	case 4:
	  mostrar_atras (cabeza);
	  break;
	case 5:
	  printf ("Dame el dato que deseas eliminar: ");
	  scanf ("%d", &dato);
	  comprobar (cabeza, dato);
	  if (comprobar (cabeza, dato) == 1)
	    {
	      eliminar (&cabeza, dato);
	      break;
	    }
	  else
	    {
	      printf
		("**********ERROR : NO EXISTE EL DATO A ELIMINAR*********\n");
	      break;
	    }
	case 6:
	  printf ("\n/////////////FIN DEL PROGRAMA///////////////");
	  exit (-1);

	}
    }
  return 0;

}
