#include "contigua.h"
int
main (void)
{
  int dato;
  struct Lista *lista;
  lista = NULL;
  insertar (&lista, 3);
  insertar (&lista, 25);
  insertar (&lista, 35);
  insertar (&lista, 85);
  eliminar (&lista, 35);
  mostrar (lista);
  return 0;
}
