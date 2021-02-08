#ifndef __POLIGONO_H
#define __POLIGONO_H

typedef void* Poligono;

Poligono criaPoligono(char cor[], int tamanho);

float poligonoGetX(Poligono poligono, int index);
float poligonoGetY(Poligono poligono, int index);
char* poligonoGetCor(Poligono poligono);
int poligonoGetTamanho(Poligono poligono);

void poligonoSetX(Poligono poligono, float x, int index);
void poligonoSetY(Poligono poligono, float y, int index);

void desalocaXY(Poligono poligono);

#endif