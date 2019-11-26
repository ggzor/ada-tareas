#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

void generar(int l, int u, int **a)  {
  int s = u - l + 1;
  int ms = s / 2;
  int i, j;

  if (s == 2) {
    a[l][0] = u + 1;
    a[u][0] = l + 1;
  } else {
    generar(l, l + ms - 1, a);
    generar(l + ms, u, a);

    for (i = 0; i < ms; i++) {
      for (j = 0; j < ms; j++) {
        a[l + i][ms - 1 + j] = l + ms + (j - i + ms) % ms + 1;
      }
    }

    for (i = 0; i < ms; i++) {
      for (j = 0; j < ms; j++) {
        a[l + ms + i][ms - 1 + j] = l + (j - i + ms) % ms + 1;
      }
    }
  }
}

int main() {
  int n;
  int i, j;
  int **tablero;

  printf("Proyecto 2 - Divide y vencerás\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Problema del calendario\n");

  printf("\nIntroduce la cantidad de participantes:\n");
  scanf("%d%*c", &n);

  asertar(n >= 2, "La cantidad de participantes tiene que ser mayor o igual a 2.");
  asertar(potenciaDe2(n), "La cantidad de participantes tiene que ser potencia de 2.");

  tablero = malloc(sizeof(int *) * n);
  for (i = 0; i < n; i++)
    tablero[i] = malloc(sizeof(int) * n - 1);

  generar(0, n - 1, tablero);

  printf("La planeación es como sigue: \n\n");
  printf("      ");

  for (i = 0; i < n - 1; i++)
    printf("%2d ", i + 1);
  printf("\n\n");

  for (i = 0; i < n; i++) {
    printf("%2d    ", i + 1);
    for (j = 0; j < n - 1; j++) {
      printf("%2d ", tablero[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for (i = 0; i < n; i++)
    free(tablero[i]);
  
  free(tablero);
}
