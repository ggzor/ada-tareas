#ifndef __VALIDACION_H__
#define __VALIDACION_H__

void asertar(int condicion, const char *mensaje);

int mayorACero(int x);
int mayorOIgualACero(int x);

int todos(int (*condicion)(int x), int xs[], int n);
int unicos(int xs[], int n);

int potenciaDe2(int n);
int enRango(int l, int u, int n);

#endif // __VALIDACION_H__
