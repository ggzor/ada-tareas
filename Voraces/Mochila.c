#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

typedef struct {
  int peso;
  int valor;
  int indice;
} Objeto;

int repartir(int pesoMax, Objeto objetos[], int n, float resultados[]) {

}

int main() {
  int pesoMax, n;
  Objeto *objetos;
  int *resultados;

  int i;

  printf("Proyecto 1 - Algoritmos Voraces\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Problema de la mochila\n");

  printf("\nIntroduce la cantidad de objetos:\n");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de objetos tiene que ser mayor a cero.");
  objetos = malloc(sizeof(Objeto) * n);
  resultados = malloc(sizeof(float) * n);

  printf("\nIntroduce el peso y valor de cada objeto: \n");
  for (i = 0; i < n; i++) {
    objetos[i].indice = i;

    scanf("%d%*c", &objetos[i].peso);
    asertar(objetos[i].peso > 0, "El peso de cada objeto debe ser mayor a cero.");

    scanf("%d%*c", &objetos[i].valor);
    asertar(objetos[i].valor > 0, "El valor de cada objeto debe ser mayor a cero.");
  }

  // Inicializar resultados en 0 e índices correspondientemente
  for (i = 0; i < n; i++)
    resultados[i] = 0;

  printf("\nIntroduce el peso máximo que puede llevar la mochila: ");
  scanf("%d%*c", &pesoMax);

  asertar(pesoMax > 0, "El peso máximo debe ser mayor a 0.");

  int resto = repartir(pesoMax, objetos, n, resultados);

  printf("La solución es tomar las siguientes fracciones de cada uno de los objetos: ");
  printf("Objeto    Fracción\n");
  
  for (i = 0; i < n; i++) {
    
  }

  free(objetos);
  free(resultados);
}
