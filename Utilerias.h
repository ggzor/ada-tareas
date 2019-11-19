#ifndef __UTILERIAS_H__
#define __UTILERIAS_H__

// Ordenamiento Combsort
void ordenar(int a[], int n);
void ordenarPor(int (*comparar)(const void *, const void *), void *a, int n, int s);

int imin(int a, int b);
int gcd(int a, int b);

#endif // __UTILERIAS_H__
