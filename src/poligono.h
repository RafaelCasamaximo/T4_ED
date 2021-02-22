#ifndef __POLIGONO_H
#define __POLIGONO_H

#include "point.h"

typedef void* Poligono;

//Create
Poligono criaPoligono(DoublyLinkedList pontos, char cor[]);

//Setters
void poligonoSetCor(Poligono poligono, char* cor);
void poligonoSetPoint(Poligono poligono, Point point);
void poligonoSetX(Poligono poligono, float x);
void poligonoSetY(Poligono poligono, float y);

//Getters
char* poligonoGetCor(Poligono poligono);
Point poligonoGetPoint(Poligono poligono);
float poligonoGetX(Poligono poligono);
float poligonoGetY(Poligono poligono);

void poligonoDesenhaSvgQry(Poligono poligono, void* fileSvg);

#endif
