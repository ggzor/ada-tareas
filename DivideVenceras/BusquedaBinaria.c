#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

int buscar(int l, int u, int dato, int *a)  {
  int m = (l + u) / 2;

  if (l <= u) {
    if (a[m] == dato)
      return m;
    else if (dato < a[m])
      return buscar(l, m, dato, a);
    else
      return buscar(m + 1, u, dato, a);
  } else {
    return -1;
  }
}

int main() {
  int n;
  int dato;
  int *a;
  int i, j;

  printf("Divide y vencerás\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Búsqueda Binaria\n");

  printf("\nIntroduce la cantidad de elementos: ");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de elementos tiene que ser mayor a 0.");

  a = malloc(sizeof(int *) * n);

  printf("Ingresa los elementos del arreglo: \n");
  for (i = 0; i < n; i++)
    scanf("%d%*c", a + i);

  printf("\nIntroduce el elemento a buscar: ");
  scanf("%d%*c", &dato);

  ordenar(a, n);

  printf("\nEl arreglo ordenado es:\n");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n\n");
  
  int indice = buscar(0, n - 1, dato, a);

  if (indice == -1)
    printf("No se encontró el elemento en el arreglo.\n");
  else
    printf("El elemento se encuentra en el índice %d.\n", indice);

  free(a);
}
