#include "Utilerias.h"

#include <stdlib.h>
#include <string.h>

void ordenar(int a[], int n) {
  int cambio, i, j, temp, fd = n;

  do {
    if (fd / 1.3 > 1) 
      fd = (int) (fd / 1.3);
    else
      fd = 1;
    
    cambio = 0;

    for (i = 0; i < n - fd; i++) {
      j = i + fd;

      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        cambio = 1;
      }
    }
  } while((fd != 1) || cambio);
}

void ordenarPor(int (*comparar)(const void *, const void *), void *a, int n, int s) {
  void *temp = malloc(s);
  int cambio, i, j, fd = n;

  do {
    if (fd / 1.3 > 1) 
      fd = (int) (fd / 1.3);
    else
      fd = 1;
    
    cambio = 0;

    for (i = 0; i < n - fd; i++) {
      j = i + fd;

      void *ai = a + (i * s);
      void *aj = a + (j * s);

      if (comparar(ai, aj) > 0) {
        memcpy(temp, ai, s);
        memcpy(ai, aj, s);
        memcpy(aj, temp, s);

        cambio = 1;
      }
    }
  } while((fd != 1) || cambio);

  free(temp);
}

int imin(int a, int b) { return a < b ? a : b; }

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
