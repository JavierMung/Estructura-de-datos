#include "Listas_Ligadas.h"



void
eliminar (struct snodo **cabeza, int dato)
{
  struct snodo *aux, *cabesa;
  cabesa = *cabeza;
  aux = NULL;

  if (cabesa == NULL)
    {

      return;

    }
  else
    {
      if ((*cabeza)->valor == dato)
	{

	  if ((*cabeza)->sig == NULL)
	    {
	      aux = *cabeza;
	      *cabeza = NULL;

	      free (aux);
	    }
	  else
	    {
	      aux = *cabeza;
	      *cabeza = (*cabeza)->sig;
	      free (aux);
	    }

	}

      else
	{

	  while (cabesa->sig->valor != dato)
	    {
	      cabesa = cabesa->sig;
	    }

	  if (cabesa->sig == NULL)
	    {

	      aux = cabesa->sig;
	      cabesa->sig = NULL;;
	      free (aux);

	    }
	  else
	    {
	      aux = cabesa->sig;
	      cabesa->sig = cabesa->sig->sig;
	      free (aux);
	    }
	}

    }

}

int
mostrar (struct snodo *cabeza)
{
  printf ("\n ");

  if (cabeza == NULL)
    {
      return 1;
    }
  else
    {

      while (cabeza != NULL)
	{
	  printf ("%d", cabeza->valor);
	  cabeza = cabeza->sig;
	  printf (" -> ");

	}
    }
  return 0;
}



void
ingresar (struct snodo **cabeza, int dato)
{

  struct snodo *nuevo;
  nuevo = NULL;
  nuevo = (struct snodo *) malloc (sizeof (struct snodo));

  if (nuevo == NULL)
    {
      return;
    }
  else
    {

      if (*cabeza == NULL)
	{

	  *cabeza = nuevo;
	  (*cabeza)->valor = dato;
	  (*cabeza)->sig = NULL;
	}
      else
	{
	  nuevo->sig = *cabeza;
	  nuevo->valor = dato;
	  *cabeza = nuevo;

	}
    }
}

void
ingresar_final (struct snodo **cabeza, int dato)
{
  struct snodo *nuevo;
  struct snodo *final;
  nuevo = NULL;
  final = NULL;
  nuevo = (struct snodo *) malloc (sizeof (struct snodo));
  final = *cabeza;
  if (nuevo == NULL)
    {
      return;
    }
  else
    {
      if (*cabeza == NULL)
	{
	  *cabeza = nuevo;
	  (*cabeza)->valor = dato;
	  (*cabeza)->sig = NULL;
	}
      else
	{
	  while ((final)->sig != NULL)
	    {
	      final = final->sig;
	    }
	  nuevo->valor = dato;
	  (final)->sig = nuevo;
	  nuevo->sig = NULL;
	}

    }


}
