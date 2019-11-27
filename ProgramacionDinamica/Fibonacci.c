#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

long tabla[100];
long fibonacci(int n)  {
  if (tabla[n] == 0) {
    if (n == 0 || n == 1)
      tabla[n] = 1;
    else
      tabla[n] = fibonacci(n - 2) + fibonacci(n - 1);
  }
  
  return tabla[n];
}

int main() {
  int n;
  int i;

  printf("Programación Dinámica\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Fibonacci\n");

  printf("\nIntroduce el número de Fibonacci que quieres calcular: ");
  scanf("%d%*c", &n);

  asertar(n >= 0, "El número tiene que ser mayor o igual a 0.");

  printf("El número es: %d\n", fibonacci(n));
}
