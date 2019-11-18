#include <stdio.h>
#include <stdlib.h>

struct hash
{

  struct Lista *dato[20];
  int cuantos;

};

struct Lista
{

  struct Lista *siguiente;
  int dato;

};

void principal ();
struct Lista *crearnodo (int);
void insertar (struct hash **, int);
int buscar (struct hash *, int);
void eliminar (struct hash **, int);
int hash(int);
int
main (void)
{

  principal ();
  system ("pause");
  return 0;
}

void
principal ()
{

  struct hash *tabla;

  tabla = NULL;

  tabla = (struct hash *) calloc (1, sizeof (struct hash));

  if (tabla == NULL)
    {
      return;
    }


//insertar(&tabla, 10);
  insertar (&tabla, 70);
  insertar (&tabla, 20);
  insertar (&tabla, 70);
  insertar (&tabla, 80);
  insertar (&tabla, 90);



  buscar (tabla, 70);
  buscar (tabla, 95);
  buscar (tabla, 20);
  eliminar (&tabla, 20);
  buscar (tabla, 80);

  return;
}


struct Lista *
crearnodo (int dato)
{

  struct Lista *nuevo;
  nuevo = NULL;
  nuevo = (struct Lista *) malloc (sizeof (struct Lista));
  nuevo->dato = dato;
  nuevo->siguiente = NULL;
  return nuevo;
}

void
insertar (struct hash **tabla, int dato)
{

  int p = 0;
  struct Lista *nuevo;
  p = hash (dato);
  nuevo = crearnodo (dato);
  struct Lista *aux;
  aux = NULL;

  if (*((*tabla)->dato + p) == NULL)
    {
      *((*tabla)->dato + p) = nuevo;

      printf
	("Numero : %d insertado en la posicion numero %d de la tabla. \n",
	 dato, p);

    }
  else
    {

      aux = *((*tabla)->dato + p);

      if (aux->siguiente == NULL)
	{
	  aux->siguiente = crearnodo (dato);
	  printf
	    ("Numero : %d insertado en la posicion numero %d de la tabla \n",
	     dato, p);

	  return;
	}
      else
	{


	  while (aux->siguiente != NULL)
	    {
	      aux = aux->siguiente;
	    }
	  aux->siguiente = crearnodo (dato);
	  printf
	    ("Numero : %d insertado en la posicion numero %d de la tabla \n",
	     dato, p);

	}
    }


}

int
hash (int dato)
{
  int p;

  p = ((dato * 17) / 3) % 20;

  return p;

}

int
buscar (struct hash *tabla, int dato)
{
  int p = 0, contador = 0, i = 0;
  p = hash (dato);
  struct Lista *aux;
  aux = (*(tabla->dato + p));

  if ((*(tabla->dato + p)) == NULL)
    {
      printf ("****************NO EXISTE EL DATO BUSCADO***********\n");
      return -1;
    }
  if (aux->siguiente == NULL)
    {
      if (aux->dato == dato)
	{
	  printf
	    ("El numero : %d, se encuentra en el lugar %d de la tabla  %d \n",
	     aux->dato, i + 1, p);
	  return p;
	}

    }
  while (aux != NULL)
    {

      if (aux->dato == dato)
	{
	  printf
	    ("El numero : %d, se encuentra en el lugar %d de la tabla  %d \n",
	     aux->dato, i + 1, p);
	  contador++;
	  return p;
	}
      aux = aux->siguiente;
      i++;

    }
  if (contador == 0)
    {
      printf
	("*************** //  NO EXISTE EL DATO BUSCADO // *****************\n");
      return -1;
    }

}


void
eliminar (struct hash **tabla, int dato)
{
  int p = 0;
  struct Lista *aux, *aux2;
  aux = NULL;
  aux2 = NULL;
  p = buscar (*tabla, dato);
  aux = ((*tabla)->dato[p]);


  if (-1 == p)
    {
      printf ("***eliminado el numero : %d ***\n", dato);
      return;
    }
  else
    {
      if (((*tabla)->dato[p])->dato == dato)
	{
	  // printf("entra"); referencia que use para saber donde se encontraba el error
	  (*tabla)->dato[p] = ((*tabla)->dato[p])->siguiente;
	  free (aux);
	  printf ("***eliminado el numero : %d ***\n", dato);
	  return;

	}
      else
	{
	  //printf("entra2"); referencia para saver donde se encontraba el error
	  while (aux->siguiente->dato != dato)
	    {
	      aux = aux->siguiente;
	    }
	  aux2 = aux;
	  aux = aux->siguiente;
	  aux2->siguiente = aux->siguiente;
	  free (aux);
	  printf ("***eliminado el numero : %d ***\n", dato);

	  return;
	}

    }

}
