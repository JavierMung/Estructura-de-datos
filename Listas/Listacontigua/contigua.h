#ifndef _CONTIGUA_H_
#define _CONTIGUA_H_

#include <stdio.h>
#include <stdlib.h>
struct Lista
{
  int *dato;
  int actual;
  int cuantos;
};
struct Lista *crearnodo (int);
void insertar (struct Lista **, int);
void eliminar (struct Lista **, int);
void mostrar (struct Lista *);

#endif
