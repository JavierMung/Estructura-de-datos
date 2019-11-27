#include "arbolbinario.h"

struct arbol *
crearnodo (int dato)
{
  struct arbol *cabeza;
  cabeza = (struct arbol *) malloc (sizeof (struct arbol));
  if (cabeza == NULL)
    {
      printf ("ERROR DE MEMORIA");
      return cabeza;
    }
  cabeza->dato = dato;
  cabeza->derecha = NULL;
  cabeza->izquierda = NULL;
  return cabeza;


}

void
insertar (struct arbol **padre, int dato)
{

  struct arbol *nuevo, *aux;
  nuevo = crearnodo (dato);
  aux = NULL;
  aux = *padre;

  if (*padre == NULL)
    {
      *padre = nuevo;
      return;
    }
  if ((*padre)->dato == dato)
    {
      return;
    }
  if (dato > (*padre)->dato)
    {
      insertar (&(*padre)->derecha, dato);
    }
  else
    {
      insertar (&(*padre)->izquierda, dato);
    }

  return;
}

void
mostrar (struct arbol *Arbol)
{

  if (Arbol == NULL)
    {
      return;
    }
  printf ("%d, ", Arbol->dato);

  mostrar (Arbol->izquierda);
  mostrar (Arbol->derecha);

  return;
}

struct arbol *
buscar (struct arbol *padre, int dato)
{

  struct arbol *aux;
  aux = padre;

  if (aux == NULL)
    {
      return aux;
    }
  if (aux->dato == dato)
    {
      return aux;
    }
  if (dato < aux->dato)
    {
      return buscar (aux->izquierda, dato);
    }
  return buscar (aux->derecha, dato);



}

void
elimiar (struct arbol **raiz, int dato)
{

  struct arbol *aux, *cam, *aux2;
  aux = NULL;
  aux = buscar (*raiz, dato);

  if ((aux->derecha == NULL && aux->izquierda == NULL))
    {
      free (aux);
      return;
    }
  if (aux->derecha == NULL)
    {
      // printf("**"); auxiliar para saber a cual entra y si esta bien 
      cam = aux;
      aux2 = aux;
      aux = aux->izquierda;

      while (aux->derecha != NULL)
	{
	  aux = aux->derecha;
	}
      if (cam->izquierda != aux)
	{

	  aux2 = aux2->izquierda;

	  while (aux2->derecha != aux)
	    {
	      aux2 = aux2->derecha;
	    }
	  cam->dato = aux->dato;
	  aux2->derecha = aux->izquierda;
	  free (aux);
	  return;
	}
      cam->izquierda = aux->izquierda;
      cam->dato = aux->dato;
      free (aux);
      return;

    }
  // printf("--"); auxiliar para saber a cual entra y si esta bien 
  cam = aux;
  aux2 = aux;
  aux = aux->derecha;

  while (aux->izquierda != NULL)
    {
      aux = aux->izquierda;
    }
  if (cam->derecha != aux)
    {

      aux2 = aux2->derecha;

      while (aux2->izquierda != aux)
	{
	  aux2 = aux2->izquierda;
	}
      cam->dato = aux->dato;
      aux2->izquierda = aux->derecha;
      free (aux);
      return;
    }
  cam->derecha = aux->derecha;
  cam->dato = aux->dato;
  free (aux);
  return;
}
