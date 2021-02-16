#ifndef __QRY1_H
#define __QRY1_H

#include "quadTree.h"

int inside(QuadTree* qt, char* j, float x, float y, float* centroMassaX, float* centroMassaY, FILE* fileTxt);

void pnt(QuadTree* qt, char* j, char* cb, char* cp, FILE* fileTxt);

void delf(QuadTree* qt, char* j, FILE* fileTxt);

#endif