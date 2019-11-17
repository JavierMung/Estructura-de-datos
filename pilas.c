#include <stdio.h>
#include <stdlib.h>
struct pila
{
  int dato;
  struct pila *siguiente;
};
void principal ();
void push (struct pila **, int);
void pop (struct pila **);
int cima (struct pila *);
int
main (void)
{
  principal ();
  return 0;
}

void
principal ()
{
  int dato;
  struct pila *cabeza, *tope;
  cabeza = NULL;
  push (&cabeza, 20);
  push (&cabeza, 30);
  push (&cabeza, 40);
  push (&cabeza, 50);
  pop (&cabeza);
  pop (&cabeza);
  pop (&cabeza);
  dato = cima (cabeza);
  if (dato != -1)
    {
      printf ("  \n  %d \n ", dato);
    }
}

struct pila *
crearnodo (int dato)
{
  struct pila *nodo;
  nodo = NULL;
  nodo = (struct pila *) malloc (sizeof (struct pila));
  if (nodo == NULL)
    {
      return nodo;
    }

  else
    {
      nodo->dato = dato;
      nodo->siguiente = NULL;
      return nodo;
    }
}

void
push (struct pila **cabeza, int dato)
{
  struct pila *nodo;
  nodo = crearnodo (dato);
  if (nodo == NULL)
    {
      return;
    }
  nodo->siguiente = *cabeza;
  *cabeza = nodo;
}

void
pop (struct pila **cabeza)
{
  if (*cabeza == NULL)
    {
      return;
    }
  struct pila *pop;
  pop = *cabeza;
  *cabeza = (*cabeza)->siguiente;
  free (pop);
  return;
}

int
cima (struct pila *cabeza)
{
  if (cabeza == NULL)
    {
      printf ("\n ***** La pila esta vacia *****  \n");
      return -1;
    }
  else
    {
      return cabeza->dato;
    }
}
