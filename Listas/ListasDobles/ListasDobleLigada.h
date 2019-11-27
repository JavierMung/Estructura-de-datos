#ifndef _LISTADOBLE_H_
#define _LISTADOBLE_H_
#include <stdio.h>
#include <stdlib.h>


struct Listadoble
{
  int dato;
  struct Listadoble *siguiente;
  struct Listadoble *anterior;

};
int comprobar (struct Listadoble *, int);
void eliminar (struct Listadoble **, int);
void ingresar_final (struct Listadoble **, int);
void mostrar (struct Listadoble *);
void mostrar_atras (struct Listadoble *);
void ingresar (struct Listadoble **, int);

#endif
