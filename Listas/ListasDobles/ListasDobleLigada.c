#include "ListasDobleLigada.h"





int
comprobar (struct Listadoble *cabeza, int dato)
{

  struct Listadoble *aux;
  aux = NULL;
  aux = cabeza;

  if (cabeza == NULL)
    {
      return 0;
    }
  else
    {

      while (aux->siguiente != NULL)
	{
	  if (aux->dato == dato)
	    {
	      return 1;
	    }
	  aux = aux->siguiente;

	}
      if (aux->dato == dato)
	{
	  return 1;
	}
    }

  return 0;





}

void
eliminar (struct Listadoble **cabeza, int dato)
{
  struct Listadoble *aux, *cabesa;

  cabesa = NULL;
  aux = NULL;
  cabesa = *cabeza;
  if ((*cabeza)->siguiente == NULL)
    {
      if ((*cabeza)->dato == dato)
	{
	  aux = *cabeza;
	  *cabeza = NULL;
	  free (aux);
	}
    }
  else
    {

      if ((*cabeza)->dato == dato)
	{
	  aux = *cabeza;
	  (*cabeza)->siguiente->anterior = *cabeza;
	  *cabeza = (*cabeza)->siguiente;
	  free (aux);
	}
      else
	{
	  while (cabesa->dato != dato)
	    {
	      cabesa = cabesa->siguiente;
	    }
	  if (cabesa->siguiente == NULL)
	    {
	      aux = cabesa;
	      cabesa->anterior->siguiente = NULL;
	      free (aux);
	    }
	  else
	    {

	      aux = cabesa;
	      cabesa->anterior->siguiente = cabesa->siguiente;
	      cabesa->siguiente->anterior = cabesa->anterior;
	      free (aux);
	    }
	}
    }



}

void
ingresar_final (struct Listadoble **cabeza, int dato)
{
  struct Listadoble *aux, *cabesa;
  aux = NULL;
  cabesa = NULL;
  aux = (struct Listadoble *) malloc (sizeof (struct Listadoble));
  cabesa = *cabeza;

  while (cabesa->siguiente != NULL)
    {
      cabesa = cabesa->siguiente;
    }

  aux->dato = dato;
  aux->siguiente = NULL;
  aux->anterior = cabesa;
  cabesa->siguiente = aux;



}

void
mostrar (struct Listadoble *cabeza)
{
  while (cabeza != NULL)
    {
      printf ("%d ->", cabeza->dato);
      cabeza = cabeza->siguiente;
    }
  printf (" \n");

}

void
mostrar_atras (struct Listadoble *cabeza)
{

  struct Listadoble *atras;
  atras = NULL;
  atras = cabeza;
  while (atras->siguiente != NULL)
    {

      atras = atras->siguiente;
    }

  while (atras != NULL)
    {
      printf ("%d <- ", atras->dato);
      atras = atras->anterior;
    }
  printf ("\n");
}

void
ingresar (struct Listadoble **cabeza, int dato)
{
  struct Listadoble *nuevo;
  nuevo = NULL;
  nuevo = (struct Listadoble *) malloc (sizeof (struct Listadoble));

  if (nuevo == NULL)
    {
      return;
    }
  else
    {
      if (*cabeza == NULL)
	{
	  nuevo->dato = dato;
	  nuevo->siguiente = NULL;
	  nuevo->anterior = NULL;;
	  *cabeza = nuevo;
	}
      else
	{

	  nuevo->dato = dato;
	  nuevo->siguiente = *cabeza;
	  nuevo->anterior = NULL;
	  (*cabeza)->anterior = nuevo;
	  *cabeza = nuevo;
	}

    }
}
