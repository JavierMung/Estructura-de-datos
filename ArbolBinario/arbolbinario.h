#ifndef _ARBOLBINARIO_H_
#define _ARBOLBINARIO_H_
#include <stdio.h>
#include <stdlib.h>

struct arbol
{


  int dato;
  struct arbol *derecha;
  struct arbol *izquierda;

};

void insertar (struct arbol **, int);
void mostrar (struct arbol *);
struct arbol *crearnodo (int dato);
struct arbol *buscar (struct arbol *, int);
void elimiar (struct arbol **, int);
struct arbol *crearnodo (int);
#endif
