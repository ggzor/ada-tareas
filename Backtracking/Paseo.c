#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

#define MEDIDA 8 
#define TOTAL (MEDIDA * MEDIDA)


int coordenadaAbsoluta(int x, int y) {
  return MEDIDA * y + x;
}

int enTablero(int x, int y) {
  return enRango(0, MEDIDA - 1, x) && enRango(0, MEDIDA - 1, y);
}

int paseo(int x, int y, int n, int recorrido[])  {
  int i, j;
  int nx, ny, p;
  int a = coordenadaAbsoluta(x, y);

  recorrido[a] = n;
  
  if (n == TOTAL)
    return 1;

  for (i = -2; i <= 2; i++) {
    for (j = -2; j <= 2; j++) {
      if (abs(i * j) == 2) {
        nx = x + i;
        ny = y + j;
        p = coordenadaAbsoluta(nx, ny);
        if (enTablero(nx, ny) 
            && recorrido[p] == -1 
            && paseo(nx, ny, n + 1, recorrido))
          return 1;        
      }
    }
  }

  recorrido[a] = -1;
  return 0;
}

int main() {
  int x, y, i, j, p;
  int *recorrido;

  printf("Proyecto 4 - Backtracking\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Problema del paseo del caballo\n");

  printf("\nIntroduce la coordenada X: ");
  scanf("%d%*c", &x);

  asertar(enRango(1, MEDIDA, x), "La coordenada X debe estar entre 1 y 8 (inclusivo).");

  printf("Introduce la coordenada Y: ");
  scanf("%d%*c", &y);

  asertar(enRango(1, MEDIDA, y), "La coordenada Y debe estar entre 1 y 8 (inclusivo).");

  // Inicializar recorrido
  recorrido = malloc(sizeof(int) * TOTAL);
  for (i = 0; i < TOTAL; i++)
    recorrido[i] = -1; 

  paseo(x - 1, y - 1, 1, recorrido);

  printf("\nEl recorrido es como sigue: \n\n");

  int colores[] = { 31, 32, 33, 34, 35, 37 };
  int nc = sizeof(colores) / sizeof(int);

  printf("      ");
  for (i = 0; i < nc + 1; i++) {
    printf("\e[");
    printf("%d", colores[i % nc]);
    printf("m█");
  }
  printf("\e[0m\n\n");

  printf("      ");

  for (i = 0; i < MEDIDA; i++)
    printf("%2d ", i + 1);
  printf("\n\n");

  for (i = 0; i < MEDIDA; i++) {
    printf("%2d    ", i + 1);
    for (j = 0; j < MEDIDA; j++) {
      p = coordenadaAbsoluta(j, i);
     
      printf("\e[");
      printf("%d", colores[((recorrido[p]) / 10) % 6]);
      printf("m");

      printf("%2d\e[0m ", recorrido[p]);
    }
    printf("\n");
  }

  printf("\n");

  free(recorrido);
}
