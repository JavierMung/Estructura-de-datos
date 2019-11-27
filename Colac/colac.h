#ifndef _COLAC_H_
#define _COLAC_H
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

#endif
