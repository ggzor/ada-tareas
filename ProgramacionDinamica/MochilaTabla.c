#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

int **tabla;

int repartir(int i, int w, int *pesos, int *valores) {
  printf("%d %d\n", i, w);

  if (tabla[i][w] == -1) {
    if (i == 0)
      tabla[i][w] = 0;
    else if (pesos[i - 1] > w)
      tabla[i][w] = repartir(i - 1, w, pesos, valores);
    else if (pesos[i - 1] <= w)
      tabla[i][w] = imax(repartir(i - 1, w, pesos, valores),
                         repartir(i - 1, w - pesos[i - 1], pesos, valores) + valores[i - 1]);
  }

  return tabla[i][w];
}

int main() {
  int pesoMax, n;
  int *pesos, *valores;

  int i, j;

  printf("Proyecto 3 - Programación Dinámica\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Problema de la mochila\n");

  printf("\nIntroduce la cantidad de objetos:\n");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de objetos tiene que ser mayor a cero.");

  pesos = malloc(sizeof(int) * n);
  valores = malloc(sizeof(int) * n);

  printf("\nIntroduce el peso y valor de cada objeto: \n");
  for (i = 0; i < n; i++) {
    scanf("%d%*c", pesos + i);
    asertar(pesos[i] > 0, "El peso de cada objeto debe ser mayor a cero.");

    scanf("%d%*c", valores + i);
    asertar(valores[i] > 0, "El valor de cada objeto debe ser mayor a cero.");
  }

  printf("\nIntroduce el peso máximo que puede llevar la mochila: ");
  scanf("%d%*c", &pesoMax);

  asertar(pesoMax > 0, "El peso máximo debe ser mayor a 0.");

  tabla = malloc(sizeof(int *) * (n + 1));

  for (i = 0; i < n + 1; i++) {
    tabla[i] = malloc(sizeof(int) * (pesoMax + 1));

    for (j = 0; j < pesoMax + 1; j++)
      tabla[i][j] = -1;
  }

  int valorMaximo = repartir(n, pesoMax, pesos, valores);

  printf("\nEl valor máximo que se puede obtener es %d.\n", valorMaximo);

  for (i = 0; i < n + 1; i++)
    free(tabla[i]);

  free(tabla);

  free(pesos);
  free(valores);
}
