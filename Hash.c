#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct hash
{

  char *nombres[20];
  int cuantos;
  int re;			// me ayuda a saber si se le hizo rehash


};

void principal ();
int hashh (char[]);
void agregar (struct hash **, char[]);
void mostrar (struct hash *, char[]);
void eliminar (struct hash **, char[]);
int rehash (int);

int
main (void)
{

  principal ();

  return 0;
}

void
principal ()
{
  int i = 0;
  struct hash *cabeza;
  cabeza = NULL;
  cabeza = (struct hash *) malloc (sizeof (struct hash));
  if (cabeza == NULL)
    {
      return;
    }
  cabeza->cuantos = 0;

  for (i = 0; i < 20; i++)
    {
      cabeza->nombres[i] = NULL;
    }
  char nombre[20];

  agregar (&cabeza, "jos");
  agregar (&cabeza, "pedro");
  agregar (&cabeza, "mike");
  agregar (&cabeza, "aldodf");

  mostrar (cabeza, "pedro");
//eliminar(&cabeza, "pedro");
  eliminar (&cabeza, "jo");

  mostrar (cabeza, "aldodf");

}





int
hashh (char nombre[])
{

  int i, j, hassh = 0;
  j = strlen (nombre);
  for (i = 0; i <= j; i++)
    {

      hassh += nombre[i];

    }
  hassh = hassh % 20;

  return hassh;
}

void
agregar (struct hash **tabla, char nombre[])
{
  int p = 0, l = 0;
  p = hashh (nombre);


  if (*tabla == NULL)
    {
      return;
    }

  if ((*tabla)->nombres[p] == NULL)
    {

      if ((*tabla)->cuantos == 10)
	{
	  printf ("La lista esta llena\n\n");
	  return;
	}
      else
	{
	  l = strlen (nombre);
	  (*tabla)->nombres[p] = (char *) malloc ((l + 1) * sizeof (char));
	  strcpy ((*tabla)->nombres[p], nombre);
	  ((*tabla)->cuantos)++;
	  printf ("agregado en la posicion %d \n", p);
	  return;
	}

    }
  else
    {
      while (1)
	{
	  p = rehash (p);

	  if ((*tabla)->nombres[p] == NULL)
	    {
	      l = strlen (nombre);
	      (*tabla)->nombres[p] =
		(char *) malloc ((l + 1) * sizeof (char));
	      strcpy ((*tabla)->nombres[p], nombre);
	      ((*tabla)->cuantos)++;

	      break;

	    }
	}
      printf ("dato con rehash agregado en la posicion %d\n", p);
      return;

    }
}

void
mostrar (struct hash *tabla, char nombre[])
{
  int p = 0;
  if (tabla == NULL)
    {

      printf ("*****Tabla vacia*****\n");
      return;
    }


  p = hashh (nombre);
  if (tabla->nombres[p] == NULL)
    {
      printf ("No exite el dato\n");
      return;
    }
  if (0 == strcmp (tabla->nombres[p], nombre))
    {
      printf ("La persona %s se encuentra en la posicion %d de la tabla. \n",
	      tabla->nombres[p], p);
      return;
    }

  while (tabla->nombres[p] != NULL)
    {
      p = rehash (p);
      if (strcmp (tabla->nombres[p], nombre) == 0)
	{
	  printf ("El nombre %s se encuentra en la posicion %d ",
		  tabla->nombres[p], p);
	  break;
	}

    }



}

void
eliminar (struct hash **tabla, char nombre[])
{
  int p = 0;

  p = hashh (nombre);
  if ((*tabla)->nombres[p] == NULL)
    {
      return;
    }
  (*tabla)->nombres[p] = NULL;
  return;
}

int
rehash (int dato)
{

  int re = 0;
  re = (((dato * 13)) + 1) % 20;
  return re;

}
