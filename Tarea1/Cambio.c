#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

int darCambio(int cantidad, int denominaciones[], int resultados[], int n) {
  ordenar(denominaciones, n);

  int i;
  for (i = n - 1; i >= 0; i--) {
    while (cantidad >= denominaciones[i]) {
      cantidad -= denominaciones[i];
      resultados[i]++;
    }
  }

  return cantidad;
}

int main() {
  int cantidad, n;
  int *denominaciones, *resultados;

  int i;

  printf("Tarea 1 - Axel Suárez Polo 201744436\n");
  printf("Dar cambio - Con divisiones y residuo.\n");

  printf("\nIntroduce la cantidad de denominaciones:\n");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de denominaciones tiene que ser mayor a 0.");
  denominaciones = malloc(sizeof(int) * n);
  resultados = malloc(sizeof(int) * n);

  printf("\nIntroduce las denominaciones: \n");
  for (i = 0; i < n; i++) {
    scanf("%d%*c", denominaciones + i);
    resultados[i] = 0;
  }

  asertar(todos(mayorACero, denominaciones, n), "Las denominaciones tienen que ser mayores a 0.");
  asertar(unicos(denominaciones, n), "Las denominaciones deben ser distintas.");

  printf("\nIntroduce la cantidad de la que quieres obtener el cambio:\n");
  scanf("%d%*c", &cantidad);

  asertar(cantidad > 0, "La cantidad debe ser mayor a 0.");

  int resto = darCambio(cantidad, denominaciones, resultados, n);

  printf("\nEl cambio es:\n");
  for (i = n - 1; i >= 0; i--) {
    printf("  %3d de %3d\n", resultados[i], denominaciones[i]);
  }

  if (resto != 0)
    printf("\nNo se pudieron repartir: %d\n", resto);

  free(denominaciones);
  free(resultados);
}
