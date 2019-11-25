#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Utilerias.h"
#include "../Validacion.h"

typedef struct {
  int peso;
  int valor;
  int indice;
} Objeto;

int proporcionValorPeso(const void *o1, const void *o2) {
  Objeto *objeto1 = *((Objeto **) o1),
         *objeto2 = *((Objeto **) o2);

  return (objeto2->valor * objeto1->peso - objeto1->valor * objeto2->peso);
}

int repartir(int pesoMax, Objeto **objetos, int n, int resultados[]) {
  ordenarPor(proporcionValorPeso, objetos, n, sizeof(Objeto *));

  int restante = pesoMax;

  int i, tomado;
  for (i = 0; i < n && restante > 0; i++) {
    tomado = imin(restante, objetos[i]->peso);
    
    restante -= tomado;
    resultados[i] = tomado;
  }

  return restante;
}

int main() {
  int pesoMax, n;
  Objeto *objetos, **apuntadoresObjetos;
  int *pesoTomado;

  int i;

  printf("Proyecto 1 - Algoritmos Voraces\n");
  printf("Axel Suárez Polo 201744436\n");
  printf("Problema de la mochila\n");

  printf("\nIntroduce la cantidad de objetos:\n");
  scanf("%d%*c", &n);

  asertar(n > 0, "La cantidad de objetos tiene que ser mayor a cero.");
  objetos = malloc(sizeof(Objeto) * n);
  apuntadoresObjetos = malloc(sizeof(Objeto *) * n);
  pesoTomado = malloc(sizeof(int) * n);

  printf("\nIntroduce el peso y valor de cada objeto: \n");
  for (i = 0; i < n; i++) {
    objetos[i].indice = i + 1;

    scanf("%d%*c", &objetos[i].peso);
    asertar(objetos[i].peso > 0, "El peso de cada objeto debe ser mayor a cero.");

    scanf("%d%*c", &objetos[i].valor);
    asertar(objetos[i].valor > 0, "El valor de cada objeto debe ser mayor a cero.");
  }

  // Inicializar resultados en 0 y apuntadores
  for (i = 0; i < n; i++) {
    pesoTomado[i] = 0;
    apuntadoresObjetos[i] = objetos + i;
  }

  printf("\nIntroduce el peso máximo que puede llevar la mochila: ");
  scanf("%d%*c", &pesoMax);

  asertar(pesoMax > 0, "El peso máximo debe ser mayor a 0.");

  int resto = repartir(pesoMax, apuntadoresObjetos, n, pesoTomado);

  // Imprimir resultados
  printf("La solución es tomar las siguientes fracciones: \n");
  printf("Objeto    Fracción\n");

  for (i = 0; i < n; i++) {
    if (pesoTomado[i] > 0) {
      printf("  %2d  " "    ", apuntadoresObjetos[i]->indice);

      if (pesoTomado[i] == apuntadoresObjetos[i]->peso) {
        printf("   1    \n");
      } else {
        int g = gcd(pesoTomado[i], apuntadoresObjetos[i]->peso);
        printf("%d/%d = %.3f\n", 
          pesoTomado[i] / g, 
          apuntadoresObjetos[i]->peso / g, 
          (float) pesoTomado[i] / apuntadoresObjetos[i]->peso);
      }
    }
  }

  if (resto > 0) {
    printf("\nQuedaron %d unidades de peso disponibles.\n", resto);
  }

  free(objetos);
  free(pesoTomado);
}
