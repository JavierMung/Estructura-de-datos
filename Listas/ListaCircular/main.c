#include "Lista_Circular.h"

int
main (void)
{
  struct Listac *cabeza;
  cabeza = NULL;
  insertar (&cabeza, 25);
  insertar (&cabeza, 24);
  insertar (&cabeza, 23);
  insertar (&cabeza, 22);
  insertar (&cabeza, 21);
  insertar_final (&cabeza, 26);
  insertar (&cabeza, 19);
  eliminar (&cabeza, 24);
  mostrar (cabeza);
  return 0;
}
