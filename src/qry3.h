#ifndef __QRY3_H
#define __QRY3_H

#include "quadTree.h"

void cv(QuadTree* qt, int casosCovid, char* cep, char face, int num);

void convertLocalCasosToPoint(QuadTree qt, char* cep, char face, int num, float* cx, float* cy);

void soc(QuadTree* qt, int k, char* cep, char face, int num, FILE* fileTxt);

#endif