#include <stdio.h>
#include <stdlib.h>
#include "Validacion.h"

void asertar(int condicion, const char *mensaje) {
  if (!condicion) {
    printf("\n\e[31mError: %s\e[0m\n", mensaje);
    exit(-1);
  }
}

int mayorACero(int x) { return x > 0; }
int mayorOIgualACero(int x) { return x >= 0; }

int todos(int (*condicion)(int x), int xs[], int n) {
  int i;

  for (i = 0; i < n; i++)
    if (!condicion(xs[i]))
      return 0;

  return 1;
}

int unicos(int xs[], int n) {
  int i, j;

  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (xs[i] == xs[j])
        return 0;

  return 1;
}
