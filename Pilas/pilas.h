#ifndef _PILAS_H_
#define _PILAS_H_
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
#endif
