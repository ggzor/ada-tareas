#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

int minimizarTiempo(int tiempos[], int n) {
  int i;
  int resultado = 0;

  ordenar(tiempos, n);
  for (i = 0; i < n; i++)
    resultado += tiempos[i] * (n - i);

  return resultado;
}

int main() {
  int n;
  int *tiempos;

  int i;

  printf("Tarea 1 - Axel Suárez Polo 201744436\n");
  printf("Minimizar tiempo - Con sumas prefijas.\n");

  printf("\nIntroduce la cantidad de clientes:\n");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de clientes tiene que ser mayor a 0.");
  tiempos = malloc(sizeof(int) * n);

  printf("\nIntroduce los tiempos por cada cliente: \n");
  for (i = 0; i < n; i++)
    scanf("%d%*c", tiempos + i);

  asertar(todos(mayorOIgualACero, tiempos, n), "Los tiempos tienen que ser mayores o iguales a 0.");

  int tiempo = minimizarTiempo(tiempos, n);
  printf("\nEl menor tiempo que se puede pasar en el sistema es: %d\n", tiempo);

  free(tiempos);
}
