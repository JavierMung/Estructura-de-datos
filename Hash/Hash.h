#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct hash
{

  char *nombres[20];
  int cuantos;


};

void principal ();
int hashh (char[]);
void agregar (struct hash **, char[]);
void mostrar (struct hash *, char[]);
void eliminar (struct hash **, char[]);
int rehash (int);

#endif
