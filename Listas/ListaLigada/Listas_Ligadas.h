#ifndef _LISTALIGADA_H_
#define _LISTALIGADA_H_
#include <stdio.h>
#include <stdlib.h>
struct snodo
{				//snodo es el nombre de la estructura

  int valor;
  struct snodo *sig;		//El puntero siguiente para recorrer  lista enlazada

};

void eliminar (struct snodo **, int);
int mostrar (struct snodo *);
void ingresar (struct snodo **, int);
void ingresar_final (struct snodo **, int);

#endif
