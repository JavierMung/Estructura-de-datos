#ifndef _HASHA_H_
#define _HASHA_H
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
int hash (int);

#endif
