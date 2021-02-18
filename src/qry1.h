#ifndef __QRY1_H
#define __QRY1_H

#include "quadTree.h"
#include "circulo.h"
#include "retangulo.h"

int inside(QuadTree* qt, char* j, float x, float y, float* centroMassaX, float* centroMassaY, FILE* fileTxt);

int overlay(QuadTree* qt, char* j, char* k, float* x, float* y, float* w, float* h, FILE* fileTxt);

int overlayCirculoCirculo(Circulo c1, Circulo c2);

int overlayCirculoRetangulo(Circulo c, Retangulo r);

int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);

void pnt(QuadTree* qt, char* j, char* cb, char* cp, FILE* fileTxt);

void delf(QuadTree* qt, char* j, FILE* fileTxt);

#endif