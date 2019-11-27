#include "arbolbinario.h"


int
main (void)
{

  struct arbol *raiz, *aux;
  raiz = NULL;
  insertar (&raiz, 52);
  insertar (&raiz, 62);

  insertar (&raiz, 6);
  insertar (&raiz, 32);
  insertar (&raiz, 87);
  mostrar (raiz);
  aux = buscar (raiz, 87);
  elimiar (&raiz, 52);
  mostrar (raiz);

  return 0;
}
