#include <stdio.h>
#include <stdlib.h>

struct cola
{
  int cabeza;
  int final;
  int cuantos;
  int datos[10];
};
void principal ();

void insertar (struct cola **Cola, int dato);
void eliminar (struct cola **Cola);
void mostrar (struct cola *);

int
main (void)
{

  principal ();

  return 0;
}

void
principal ()
{

  struct cola *Cola;
  Cola = (struct cola *) malloc (sizeof (struct cola));


  Cola->cuantos = 0;
  Cola->cabeza = 0;
  Cola->final = 0;
  insertar (&Cola, 20);
  insertar (&Cola, 30);
  insertar (&Cola, 40);
  insertar (&Cola, 50);
  insertar (&Cola, 60);
  insertar (&Cola, 70);
  insertar (&Cola, 80);
  insertar (&Cola, 90);
  insertar (&Cola, 100);
  insertar (&Cola, 200);
  insertar (&Cola, 300);




  eliminar (&Cola);
  eliminar (&Cola);
  insertar (&Cola, 400);
  insertar (&Cola, 500);
  printf ("Eliminado y agregado\n");
  mostrar (Cola);
  insertar (&Cola, 500);


}

void
insertar (struct cola **Cola, int dato)
{

  if ((*Cola)->cuantos == 10)
    {
      printf ("\nCola llena \n");
      return;
    }
  if ((*Cola)->cabeza == (*Cola)->final)
    {


      (*Cola)->datos[((*Cola)->cabeza) % 10] = dato;
      ((*Cola)->final)++;
      ((*Cola)->cuantos)++;

    }
  else
    {
      (*Cola)->datos[((*Cola)->final) % 10] = dato;
      ((*Cola)->final)++;
      ((*Cola)->cuantos)++;
    }
}

void
eliminar (struct cola **Cola)
{

  if ((*Cola)->cuantos == 0)
    {
      printf ("cola vacia");
      return;
    }
  ((*Cola)->cuantos)--;
  ((*Cola)->cabeza)++;
  return;
}

void
mostrar (struct cola *Cola)
{
  int i = 0;

  if (Cola->cuantos == 0)
    {

      printf ("\nLista vacia\n");

      return;
    }

  for (i = (Cola->cabeza); i < (Cola->final); i++)
    {

      printf ("%d ->", Cola->datos[i % 10]);

    }

}
