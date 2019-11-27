#ifndef _LISTACIRCULAR_H_
#define _LISTACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
struct Listac
{
  int dato;
  struct Listac *siguiente;
};
struct Listac *crear (int dato);
void insertar_final (struct Listac **cabeza, int dato);
void insertar (struct Listac **cabeza, int dato);
void eliminar (struct Listac **, int);
void mostrar(struct Listac *);


#endif
